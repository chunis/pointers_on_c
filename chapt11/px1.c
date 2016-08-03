/*
 * my own calloc(), using malloc() to get memory
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>

#define NUM 8
void *my_calloc(size_t num_elements, size_t element_size)
{
	char *p;
	size_t size;

	size = num_elements * element_size;
	p = (char *)malloc(size);
	if(p){
		while(size--)
			p[size] = '\0';
	}

	return (void *)p;
}

int main(int argc, char *argv[])
{
	int i;
	int *p;

	p = my_calloc(NUM, sizeof(int));
	if(p == NULL){
		perror("my_malloc");
		exit(EXIT_FAILURE);
	}

	// test if my_calloc initialize all memory to 0
	for(i=0; i<NUM; i++)
		printf("p[%d]: %d\n", i, p[i]);

	return 0;
}

