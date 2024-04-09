/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier */
#define LED0_NODE DT_ALIAS(led0)

LOG_MODULE_REGISTER(acc);

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

static void fetch_and_display(const struct device *sensor)
{
	static unsigned int count;
	struct sensor_value accel[3];
	const char *overrun = "";
	int rc = sensor_sample_fetch(sensor);

	++count;
	
	if (rc == 0) {
		rc = sensor_channel_get(sensor,
					SENSOR_CHAN_ACCEL_XYZ,
					accel);
	}
	if (rc < 0) {
		printf("ERROR: Update failed: %d\n", rc);
	} 
	
	/* Aqui pode dar o problema do *float*. Para o que esta a seguir funcionar 
		tem que colocar o que esta la no proj.conf. Se nao usar aquilo, tem 
		que descomentar o que eu vou colocar a seguir
	*/
	
	// else 
	// {
	// 	printf("#%u @ %u ms: %sx %i.%i , y %i.%i , z %i.%i",
	// 	       count, k_uptime_get_32(), overrun,
	// 	       abs(&accel[0].val1), abs(&accel[0].val2), 
	// 	       abs(&accel[1].val1), abs(&accel[1].val2), 
	// 		   abs(&accel[2].val1), abs(&accel[2].val2) );
	// }

	else 
	{
		printf("#%u @ %u ms: %sx %f , y %f , z %f",
		       count, k_uptime_get_32(), overrun,
		       sensor_value_to_double(&accel[0]),
		       sensor_value_to_double(&accel[1]),
		       sensor_value_to_double(&accel[2]));
	}
}


void main(void)
{
	static const struct device *acc= DEVICE_DT_GET(DT_NODELABEL(adxl345));

	if (acc == NULL) {
		LOG_ERR("Accelerometer device pointer is NULL");
		return;
	}

	if (!device_is_ready(acc)) {
		LOG_ERR("Accelerometer device is not ready");
		return;
	}

	if (!gpio_is_ready_dt(&led)) {
		return;
	}

	if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) != 0) {
		LOG_ERR("Unnable to configure LED");
		return;
	}

	while (true) {

		LOG_INF("Polling at 0.5 Hz");
		fetch_and_display(acc);

		if (gpio_pin_toggle_dt(&led) != 0) {
			LOG_ERR("Unnable to toggle LED");
			return;
		}

		k_msleep(SLEEP_TIME_MS);
	}
}