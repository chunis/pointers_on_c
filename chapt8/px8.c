/*
 * 8 Queens Questions.
 * This program cost me more than 3 hours. :(
 *
 * Other improvement:
 *  	1. set board[][] as a global variable.
 * 	   I didn't because I want to practice pointer.
 *	2. replace label 'end' and goto with a flag variable. 
 *
 * Chunis Deng @ 2009.11.10
 */
 
#include <stdio.h>
#include <stdlib.h>

//#define LINE 5	// define this to get a 5 Queens test  (:
#define LINE 8

long count = 0;

void print_arrays(int *p, int n)
{
	int i, j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			if(p[i*n+j] == 1)
				printf("X ");
			else
				printf("- ");
		printf("\n");
	}
}

void eight_queens(int (*board)[LINE], int row)
{
	int i, j;
	int (*bd)[LINE];
	int col = 0;

	count++;

	bd = board;
	//printf("row: %d\n", row);

	// test col
	for(col = 0; col < LINE;){
		// current ax: (row, col)

		// test '|'
		for(i=0; i<row; i++){	// test the same col in each row
			if(bd[i][col] == 1){
				goto end;
			}
		}

		// test '\'
		for(i=(row-1),j=(col-1); i>=0 && j>=0; i--, j--){
			if(bd[i][j] == 1){
				goto end;
			}
		}

		// test '/'
		for(i=(row-1),j=(col+1); i>=0 && j<LINE; i--, j++){
			if(bd[i][j] == 1){
				goto end;
			}
		}

		// restore the status for the new test
		for(i=0; i<LINE; i++)
			bd[row][i] = 0;

		// now this location is OK to put a queen
		bd[row][col] = 1;

		// recusive call itself
		if(row < (LINE-1)){
			eight_queens(board, row+1);
		} else {
			printf("\nResolutions as below:\n");
			print_arrays((int *)bd, LINE);
		}
end:
		col++;
	}
}

int main(int argc, char *argv[])
{
	int i, j;
	int board[LINE][LINE];

	for(i=0; i<LINE; i++)
		for(j=0; j<LINE; j++)
			board[i][j] = 0;

	eight_queens(board, 0);
	printf("\nWe runned 'eight_queens()' %ld times"
			"to get all results!\n", count);

	return 0;
}
