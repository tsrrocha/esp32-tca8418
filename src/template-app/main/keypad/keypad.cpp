/**
 * @file keypad.cpp
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 
 * @version 1.0
 * @date 23/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "keypad.h"

const uint8_t keymaps[20] = {
	0,
	32, 	// 0 Released
	1, 		// 1 Released
	2,		// 2 Released
	3,		// 3 Released
	11, 	// 4 Released
	12, 	// 5 Released
	13, 	// 6 Released
	21, 	// 7 Released
	22, 	// 8 Released
	23, 	// 9 Released
	 4,		// A Released
	14, 	// B Released
	24, 	// C Released
	34, 	// D Released
	33, 	// # Released
	161, 	// # Pressed
	31, 	// * Released
	159, 	// * Pressed
	0
};

/**
 * @brief 
 * 
 * @return esp_err_t 
 */
esp_err_t KeypadConfig( void )
{
    return ESP_OK;
}

/**
 * @brief 
 * 
 */
void KeypadInit( void )
{
    KeypadWriteByte( TCA8418_CFG_REG, (CFG_INT_CFG | CFG_KE_IEN) );
    KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
    KeypadWriteByte( TCA8418_KP_GPIO1_REG, (KP_GPIO_ROW0|KP_GPIO_ROW1|KP_GPIO_ROW2|KP_GPIO_ROW3) );
    KeypadWriteByte( TCA8418_KP_GPIO2_REG, (KP_GPIO_COL0|KP_GPIO_COL1|KP_GPIO_COL2|KP_GPIO_COL3) );
    KeypadWriteByte( TCA8418_KP_GPIO3_REG, 0x00 );	
}

/**
 * @brief 
 * 
 * @param reg_addr 
 * @param data 
 */
void KeypadWriteByte( uint8_t reg_addr, uint8_t data )
{
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();

	// Start condition
	i2c_master_start(cmd);
	// Send Slave address
	i2c_master_write_byte(cmd, ( TCA8418_ADDR << 1) | I2C_MASTER_WRITE, true);	
	//	Escreve no registrador CFG. 
	i2c_master_write_byte(cmd, reg_addr, true);
	i2c_master_write_byte(cmd, data, true);
	// Stop condition
	i2c_master_stop(cmd);

	// Send command
	//esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);
	i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);
}//*/

/**
 * @brief 
 * 
 * @param address 
 * @return uint8_t 
 */
uint8_t KeypadRead( uint8_t address )
{
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	uint8_t data;
	
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, ( TCA8418_ADDR << 1) | I2C_MASTER_WRITE, true);
	i2c_master_write_byte(cmd, address, true);

	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, ( TCA8418_ADDR << 1) | I2C_MASTER_READ, true);
	i2c_master_read_byte(cmd, &data, I2C_MASTER_LAST_NACK);

	i2c_master_stop(cmd);

	// Send command
	//esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);
	i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);

	return data;
}
