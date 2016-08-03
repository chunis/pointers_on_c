/*
 * my_strcat() behaves like strcat(), but won't overflow the destination array
 *
 * Chunis Deng @ 2009.11.23
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

// behaves like strcat(), but won't overflow the destination array
char *my_strcat(char *dst, char const *src, int length)
{
	char *p = dst;
	int len;

	len = strlen(dst);

	length -= len;
	dst += len;

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
	char c[30] = "abcdefghijklmnopqrstuvwxyz";
	char d[LEN] = "hello-";

	// (dst+src) is shorter than dst array, both strcat() and my_strcat() are OK
	strncpy(a, d, LEN);
	strcat(a, b);
	printf("a: %s\n", a);

	strncpy(a, d, LEN);
	my_strcat(a, b, LEN);
	printf("a: %s\n", a);

	// (dst+src) is longer than dst array, strcat() failed, my_strcat() is OK
	strncpy(a, d, LEN);
	my_strcat(a, c, LEN);
	printf("a: %s\n", a);

	/*
	// below will make 'segmentation fault'
	strncpy(a, d, LEN);
	strcat(a, c);	// don't do this
	printf("a: %s\n", a);
	*/

	return 0;
}
