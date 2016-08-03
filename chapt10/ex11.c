/*
 * Demonstrate bit-field and shift operation using 16-bit variables.
 * Note: my machine puts bit-field from right to left, not as Exercise 10.11 said.
 *
 * Chunis Deng @ 2009.11.27
 */
 
#include <stdio.h>
#include <stdlib.h>

struct _x {
	int a:4;
	int b:8;
	int c:3;
	int d:1;
} x;

int main(int argc, char *argv[])
{
	short s = 0;
	int a = 9, b = 0xf8, c = 5, d = 1;
	short *p;

	x.a = a;
	x.b = b;
	x.c = c;
	x.d = d;

	/*
	// solution for left-right position bit-field
	s |= (a & 0xf) << (1+3+8);
	s |= (b & 0xff) << (1+3);
	s |= (c & 0x7) << (1);
	s |= (d & 0x1);
	*/

	// from output, we know x=0xdf89, so the bit-field is right-left
	s |= (a & 0xf);
	s |= (b & 0xff) << (4);
	s |= (c & 0x7) << (4+8);
	s |= (d & 0x1) << (4+8+3);

	p = (short *)&x;
	printf("x: 0x%x\n", *p);
	printf("s: 0x%x\n", s);


	return 0;
}

