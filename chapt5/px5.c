/*
 * set bit fields (start~end) of a int with another value's certain bits
 *
 * Chunis Deng @ 2009,11,04
 */

#include <stdio.h>
#include <stdlib.h>

int store_bit_field(int original_value,
	int value_to_store,
	unsigned starting_bit, unsigned ending_bit)
{
	unsigned mask;

	mask = ~0;
	mask <<= (starting_bit - ending_bit + 1);
	mask = ~mask;
	mask <<= ending_bit;

	original_value &= ~mask;
	value_to_store <<= ending_bit;
	value_to_store &= mask;

	return 	(value_to_store | original_value);
}

int main(int argc, char *argv[])
{
	unsigned ret;

	ret = store_bit_field(0x0, 0x1, 4, 4);
	printf("ret: 0x%x\n", ret);	// should be 0x10

	ret = store_bit_field(0xffff, 0x123, 15, 4);
	printf("ret: 0x%x\n", ret);	// should be 0x123f

	ret = store_bit_field(0xffff, 0x123, 13, 9);
	printf("ret: 0x%x\n", ret);	// should be 0xc7ff

	return 0;
}

