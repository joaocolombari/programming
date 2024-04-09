/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>

LOG_MODULE_REGISTER(Acc_sensor, LOG_LEVEL_INF);

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

#define DELAY_REG 		10
#define DELAY_PARAM		50
#define DELAY_VALUES	1000

// AD ACC registers
#define DEVID 			0x00			// Device ID
//#define RESERVED 		0x01 to 0x1C	// Reserved
#define THRESH_TAP 		0x1D 			// Tap threshold
#define OFSX  			0x1E 			// X-axis offset
#define OFSY  			0x1F			// Y-axis offset
#define OFSZ 			0x20 			// Z-axis offset
#define DUR 			0x21			// Tap duration
#define Latent 			0x22			// Tap latency
#define Window 			0x23			// Tap window
#define THRESH_ACT 		0x24			// Activity threshold
#define THRESH_INACT 	0x25			// Inactivity threshold
#define TIME_INACT 		0x26			// Inactivity time
#define ACT_INACT_CTL 	0x27			// Axis enable control for activity and inactivity detection
#define THRESH_FF 		0x28			// Free-fall threshold
#define TIME_FF			0x29			// Free-fall time
#define TAP_AXES		0x2A			// Axis control for single tap/double tap
#define ACT_TAP_STATUS  0x2B			// Source of single tap/double tap
#define BW_RATE 		0x2C			// Data rate and power mode control
#define POWER_CTL		0x2D			// Power-saving features control
#define INT_ENABLE		0x2E			// Interrupt enable control
#define INT_MAP 		0x2F			// Interrupt mapping control
#define INT_SOURCE		0x30			// Source of interrupts
#define DATA_FORMAT		0x31			// Data format control
#define DATAX0 			0x32			// X-Axis Data 0
#define DATAX1			0x33			// X-Axis Data 1
#define DATAY0 			0x34			// Y-Axis Data 0
#define DATAY1 			0x35			// Y-Axis Data 1
#define DATAZ0 			0x36			// Z-Axis Data 0
#define DATAZ1 			0x37			// Z-Axis Data 1
#define FIFO_CTL		0x38			// FIFO control
#define FIFO_STATUS 	0x39			// FIFO status

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

#define SPIOP	SPI_WORD_SET(8) | SPI_TRANSFER_MSB
struct spi_dt_spec spispec = SPI_DT_SPEC_GET(DT_NODELABEL(adxl345), SPIOP, 3);

/* Data structure to store BME280 data */
struct adxl345_data {
	/* Compensation parameters */
	uint8_t devid;
	uint8_t tap_threshold;
	uint8_t	x_axis_offset;
	uint8_t y_axis_offset;
	uint8_t z_axis_offset;
	uint8_t tap_duration;
	uint8_t	tap_latecy;
	uint8_t	tap_window;
	uint8_t	activity_threshold;
	uint8_t inactivity_threshold;
	uint8_t inactivity_time;
	uint8_t	axis_enable_control_for_act_or_inact_detection;
	uint8_t free_fall_threshold;
	uint8_t	free_fall_time;
	uint8_t	axis_control_for_single_tap_double_tap;
	uint8_t	source_of_single_tap_double_tap;
	uint8_t data_rate_and_power_mode_control;
	uint8_t	power_saving_features_control;
	uint8_t	interrupt_enable_control;
	uint8_t	interrupt_mapping_control;
	uint8_t source_of_interrupts;
	uint8_t data_format_control;
	uint8_t x_axis_data_0;
	uint8_t x_axis_data_1;
	uint8_t y_axis_data_0;
	uint8_t y_axis_data_1;
	uint8_t z_axis_data_0;
	uint8_t z_axis_data_1;
	uint8_t fifo_control;
	uint8_t fifo_status;
} adxl345_structure;

static int ad_read_reg(uint8_t reg, uint8_t *data, uint8_t size)
{
	int err;

	uint8_t tx_buffer = reg;
	struct spi_buf tx_spi_buf		= {.buf = (void *)&tx_buffer, .len = 1};
	struct spi_buf_set tx_spi_buf_set 	= {.buffers = &tx_spi_buf, .count = 1};
	struct spi_buf rx_spi_bufs 		= {.buf = data, .len = size};
	struct spi_buf_set rx_spi_buf_set	= {.buffers = &rx_spi_bufs, .count = 1};

	err = spi_transceive_dt(&spispec, &tx_spi_buf_set, &rx_spi_buf_set);
	if (err < 0) {
		LOG_ERR("spi_transceive_dt() failed, err: %d", err);
		return err;
	}

	return 0;
}

void ad_calibrationdata(void)
{
	uint8_t values[2];
	uint8_t size = 2;	
	
	uint8_t regaddr;
	LOG_INF("-------------------------------------------------------------");
	LOG_INF("adxl345: Reading from device ID register:");

	regaddr = DEVID;
	ad_read_reg(regaddr, values, size);
	adxl345_structure.devid = (uint8_t)values[1];
	LOG_INF("\tReg[0x%02x] %d Bytes read: DEV ID = %d", regaddr, size-1, adxl345_structure.devid);
	k_msleep(DELAY_PARAM);

	LOG_INF("-------------------------------------------------------------");

}

int main(void)
{
	int err;

	err = gpio_is_ready_dt(&led);
	if (!gpio_is_ready_dt(&led)) {
		LOG_ERR("Error: GPIO device is not ready, err: %d", err);
		return 0;
	}

	err = spi_is_ready_dt(&spispec);
	if (!err) {
		LOG_ERR("Error: SPI device is not ready, err: %d", err);
		return 0;
	}

	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	ad_calibrationdata();

	while (1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}

