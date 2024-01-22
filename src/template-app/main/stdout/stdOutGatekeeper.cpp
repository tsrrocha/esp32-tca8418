#include "stdOutGatekeeper.h"

/**
 * @brief 
 * 
 */
QueueHandle_t StdOutQueue;

/**
 * @brief 
 * 
 * @param pvParameters 
 */
void prvStdOutGatekeeperTask (void *pvParameters)
{
	char * pcMessageToPrint;

	// Cria a fila de eventos 
	StdOutQueue = xQueueCreate(STDOUT_QUEUE_MAXSIZE, sizeof(char *));
	
	for (;;) {
        // Wait to receive a new event on the queue.
		xQueueReceive (StdOutQueue, &pcMessageToPrint, portMAX_DELAY);
        // Print message into StdOut
        printf("%s", pcMessageToPrint);
        //fflush( stdout );
	}
}