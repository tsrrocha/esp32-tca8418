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
    I2C_EV_KEYPAD = 1,
    I2C_EV_EEPROM,
    I2C_EV_DISPLAY,
    I2C_EV_UNKNOWN
} I2CEventType;

/**
 * @brief 
 * 
 */
typedef struct {
    I2CEventType type;
    I2CDataEvent event;
} I2CEvent ;

/**
 * @brief 
 * 
 */
typedef struct {

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
typedef union I2CDataEvent {
    I2CKeypadEvent keypad;
    I2CEEPROMEvent eeprom;
    I2CDisplayEvent display;
};


#endif; // MAIN_TYPES_H_