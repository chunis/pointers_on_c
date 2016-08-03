#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
	int a;
	short b[2];
} Ex2;

typedef struct EX {
	int	a;
	char	b[3];
	Ex2	c;
	struct EX	*d;
} Ex;

int main(int argc, char *argv[])
{
	Ex x = { 10, "Hi", { 5, { -1, 25 } }, 0 };
	Ex *px = &x;

	printf("px->c.a: %d\n", px->c.a);
	printf("px->c.b[1]: %d\n", px->c.b[1]);
	printf("*px->c.b: %d\n", *px->c.b);
	printf("px->b[1]: %c\n", px->b[1]);
	printf("offsetof(struct EX, Ex2.b): %d\n", offsetof(struct EX, c.b));

	return 0;
}

