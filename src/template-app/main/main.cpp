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
#include "gpio/gpio.h"
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

#define INCLUDE_vTaskSuspend 1

#define MAX_SIZE_STDOUT 50
#define MAX_TASK_DELAY 1000 //5000



I2CEvent *evKeypad;

QueueHandle_t StdOutQueue;
QueueHandle_t I2CEventQueue;

extern "C" void app_main(void)
{
    uint8_t idx = 0;
    uint8_t d = 0;
    uint8_t qtyEvent = 0;
    uint8_t aux = 0;

    // Variável para envio de mensagens para a saida padrao STDOUT.
    char *msg =  (char *)( malloc( (size_t)((sizeof(char *) * MAX_SIZE_STDOUT) + 1 )) );
    //
    evKeypad =  (I2CEvent *)( malloc( sizeof(I2CEvent) ) );
    
    // Inicializa a MSG
    memset((void *)(msg), '\0', (  (size_t)((sizeof(char *) * MAX_SIZE_STDOUT) + 1 ) ));
    //
    memset(evKeypad, 0, sizeof(I2CEvent));
    
    StdOutQueue = xQueueCreate(5, sizeof(char *));
    I2CEventQueue = xQueueCreate(20, sizeof(I2CEvent *));

    //
    evKeypad->type = I2CEventType::I2CEV_KEYPAD_READKEY;
    
    //
    //memset(&evKeypad, 0, sizeof(I2CEvent));
    //evKeypad.type = I2CEventType::I2CEV_KEYPAD_READKEY;
    
    if ((StdOutQueue != NULL) && (I2CEventQueue != NULL )){
        // Cria a Task que é responsável por enviar textos para a saida padrao (stdout)
        xTaskCreate ( prvStdOutGatekeeperTask, "StdoutGatekeeper", 4096, (void *) &(StdOutQueue), 2, NULL );
        // 
        xTaskCreate ( prvI2CGatekeeperTask, "I2CGatekeeper", 4096, (void *) &(I2CEventQueue), 0, NULL );
        
        sprintf(msg, "Inicializando...");
        xQueueSendToBack(StdOutQueue, &(msg), 0);

        sprintf(msg, "Gatekeepers criado com sucesso!");
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);

        GPIOConfig();
    }

    sprintf(msg, "Aguarda a instalação do I2C Driver!");
    xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
    vTaskDelay( pdMS_TO_TICKS ( 500 ) );

    // 
    KeypadConfig();
	KeypadInit();


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

        /*if (idx >=9) {
            evKeypad->type = I2CEventType::I2CEV_KEYPAD_CLEAR_INT;
            if (xQueueSendToBack(I2CEventQueue, &(evKeypad), portMAX_DELAY) == pdTRUE)
            {
                sprintf(msg, "I2CEvent sent successfully! %d, qty=%d", evKeypad->type, evKeypad->data.keypad.qty);
                xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);    
            }
            idx = 0;
        } else {
            idx++;
        }//*/

        //
        d = !(gpio_get_level(CONFIG_GPIO_INT_KEYPAD));
        sprintf(msg, "vTaskDelay(%d) /INT=%d", MAX_TASK_DELAY, d);
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);

        

        //
        vTaskDelay( pdMS_TO_TICKS ( MAX_TASK_DELAY ) ); // 5 seg

        //aux = 0;
        //aux = KeypadRead (TCA8418_CFG_REG);
        //sprintf(msg, "[idx=%d] REG CFG %02d = %02d", idx, TCA8418_CFG_REG, aux);
        //xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
        //vTaskDelay( pdMS_TO_TICKS ( 1000 ) );

        //aux = 0;
        //aux = KeypadRead (TCA8418_INT_STAT_REG);
        //sprintf(msg, "REG INT_STAT %02d = %02d", TCA8418_INT_STAT_REG, aux);
        //xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
        //vTaskDelay( pdMS_TO_TICKS ( 1000 ) );

        
        if (d == 1) {
            if (idx >= 5) {
                aux = 0;
                aux = (KeypadRead (TCA8418_KEY_LCK_EC_REG) & 0x0F);                
                sprintf(msg, "REG KEY_LCK_EC_REG %02d = %02d", TCA8418_KEY_LCK_EC_REG, aux);
                xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);

                if (aux > 0){
                    evKeypad->type = I2CEventType::I2CEV_KEYPAD_READKEY;
                    if (xQueueSendFromISR(I2CEventQueue, &evKeypad, NULL))
                    {
                    }
                }//*/
                //KeypadWriteByte( TCA8418_INT_STAT_REG, ( INT_STAT_CAD_INT | INT_STAT_OVR_FLOW_INT | INT_STAT_GPI_INT | INT_STAT_K_INT | INT_STAT_K_LCK_INT ) );
            }
            idx++;
        } else {
            idx=0;
        }

        /*
        aux = KeypadRead (TCA8418_GPIO_DAT_STAT1_REG);
        sprintf(msg, "REG DAT_STAT1 %02X = %02d", TCA8418_GPIO_DAT_STAT1_REG, aux);
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
        vTaskDelay( pdMS_TO_TICKS ( 100 ) );
        aux = KeypadRead (TCA8418_GPIO_DAT_STAT2_REG);
        sprintf(msg, "REG DAT_STAT2 %02X = %02d", TCA8418_GPIO_DAT_STAT2_REG, aux);
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
        vTaskDelay( pdMS_TO_TICKS ( 100 ) );
        aux = KeypadRead (TCA8418_GPIO_DAT_STAT3_REG);
        sprintf(msg, "REG DAT_STAT3 %02X = %02d", TCA8418_GPIO_DAT_STAT3_REG, aux);
        xQueueSendToBack(StdOutQueue, &(msg), portMAX_DELAY);
        vTaskDelay( pdMS_TO_TICKS ( 100 ) );
        //*/


        /*
		aux = KeypadRead (TCA8418_INT_STAT_REG);
		ESP_LOGD(tag, "REG INT_STAT %02d = %02d", TCA8418_INT_STAT_REG, aux);

		aux = KeypadRead (TCA8418_GPIO_DAT_STAT1_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT1 %02d = %02d", TCA8418_GPIO_DAT_STAT1_REG, aux);
		aux = KeypadRead (TCA8418_GPIO_DAT_STAT2_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT2 %02d = %02d", TCA8418_GPIO_DAT_STAT2_REG, aux);
		aux = KeypadRead (TCA8418_GPIO_DAT_STAT3_REG);
		ESP_LOGD(tag, "REG GPIO_DAT_STAT3 %02d = %02d", TCA8418_GPIO_DAT_STAT3_REG, aux);

        //*/

    }
}