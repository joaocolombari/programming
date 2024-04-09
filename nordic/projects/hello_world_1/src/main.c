/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

int main(void)
{
	printf("Hello World! f%s\n", CONFIG_BOARD);
	//printk("Hello World! k%s\n", CONFIG_BOARD);
	return 0;
}
