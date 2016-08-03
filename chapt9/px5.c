/*
 * my_strncat() behaves like strncat(), but won't overflow the destination array
 *
 * I've changed the protocol of my_strncat() from the requirement in Exercise 9.5,
 * because I think what I did in my solution (px4.c) for Exercise 9.4 is just
 * the answer to the author's requirement.
 *
 * I've changed the protocol to what I think is better for my 'own' my_strncat().  :)
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

// behaves like strncat(), but won't overflow the destination array
// if dst is not long enough, no 'null' char at the end
// if dst is too long, will filled with 'null' in all space at the end
void my_strncat(char *dst, char const *src, int n, int dest_len)
{
	int len;

	len = strlen(dst);

	dest_len -= len;
	dst += len;

	// make sure 'n' is no longer than the space available besides src
	if(n > dest_len)
		n = dest_len;

	while(--n >= 0 && *src != '\0')
		*dst++ = *src++;

	while(--n >= 0)
		*dst++ = '\0';
}

int main(int argc, char *argv[])
{
	char a[LEN];
	char b[10] = "goodbye";
	char c[30] = "abcdefghijklmnopqrstuvwxyz";
	char d[LEN] = "hello-";

	strncpy(a, d, LEN);
	my_strncat(a, b, LEN/2, LEN);
	printf("a: %s\n", a);

	strncpy(a, d, LEN);
	my_strncat(a, b, LEN, LEN);
	printf("a: %s\n", a);

	strncpy(a, d, LEN);
	my_strncat(a, c, LEN/2, LEN);
	printf("a: %s\n", a);

	strncpy(a, d, LEN);
	// note: below will make 'a' not terminated with a 'null' char!
	my_strncat(a, c, LEN, LEN);
	printf("a: %s\n", a);

	return 0;
}
