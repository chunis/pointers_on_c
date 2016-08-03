/*
 * Demonstrate bit-field and shift operation using 32-bit variables.
 * Note: my machine puts bit-field from right to left, not as Exercise 10.11 said.
 *
 * Chunis Deng @ 2009.11.27
 */
#include <stdio.h>
#include <stdlib.h>

struct _x {
	int z:16;	// I add this field to make the struct 32-bit long
	int a:4;
	int b:8;
	int c:3;
	int d:1;
} x;

int main(int argc, char *argv[])
{
	int s;
	int a = 9, b = 0xf8, c = 5, d = 1;
	int *p;

	x.z = 0xabcd;
	x.a = a;
	x.b = b;
	x.c = c;
	x.d = d;

	/*
	// solution for left-right position bit-field
	s = 0;
	s |= (a & 0xf) << (1+3+8);
	s |= (b & 0xff) << (1+3);
	s |= (c & 0x7) << (1);
	s |= (d & 0x1);
	*/

	// from output, we know x=0xdf89abcd, so the bit-field is right-left
	s = 0;
	s |= (d & 0x1) << (4+8+3);
	s |= (c & 0x7) << (4+8);
	s |= (b & 0xff) << (4);
	s |= (a & 0xf);
	s = (s << 16) + 0xabcd;	// we are in 32-bit PC, so we need this

	p = (int *)&x;
	printf("x: 0x%x\n", *p);
	printf("s: 0x%x\n", s);


	return 0;
}

