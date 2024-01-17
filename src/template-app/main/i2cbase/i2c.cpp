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

#define tag "I2C"

xQueue_t xI2CEventQueue;

/**
 * 
 * @brief Esta função configura os GPIOs que serão utilizados na comunicação I2C, inicializa o protocolo e instala-o na ESP32
 * 
 * @param sda 
 * @param scl 
 */
void i2c_master_init(uint16_t sda, uint16_t scl )
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
 * @param pvParameters 
 */
static void prvI2CGatekeeperTask (void *pvParameters)
{
	void* pvI2CEvent;
	for (;;) {
		
		xQueueReceive (xI2CEventQueue, &pvI2CEvent, portMAX_DELAY);
	}
}