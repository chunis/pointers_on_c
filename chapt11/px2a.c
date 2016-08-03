/*
 * Demonstrate malloc()/realloc()/free(), another solution to Exercise 11.2
 *
 * compare to px2.c, we remove variable 'val' now, and save scanfed value to
 * the memory directly, so its performance should be a little better.
 * also note the value of 'count' is not all the same as px2.c.
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>

//#define NUM	100
#define NUM	5	// use this value for test

// got some integers from stdin, save it in a array which is dynamic alloced
// the number of integers is saved in the first element of array
int *get_int_array(void)
{
	int *p;
	int count = 0;
	int num = NUM;	// num: malloced memory size

	p = (int *)malloc(num * sizeof(int));
	if(p == NULL){
		perror("malloc");
		//exit(EXIT_FAILURE);
		return NULL;
	}

	// just scanf value to p[X] directly 
	while( scanf("%d", p+(++count)) == 1 && p[count] != EOF){
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
	}

	// p[count] = EOF now, so we need to deal with this
	// save the total number of integers in the start of array
	p[0] = count-1;

	// strip not used memory at the rear
	p = realloc(p, count * sizeof(int));
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

