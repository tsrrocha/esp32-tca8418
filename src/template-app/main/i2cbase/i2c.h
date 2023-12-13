#ifndef _I2C_H_
#define _I2C_H_

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"

void i2c_master_init(uint16_t sda, uint16_t scl, uint16_t reset);

#endif