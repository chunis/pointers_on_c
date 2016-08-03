/*
 * This program is used to show a few things about strncpy,
 * and the arrange of argument in stack,
 * and how to use it to do some bad things(for example, shellcode).
 *
 * Chunis Deng @ 2009.10.28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char static_str[20];

// print 'num' chars from pointer p
void print_fix_num(char *p, int num)
{
	int i = 0;
	int j;
	
	while(i<num){
		j = *p++;
		if(j == (int)NULL)
			printf("-");
		else
			printf("%c", j);
		i++;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	char str[20] = "hello world";
	char str2[10] = "hello ";
	//char *str = "hello world";
	char new[20];
	char *p;

	p = str2;

	// here, the str is changed, not str2, becourse p is enter str now
	p += 11;
	printf("p: %c\n", *p);
	*p = 'X';

	// you can see str is just follow str2,
	// so we can move from str to str2, as above
	print_fix_num(str, 20);
	print_fix_num(str2, 20);
	printf("\n");

	// static variable 'static_str' will be initialized
	print_fix_num(static_str, 20);

	// auto variable 'new' doesn't be initialized.
	print_fix_num(new, 20);

	// strncpy will set new with at most 'n' chars; if src has less than 'n' chars,
	// the left will be filled with 'NULL'.
	strncpy(new, str, 8);
	print_fix_num(new, 20);
	strncpy(new, str, 15);
	print_fix_num(new, 20);

	return 0;
}

