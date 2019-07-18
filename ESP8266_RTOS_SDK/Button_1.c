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

void app_main(void)
{
	int a;
	gpio_set_direction(GPIO_NUM_5,GPIO_MODE_INPUT);
	gpio_set_direction(GPIO_NUM_4,GPIO_MODE_OUTPUT);
	printf("GPIO test!");


	while(1)
	{
		a = gpio_get_level(GPIO_NUM_5);
		if(a == 0)
		{
			gpio_set_level(GPIO_NUM_4,1);
			printf("%d",a);
		}
		else
		{
			gpio_set_level(GPIO_NUM_4,0);
			printf("%d",a);
		}



	}


}

