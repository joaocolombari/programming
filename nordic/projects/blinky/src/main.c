/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>		// Inclui dois headers de maneira indireta, que deve ser evitado 
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
/* The line below uses the devicetree macro DT_ALIAS() to get the node identifier symbol LED0_NODE, 
which will represent LED1 (node led_0). Remember from the Devicetree section that led_0 node is 
defined in the devicetree of the DK. LED0_NODE is now the source code symbol that represents the 
hardware for LED1.

The DT_ALIAS() macro gets the node identifier from the node’s alias, which as we saw in the 
Devicetree section, is led0.
Aqui ele está pegando o ponteiro referenciado pelo alias led0

*/
#define LED0_NODE DT_ALIAS(led0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

void main(void)
{
	int ret;

	// if (!gpio_is_ready_dt(&led)) {
	// 	return 0;
	// }
	
	if (!device_is_ready(led.port)) {
    	return;
	}

	/* The generic GPIO API function gpio_pin_configure_dt() is used to configure the 
		GPIO pin associated with led as an output (active low) and initializes it to 
		a logic 1, as explained in the GPIO Generic API section */
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
















