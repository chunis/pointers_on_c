/*
 * reverse a string, change in its same place.
 * So don't pass it with a string literal, or it will fail!
 *
 * Chunis Deng @ 2009.11.05
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *string)
{
	int len, tmp;
	char *p = string;
	char *q = string;

	if(string == NULL || *string == '\0')
		return;

	len = strlen(string);
	q += (len - 1);

	while(p < q){
		tmp = *p;
		*p++ = *q;
		*q-- = tmp;
	}
}

int main(int argc, char *argv[])
{
	//char *str = "hello world";	// will fail!
	char str[20] = "hello world";

	printf("%s\n", str);
	reverse_string(str);
	printf("%s\n", str);

	return 0;
}

