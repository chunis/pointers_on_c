/*
 * Demostrate how to use '#define' to run conditional expression
 *
 * You can give a defined value when compile it, like below command:
 * gcc -Wall -DU3B2 px2.c -o px2 && ./px2
 *
 * Chunis Deng @ 2009.11.27
 */
 
#include <stdio.h>
#include <stdlib.h>

#include "cpu_type.h"

//#define I80386
#define X6809

int cpu_type(void)
{
#if defined(VAX)
	return CPU_VAX;
#elif defined(M68000)
	return CPU_68000;
#elif defined(M68020)
	return CPU_68020;
#elif defined(I80386)
	return CPU_80386;
#elif defined(X6809)
	return CPU_6809;
#elif defined(X6502)
	return CPU_6502;
#elif defined(U3B2)
	return CPU_3B2;
#else
	return CPU_UNKNOWN;
#endif
}

int main(int argc, char *argv[])
{
	int type;

	type = cpu_type();
	printf("You cpu type number is: %d\n", type);

	return 0;
}

