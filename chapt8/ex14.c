#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int array[10][20] = {
		{0}, {0}, {0}, {0},
		{1, 2, 3, 4, 5, 6},
	};
	int (*i)[20];

	i = array[3,4];		// This doesn't work well
	//i = &array[3,4];	// This should work well
	//i = array + 4;	// This should work well
	printf("i[2]: %d, i[4]: %d\n", (*i)[2], (*i)[4]);

	return 0;
}

