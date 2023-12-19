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
    uint8_t d = 0;
    uint8_t qtyEvent = 0;

    //i2c_master_init();
    KeypadConfig();
    KeypadInit();



    for (;;)
    {
        //d = 0;
        //d = KeypadRead (TCA8418_CFG_REG);
        //printf("DEBUG: CFG: %d \r\n", d);

        //d = 0;
        //d = KeypadRead (TCA8418_INT_STAT_REG);
        //printf("DEBUG: INT_STAT: %d \r\n", d);

        d = 0;
        qtyEvent = (KeypadRead (TCA8418_KEY_LCK_EC_REG) & 0x0F);
        //printf("DEBUG: KEY_LCK_EC: %d \r\n", qtyEvent);

        if (qtyEvent > 0) {
            for (uint8_t idx = 0; idx < qtyEvent; idx++ ) {
                d = 0;
                d = KeypadRead (TCA8418_KEY_EVENT_A_REG);
                printf("DEBUG: Tecla: %d - (%d)\r\n", (d & 0x7F), (d & 0x80));
            }
        }

        //printf("DEBUG: vTaskDelay(1000 ms) \r\n");
        vTaskDelay( pdMS_TO_TICKS ( 1000 ) ); // 5 seg


    }
}