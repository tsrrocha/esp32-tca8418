#include "keypad.h"


esp_err_t KeypadConfig( void )
{
    i2c_master_init(CONFIG_SDA_GPIO, CONFIG_SCL_GPIO);
    return ESP_OK;
}


void KeypadInit( void )
{
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();

	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, ( TCA8418_ADDR << 1) | I2C_MASTER_WRITE, true);
	
	//	Escreve no registrador CFG. 
	i2c_master_write_byte(cmd, TCA8418_CFG_REG, true);
	i2c_master_write_byte(cmd, ( CFG_INT_CFG | CFG_KE_IEN ), true);

	//	Escreve no registrador INT_STAT. 
	i2c_master_write_byte(cmd, TCA8418_INT_STAT_REG, true);
	i2c_master_write_byte(cmd, 0x00, true);
	
	// Configura a matriz para          
	i2c_master_write_byte(cmd, TCA8418_KP_GPIO1_REG, true);
	i2c_master_write_byte(cmd, ( KP_GPIO_ROW0|KP_GPIO_ROW1|KP_GPIO_ROW2|KP_GPIO_ROW3), true);
	i2c_master_write_byte(cmd, TCA8418_KP_GPIO2_REG, true);
	i2c_master_write_byte(cmd, ( KP_GPIO_COL0|KP_GPIO_COL1|KP_GPIO_COL2|KP_GPIO_COL3 ), true);
	i2c_master_write_byte(cmd, TCA8418_KP_GPIO3_REG, true);
	i2c_master_write_byte(cmd, 0x00, true);
	
	//	Escreve no registrador . 
	i2c_master_write_byte(cmd, TCA8418_GPIO_PULL2_REG, true);
	i2c_master_write_byte(cmd, 0xFF, true);		
	i2c_master_write_byte(cmd, TCA8418_GPIO_PULL3_REG, true);
	i2c_master_write_byte(cmd, 0xFF, true);	
	
	//	Escreve no registrador . 
	i2c_master_write_byte(cmd, TCA8418_GPI_EM1_REG, true);
	i2c_master_write_byte(cmd, ( EVENT_MODE_ROW0|EVENT_MODE_ROW1|EVENT_MODE_ROW2|EVENT_MODE_ROW3 ), true);
	i2c_master_write_byte(cmd, TCA8418_GPI_EM2_REG, true);
	i2c_master_write_byte(cmd, ( EVENT_MODE_COL0|EVENT_MODE_COL1|EVENT_MODE_COL2|EVENT_MODE_COL3 ), true);
	i2c_master_write_byte(cmd, TCA8418_GPI_EM3_REG, true);
	i2c_master_write_byte(cmd, 0x00, true);
	//	Escreve no registrador KP_GPIO1. 
	//i2c_master_write_byte(cmd, TCA8418_REG_KP_GPIO_1, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111
	
	//	Escreve no registrador KP_GPIO2. 
	//i2c_master_write_byte(cmd, TCA8418_REG_KP_GPIO_2, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111
	
	//	Escreve no registrador KP_GPIO3. 
	//i2c_master_write_byte(cmd, TCA8418_REG_KP_GPIO_3, true);
	//i2c_master_write_byte(cmd, 0x00, true);		// 0b00000000
	
	//	Escreve no registrador GPIO_DIR1. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_DIR_1, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111

	//	Escreve no registrador GPIO_DIR2. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_DIR_2, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111

	//	Escreve no registrador GPIO_DIR3. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_DIR_1, true);
	//i2c_master_write_byte(cmd, 0x03, true);		// 0b00000011

	//	Escreve no registrador DEBOUNCE_DIS_1. 
	//i2c_master_write_byte(cmd, TCA8418_REG_DEBOUNCE_DIS_1, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111
	
	//	Escreve no registrador DEBOUNCE_DIS_2. 
	//i2c_master_write_byte(cmd, TCA8418_REG_DEBOUNCE_DIS_2, true);
	//i2c_master_write_byte(cmd, 0x0F, true);		// 0b00001111
	
	//	Escreve no registrador DEBOUNCE_DIS_3. 
	//i2c_master_write_byte(cmd, TCA8418_REG_DEBOUNCE_DIS_3, true);
	//i2c_master_write_byte(cmd, 0x00, true);		// 0b00000000
	
	//	Escreve no registrador GPIO_PULL1. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_PULL_1, true);
	//i2c_master_write_byte(cmd, 0x00, true);		// 0b00000000
	
	//	Escreve no registrador GPIO_PULL2. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_PULL_2, true);
	//i2c_master_write_byte(cmd, 0x00, true);		// 0b00000000
	
	//	Escreve no registrador GPIO_PULL3. 
	//i2c_master_write_byte(cmd, TCA8418_REG_GPIO_PULL_3, true);
	//i2c_master_write_byte(cmd, 0x00, true);		// 0b00000000

	i2c_master_stop(cmd);


	esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);
}//*/

