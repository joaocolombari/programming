/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/util_macro.h>

const struct device *const dev = DEVICE_DT_GET(DT_NODELABEL(adxl345));

static const enum sensor_channel channels[] = {
	SENSOR_CHAN_ACCEL_X,
	SENSOR_CHAN_ACCEL_Y,
	SENSOR_CHAN_ACCEL_Z,
};

int main(void)
{	
	if (dev == NULL) {
		printk("\nError: no device found.\n");
		return NULL;
	}

	if (!device_is_ready(dev)) {
		printk("\nError: Device \"%s\" is not ready; ", dev->name);
		return NULL;
	}

	printk("Found device \"%s\", getting sensor data\n", dev->name);

	while (1) {
		int ret;
		struct sensor_value accel[3];
		
		ret = sensor_sample_fetch(dev);
		if (ret < 0) {
			printk("%s: sensor_sample_fetch() failed: %d\n", dev->name, ret);
			return ret;
		}
		
		for (size_t i = 0; i < ARRAY_SIZE(channels); i++) {
			ret = sensor_channel_get(dev, channels[i], &accel[i]);
			if (ret < 0) {
				printk("%s: sensor_channel_get(%c) failed: %d\n", dev->name, 'X' + i, ret);
				return ret;
			}
		}

		printk("%16s [m/s^2]:    (%d, %d, %d)\n", dev->name,
	       &accel[0], &accel[1], &accel[2]);

		k_sleep(K_MSEC(1000));
	}
	return 0;
}
