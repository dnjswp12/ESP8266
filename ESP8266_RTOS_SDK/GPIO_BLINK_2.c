/* gpio example
test NodeMcu V3 Board
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "esp_log.h"
#include "esp_system.h"


/**
 * Brief:
 * GPIO 0 - D3
 * GPIO 1 - D10 (TXD0) X >> no works led
 * GPIO 2 - D4 (TX1D) -- with blue led
 * GPIO 3 - D9 (RXD0) X
 * GPIO 4 - D2
 * GPIO 5 - D1
 * GPIO 9 - SD2 X
 * GPIO10 - SD3 X
 * GPIO12 - D6  X
 * GPIO13 - D7  X
 * GPIO14 - D5  X
 * GPIO15 - D8 (TX2)
 * GPIO16 - D0 (wake)O
 */




void app_main(void)
{
	gpio_set_direction(GPIO_NUM_5,GPIO_MODE_OUTPUT);
	printf("GPIO test!");
	
	while(1)
	{
		
		gpio_set_level(GPIO_NUM_5,0);
		vTaskDelay(100 / portTICK_RATE_MS);
		gpio_set_level(GPIO_NUM_5,1);
		vTaskDelay(100 / portTICK_RATE_MS);
	
	}


}


