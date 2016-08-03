/*
 * Demostrate function with variable arguments
 *
 * Chunis Deng @ 2009.11.05
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float average(int num, ...)
{
	int total = 0;
	int count = num;
	va_list varg;

	va_start(varg, num);
	
	while(count-- > 0){
		total += va_arg(varg, int);
	}

	va_end(varg);

	return total*1.0/num;
}

int main(int argc, char *argv[])
{
	printf("the average of 1, 3, 6, 8 is: %.2f\n", average(4, 1, 3, 6, 8));
	printf("the average of 1, 30, 26, 8, 4, 20 is: %.2f\n",
			average(6, 1, 30, 26, 8, 4, 20));

	return 0;
}

