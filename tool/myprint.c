#include <stdio.h>
#include <stdlib.h>

// print 'num' chars from pointer p
void print_fix_num(char *p, int num)
{
	int i = 0;
	int j;
	
	while(i<num){
		j = *p++;
		if(j == (int)NULL)
			printf("-");
		else
			printf("%c", j);
		i++;
	}
	printf("\n");
}
