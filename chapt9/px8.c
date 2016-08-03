/*
 * search char in string from left to right.
 * return the position where is the 'which' time the char appears
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// return the position where 'ch' appears for the 'which' time in the str
// if 'ch' appears less than 'which' times, return NULL
char *my_strnchr(char const *str, int ch, int which)
{
	if(which < 1)
		return NULL;

	while(*str != '\0'){
		if(*str++ == ch){
			which--;
			if(which == 0)
				return (char *)--str;
		}
	}

	return NULL;
}

void test(char *str, char ch, int n)
{
	char *p;

	p = my_strnchr(str, ch, n);
	if(p){
		printf("search '%c' in '%s', the '%d' times: p: %s\n",
				ch, str, n, p);
	}else{
		printf("search '%c' in '%s', the '%d' times: not found\n",
				ch, str, n);
	}
}

int main(int argc, char *argv[])
{
	char *str = "hello_world";

	test(str, 'l', 1);
	test(str, 'l', 3);
	test(str, 'l', 5);
	test(str, 'e', 1);
	test(str, 'k', 1);

	return 0;
}
