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

#define FRAMEBUFFER_SIZE LCD_SCREEN_WIDTH * LCD_SCREEN_HEIGHT

#define LVGL_BUFFER_1_ADDR_AT_SDRAM	(lv_color_t *)(SDRAM_DEVICE_ADDR)
#define LVGL_BUFFER_2_ADDR_AT_SDRAM (LVGL_BUFFER_1_ADDR_AT_SDRAM + FRAMEBUFFER_SIZE)

extern DMA2D_HandleTypeDef hdma2d_eval;
extern LTDC_HandleTypeDef  hltdc_eval;

/*
 * Global variables
 */
lv_disp_drv_t lv_display_driver;

/*
 * Private functions prototypes
 */
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p);
static void dma2d_copy_area(lv_area_t area, uint32_t src_buffer, uint32_t dst_buffer);

/*
 * Public functions definitions
 */

void screen_driver_init() {
    BSP_LCD_Init() ;
  	BSP_LCD_LayerDefaultInit(0, (uint32_t)LVGL_BUFFER_1_ADDR_AT_SDRAM);

  	BSP_LCD_Clear(LCD_COLOR_BLACK);

	static lv_disp_draw_buf_t draw_buf;
	lv_disp_draw_buf_init(&draw_buf, (void*)LVGL_BUFFER_1_ADDR_AT_SDRAM, (void*)LVGL_BUFFER_2_ADDR_AT_SDRAM, FRAMEBUFFER_SIZE);

	lv_disp_drv_init(&lv_display_driver);
	lv_display_driver.direct_mode = true;
	lv_display_driver.full_refresh = true;
	lv_display_driver.hor_res = LCD_SCREEN_WIDTH;
	lv_display_driver.ver_res = LCD_SCREEN_HEIGHT;
	lv_display_driver.flush_cb = disp_flush;
	lv_display_driver.draw_buf = &draw_buf;

	lv_disp_drv_register(&lv_display_driver);
}

/*
 * Private functions definitions
 */

/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished*/
static void disp_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p) {
	if (!lv_disp_flush_is_last(&lv_display_driver)) {
		lv_disp_flush_ready(&lv_display_driver);
		return;
	}

	// Swap the buffer for the one to display and reload the screen at the next vertical blanking
	HAL_LTDC_SetAddress_NoReload(&hltdc_eval, (uint32_t)color_p, 0);
	HAL_LTDC_Reload(&hltdc_eval, LTDC_RELOAD_VERTICAL_BLANKING); // VSYNC

	// Determine source and destination of transfer
	uint32_t *dma_xfer_src = (uint32_t *)color_p;
	uint32_t *dma_xfer_dst = (uint32_t *)(color_p == LVGL_BUFFER_1_ADDR_AT_SDRAM ? LVGL_BUFFER_2_ADDR_AT_SDRAM : LVGL_BUFFER_1_ADDR_AT_SDRAM);

    lv_disp_t *disp = _lv_refr_get_disp_refreshing();
	for (size_t i = 0; i < disp->inv_p; i++){
		// If the area was not joined (and thus should not be ignored)
		if (!disp->inv_area_joined[i]){
			dma2d_copy_area(disp->inv_areas[i], (uint32_t)dma_xfer_src, (uint32_t)dma_xfer_dst);
		}
	}

	lv_disp_flush_ready(&lv_display_driver);
}

/**
 * @brief  Copy to LCD frame buffer area centered in WVGA resolution.
 * The area of copy is of size in ARGB8888.
 * @param  pSrc: Pointer to source buffer : source image buffer start here
 * @param  pDst: Pointer to destination buffer LCD frame buffer center area start here
 * @param  xSize: Buffer width
 * @param  ySize: Buffer height
 */
static void dma2d_copy_area(lv_area_t area, uint32_t src_buffer, uint32_t dst_buffer) {
	size_t start_offset = (LCD_SCREEN_WIDTH * area.y1 + area.x1) * 4; // address offset (not pixel offset so it is multiplied by 4)
	size_t area_width = 1 + area.x2 - area.x1;
	size_t area_height = 1 + area.y2 - area.y1;
	size_t in_out_offset = LCD_SCREEN_WIDTH - area_width;

	// Set up DMA2D to transfer parts of picture to part of picture
	hdma2d_eval.Init.Mode = DMA2D_M2M; // plain memory to memory
	hdma2d_eval.Init.ColorMode = DMA2D_INPUT_ARGB8888;
	hdma2d_eval.Init.OutputOffset = in_out_offset; // nb pixels in buffer between end of area line and start of next area line
	hdma2d_eval.LayerCfg[DMA2D_FOREGROUND_LAYER].InputColorMode = DMA2D_INPUT_ARGB8888;
	hdma2d_eval.LayerCfg[DMA2D_FOREGROUND_LAYER].InputOffset = in_out_offset;
	hdma2d_eval.LayerCfg[DMA2D_FOREGROUND_LAYER].AlphaMode = DMA2D_NO_MODIF_ALPHA;
	hdma2d_eval.LayerCfg[DMA2D_FOREGROUND_LAYER].InputAlpha = 0;

	HAL_DMA2D_Init(&hdma2d_eval);
	HAL_DMA2D_ConfigLayer(&hdma2d_eval, DMA2D_FOREGROUND_LAYER);
	HAL_DMA2D_Start(&hdma2d_eval, src_buffer + start_offset, dst_buffer + start_offset, area_width, area_height);	// Start transfer
	HAL_DMA2D_PollForTransfer(&hdma2d_eval, 10000);	// Wait for transfer to be over
}
