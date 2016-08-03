/*
 * behave like strlen(), but do well if the string not terminated by 'null'
 *
 * Compile: gcc -Wall -o px2 px2.c ../tool/myprint.o
 *
 * Chunis Deng @ 2009.11.21
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tool/myprint.h"

extern void print_fix_num(char *p, int num);

// do the same things like function 'strlen',
// but do well with strings without NULL terminated.
// the argument 'length' is passed as the length of array hold the string
size_t my_strlen(char const *str, int length)
{
	int len = 0;

	while(*str++ != '\0' && len < length)
		len++;

	return len;
}

int main(int argc, char *argv[])
{
	//char a[10] = "";	// this will make everything right
	char a[10];
	char b[30] = "hello_good_world";
	int len;

	// first, we make 'a' not terminated with null chars
	// check with print_fix_num(), defined in ../tool/myprint.c
	strncpy(a, b, 8);
	print_fix_num(a, 10);

	// see if strlen() work or not
	len = strlen(a);
	printf("the length of a is: %d\n", len);

	// use our own my_strlen() now
	// you'll get 10, not right, but better than strlen.  (:
	len = my_strlen(a, 10);
	printf("the length of a is: %d\n", len);

	return 0;
}
