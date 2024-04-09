#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/drivers/spi.h>

/* Aqui eu definiria os registradores de algum sensor comercial */
#define REGISTER_ADD	0x10
struct {
	u_int8_t chip_id; 	
} chip;


/* Aqui estou definindo o no da device tree e pegando o objeto relacionado a ele */
#define SPI4_NODE 		DT_NODELABEL(spi4)							
static const struct device *spi4_dev = DEVICE_DT_GET(SPI4_NODE);

/* Aqui vou definir o chip select com as mesmas funcoes */
#define MY_GPIO0	DT_NODELABEL(gpio0)
#define GPIO_0_CS 	1
const struct device *cs_config = DEVICE_DT_GET(MY_GPIO0);

/* Aqui vou configurar o SPI com spi_config */
static struct spi_config spi_cfg = {
	.frequency = 125000U,
	.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8),
	.slave = 1,
};

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* Funcao para leitura do registrador no qual vou salvar o valor do botao no slave */
static void read_register(uint8_t reg, uint8_t values[], uint8_t size){
	int err;

	// carregando o meu buffer com o valor do register 
	u_int8_t tx_buffer[1];
	tx_buffer[0]=reg;

	struct spi_buf tx_spi_bufs[] = {
		{.buf = tx_buffer, .len = sizeof(tx_buffer)},
	};

	struct spi_buf_set spi_tx_buffer_set  = {
		.buffers = tx_spi_bufs, 
		.count = 1
	};

	struct spi_buf rx_spi_bufs[] = {
		{.buf = values, .len = size}
	};
	
	struct spi_buf_set spi_rx_buffer_set = {
		.buffers = rx_spi_bufs, 
		.count = 1
	};
	
	gpio_pin_set(cs_config, GPIO_0_CS, 0);

	do {
		err = spi_write(spi4_dev, &spi_cfg, &spi_tx_buffer_set);

		if(err < 0) {break;}

		err = spi_read(spi4_dev,&spi_cfg,&spi_rx_buffer_set);

	} while (false);

	gpio_pin_set(cs_config, GPIO_0_CS, 1);
	
	if(err < 0) {
		printk("Read Registers failed: %d \n", err);
	};
};

static void read_spi(void)
{
	u_int8_t rx_buf_chip_id[1];
	read_register(REGISTER_ADD, rx_buf_chip_id, 1);

	chip.chip_id=rx_buf_chip_id[0];
	printk("Chip ID is: 0x%02X\n", chip.chip_id);
}

int main(void)
{

	gpio_pin_configure(cs_config, GPIO_0_CS, GPIO_OUTPUT);
	gpio_pin_set(cs_config, GPIO_0_CS, 1);

	if(!device_is_ready(spi4_dev)) {
		printk("spi4_dev not ready \n");
		return;
	}

	read_spi();

	int ret;

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

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
