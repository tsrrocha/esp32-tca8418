#include "stdOutGatekeeper.h"

/**
 * @brief 
 * 
 */
//QueueHandle_t StdOutQueue;

/**
 * @brief 
 * 
 * @param pvQueue 
 */
void prvStdOutGatekeeperTask (void * pvQueue)
{
	// 
	char *pcMessageToPrint;
	// Coleta a Fila passa por parâmetro
	QueueHandle_t * queue = (QueueHandle_t *) pvQueue ;

	for (;;) {
        // Wait to receive a new event on the queue.
		xQueueReceive (*queue, &pcMessageToPrint, portMAX_DELAY);
		printf("STD: %s\r\n", pcMessageToPrint);
        fflush( stdout );
	}
}