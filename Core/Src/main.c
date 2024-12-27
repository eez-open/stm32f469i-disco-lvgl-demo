/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "dma2d.h"
#include "dsihost.h"
#include "fatfs.h"
#include "i2c.h"
#include "ltdc.h"
#include "quadspi.h"
#include "sai.h"
#include "sdio.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>

#include "stm32469i_discovery_sdram.h"
#include "stm32469i_discovery_qspi.h"
#include "stm32469i_discovery_lcd.h"

#include "hal_stm_lvgl/screen_driver.h"
#include "hal_stm_lvgl/touch_sensor_driver.h"

#include <lvgl/src/drivers/display/st_ltdc/lv_st_ltdc.h>

#include "../../eez-project/src/ui/ui.h"
#include "../../eez-project/src/ui/screens.h"
#include "../../eez-project/src/ui/images.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define TFT_HOR_RES		800
#define TFT_VER_RES		480
#define BYTES_PER_PIXEL 4
#define FRAMEBUF_SIZE	(TFT_HOR_RES * TFT_VER_RES * BYTES_PER_PIXEL)

#define OSC_WIDTH	800
#define OSC_HEIGHT	400
#define DP_NUM		800
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
__attribute__((section(".sdram"), aligned(4)))  LV_DRAW_BUF_DEFINE_STATIC (canvas_buf, OSC_WIDTH, OSC_HEIGHT, LV_COLOR_FORMAT_XRGB8888);
__attribute__((section(".sdram"), aligned(4)))  uint8_t fb2[FRAMEBUF_SIZE];
__attribute__((section(".sdram"), aligned(4)))  uint8_t fb1[FRAMEBUF_SIZE];

uint32_t old_y[DP_NUM] = { 0 };

uint32_t old_y_fb1[DP_NUM] = { 0 };
uint32_t old_y_fb2[DP_NUM] = { 0 };

int32_t data_buf1[800] __attribute__((aligned(4))) = { 0 };

int32_t data_buf2[800] __attribute__((aligned(4))) = { 0 };

int32_t *buf_to_write;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int32_t diff;

int32_t get_var_diff() {
    return diff;
}

void set_var_diff(int32_t value) {
    diff = value;
}

int32_t timestamp;

int32_t get_var_timestamp() {
    return timestamp;
}

void set_var_timestamp(int32_t value) {
    timestamp = value;
}

uint32_t *buf;

void update_chart(uint8_t *px_map) {
    uint32_t T = HAL_GetTick() % 800;
	static uint32_t last_t;
    diff = T - last_t;
    last_t = T;
    timestamp = T;

    uint32_t *fb = (uint32_t *)(px_map);
	uint32_t *old_y_fb = (uint8_t *)fb == fb1 ? old_y_fb1 : old_y_fb2;

    uint32_t black_32 = lv_color_to_u32(lv_color_make(0, 0, 0));
    uint32_t yellow_32 = lv_color_to_u32(lv_color_make(255, 255, 0));

	for (int x = 0; x < 800; x++) {
	  int y = buf_to_write[x] / 4096.0 * OSC_HEIGHT;

	  //buf[x + old_y[x] * OSC_WIDTH] = black_32;
	  //buf[x + y * OSC_WIDTH] = yellow_32;
	  //old_y[x] = y;

	  fb[x + old_y_fb[x] * OSC_WIDTH] = black_32;
	  fb[x + y * OSC_WIDTH] = yellow_32;

	  old_y_fb[x] = y;
	}

    buf_to_write = buf_to_write == data_buf1 ? data_buf2: data_buf1;
    for (int x = 0; x < 800; x++) {
    	buf_to_write[x] = 2048.0f + 1800.0f * sinf(2 * (2.0f * 3.14159265f / 800.0f) * (x + T));
    }
}

void disp_flash_start_cb(lv_event_t *e) {
	static uint8_t *fb = fb1;

	lv_display_t *disp = lv_event_get_target(e);
	if (lv_display_flush_is_last(disp)) {
		update_chart(fb);

		fb = fb == fb1 ? fb2 : fb1;
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
#if 0
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_DMA2D_Init();
  MX_DSIHOST_DSI_Init();
  MX_FMC_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_LTDC_Init();
  MX_SAI1_Init();
  MX_SDIO_SD_Init();
  MX_TIM1_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_FATFS_Init();
  MX_USB_DEVICE_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  // STM32 init
  HAL_Init();
  SystemClock_Config();

  BSP_QSPI_Init();
  BSP_QSPI_EnableMemoryMappedMode();

  BSP_SDRAM_Init();

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(0, (uint32_t)fb1);
  BSP_LCD_Clear(LCD_COLOR_BLACK);

  LV_DRAW_BUF_INIT_STATIC(canvas_buf);

  // LVGL init
  lv_init();

  // init display
  uint32_t ltdc_layer_index = 0; /* typically 0 or 1 */
#if 1
  // note: direct mode with the LV_USE_DRAW_DMA2D enabled results in glitches on the screen
  lv_display_t *disp = lv_st_ltdc_create_direct(fb1, fb2, ltdc_layer_index);
#else
  // note: partial mode works fine with the LV_USE_DRAW_DMA2D enabled
  #define BUF_SIZE 800*40*4
  static uint8_t partial_buf1[BUF_SIZE];
  static uint8_t optional_partial_buf2[BUF_SIZE];
  //create_disp(partial_buf1, 0/*optional_partial_buf2*/, BUF_SIZE, ltdc_layer_index);
  lv_st_ltdc_create_partial(partial_buf1, optional_partial_buf2, BUF_SIZE, ltdc_layer_index);
#endif

  lv_display_add_event_cb(disp, disp_flash_start_cb, LV_EVENT_FLUSH_START, NULL);

  // init touch
  touch_sensor_driver_init();

  // from the source code generated by the EEZ Studio
  ui_init();
  ui_tick();

  lv_canvas_set_draw_buf(objects.canvas, &canvas_buf);
  lv_obj_set_style_bg_opa(objects.canvas, LV_OPA_TRANSP, 0);

  // Fill the background once initially
  lv_canvas_fill_bg(objects.canvas, lv_color_black(), LV_OPA_COVER);

  // Get the image descriptor of the canvas
  const lv_img_dsc_t *img_dsc = lv_canvas_get_image(objects.canvas);
  // Get a pointer to the color buffer
  buf = (uint32_t*) img_dsc->data; // For RGB565

  buf_to_write = data_buf1;

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	uint32_t delay = lv_timer_handler();

	uint32_t t1 = HAL_GetTick();
    ui_tick();
    uint32_t t2 = HAL_GetTick();
    uint32_t diff = t2 - t1;

	if (delay != LV_NO_TIMER_READY) {
		if (diff < delay) {
			HAL_Delay(delay - diff);
		}
	} else
		HAL_Delay(5);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  RCC_OscInitStruct.PLL.PLLR = 6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SAI_PLLSAI|RCC_PERIPHCLK_SDIO
                              |RCC_PERIPHCLK_CLK48|RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 288;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV6;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48CLKSOURCE_PLLSAIP;
  PeriphClkInitStruct.SdioClockSelection = RCC_SDIOCLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
	lv_tick_inc(1);
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
