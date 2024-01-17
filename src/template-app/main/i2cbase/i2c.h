/**
 * @file i2c.h
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief   Este arquivo implementa um Gatekeeper (porteiro) para controlar o recurso I2C.
 * @version 1.0
 * @date 16/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _I2C_H_
#define _I2C_H_

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"

// GPIO definido para ser o SDA na comunicação I2C
#define CONFIG_SDA_GPIO 21
// GPIO definido para ser o SCL na comunicação I2C
#define CONFIG_SCL_GPIO 22
// Definição do I2C utilizado pelo ESP32
#define I2C_NUM I2C_NUM_0
// Definição da frequência do barramento I2C
#define I2C_MASTER_FREQ_HZ 100000 /*!< I2C clock of TCA8418 can run at 400 kHz max. */

/**
 * @brief Esta função configura os GPIOs que serão utilizados na comunicação I2C, inicializa o protocolo e instala-o na ESP32
 * 
 * @param sda 
 * @param scl 
 */
void i2c_master_init(uint16_t sda, uint16_t scl);

#endif