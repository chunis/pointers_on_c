/*
 * count the number of appearence from 'chars' in 'str'.
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>

// find how many times the char from 'chars' are appeared in str
// if 'chars' is null, return 0.
int count_chars(char const *str, char const *chars)
{
	int cnt = 0;
	char *p;

	if(chars == NULL)
		return cnt;

	while(*str != '\0'){
		for(p = (char *)chars; *p; p++){
			if(*p == *str)
				cnt++;
		}
		str++;
	}

	return cnt;
}

void test(char *str, char *chs)
{
	int count;

	count = count_chars(str, chs);
	printf("In '%s', here are %d appears of '%s'\n", str, count, chs);
}

int main(int argc, char *argv[])
{
	char *a = "hello_world";
	char *b = "el";
	char *c = "els";
	char *d = "w";
	char *e = "st";

	test(a, b);
	test(a, c);
	test(a, d);
	test(a, e);

	return 0;
}
