/*
 * my_strcpy() behaves like strcpy(), but won't overflow the destination array
 *
 * Chunis Deng @ 2009.11.21
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 12

// behaves like strcpy(), but won't overflow the destination array
char *my_strcpy(char *dst, char const *src, int length)
{
	char *p = dst;

	while(--length > 0 && *src != '\0')
		*dst++ = *src++;

	if(length == 0)
		*dst = '\0';

	return p;
}

int main(int argc, char *argv[])
{
	char a[LEN];
	char b[10] = "goodbye";
	char c[30] = "hello_very_good_world";

	// dststr is longer than src str, both strcpy() and my_strcpy() are OK
	strcpy(a, b);
	printf("a: %s\n", a);
	my_strcpy(a, b, LEN);
	printf("a: %s\n", a);

	// dststr is shorter than src str, strcpy() failed, but my_strcpy() is OK
	//strcpy(a, c);	// don't do this
	my_strcpy(a, c, LEN);
	printf("a: %s\n", a);

	return 0;
}
