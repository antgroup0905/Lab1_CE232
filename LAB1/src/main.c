#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 2

void app_main(void)
{
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while(1) {
        gpio_set_level(BLINK_GPIO, 0);
        printf("LED OFF\n"); // Print status to terminal
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
        gpio_set_level(BLINK_GPIO, 1);
        printf("LED ON\n"); // Print status to terminal
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
    }
}