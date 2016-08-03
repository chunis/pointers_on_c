/*
 * encrypt data, using key get from solution Exercise 9.12.
 * 
 * Note: before compile, change 'main_px13' to 'main' first!
 * Compile: gcc -Wall -o px13 px12.c px13.c
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "px12.h"

extern int prepare_key(char *key);

void encrypt(char *data, char const *key)
{
	char *p;

	p = data;
	while(*p != '\0'){
		if(islower(*p))
			*p = tolower(key[*p-'a']);
		if(isupper(*p))
			*p = key[*p-'A'];
		p++;
	}
}

int main_px13(int argc, char *argv[])
{
	char str[27] = "TRAILblazERS";
	char data[50] = "Attack at Dawn, OK?";
	int ret;

	ret = prepare_key(str);
	if(ret){
		encrypt(data, str);
		printf("encrypted data: %s\n", data);
	}

	return 0;
}

