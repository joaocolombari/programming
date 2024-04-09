/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <stdlib.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/util_macro.h>


#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/logging/log.h>

#include "custom_adxl345_driver.h"

LOG_MODULE_REGISTER(Lesson7_Exercise1, LOG_LEVEL_INF);

#define SPIOP	SPI_WORD_SET(8) | SPI_TRANSFER_MSB
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec ledspec = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
const struct device *spi_dev = DEVICE_DT_GET(DT_NODELABEL(adxl345));

static const enum sensor_channel channels[] = {
	SENSOR_CHAN_ACCEL_X,
	SENSOR_CHAN_ACCEL_Y,
	SENSOR_CHAN_ACCEL_Z,
};

int main(void)
{
	int err;

	LOG_INF("Lesson 7 - Exercise 1 started");

	err = gpio_is_ready_dt(&ledspec);
	if (!err) {
		LOG_INF("Error: GPIO device is not ready, err: %d", err);
		return 0;
	}

	err = device_is_ready(spi_dev);
	if (!err) {
		LOG_INF("Error: SPI device is not ready, err: %d", err);
		return 0;
	}

	gpio_pin_configure_dt(&ledspec, GPIO_OUTPUT_ACTIVE);
	
	adxl345_init(spi_dev);

	while (1) {		
		int ret;
		struct sensor_value accel[3];
		
		ret = adxl345_sample_fetch(spi_dev);
		if (ret < 0) {
			printk("%s: sensor_sample_fetch() failed: %d\n", spi_dev->name, ret);
			return ret;
		}
		
		for (size_t i = 0; i < ARRAY_SIZE(channels); i++) {
			ret = adxl345_channel_get(spi_dev, channels[i], &accel[i]);
			if (ret < 0) {
				printk("%s: sensor_channel_get(%c) failed: %d\n", spi_dev->name, 'X' + i, ret);
				return ret;
			}
		}

		printk("%16s [m/s^2]:    (%d, %d, %d)\n", spi_dev->name,
	       &accel[0], &accel[1], &accel[2]);

		gpio_pin_toggle_dt(&ledspec);
		k_sleep(K_MSEC(1000));
	}

	return 0;
}