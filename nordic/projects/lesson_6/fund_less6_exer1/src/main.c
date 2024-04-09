#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
/* STEP 3 - Include the header file of the I2C API */
#include <zephyr/drivers/i2c.h>
/* STEP 4.1 - Include the header file of printk() */
#include <zephyr/sys/printk.h>
/* 1000 msec = 1 sec */


#define SLEEP_TIME_MS   	1000
/* STEP 8 - Define the I2C slave device address and the addresses of relevant registers */
#define INA240_CONFIG_REG   0x00
#define INA240_SHUNT_REG	0x01
/* STEP 6 - Get the node identifier of the sensor */
#define I2C0_NODE DT_NODELABEL(vbat_sensor)

void main(void)
{
	int ret;

	/* STEP 7 - Retrieve the API-specific device structure and make sure that the device is ready to use  */
	static const struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C0_NODE);
	if (!device_is_ready(dev_i2c.bus)) {
		printk("I2C bus %s is not ready!\n\r",dev_i2c.bus->name);
		return;
	}

	/* STEP 9 - Setup the sensor by writing the value 0x8C to the Configuration register */
	char config[] = {INA240_CONFIG_REG,0x4127};
	ret = i2c_write_dt(&dev_i2c, config, sizeof(config));
	if(ret != 0){
		printk("Failed to write to I2C device address %x at Reg. %x \n", dev_i2c.addr,config[0]);
		return;
	}
	printk("Ret is %x\n", ret);
	while (1) {
		/* STEP 10 - Read the temperature from the sensor */
		uint8_t sensor_reading = 0;
		uint8_t sensor_regs = {INA240_SHUNT_REG};
		ret = i2c_write_read_dt(&dev_i2c,&sensor_regs,2,&sensor_reading,2);
		if(ret != 0){
			printk("Failed to write/read I2C device address %x at Reg. %x \r\n", dev_i2c.addr,sensor_regs);
		}

		/* STEP 11 - Convert the two bytes to a 12-bits */
		printk("Reading is %x\n", sensor_reading);

		k_msleep(SLEEP_TIME_MS);
	}
}