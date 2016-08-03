/*
 * search char in string from right to left.
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// behaves like strchr(), but from right to left
// if doesn't find the char, then return NULL
char *my_strrchr(char const *str, int ch)
{
	char *p;

	p = (char *)(str + strlen(str));
	while(*--p != ch && p >= str)
		;	// do nothing

	if(p < str)
		p = NULL;

	return p;
}

void test(char *str, char ch)
{
	char *p;

	p = my_strrchr(str, ch);
	if(p)
		printf("search '%c' in '%s': p-str: %d\n", ch, str, p-str);
	else
		printf("search '%c' in '%s': not found\n", ch, str);
}

int main(int argc, char *argv[])
{
	char *str = "hello_world";

	test(str, 'l');
	test(str, 'h');
	test(str, 'k');

	return 0;
}
