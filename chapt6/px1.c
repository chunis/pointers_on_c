/*
 * A function behave like function strpbrk().
 *
 * Chunis Deng @ 2009.11.05
 */

#include <stdio.h>
#include <stdlib.h>

char *find_char(char const *source, char const *chars)
{
	const char *p = chars;
	char *src = (char *)source;

	if(src == NULL || *src == '\0' || chars == NULL || *chars == '\0')
		return NULL;

	for(; *src; src++){
		for(p = chars; *p; p++){
			if(*p == *src)
				return src;
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	char *source = "ABCDEF";
	char *chars = "XYZ";
	char *ch2 = "XRCQEF";
	char *ret;

	ret = find_char(source, chars);
	if(ret)
		printf("%s\n", ret);

	ret = find_char(source, ch2);
	if(ret)
		printf("%s\n", ret);

	return 0;
}

