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
#include "keypad/keypad.h"


/**
 * @brief Enumerator para os tipos de eventos enviados para o Gatekeeper do barramento I2C.
 * 
 */
typedef enum {
    I2CEV_NOEVENT = 0,          // Nenhum evento
    I2CEV_KEYPAD_READKEY,       // Evento para leitura das teclas pressionadas no teclado
    I2CEV_KEYPAD_CLEAR_INT,
    I2CEV_EEPROM,
    I2CEV_DISPLAY,
    I2CEV_UNKNOWN
} I2CEventType;


/**
 * @brief Estrutura de dados que representa uma tecla pressionada ou liberada.
 * 
 */
typedef struct {
    uint8_t key;
    struct {
        unsigned pressed : 1;
    } flag;
} Key;

/**
 * @brief Estrutura de dados que representa dados de um evento I2C do teclado.
 * 
 */
typedef struct {
    uint8_t qty;
    Key keys[10];
} I2CKeypadEvent;

/**
 * @brief Estrutura de dados que representa dados de um evento I2C da memória E2PROM.
 * 
 */
typedef struct {

} I2CEEPROMEvent;

/**
 * @brief Estrutura de dados que representa dados de um evento I2C do display.
 * 
 */
typedef struct {

} I2CDisplayEvent;

/**
 * @brief Estrutura de dados que representa um evento genérico do I2C. 
 *  Por ser genérico, os dados que o evento armazena pode ser um evento de teclado, de memória E2PROM ou de display.
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