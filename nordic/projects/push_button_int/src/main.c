/*
	Controling LED through a Button via Interrupt
	Joao Victor Colombari Carlet
	Nov, 13th, 2023
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

// Defines
#define SLEEP_TIME_MS   10*60*1000
#define SW0_NODE	DT_ALIAS(sw0)
#define LED2_NODE	DT_ALIAS(led2)

// Structs
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static struct gpio_callback button_cb_data;


// Functions 
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{

    gpio_pin_toggle_dt(&led);
	k_msleep(50); 
	gpio_pin_toggle_dt(&led);

}

void main(void)
{
    int ret;

	// Checking if device is ready to use
	// Checks ports
		if (!device_is_ready(led.port)) {
			return;
		}
		if (!device_is_ready(button.port)) {
			return;
		}
		
	// Checks pins 
		ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
		if (ret < 0) {
			return;
		}
		ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
		if (ret < 0) {
			return;
		}


        // Interrupt Config
	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
        // Interrupt callback variable initialize 
	gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin)); 
        // Adding callback function 	
	gpio_add_callback(button.port, &button_cb_data);

	while (1) {                     // Main Loop
        k_msleep(SLEEP_TIME_MS); 
	}
}