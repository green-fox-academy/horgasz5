/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern ADC_HandleTypeDef AdcHandle;
uint16_t value;
typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t pin_no;
}cell_t;

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

cell_t led_matrix_rows[LED_MATRIX_ROWS] = {
	{GPIOA, GPIO_PIN_15},
	{GPIOB, GPIO_PIN_9},
	{GPIOI, GPIO_PIN_2},
	{GPIOI, GPIO_PIN_0},
	{GPIOC, GPIO_PIN_6},
	{GPIOI, GPIO_PIN_3},
	{GPIOG, GPIO_PIN_6}
};

cell_t led_matrix_cols[LED_MATRIX_COLS] = {
	{GPIOI, GPIO_PIN_1},
	{GPIOB, GPIO_PIN_4},
	{GPIOG, GPIO_PIN_7},
	{GPIOA, GPIO_PIN_8},
	{GPIOH, GPIO_PIN_6}
};

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

osMessageQDef(message_q, 1, uint16_t); // Declare a message queue
osMessageQId (message_q_id);           // Declare an ID for the message queue

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
void ADC_thread(void const *argument);
/* Private functions ---------------------------------------------------------*/

void ADC_thread(void const *argument)
{
	while (1){
		HAL_ADC_Start(&AdcHandle);
		HAL_ADC_PollForConversion(&AdcHandle, HAL_MAX_DELAY);
		value = (HAL_ADC_GetValue(&AdcHandle) / 16);

		LCD_UsrLog("%d\n", value);
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("ADC - terminating...\n");
		osThreadTerminate(NULL);
	}
}

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state) {
	// TODO:
	// Wait for the mutex
	osMutexWait(led_matrix_mutex_id, osWaitForever);

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	led_matrix_state[row][col] = state;

	// TODO:
	// Release the mutex
	osMutexRelease(led_matrix_mutex_id);
}

// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	GPIO_InitTypeDef GPIO_InitDef;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();

	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull = GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_MEDIUM;

	GPIO_InitDef.Pin = GPIO_PIN_8 | GPIO_PIN_15;
	HAL_GPIO_Init(GPIOA, &GPIO_InitDef);

	GPIO_InitDef.Pin = GPIO_PIN_4 | GPIO_PIN_9;
	HAL_GPIO_Init(GPIOB, &GPIO_InitDef);

	GPIO_InitDef.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOC, &GPIO_InitDef);

	GPIO_InitDef.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	HAL_GPIO_Init(GPIOG, &GPIO_InitDef);

	GPIO_InitDef.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOH, &GPIO_InitDef);

	GPIO_InitDef.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	HAL_GPIO_Init(GPIOI, &GPIO_InitDef);

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	led_matrix_mutex_id = osMutexCreate(osMutex (LED_MATRIX_MUTEX_DEF));

	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row
		for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {

			// Step 2:
			// Wait for the mutex
			osMutexWait(led_matrix_mutex_id, osWaitForever);

			// Step 3:
			// Turn on the column or row
			HAL_GPIO_WritePin(led_matrix_cols[c].GPIOx, led_matrix_cols[c].pin_no, 1);

			// Step 4:
			// Turn on the leds in that column or row
			for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
				HAL_GPIO_WritePin(led_matrix_rows[r].GPIOx, led_matrix_rows[r].pin_no, !led_matrix_state[r][c]);
			}

			// Step 5:
			// Release the mutex
			osMutexRelease(led_matrix_mutex_id);

			// Step 6:
			// Delay
			osDelay(5);

			// Step 7:
			// Turn off the column or row
			HAL_GPIO_WritePin(led_matrix_cols[c].GPIOx, led_matrix_cols[c].pin_no, 0);
		}
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	message_q_id = osMessageCreate(osMessageQ(message_q), NULL);
	osMessagePut(message_q_id, value, osWaitForever);

	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osDelay(value);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
