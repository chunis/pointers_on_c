/*
 * Demonstrate the importance to using 'unsigned int' or 'signed int' instead of
 * 'int' when define bit-field structure.
 *
 * Chunis Deng @ 2009.11.27
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct {
		int a:2;
	} x;

	x.a = 1;
	x.a += 1;

	// you'll get -2.
	// change 'int' to 'unsigned int' to make it work as what you thought
	printf("%d\n", x.a);

	return 0;
}

