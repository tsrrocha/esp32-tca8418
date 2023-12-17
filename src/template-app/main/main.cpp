/**
 *      @brief  This file is the main file of project. 
 *              This version of project has been done for test the Keypad hardware with I2c protocol.
 *      @file   main.cpp
 *      @author Tiago Sousa Rocha <tsrrocha@gmail.com>
 *      @date   05/11/2023
 * 
 * 
*/

/** INCLUDES    */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "i2cbase/i2c.h"
#include "keypad/keypad.h"
//#include "gpio/gpio.h"
//#include "status/status.h"
//#include "oled/oled.h"
//#include "keypad/keypad.h"
//#include "alarm/alarm.h"
//#include "bomb/bomb.h"
//#include "leds/leds.h"
//#include "buzzer/buzzer.h"
//#include "config.h"


extern "C" void app_main(void)
{


    //i2c_master_init();
    KeypadConfig();
    KeypadInit();

    for (;;)
    {
        printf("DEBUG: vTaskDelay(5000 ms) \r\n");
        vTaskDelay( pdMS_TO_TICKS ( 5000 ) ); // 5 seg
    }
}