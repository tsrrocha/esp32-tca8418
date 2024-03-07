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
	31, 	// * Released
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
	// Configura as portas que serão Keypad Matrix
	KeypadWriteByte( TCA8418_KP_GPIO1_REG, (KP_GPIO_ROW0|KP_GPIO_ROW1|KP_GPIO_ROW2|KP_GPIO_ROW3) );
    KeypadWriteByte( TCA8418_KP_GPIO2_REG, (KP_GPIO_COL0|KP_GPIO_COL1|KP_GPIO_COL2|KP_GPIO_COL3) );
    KeypadWriteByte( TCA8418_KP_GPIO3_REG, 0x00 );

	// Configura os demais pinos como saídas (OUTPUT)	
	KeypadWriteByte ( TCA8418_GPIO_DIR1_REG, ( DATA_DIR_R7DD | DATA_DIR_R6DD | DATA_DIR_R5DD | DATA_DIR_R4DD ) );
	KeypadWriteByte ( TCA8418_GPIO_DIR2_REG, ( DATA_DIR_C7DD | DATA_DIR_C6DD | DATA_DIR_C5DD | DATA_DIR_C4DD ) );
	KeypadWriteByte ( TCA8418_GPIO_DIR3_REG, ( DATA_DIR_C9DD | DATA_DIR_C8DD ) );

	// Configura as portas que serão Event Mode
	KeypadWriteByte( TCA8418_GPI_EM1_REG, (EVENT_MODE_ROW0|EVENT_MODE_ROW1|EVENT_MODE_ROW2|EVENT_MODE_ROW3) );
    KeypadWriteByte( TCA8418_GPI_EM2_REG, (EVENT_MODE_COL0|EVENT_MODE_COL1|EVENT_MODE_COL2|EVENT_MODE_COL3) );
    KeypadWriteByte( TCA8418_GPI_EM3_REG, 0x00 );

	// Set 0 (LOW) nas saídas
	KeypadWriteByte ( TCA8418_GPIO_DAT_OUT1_REG, ( DATA_OUT_R7DO | DATA_OUT_R6DO | DATA_OUT_R5DO | DATA_OUT_R4DO ) );
	KeypadWriteByte ( TCA8418_GPIO_DAT_OUT2_REG, ( DATA_OUT_C7DO | DATA_OUT_C6DO | DATA_OUT_C5DO | DATA_OUT_C4DO ) );
	KeypadWriteByte ( TCA8418_GPIO_DAT_OUT3_REG, ( DATA_OUT_C9DO | DATA_OUT_C8DO ) );

	// 
    KeypadWriteByte( TCA8418_CFG_REG, ( CFG_KE_IEN ) );
    //KeypadWriteByte( TCA8418_INT_STAT_REG, 0x00 );
	KeypadWriteByte( TCA8418_INT_STAT_REG, ( INT_STAT_CAD_INT | INT_STAT_OVR_FLOW_INT | INT_STAT_GPI_INT | INT_STAT_K_INT | INT_STAT_K_LCK_INT ) );
	KeypadWriteByte( TCA8418_KEY_LCK_EC_REG, 0x00 );
    

	//
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
	esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);
	//i2c_master_cmd_begin(I2C_NUM, cmd, pdMS_TO_TICKS( 1 ));

	/*if (espRc == ESP_OK) {
		ESP_LOGI(tag, "Keypad configured successfully");
	} else {
		ESP_LOGE(tag, "Keypad configuration failed. code: 0x%.2X", espRc);
	}//*/

	i2c_cmd_link_delete(cmd);
	//vTaskDelay( pdMS_TO_TICKS ( 1 ) );

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
	// Re-Start
	i2c_master_start(cmd);
	i2c_master_write_byte(cmd, ( TCA8418_ADDR << 1) | I2C_MASTER_READ, true);
	i2c_master_read_byte(cmd, &data, I2C_MASTER_LAST_NACK);
	i2c_master_stop(cmd);

	

	// Send command
	esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, 10/portTICK_PERIOD_MS);
	//esp_err_t espRc = i2c_master_cmd_begin(I2C_NUM, cmd, pdMS_TO_TICKS( 3 ));
	//vTaskDelay( pdMS_TO_TICKS ( 1 ) );
	

	i2c_cmd_link_delete(cmd);
	//vTaskDelay( pdMS_TO_TICKS ( 1 ) );

	return data;
}
