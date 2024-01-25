/**
 * @file gpio.h
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 
 * @version 1.0
 * @date 24/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "maintypes.h"

#define TAG_GPIO    "GPIO"

// Definição dos GPIOs
#define CONFIG_GPIO_INT_KEYPAD      (gpio_num_t) 13

typedef struct {
    struct {
        unsigned KeypadIntActive: 1;
    } state;
} InterruptHandle_t;


// 
typedef enum {
    LOW = 0,
    HIGH = 1
} eGPIOState;

typedef struct {
    gpio_num_t pin;
    eGPIOState state;
} Gpio_t;


//************    Prototypes    ***********************

/**
 * @brief 
 * 
 * @return esp_err_t 
 */
esp_err_t GPIOConfig(void);

/**
 * @brief 
 * 
 * @param pvQueue 
 */
void vGpioOutputControllerTask ( void * pvQueue );

/**
 * @brief 
 * 
 * @param args 
 */
void IRAM_ATTR gpio_interrupt_keypad_handler(void *args);


#endif      // _GPIO_H_