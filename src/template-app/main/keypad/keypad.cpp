#include "keypad.h"


esp_err_t KeypadConfig( void )
{
    i2c_master_init(CONFIG_SDA_GPIO, CONFIG_SCL_GPIO);
    return ESP_OK;
}


void KeypadInit( void )
{
    KeypadWriteByte( TCA8418_CFG_REG, (CFG_INT_CFG | CFG_KE_IEN) );
    KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
    KeypadWriteByte( TCA8418_KP_GPIO1_REG, (KP_GPIO_ROW0|KP_GPIO_ROW1|KP_GPIO_ROW2|KP_GPIO_ROW3) );
    KeypadWriteByte( TCA8418_KP_GPIO2_REG, (KP_GPIO_COL0|KP_GPIO_COL1|KP_GPIO_COL2|KP_GPIO_COL3) );
    KeypadWriteByte( TCA8418_KP_GPIO3_REG, 0x00 );	
}


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
	esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);
}//*/

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
	esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);

	return data;
}
