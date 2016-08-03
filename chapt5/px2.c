/*
 * Very simple encrypt which only applies to chars
 *
 * Chunis Deng @ 2009.11.02
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;

	while( (c=getchar()) != EOF){
		if( c >= 'A' && c <= 'M')
			c += 13;
		else if( c >= 'a' && c <= 'm')
			c += 13;
		else if( c >= 'N' && c <= 'Z')
			c -= 13;
		else if( c >= 'n' && c <= 'z')
			c -= 13;

		putchar(c);
	}

	return 0;
}

