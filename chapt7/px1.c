/*
 * Calculate 'Hermite Polynomials'.
 *
 * Chunis Deng @ 2009.11.06
 */
 
#include <stdio.h>
#include <stdlib.h>

int hermite(int n, int x)
{
	if(n <= 0)
		return 1;
	if(n == 1)
		return 2*x;

	return (2 * x * hermite( (n-1), x) - 2 * (n-1) * hermite( (n-2), x));
}

int main(int argc, char *argv[])
{
	int ret;

	ret = hermite(3, 2);
	printf("ret: %d\n", ret);

	return 0;
}

