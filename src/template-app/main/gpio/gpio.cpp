/**
 * @file gpio.cpp
 * @author Tiago Sousa Rocha (tsrrocha@gmail.com)
 * @brief 
 * @version 1.0
 * @date 24/01/2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gpio.h"
#include "driver/gpio.h"
#include "esp_log.h"

extern QueueHandle_t I2CEventQueue;
extern I2CEvent *evKeypad;

static InterruptHandle_t intHandle;

/**
 * @brief 
 * 
 * @return esp_err_t 
 */
esp_err_t GPIOConfig(void)
{
    /*  Zero-initialize the config structure. */
    gpio_config_t gpiocfg = {};
    // 
    gpio_install_isr_service(0);
    /*  Set gpios as input. */
    gpiocfg.mode = GPIO_MODE_INPUT;
    
    gpiocfg.pin_bit_mask = ((1ULL << CONFIG_GPIO_INT_KEYPAD));      // 
    gpiocfg.pull_down_en = GPIO_PULLDOWN_DISABLE;                   // Disable Pull-down
    gpiocfg.pull_up_en = GPIO_PULLUP_ENABLE;                        // Enable Pull-up
    gpiocfg.intr_type = GPIO_INTR_ANYEDGE;                        // Active on Negative Edge
    // 
    gpio_isr_handler_add(CONFIG_GPIO_INT_KEYPAD, gpio_interrupt_keypad_handler, (void *)CONFIG_GPIO_INT_KEYPAD);
    
    /*  Configure GPIOs with given settings. */
    gpio_config( &gpiocfg );

    intHandle.state.KeypadIntActive = 0;

    return ESP_OK;
}

/**
 * @brief 
 * 
 * @param pvQueue 
 */
void vGpioOutputControllerTask ( void * pvQueue )
{

}

/**
 * @brief 
 * 
 * @param args 
 */
void IRAM_ATTR gpio_interrupt_keypad_handler(void *args)
{
    uint32_t pinNumber = (uint32_t) args;

    intHandle.state.KeypadIntActive = !(gpio_get_level(CONFIG_GPIO_INT_KEYPAD));
    if (intHandle.state.KeypadIntActive == 1) {
        evKeypad->type = I2CEventType::I2CEV_KEYPAD_READKEY;
        if (xQueueSendFromISR(I2CEventQueue, &evKeypad, NULL))
        {
        }
    } else {
        intHandle.state.KeypadIntActive = 0;
        /*d//evKeypad->type = I2CEventType::I2CEV_KEYPAD_CLEAR_INT;
        evKeypad->type = I2CEventType::I2CEV_KEYPAD_READKEY;
        if (xQueueSendFromISR(I2CEventQueue, &evKeypad, NULL))
        {
            //ESP_LOGI(TAG_GPIO, "I2CEvent Keypad sent to queue .... ");
        }//*/
    }
}