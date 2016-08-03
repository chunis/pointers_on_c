/*
 * Abstract a substr which saves in 'dst' from str 'src' from 'start'
 * with at most 'len' chars.
 *
 * Compile: gcc -Wall -o px6 px6.c ../tool/myprint.o
 *
 * Chunis Deng @ 2009.11.02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tool/myprint.h"

#define	MAXNUM	20

/*
About:	Abstract a substr which saves in 'dst' from str 'src' from 'start'
	with at most 'len' chars.
return:	the length of str saved in dst, -1 if start<0, or len<0,
	or start over the end of src
*/
int substr(char dst[], char src[], int start, int len)
{
	char *srcp = src;
	char *dstp = dst;
	int srclen;
	int count = 0;

	srclen = strlen(src);
	if(start > srclen || start < 0 || len < 0){
		dst[count] = '\0';
		return count;
	}

	srcp += start;
	while(count < len && *srcp){
		*dstp++ = *srcp++;
		count++;
	}

	*dstp = '\0';	// don't forget this line!
	return count;
}

void test_substr(int start, int len)
{
	char *str = "Hello world";
	char sub[MAXNUM] = "";
	int savelen;

	savelen = substr(sub, str, start, len);
	print_fix_num(sub, MAXNUM);
	printf("savelen: %d\n", savelen);
	puts(sub);
}

int main(int argc, char *argv[])
{
	test_substr(0, 8);
	test_substr(0, 16);
	test_substr(2, 8);
	test_substr(0, 16);
	test_substr(16, 16);
	test_substr(-2, 16);
	test_substr(16, -2);

	return 0;
}

