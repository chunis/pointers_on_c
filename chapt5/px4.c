/*
 * Implement a set of functions for bit-array.
 *
 * Chunis Deng @ 2009.11.04
 */

#include <stdio.h>
#include <stdlib.h>

void set_bit(char bit_array[], unsigned bit_number)
{
	unsigned int ch_offset;
	unsigned int left;

	ch_offset = (bit_number >> 3);
	left = (bit_number & 0x07);
	bit_array[ch_offset] |= (0x1 << left);

	//printf("ch_offset: %d, left: %d\n", ch_offset, left);
}

void clear_bit(char bit_array[], unsigned bit_number)
{
	unsigned int ch_offset;
	unsigned int left;

	ch_offset = (bit_number >> 3);
	left = (bit_number & 0x07);
	bit_array[ch_offset] &= ~(0x1 << left);

	//printf("ch_offset: %d, left: %d\n", ch_offset, left);
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
	if(value)
		set_bit(bit_array, bit_number);
	else
		clear_bit(bit_array, bit_number);
}

int test_bit(char bit_array[], unsigned bit_number)
{
	unsigned int ch_offset;
	unsigned int left;

	ch_offset = (bit_number >> 3);
	left = (bit_number & 0x07);

	//return (bit_array[ch_offset] >> left) & 0x1;
	return (bit_array[ch_offset] & (0x1 << left) ? 1 : 0);
}

int main(int argc, char *argv[])
{
	int i;
	int offset[6] = { 0, 1, 10, 14, 16, 19 };
	int test_offset[6] = { 4, 10, 14, 15, 18, 19 };
	char num[10] = { 0b00000000 };
	char new[10] = { 0b11111111, 0b11111111, 0b01111111 };

	// test set_bit
	printf(" Now test set_bit()...\n");
	for(i=0; i<6; i++){
		printf("in num: offset: %d, value: %d\n", 
				test_offset[i], test_bit(num, test_offset[i]));
	}
	for(i=0; i<6; i++)
		set_bit(num, offset[i]);

	printf("\n After set_bit:\n");
	for(i=0; i<6; i++){
		printf("in num: offset: %d, value: %d\n", 
				test_offset[i], test_bit(num, test_offset[i]));
	}

	// test clear_bit
	printf("\n Now test clear_bit()...\n");
	for(i=5; i<18; i++)
		clear_bit(new, i);
	printf("new[0]=0x%x, new[1]=0x%x, new[2]=0x%x\n",
			new[0], new[1], new[2]);


	// test assign_bit
	printf("\n Now test assign_bit()...\n");
	printf("in num: offset:0, value: %d\n", test_bit(num, 0));
	printf("in new: offset:23, value: %d\n", test_bit(new, 23));
	assign_bit(num, 0, 0);
	assign_bit(new, 23, 1);
	printf("in num: offset:0, value: %d\n", test_bit(num, 0));
	printf("in new: offset:23, value: %d\n", test_bit(new, 23));


	return 0;
}
