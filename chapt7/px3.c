/*
 * Translate ascii strings to integer number.
 *
 * Chunis Deng @ 2009.11.06
 */
 
#include <stdio.h>
#include <stdlib.h>

int ascii_to_integer(char *string)
{
	int ret = 0;

	while(*string){
		if(*string >= '0' && *string <= '9'){
			ret = (ret * 10 + *string - '0');
		} else
			return 0;

		string++;
	}

	return ret;
}

int main(int argc, char *argv[])
{
	char *a = "349";
	char *b = "34a8";

	printf("%d\n", ascii_to_integer(a));
	printf("%d\n", ascii_to_integer(b));

	return 0;
}

