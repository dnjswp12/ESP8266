
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "esp_log.h"
#include "esp_system.h"



#define PIN_OUT           *(volatile uint32_t *)0x60000300
#define PIN_OUT_SET       *(volatile uint32_t *)0x60000304
#define PIN_OUT_CLEAR     *(volatile uint32_t *)0x60000308

#define PIN_DIR           *(volatile uint32_t *)0x6000030C
#define PIN_DIR_OUTPUT    *(volatile uint32_t *)0x60000310
#define PIN_DIR_INPUT     *(volatile uint32_t *)0x60000314

#define PIN_IN            *(volatile uint32_t *)0x60000318

#define PIN_13            *(volatile uint32_t *)0x6000035C

#define LED_GPIO13        13
#define LED_GPIO_MUX13    PERIPHS_IO_MUX_MTCK_U
#define LED_GPIO_FUNC13   FUNC_GPIO13

void app_main(void)
{
	PIN_FUNC_SELECT(LED_GPIO_MUX13, LED_GPIO_FUNC13);
	    PIN_13 &= ( 0xF << 7 );
	    PIN_DIR_OUTPUT = ( 1 << LED_GPIO13 );
    while(1)
    {

    	PIN_OUT_SET = ( 1 << LED_GPIO13 );
    	os_delay_us(100000);
    	PIN_OUT_CLEAR = ( 1 << LED_GPIO13 );
        //os_delay_us(1000000);
        vTaskDelay(1000 / portTICK_RATE_MS);


    }

}
