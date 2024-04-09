#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>

#define MY_SPI_SLAVE  DT_NODELABEL(my_spi_slave)

void spi_slave(const struct device *dev)
{
	struct spi_config config;

	config.frequency = 8000000;
	config.operation = SPI_WORD_SET(8) | SPI_TRANSFER_MSB |
				 SPI_MODE_CPOL | SPI_MODE_CPHA | SPI_OP_MODE_SLAVE,
	config.slave = 0;	

	enum { datacount = 5 };
	uint8_t buff[datacount] = { 0x05, 0x04, 0x03, 0x02, 0x01};
	uint8_t rxdata[datacount];

	struct spi_buf tx_buf[1] = { {.buf = buff, .len = sizeof(buff)}};
	struct spi_buf rx_buf[1] = { {.buf = rxdata, .len = sizeof(rxdata)}};

	struct spi_buf_set tx_set = { .buffers = tx_buf, .count = 1 };
	struct spi_buf_set rx_set = { .buffers = rx_buf, .count = 1 };

	int ret = spi_transceive(dev, &config, &tx_set, &rx_set);

	printf("Slave ret: %d\n", ret);
	printf(" tx (i)  : %02x %02x %02x %02x %02x\n",
	       buff[0], buff[1], buff[2], buff[3], buff[4]);
	printf(" rx (i)  : %02x %02x %02x %02x %02x\n",
	       rxdata[0], rxdata[1], rxdata[2], rxdata[3], rxdata[4]);
}

int main(void)
{
	const struct device *dev = DEVICE_DT_GET(MY_SPI_SLAVE);

	if (!device_is_ready(dev)) {
		printk("%s: device not ready.\n", dev->name);
		return 0;
	}

	while (1) {
		spi_slave(dev);
		k_sleep(K_MSEC(2000));
	}
	return 0;
}