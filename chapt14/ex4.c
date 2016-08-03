#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)	(a)>(b)?(a):(b)
#define SQUARE(x)	x*x
#define DOUBLE(x)	x+x

int main(int argc, char *argv[])
{
	int x, y, z;

	y = 2;
	z = 3;
	x = MAX(y, z);
	printf("%d %d %d\n", x, y, z);	/* a */

	y = 2;
	z = 3;
	x = MAX(++y, ++z);
	printf("%d %d %d\n", x, y, z);	/* b */

	x = 2;
	y = SQUARE(x);
	z = SQUARE(x+6);
	printf("%d %d %d\n", x, y, z);	/* c */

	x = 2;
	y = 3;
	z = MAX(5*DOUBLE(x), ++y);
	printf("%d %d %d\n", x, y, z);	/* d */

	return 0;
}

