#ifndef _I2C_H_
#define _I2C_H_

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"

#define CONFIG_SDA_GPIO 21
#define CONFIG_SCL_GPIO 22

#define I2C_NUM I2C_NUM_0
#define I2C_MASTER_FREQ_HZ 100000 /*!< I2C clock of TCA8418 can run at 400 kHz max. */

/**
 * 
*/
void i2c_master_init(uint16_t sda, uint16_t scl);

#endif