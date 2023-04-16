/*
 * screen.c
 *
 *  Created on: Feb 16, 2023
 *      Author: morgan
 */

#include "main.h"
#include "stm32469i_discovery.h"
#include "stm32469i_discovery_lcd.h"
#include <lvgl/lvgl.h>
#include "screen_driver.h"
#include <stdio.h>

#define LCD_SCREEN_WIDTH 800
#define LCD_SCREEN_HEIGHT 480

#define FRAMEBUFFER_SIZE LCD_SCREEN_HEIGHT * LCD_SCREEN_WIDTH

#define LVGL_BUFFER_1_ADDR_AT_SDRAM	(SDRAM_DEVICE_ADDR + FRAMEBUFFER_SIZE * 4)
#define LVGL_BUFFER_2_ADDR_AT_SDRAM (SDRAM_DEVICE_ADDR + FRAMEBUFFER_SIZE * 4 + FRAMEBUFFER_SIZE * 4)

/*
 * Handles to peripherals
 */
extern LTDC_HandleTypeDef hltdc;
extern DMA2D_HandleTypeDef hdma2d;
/*
 * Global variables
 */
lv_disp_drv_t lv_display_driver;
/*
 * Private functions prototypes
 */
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p);
static void disp_clean_dcache(lv_disp_drv_t *drv);
static void CopyImageToLcdFrameBuffer(uint32_t src, uint32_t dst, uint32_t width, uint32_t height);

/*
 * Public functions definitions
 */

// C: rrrrrggggggbbbbb
#define RGB_TO_COLOR(R, G, B) ((uint16_t)((R)&0xF8) << 8) | ((uint16_t)((G)&0xFC) << 3) | (((B)&0xF8) >> 3)

void screen_driver_init() {
    BSP_LCD_Init() ;
  	BSP_LCD_LayerDefaultInit(0, (uint32_t)SDRAM_DEVICE_ADDR);
  	BSP_LCD_SelectLayer(0);
  	BSP_LCD_DisplayOn();
  	BSP_LCD_SetLayerVisible(0, ENABLE);

  	BSP_LCD_Clear(0xFFFFFFFF);

    HAL_Delay(3000);

	static lv_disp_draw_buf_t draw_buf;
	lv_disp_draw_buf_init(&draw_buf, (void*)LVGL_BUFFER_1_ADDR_AT_SDRAM, (void*)LVGL_BUFFER_2_ADDR_AT_SDRAM, FRAMEBUFFER_SIZE);

	lv_disp_drv_init(&lv_display_driver);
	lv_display_driver.hor_res = LCD_SCREEN_WIDTH;
	lv_display_driver.ver_res = LCD_SCREEN_HEIGHT;
	lv_display_driver.flush_cb = disp_flush;
	lv_display_driver.clean_dcache_cb = disp_clean_dcache;
	lv_display_driver.draw_buf = &draw_buf;

	lv_disp_drv_register(&lv_display_driver);
}

/*
 * Private functions definitions
 */

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
	/* Return if the area is out the screen */
	if (area->x2 < 0)
		return;
	if (area->y2 < 0)
		return;
	if (area->x1 > LCD_SCREEN_WIDTH - 1)
		return;
	if (area->y1 > LCD_SCREEN_HEIGHT - 1)
		return;

	CopyImageToLcdFrameBuffer(
		(uint32_t)color_p + (area->y1 * LCD_SCREEN_WIDTH + area->x1) * 4,
		SDRAM_DEVICE_ADDR + (area->y1 * LCD_SCREEN_WIDTH + area->x1) * 2,
		lv_area_get_width(area),
		lv_area_get_height(area)
	);

	lv_disp_flush_ready(&lv_display_driver);
}

static void disp_clean_dcache(lv_disp_drv_t *drv)
{
	//SCB_CleanInvalidateDCache();
}

/**
 * @brief  Copy to LCD frame buffer area centered in WVGA resolution.
 * The area of copy is of size in ARGB8888.
 * @param  pSrc: Pointer to source buffer : source image buffer start here
 * @param  pDst: Pointer to destination buffer LCD frame buffer center area start here
 * @param  xSize: Buffer width
 * @param  ySize: Buffer height
 */
static void CopyImageToLcdFrameBuffer(uint32_t src, uint32_t dst, uint32_t width, uint32_t height) {
	uint32_t inputOutputOffset = LCD_SCREEN_WIDTH - width;

	hdma2d.Instance = DMA2D;

	hdma2d.Init.Mode = DMA2D_M2M_PFC;
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;
	hdma2d.Init.OutputOffset = inputOutputOffset;

	hdma2d.LayerCfg[1].InputOffset = inputOutputOffset;
	hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
	hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
	hdma2d.LayerCfg[1].InputAlpha = 0;

    HAL_DMA2D_Init(&hdma2d);
    HAL_DMA2D_ConfigLayer(&hdma2d, 1);
    HAL_DMA2D_Start(&hdma2d, src, dst, width, height);
    HAL_DMA2D_PollForTransfer(&hdma2d, 1000);

  	BSP_LCD_SetLayerVisible(0, DISABLE);
  	BSP_LCD_SetLayerVisible(0, ENABLE);
}
