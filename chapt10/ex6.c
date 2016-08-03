#include <stdio.h>
#include <stdlib.h>

struct {
	int a;
	char b[10];
	float c;
} x = { 3, "hello"};

int main(int argc, char *argv[])
{
	printf("x.a: %d\n", x.a);
	printf("x.b: %s\n", x.b);
	printf("x.c: %f\n", x.c);

	return 0;
}

