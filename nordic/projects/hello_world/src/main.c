#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#ifdef CONFIG_MYFUNCTION
#include "myfunction.h"
#endif

// 1kms = 1s
#define SLEEP_TIME_MS 1000 

int main(void)
{
	int a = 3, b = 4;
	
	while (1) 
	{
		#ifdef CONFIG_MYFUNCTION
		int a = 3, b = 4;
			printk("The sum of %d and %d is %d\n Hello World!!\n\n", a, b, sum(a,b));
		#else
			printk("MYFUNCTION not enabled\r\n");
			return;
		#endif
		k_msleep(1000);
	}
	return 0;
}