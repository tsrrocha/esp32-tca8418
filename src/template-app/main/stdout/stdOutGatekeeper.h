#ifndef _STD_OUT_GATEKEEPER_H_
#define _STD_OUT_GATEKEEPER_H_

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define STDOUT_QUEUE_MAXSIZE    5

/**
 * @brief 
 * 
 * @param pvParameters 
 */
void prvStdOutGatekeeperTask (void *pvParameters);



#endif // _STD_OUT_GATEKEEPER_H_