/*
 * Delete the first appearance of 'substr' in 'str'. Only delete once.
 *
 * Chunis Deng @ 2009.11.06
 */

#include <stdio.h>
#include <stdlib.h>

int del_substr(char *str, char const *substr)
{
	char *start = NULL;
	char *subp = NULL;

	if(str == NULL || substr == NULL)
		return 0;

	// when substr == ""
	if(*substr == '\0')
		return 1;

	for(; *str; str++){
		start = str;
		for(subp=(char *)substr; *start++ == *subp++; ){
			//printf("start: %c, subp: %c\n", *start, *subp);
			if(*subp == '\0'){	// find substr now
				while((*str++ = *start++) != '\0')
					;	// do nothing here
				return 1;
			}
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	char str[20] = "ABCDEFG";
	char *sub = "XABC";
	char *sub2 = "CDE";
	int ret;

	ret = del_substr(str, sub);
	if(ret)
		printf("str: %s\n", str);

	ret = del_substr(str, sub2);
	if(ret)
		printf("str: %s, ret: %d\n", str, ret);

	return 0;
}

