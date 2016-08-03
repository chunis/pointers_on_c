/*
 * Calculate matrix.
 *
 * I have to admit that the solution provided by the author using pointer is
 * much better than what I do using subindex.
 *
 * Chunis Deng @ 2009.11.19
 */
 
#include <stdio.h>
#include <stdlib.h>

// my solution
void my_matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	int i, j, k;
	int sum;

	for(i=0; i<x; i++){
		for(j=0; j<z; j++){
			sum = 0;
			for(k=0; k<y; k++){
				sum += m1[i*y+k] * m2[k*z+j];
				//printf("i: %d, j:%d, k: %d, ", i, j, k);
				//printf("m1: %d, m2: %d, sum: %d\n", m1[i*y+k], m2[k*z+j], sum);
			}
			r[i*z+j] = sum;
		}
	}
}

// this solution is provided by the author
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
	int i, j, k;
	int *mp1, *mp2;

	for(i=0; i<x; i++){
		for(j=0; j<z; j++){
			mp1 = m1 + i*y;
			mp2 = m2 + j;
			*r = 0;

			for(k=0; k<y; k++){
				mp1 += k;
				mp2 += k*z;
				*r += *mp1 * *mp2;
				//printf("i: %d, j:%d, k: %d, ", i, j, k);
				//printf("m1: %d, m2: %d, sum: %d\n", m1[i*y+k], m2[k*z+j], sum);
			}
			r++;
		}
	}
}

int main(int argc, char *argv[])
{
	int a[3][2] = { {2, -6},
			{3, 5},
			{1, -1} };
	int b[2][4] = { {4, -2, -4, -5},
			{-7, -3, 6, 7} };
	int c[3][4];
	int i, j;

	//my_matrix_multiply((int *)a, (int *)b, (int *)c, 3, 2, 4);
	matrix_multiply((int *)a, (int *)b, (int *)c, 3, 2, 4);

	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}

