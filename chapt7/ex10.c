/*
 * Chunis Deng @ 2009.11.06
 */

#include <stdio.h>
#include <stdlib.h>

long count = 0;

long fibonacci(int n)
{
	count++;
	if(n <= 2)
		return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[])
{
	count = 0;
	fibonacci(1);
	printf("count: %ld\n", count);

	count = 0;
	fibonacci(5);
	printf("count: %ld\n", count);

	count = 0;
	fibonacci(11);
	printf("count: %ld\n", count);

	count = 0;
	fibonacci(25);
	printf("count: %ld\n", count);	// Output is : count: 150049

	count = 0;
	fibonacci(40);
	printf("count: %ld\n", count);	// Output is : count: 204668309

	return 0;
}

