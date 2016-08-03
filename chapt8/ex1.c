#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ints[20] = {
		10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
		110, 120, 130, 140, 150, 160, 170, 180, 190, 200
	};

	int *ip = ints + 3;

	printf("ints: %u\n", (unsigned)ints);
	printf("ip: %u\n", (unsigned)ip);

	printf("ints[4]: %u\n", ints[4]);
	printf("ints+4: %u\n", ints+4);
	printf("*ints+4: %u\n", *ints+4);
	printf("*(ints+4): %u\n", *(ints+4));
	printf("ints[-2]: %u\n", ints[-2]);
	printf("&ints: %u\n", &ints);
	printf("&ints[4]: %u\n", &ints[4]);
	printf("&ints+4: %u\n", &ints+4);
	printf("&ints[-2]: %u\n", &ints[-2]);

	return 0;
}

