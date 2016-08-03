/*
 * check if a string is palindrome or not.
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// check if 'str' is palindrome or not
int palindrome(char *str)
{
	int len;
	char *p;

	if(str == NULL)
		return 0;

	// if str == ""
	len = strlen(str);
	if(len == 0)
		return 1;

	p = str + len - 1;
	while(p > str){
		while(!isalpha(*p))
			p--;

		while(!isalpha(*str))
			str++;

		// make the chars are ingorecases
		if(tolower(*p--) != tolower(*str++))
			return 0;
	}

	return 1;
}

void test(char *str)
{
	int ret;

	ret = palindrome(str);
	if(ret)
		printf("str '%s' is palindrome\n", str);
	else
		printf("str '%s' is not palindrome\n", str);
}

int main(int argc, char *argv[])
{
	char *str1 = "Madam, I'm Adam";
	char *str2 = "hello";
	char *str3 = "";
	char *str4 = "\thelleh ";

	test(str1);
	test(str2);
	test(str3);
	test(str4);

	return 0;
}

