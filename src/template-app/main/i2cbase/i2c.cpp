/**
 * @file i2c.cpp
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 	Este arquivo implementa um Gatekeeper (porteiro) para controlar o recurso I2C.
 * @version 1.0
 * @date 16/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "i2c.h"
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "keypad/keypad.h"

#define tag "I2C"

extern QueueHandle_t StdOutQueue;

static char *keypadMsg[] = { "Novo evento de tecla..." };

/**
 * 
 * @brief Esta função configura os GPIOs que serão utilizados na comunicação I2C, inicializa o protocolo e instala-o na ESP32
 * 
 * @param sda 
 * @param scl 
 */
static void i2c_init(uint16_t sda, uint16_t scl )
{
	i2c_config_t i2c_config = {};
	i2c_config.mode = I2C_MODE_MASTER;
	i2c_config.master.clk_speed = I2C_MASTER_FREQ_HZ;
	i2c_config.sda_io_num = sda;
	i2c_config.scl_io_num = scl;
	i2c_config.sda_pullup_en = GPIO_PULLUP_ENABLE;
	i2c_config.scl_pullup_en = GPIO_PULLUP_ENABLE;
	// Configura o barramento I2C
	ESP_ERROR_CHECK(i2c_param_config(I2C_NUM, &i2c_config));
	// Instala o driver I2C
	ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM, I2C_MODE_MASTER, 0, 0, 0));
}


/**
 * @brief Esta função é uma tarefa (Task) responsável por controlar o uso do recurso I2C.
 * 
 * @param pvQueue 
 */
void prvI2CGatekeeperTask (void *pvQueue)
{
	// 
	I2CEvent *pI2CEvent;
	//
	QueueHandle_t * queue = (QueueHandle_t *) pvQueue ;	

	// Configura e instala o driver I2C.
	i2c_init(CONFIG_SDA_GPIO, CONFIG_SCL_GPIO);

	for (;;) {
		//
		xQueueReceive (*queue, &pI2CEvent, portMAX_DELAY);
		ESP_LOGI(tag, "Novo evento de tecla! %03d", pI2CEvent->type);

		if ((I2CEventType)(pI2CEvent->type) == (I2CEventType) I2CEventType::I2CEV_KEYPAD_READKEY) {
			ESP_LOGI(tag, "Novo evento de KEYPAD!");
			pI2CEvent->data.keypad.qty = (KeypadRead (TCA8418_KEY_LCK_EC_REG) & 0x0F);
			if (pI2CEvent->data.keypad.qty > 0) {
				for (int idx = 0; idx < pI2CEvent->data.keypad.qty; idx++) {
					pI2CEvent->data.keypad.keys[idx].key = KeypadRead (TCA8418_KEY_EVENT_A_REG);
					ESP_LOGI(tag, "TECLA: %d", pI2CEvent->data.keypad.keys[idx].key);
				}
				// Depois de ler as teclas, ocasionadas pela interrupção, deve-se escrever no INT_STAT para o
				// pino /INT voltar ao estado normal.
				KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
			}
			ESP_LOGI(tag, "I2CEV_KEYPAD_READKEY! Qty=%d", pI2CEvent->data.keypad.qty);
		} else {
			ESP_LOGI(tag, "Outro tipo de evento!");
		}

		//
		//xQueueSendToBack(StdOutQueue, keypadMsg, portMAX_DELAY);
		//
		//ESP_LOGD(tag, "Novo evento de tecla! %03d", 100);
		
		memset(pI2CEvent, 0, sizeof(I2CEvent));
	}
}