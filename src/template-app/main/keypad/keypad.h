#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/i2c.h"
#include "i2cbase/i2c.h"
#include "tca8418_reg.h"

#define tag "I2C"
#define TCA8418_ADDR    0x34 // W=0x68 & R=0x69


esp_err_t KeypadConfig( void );
void KeypadInit(void);
void KeypadWriteByte( uint8_t reg_addr, uint8_t data );
uint8_t KeypadRead( uint8_t address );

#endif