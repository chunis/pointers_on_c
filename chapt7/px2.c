/*
 * Chunis Deng @ 2009.11.06
 */
 
#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	int r;

	if(m <= 0 || n <= 0)
		return 0;

	r = m % n;
	if(r == 0)
		return n;
	if(r > 0)
		return gcd(n, r);
}

int main(int argc, char *argv[])
{
	int a = 36, b = 48, c = -12;
	int ret;

	ret = gcd(a, b);
	printf("ret: %d\n", ret);

	ret = gcd(a, c);
	printf("ret: %d\n", ret);

	return 0;
}

