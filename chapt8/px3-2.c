#include <stdio.h>
#include <stdlib.h>

#define WIDTH 4

// return 1 if the array argument is a matrix
int identity_matrix(int (*m)[4])
{
	int x, y;

	int width = WIDTH;

	for(x=0; x<width; x++){
		for(y=0; y<width; y++){
			if(x == y){
				if((*m)[y] != 1)
					return 0;
			} else { // x != y
				if((*m)[y] != 0)
					return 0;
			}
		}
		m++;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	int t;
	int matrix[4][4] = {
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};


	t = identity_matrix(matrix);
	//t = identity_matrix();
	if(t)
		printf("It is a matrix!\n");
	else
		printf("It isn't a matrix!\n");

	return 0;
}

