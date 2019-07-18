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

#define LED    4
#define SW    5
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<LED)
#define GPIO_INPUT_PIN_SEL   (1ULL<<SW)


static const char *TAG = "main";

void app_main(void)
{
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);

    /*SW*/
    io_conf.intr_type = GPIO_INTR_DISABLE;
       //set as output mode
       io_conf.mode = GPIO_MODE_INPUT;
       //bit mask of the pins that you want to set,e.g.GPIO15/16
       io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
       //disable pull-down mode
       io_conf.pull_down_en = 1;
       //disable pull-up mode
       io_conf.pull_up_en = 0;
       //configure GPIO with the given settings
       gpio_config(&io_conf);


    int cnt = 0;
    int a;

    while (1) {
    	a = gpio_get_level(SW);

    	if (a == 1)
    	{
    		ESP_LOGI(TAG, "cnt: %d\n", cnt++);
    		vTaskDelay(1000 / portTICK_RATE_MS);
    		printf("%d",a);
    	}
    	else
    	{
    		printf("%d",a);
        gpio_set_level(LED, 1);
        gpio_set_level(LED, 0);
    	}
    }
}
