/*
 * The function do just as what its name means
 *
 * Chunis Deng @ 2009.11.02
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int reverse_bits(unsigned int value)
{
	unsigned int a = 1;
	unsigned int reval = 0;

	while(a != 0){
		// note: below two statements can't be exchanged
		reval <<= 1;
		if(value & 1)
			reval |= 1;

		value >>= 1;
		a <<= 1;
	}

	return reval;
}

int main(int argc, char *argv[])
{
	//printf("0x%08x\n", reverse_bits(0));	// should output 0x00000000
	printf("0x%x\n", reverse_bits(0));	// should output 0x00000000
	printf("0x%x\n", reverse_bits(1));	// should output 0x80000000
	printf("0x%x\n", reverse_bits(25));	// should output 0x98000000

	return 0;
}

