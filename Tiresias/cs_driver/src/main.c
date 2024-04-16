#include <zephyr/kernel.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/shell/shell.h>
#include <zephyr/zbus/zbus.h>

#include "cs47l63.h"
#include "cs47l63_spec.h"
#include "cs47l63_reg_conf.h"
#include "cs47l63_comm.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(Main_app, LOG_LEVEL_INF);

#define VOLUME_ADJUST_STEP_DB 3
#define BASE_10		      10

// ZBUS_SUBSCRIBER_DEFINE(volume_evt_sub, CONFIG_VOLUME_MSG_SUB_QUEUE_SIZE);

static uint32_t prev_volume_reg_val = OUT_VOLUME_DEFAULT;

static cs47l63_t cs47l63_driver;

static k_tid_t volume_msg_sub_thread_id;
static struct k_thread volume_msg_sub_thread_data;

/**
 * @brief Write to multiple registers in CS47L63.
 */
static int cs47l63_comm_reg_conf_write(const uint32_t config[][2], uint32_t num_of_regs)
{
	int ret;
	uint32_t reg;
	uint32_t value;

	for (int i = 0; i < num_of_regs; i++) {
		reg = config[i][0];
		value = config[i][1];

		if (reg == SPI_BUSY_WAIT) {
			LOG_DBG("Busy waiting instead of writing to CS47L63");
			/* Wait for us defined in value */
			k_busy_wait(value);
		} else {
			ret = cs47l63_write_reg(&cs47l63_driver, reg, value);
			if (ret) {
				return ret;
			}
		}
	}

	return 0;
}

int hw_codec_volume_set(uint8_t set_val)
{
	int ret;
	uint32_t volume_reg_val;

	volume_reg_val = set_val;
	if (volume_reg_val == 0) {
		LOG_WRN("Volume at MIN (-64dB)");
	} else if (volume_reg_val >= MAX_VOLUME_REG_VAL) {
		LOG_WRN("Volume at MAX (0dB)");
		volume_reg_val = MAX_VOLUME_REG_VAL;
	}

	ret = cs47l63_write_reg(&cs47l63_driver, CS47L63_OUT1L_VOLUME_1,
				volume_reg_val | CS47L63_OUT_VU);
	if (ret) {
		return ret;
	}

	prev_volume_reg_val = volume_reg_val;

	/* This is rounded down to nearest integer */
	LOG_DBG("Volume: %" PRId32 " dB", (volume_reg_val / 2) - MAX_VOLUME_DB);

	return 0;
}

int hw_codec_volume_adjust(int8_t adjustment_db)
{
	int ret;
	int32_t new_volume_reg_val;

	LOG_DBG("Adj dB in: %d", adjustment_db);

	if (adjustment_db == 0) {
		new_volume_reg_val = prev_volume_reg_val;
	} else {
		uint32_t volume_reg_val;

		ret = cs47l63_read_reg(&cs47l63_driver, CS47L63_OUT1L_VOLUME_1, &volume_reg_val);
		if (ret) {
			LOG_ERR("Failed to get volume from CS47L63");
			return ret;
		}

		volume_reg_val &= CS47L63_OUT1L_VOL_MASK;

		/* The adjustment is in dB, 1 bit equals 0.5 dB,
		 * so multiply by 2 to get increments of 1 dB
		 */
		new_volume_reg_val = volume_reg_val + (adjustment_db * 2);
		if (new_volume_reg_val <= 0) {
			LOG_WRN("Volume at MIN (-64dB)");
			new_volume_reg_val = 0;
		} else if (new_volume_reg_val >= MAX_VOLUME_REG_VAL) {
			LOG_WRN("Volume at MAX (0dB)");
			new_volume_reg_val = MAX_VOLUME_REG_VAL;
		}
	}

	ret = hw_codec_volume_set(new_volume_reg_val);
	if (ret) {
		return ret;
	}

	return 0;
}

int hw_codec_default_conf_enable(void)
{
	int ret;

	ret = cs47l63_comm_reg_conf_write(clock_configuration, ARRAY_SIZE(clock_configuration));
	if (ret) {
		return ret;
	}

	ret = cs47l63_comm_reg_conf_write(GPIO_configuration, ARRAY_SIZE(GPIO_configuration));
	if (ret) {
		return ret;
	}

	ret = cs47l63_comm_reg_conf_write(asp1_enable, ARRAY_SIZE(asp1_enable));
	if (ret) {
		return ret;
	}

	ret = cs47l63_comm_reg_conf_write(output_enable, ARRAY_SIZE(output_enable));
	if (ret) {
		return ret;
	}

	ret = hw_codec_volume_adjust(0);
	if (ret) {
		return ret;
	}

	ret = cs47l63_comm_reg_conf_write(pdm_mic_enable_configure, ARRAY_SIZE(pdm_mic_enable_configure));
	if (ret) {
		return ret;
	}

	/* Line in Enable */ 
	// ret = cs47l63_comm_reg_conf_write(line_in_enable, ARRAY_SIZE(line_in_enable));
	// if (ret) {
	// 	return ret;
	// }

	/* Toggle FLL to start up CS47L63 */
	ret = cs47l63_comm_reg_conf_write(FLL_toggle, ARRAY_SIZE(FLL_toggle));
	if (ret) {
		return ret;
	}

	return 0;
}

int main(void)
{
	int ret;

	LOG_INF("CS47L63 Driver programm");

	ret = cs47l63_comm_init(&cs47l63_driver);
	if (ret) {
		printf("%d\n", ret);
		return ret;
	}

	LOG_INF("CS47L63 initialized");

	/* Run a soft reset on start to make sure all registers are default values */
	ret = cs47l63_comm_reg_conf_write(soft_reset, ARRAY_SIZE(soft_reset));
	if (ret) {
		return ret;
	}
	cs47l63_driver.state = CS47L63_STATE_STANDBY;

	hw_codec_default_conf_enable();
	LOG_INF("HW codec defaut configuration done!");

	return 0;
}