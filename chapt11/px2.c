/*
 * Demonstrate malloc()/realloc()/free()
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>

#define NUM	100
//#define NUM	5	// use this value for test

// got some integers from stdin, save it in a array which is dynamic alloced
// the number of integers is saved in the first element of array
int *get_int_array(void)
{
	int *p;
	int count = 0;
	int val;	// val: scanfed value 
	int num = NUM;	// num: malloced memory size

	p = (int *)malloc(num * sizeof(int));
	if(p == NULL){
		perror("malloc");
		//exit(EXIT_FAILURE);
		return NULL;
	}

	while( scanf("%d", &val) == 1 && val != EOF){
		// get more memory if there are too many integers
		if(count+1 >= num){
			num += NUM;
			p = (int *)realloc(p, num * sizeof(int));
			if(p == NULL){
				perror("realloc");
				//exit(EXIT_FAILURE);
				return NULL;
			}
		}
		// save the value got from stdin
		p[++count] = val;
	}

	// save the total number of integers in the start of array
	p[0] = count;

	// strip not used memory at the rear
	// (count+1) for the first element not included in the total number
	p = realloc(p, (count+1) * sizeof(int));
	if(p == NULL){
		perror("realloc");
		//exit(EXIT_FAILURE);
		return NULL;
	}

	return p;
}

int main(int argc, char *argv[])
{
	int *p, *s;
	int num;

	p = get_int_array();
	if(p == NULL)
		return -1;

	s = p;	// s used to save the start position of memory
	num = *p++;
	printf("there are %d integers\n", num);

	while(num-- > 0)
		printf("%d  ", *p++);
	printf("\n");

	// don't forget this!
	free(s);

	return 0;
}

