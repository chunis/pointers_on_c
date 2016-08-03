/*
 * change Upper chars to lower chars, other chars stay the same.
 *
 * Chunis Deng @ 2009.11.02
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;

	while( (c=getchar()) != EOF){
		if( c >= 'A' && c <= 'Z')
			c += 'a' - 'A';
		putchar(c);
	}

	return 0;
}

