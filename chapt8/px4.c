#include <stdio.h>
#include <stdlib.h>

int identity_matrix(int *m, int width)
{
	int x, y;

	for(x=0; x<width; x++){
		for(y=0; y<width; y++){
			//printf("m[%d] = m[%d*4+%d] = %d\n",
			//	x*width+y, x, y, m[x*width+y]);
			if(x == y){
				if(m[x*width+y] != 1)
					return 0;
			} else {// x != y
				if(m[x*width+y] != 0)
					return 0;
			}
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	int matrix[4][4] = {
		{1,0,0,0},
		{3,1,0,5},
		{0,0,1,0},
		{0,0,0,1},
	};

	int t;

	t = identity_matrix(matrix, 4);
	if(t)
		printf("It is a matrix!\n");
	else
		printf("It isn't a matrix!\n");

	return 0;
}

