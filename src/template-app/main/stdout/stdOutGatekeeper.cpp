#include "stdOutGatekeeper.h"

/**
 * @brief 
 * 
 */
//QueueHandle_t StdOutQueue;

/**
 * @brief 
 * 
 * @param pvParameters 
 */
void prvStdOutGatekeeperTask (void * pvQueue)
{
	// 
	char * pcMessageToPrint;
	// Coleta a Fila passa por parâmetro
	QueueHandle_t * queue = (QueueHandle_t *) pvQueue ;

	for (;;) {
        // Wait to receive a new event on the queue.
		xQueueReceive (*queue, &pcMessageToPrint, portMAX_DELAY);
		printf("STD: %s\r\n", pcMessageToPrint);
		//sprintf(&msg[0], "INFO: %s\r\n", pcMessageToPrint);
        // Print message into StdOut
        //printf("%s", &msg[0]);
        fflush( stdout );
	}
}