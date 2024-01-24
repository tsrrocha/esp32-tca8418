/**
 * @file keypad.h
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 
 * @version 1.0
 * @date 23/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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

typedef enum {
    NO_KEY = 0,
    KEY_0_RELEASED,
    KEY_1_RELEASED,
    KEY_2_RELEASED,
    KEY_3_RELEASED,
    KEY_4_RELEASED,
    KEY_5_RELEASED,
    KEY_6_RELEASED,
    KEY_7_RELEASED,
    KEY_8_RELEASED,
    KEY_9_RELEASED,
    KEY_A_RELEASED,
    KEY_B_RELEASED,
    KEY_C_RELEASED,
    KEY_D_RELEASED,
    KEY_HASH_RELEASED,
    KEY_HASH_PRESSED,
    KEY_AST_RELEASED,
    KEY_AST_PRESSED,
    UNKNOWN_KEY
} KeyEnum_t;


esp_err_t KeypadConfig( void );
void KeypadInit(void);
void KeypadWriteByte( uint8_t reg_addr, uint8_t data );
uint8_t KeypadRead( uint8_t address );

#endif