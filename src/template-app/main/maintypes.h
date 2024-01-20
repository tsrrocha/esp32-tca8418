/**
 * @file maintypes.h
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 
 * @version 1.0
 * @date 17/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MAIN_TYPES_H_
#define MAIN_TYPES_H_

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief 
 * 
 */
typedef enum {
    I2C_EV_NOEVENT = 0,
    I2C_EV_KEYPAD,
    I2CEV_KEYPAD_READKEY,
    I2C_EV_EEPROM,
    I2C_EV_DISPLAY,
    I2C_EV_UNKNOWN
} I2CEventType;


typedef struct {
    uint8_t key;
    struct {
        unsigned pressed : 1;
    } flag;
} Key;

/**
 * @brief 
 * 
 */
typedef struct {
    uint8_t qty;
    Key keys[10];
} I2CKeypadEvent;

/**
 * @brief 
 * 
 */
typedef struct {

} I2CEEPROMEvent;

/**
 * @brief 
 * 
 */
typedef struct {

} I2CDisplayEvent;

/**
 * @brief 
 * 
 */
typedef struct {
    I2CEventType type;
    union data {
        I2CKeypadEvent keypad;
        I2CEEPROMEvent e2prom;
        I2CDisplayEvent display;
    } data ;
} I2CEvent ;



#endif // MAIN_TYPES_H_