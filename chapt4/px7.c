/*
 * Change multi white space to a single one in a string.
 *
 * Chunis Deng @ 2009.11.02
 */

#include <stdio.h>
#include <stdlib.h>

void delbank(char string[])
{
	char *p = string;

	if(*string){
		*p++ = *string++;
	}

	while(*string){
		if(*string == ' ' || *string == '\t'){
			if(p[-1] == ' ' || p[-1] == '\t')
				p--;
		}
		*p++ = *string++;
	}

	*p = '\0';
}

int main(int argc, char *argv[])
{
	//char str[60] = " hello world 	 !";
	char str[60] = "   hello   world 	 !";

	delbank(str);
	puts(str);

	return 0;
}

