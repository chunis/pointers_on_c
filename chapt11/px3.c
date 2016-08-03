/*
 * return a string saved in dynamic alloced memory,
 * which is not limited by the string's length.
 *
 * Chunis Deng @ 2009.11.29
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM	100
//#define NUM	5	// use this for test

char *get_string(void)
{
	int len = 0, num = NUM;
	char *p;

	p = malloc(num * sizeof(char));
	if(p == NULL)
		return NULL;

	while(scanf("%c", p+len) == 1) {
		// not sure if my understand of string end is right or not   :(
		if(p[len] == ' ' || p[len] == '\t' || p[len] == '\n'
				|| p[len] == '\f' || p[len] == '\r'
				|| p[len] == '\v'){
			p[len] = '\0';
			break;
		}
		
		// if memory is not enough
		if(++len > num){
			num += NUM;
			p = realloc(p, num * sizeof(char));
			if(p == NULL)
				return NULL;
		}
	}

	// shrink to the exactly size, (len+1) for len and '\0'
	p = realloc(p, (len+1) * sizeof(char));
	if(p == NULL)
		return NULL;

	return p;
}

int main(int argc, char *argv[])
{
	char *p;

	p = get_string();
	printf("you got: %s, len: %d\n", p, strlen(p));
	free(p);

	return 0;
}
