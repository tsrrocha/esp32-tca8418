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
#include <stdlib.h>
#include <string.h>
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
#include "maintypes.h"
#include "stdout/stdOutGatekeeper.h"

#define MAX_SIZE_STDOUT 50
#define MAX_TASK_DELAY 5000



I2CEvent evKeypad;

QueueHandle_t StdOutQueue;

extern "C" void app_main(void)
{
    // Variável para envio de mensagens para a saida padrao STDOUT.
    char *msg =  (char *)( malloc( (size_t)((sizeof(char *) * MAX_SIZE_STDOUT) + 1 )) );
    
    uint8_t d = 0;
    uint8_t qtyEvent = 0;

    
    // Inicializa a MSG
    memset((void *)(msg), '\0', (  (size_t)((sizeof(char *) * MAX_SIZE_STDOUT) + 1 ) ));

    StdOutQueue = xQueueCreate(5, sizeof(char *));
    
    //
    //memset(&evKeypad, 0, sizeof(I2CEvent));
    //evKeypad.type = I2CEventType::I2CEV_KEYPAD_READKEY;
    
    if (StdOutQueue != NULL) {
        // Cria a Task que é responsável por enviar textos para a saida padrao (stdout)
        xTaskCreate ( prvStdOutGatekeeperTask, "Stdout", 4096, (void *) &(StdOutQueue), 1, NULL );
        
        sprintf(msg, "Inicializando...");
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);

        sprintf(msg, "Gatekeeper criado com sucesso!");
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
    }

    //KeypadConfig();
    //KeypadInit();

    for (;;)
    {
        /*
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

        // Depois de ler as teclas, ocasionadas pela interrupção, deve-se escrever no INT_STAT para o
        // pino /INT voltar ao estado normal.
        KeypadWriteByte( TCA8418_INT_STAT_REG, (INT_STAT_K_INT) );
        //*/

        //printf("DEBUG: vTaskDelay(1000 ms) \r\n");

        sprintf(msg, "vTaskDelay(%d)", MAX_TASK_DELAY);
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);

        vTaskDelay( pdMS_TO_TICKS ( MAX_TASK_DELAY ) ); // 5 seg


    }
}