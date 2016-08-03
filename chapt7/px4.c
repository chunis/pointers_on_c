/*
 * Chunis Deng @ 2009.11.06
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// return the max number in a list with variable numbers.
// The list should end with a negative number.
int max_list(int first, ...)
{
	int max = first;
	int tmp;
	va_list varg;

	va_start(varg, first);

	while((tmp = va_arg(varg, int)) >= 0){
		if(tmp > max)
			max = tmp;
	}

	va_end(varg);
	return max;
}

int main(int argc, char *argv[])
{
	int ret;

	ret = max_list(23, 44, 78, 11, 0, 8, 9, -45);
	printf("ret: %d\n", ret);

	return 0;
}

