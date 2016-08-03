#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *fpr1, *fpr2, *fpw;

	fpr1 = fopen("kk", "r");
	if(fpr1 == NULL){
		perror("fpr1");
		exit(1);
	}

	fpw = fopen("kk", "w");
	if(fpw == NULL){
		perror("fpw");
		exit(1);
	}

	fpr2 = fopen("kk", "r");
	if(fpr2 == NULL){
		perror("fpr2");
		exit(1);
	}

	printf("here\n");

	return 0;
}

