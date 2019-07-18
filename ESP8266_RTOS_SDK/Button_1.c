/* gpio example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
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

#define  SW 	GPIO_NUM_5
#define  LED 	GPIO_NUM_4

void app_main(void)
{
	int a, b=0;
	gpio_set_direction(LED, GPIO_MODE_OUTPUT);
	gpio_set_direction(SW, GPIO_MODE_INPUT);
	a = gpio_get_level(SW);

    while(1)
    {
    	gpio_set_level(LED,0);
    	vTaskDelay(200 / portTICK_PERIOD_MS);
    	gpio_set_level(LED,1);
    	vTaskDelay(200 / portTICK_PERIOD_MS);
    	if(a == 0)
    	{
    		b++;
    		printf("button %d",b);
    	}
    	else
    	{
    		b = 0;
    		printf("button %d",b);
    	}

    }

}


