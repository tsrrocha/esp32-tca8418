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
//extern I2CEvent *evKeypad;
//extern QueueHandle_t I2CEventQueue;

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
	ESP_LOGI(tag, "I2C: Driver instalado...");
	//vTaskDelay( pdMS_TO_TICKS ( 1000 ) );
	//ESP_LOGI(tag, "I2C: Configurando Keypad...");
	//KeypadConfig();
	//ESP_LOGI(tag, "I2C: Inicializando o Keypad...");
    //KeypadInit();
	//vTaskDelay( pdMS_TO_TICKS ( 1000 ) );
	//KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
	


	for (;;) {
		//
		xQueueReceive (*queue, &pI2CEvent, portMAX_DELAY);
		ESP_LOGI(tag, "Novo evento de tecla! %03d", pI2CEvent->type);
		vTaskDelay( pdMS_TO_TICKS ( 20 ) );

		if ((I2CEventType)(pI2CEvent->type) == (I2CEventType) I2CEventType::I2CEV_KEYPAD_READKEY) {
			//KeypadWriteByte( TCA8418_CFG_REG, 0x00 );

			//uint8_t intStatData = KeypadRead (TCA8418_INT_STAT_REG);
			/*if (( intStatData & (INT_STAT_K_INT) ) > 0) {
				ESP_LOGI(tag, "Interrupcao KEYPAD!");
			} else if (( intStatData & (INT_STAT_GPI_INT) ) > 0) {
				ESP_LOGI(tag, "Interrupcao GPI Event!");
			} else if (( intStatData & (INT_STAT_OVR_FLOW_INT) ) > 0) {
				ESP_LOGI(tag, "Interrupcao OverFlow!");
			} else {
				ESP_LOGI(tag, "Interrupcao Key Lock!");
			}//*/			

			pI2CEvent->data.keypad.qty = (KeypadRead (TCA8418_KEY_LCK_EC_REG) & 0x0F);
			//ESP_LOGI(tag, "I2CEV_KEYPAD_READKEY! Qty=%d", pI2CEvent->data.keypad.qty);
			while (pI2CEvent->data.keypad.qty > 0) {
				for (int idx = 0; idx < pI2CEvent->data.keypad.qty; idx++) {
					uint8_t aux = 0;
					aux = KeypadRead (TCA8418_KEY_EVENT_A_REG);
					pI2CEvent->data.keypad.keys[idx].key = (KeyEnum_t) (aux & 0x7F);
					pI2CEvent->data.keypad.keys[idx].flag.pressed = (aux & 0x80) >> 7;
					//ESP_LOGI(tag, "TECLA: %d %s", pI2CEvent->data.keypad.keys[idx].key, (pI2CEvent->data.keypad.keys[idx].flag.pressed == 1) ? "Pressed" : "Released" );
					vTaskDelay( pdMS_TO_TICKS ( 10 ) );
				}
				//vTaskDelay( pdMS_TO_TICKS ( 20 ) );
				pI2CEvent->data.keypad.qty = (KeypadRead (TCA8418_KEY_LCK_EC_REG) & 0x0F);	
				//if (pI2CEvent->data.keypad.qty == 0)
				//	KeypadWriteByte( TCA8418_INT_STAT_REG, ( INT_STAT_CAD_INT | INT_STAT_OVR_FLOW_INT | INT_STAT_GPI_INT | INT_STAT_K_INT | INT_STAT_K_LCK_INT ) );
			}
			KeypadWriteByte( TCA8418_INT_STAT_REG, ( INT_STAT_CAD_INT | INT_STAT_OVR_FLOW_INT | INT_STAT_GPI_INT | INT_STAT_K_INT | INT_STAT_K_LCK_INT ) );
			//KeypadWriteByte( TCA8418_CFG_REG, ( CFG_KE_IEN ) );
			
		}
		
		/*
		else if ((I2CEventType)(pI2CEvent->type) == (I2CEventType) I2CEventType::I2CEV_KEYPAD_CLEAR_INT) {
			ESP_LOGI(tag, "EVENTO: Limpa interrupcao...",);
			//KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
		}//*/
		else {
			ESP_LOGI(tag, "Outro tipo de evento!");
		}//*/

		//
		//xQueueSendToBack(StdOutQueue, keypadMsg, portMAX_DELAY);
		//
		//ESP_LOGD(tag, "Novo evento de tecla! %03d", 100);
	
		/*
		uint8_t aux = KeypadRead (TCA8418_CFG_REG);
		ESP_LOGD(tag, "REG CFG %02d = %02d", TCA8418_CFG_REG, aux);

		aux = KeypadRead (TCA8418_INT_STAT_REG);
		ESP_LOGD(tag, "REG INT_STAT %02d = %02d", TCA8418_INT_STAT_REG, aux);

		aux = KeypadRead (TCA8418_GPIO_DAT_STAT1_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT1 %02d = %02d", TCA8418_GPIO_DAT_STAT1_REG, aux);
		aux = KeypadRead (TCA8418_GPIO_DAT_STAT2_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT2 %02d = %02d", TCA8418_GPIO_DAT_STAT2_REG, aux);
		aux = KeypadRead (TCA8418_GPIO_DAT_STAT3_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT3 %02d = %02d", TCA8418_GPIO_DAT_STAT3_REG, aux);
		//*/

		memset(pI2CEvent, 0, sizeof(I2CEvent));
	}
}