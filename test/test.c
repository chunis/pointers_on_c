#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
#if 0	// test strtok()
	char a[80] = "hello   	 world!  		kk	uhh";
	char *token;
	char *wh = "\t \f\r\v\n";

	for(token = strtok(a, wh); token != NULL; token = strtok(NULL, wh))
		printf("Next token is |%s|\n", token);
	printf("a: %s\n", a);
#endif

#if 0	// test strerror()
	int ecode;
	int *p;

	for(ecode=1; ecode<20; ecode++){
		p = strerror(ecode);
		printf("%d: %s\n", ecode, p);
	}
#endif

#if 1	// test if strcat work for 'dst' if 'dst' is not terminated by null
	// conclude: you must make 'a[20]' be a true string
	char a[20];	// not initialized, so you'll see something wrong
	char *c = "hello";
	int len;

	len = strlen(a);
	printf("a: %s\n", a);
	printf("length of a: %d\n", len);

	strcat(a, c);
	len = strlen(a);
	printf("a: %s\n", a);
	printf("length of a: %d\n", len);
#endif

	return 0;
}

