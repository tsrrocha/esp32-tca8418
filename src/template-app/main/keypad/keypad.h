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

//#define tag "I2C"
#define TCA8418_ADDR    0x34 // W=0x68 & R=0x69

typedef enum {
    NO_KEY = 0,
    KEY_0_RELEASED = 32,
    KEY_1_RELEASED = 1,
    KEY_2_RELEASED = 2,
    KEY_3_RELEASED = 3,
    KEY_4_RELEASED = 11,
    KEY_5_RELEASED = 12,
    KEY_6_RELEASED = 13,
    KEY_7_RELEASED = 21,
    KEY_8_RELEASED = 22,
    KEY_9_RELEASED = 23,
    KEY_A_RELEASED = 4,
    KEY_B_RELEASED = 14,
    KEY_C_RELEASED = 24,
    KEY_D_RELEASED = 34,
    KEY_HASH_RELEASED = 33,
    KEY_AST_RELEASED = 31
} KeyEnum_t;


typedef struct {
    KeyEnum_t key;
    struct {
        unsigned pressed : 1;
    } state;
} Key_t;

esp_err_t KeypadConfig( void );
void KeypadInit(void);
void KeypadWriteByte( uint8_t reg_addr, uint8_t data );
uint8_t KeypadRead( uint8_t address );

#endif