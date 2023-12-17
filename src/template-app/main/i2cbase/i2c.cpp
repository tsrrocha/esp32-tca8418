#include "i2c.h"
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_log.h"

#define tag "I2C"




void i2c_master_init(uint16_t sda, uint16_t scl )
{
	i2c_config_t i2c_config = {};
	i2c_config.mode = I2C_MODE_MASTER;
	i2c_config.master.clk_speed = I2C_MASTER_FREQ_HZ;
	i2c_config.sda_io_num = sda;
	i2c_config.scl_io_num = scl;
	i2c_config.sda_pullup_en = GPIO_PULLUP_ENABLE;
	i2c_config.scl_pullup_en = GPIO_PULLUP_ENABLE;

	ESP_ERROR_CHECK(i2c_param_config(I2C_NUM, &i2c_config));
	ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM, I2C_MODE_MASTER, 0, 0, 0));
}


