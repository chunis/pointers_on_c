/*
 * 
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>

// Behaves like strcpy(), but return a pointer pointed to the end of dst
char *my_strcpy_end(char *dst, char const *src)
{
	while( (*dst++ = *src++) )
		;	// do nothing

	return dst-1;
}

int main(int argc, char *argv[])
{
	char a[30] = "abcdefghijklmnopqrstuvwxyz";
	char *b = "hello";
	char *p;

	p = my_strcpy_end(a, b);
	printf("p-a = %d\n", p-a); // count how many chars are copied to 'a'

	return 0;
}

