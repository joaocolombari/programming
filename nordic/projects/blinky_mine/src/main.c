/*
    Blinky com LED_2. O programa acende o led vermelho por um segundo
    então o apaga e acende o verde por mais um segundo, while(1)

    Joao Victor Colombari Carlet - jvccarlet@usp.br
    09 de Novembro de 2023
*/

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include <hal/nrf_gpio.h>

// 1kms = 1s
#define SLEEP_TIME_MS   1000 
// Defining GPIO_PIN based on red pin location of red led in dev tree
#define GPIO_PIN_RED    NRF_GPIO_PIN_MAP(0,28)
#define GPIO_PIN_GREEN  NRF_GPIO_PIN_MAP(0,29)

int main(void)
{
    // Sets pins as outputs
    nrf_gpio_cfg_output(GPIO_PIN_RED);
    nrf_gpio_cfg_output(GPIO_PIN_GREEN);

    while (1) 
    {
	    nrf_gpio_pin_set(GPIO_PIN_RED);         // Turns RED LED on
        nrf_gpio_pin_clear(GPIO_PIN_GREEN);     // Turns GREEN LED off
        k_msleep(SLEEP_TIME_MS);                // Waits a second
        nrf_gpio_pin_set(GPIO_PIN_GREEN);       // Turns GREEN LED on
        nrf_gpio_pin_clear(GPIO_PIN_RED);       // Turns RED LED off
        k_msleep(SLEEP_TIME_MS);                // Waits again
    }
    return 0;
}