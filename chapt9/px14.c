/*
 * decrypt data, using key get from solution Exercise 9.12.
 * 
 * Compile: gcc -Wall -o px14 px12.c px13.c px14.c
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "px12.h"
#include "px13.h"

extern int prepare_key(char *key);
extern void encrypt(char *data, char const *key);

void decrypt(char *data, char const *key)
{
	char *p, *s;

	p = data;
	while(*p != '\0'){
		if(islower(*p)){
			s = strchr(key, toupper(*p));
			if(s)
				*p = tolower((s - key) + 'A');
		} else if(isupper(*p)){
			s = strchr(key, *p);
			if(s)
				*p = (s - key) + 'A';
		}
		p++;
	}
}

int main(int argc, char *argv[])
{
	char str[27] = "TRAILblazERS";
	char data[50] = "Attack at Dawn, OK?";
	int ret;

	ret = prepare_key(str);
	if(ret){
		encrypt(data, str);
		printf("encrypted data: %s\n", data);

		decrypt(data, str);
		printf("decrypted data: %s\n", data);
	}

	return 0;
}

