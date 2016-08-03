/*
 * about keyword 'const' used in pointers.
 *
 * chunis.deng 2009.10.09
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 6;
	int j = 12;

#if 0
	int *p;
	p = &i;
	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);
	*p = 9;
	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);
#endif

#if 0
	int const *p;
	p = &i;
	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);

	// *p = 9;	// error!
	p = &j;
	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);
#endif

#if 1
	// below is error!
	/* int * const p;
	p = &i; */
	int * const p = &i;

	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);

	// p = &j;	// error!
	*p = 9;
	printf("i: %d, j: %d\n", i, j);
	printf("*p: %d\n", *p);
#endif

	return 0;
}
