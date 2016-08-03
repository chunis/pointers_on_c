#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// this should be a little better in performance than the below 'copy_n'
void copy_n_1(char dst[], char src[], int n)
{
	int i;

	for(i=0; i<n; i++){
		if(src[i] == '\0')
			break;

		dst[i] = src[i];
	}

	for(; i<n; i++)
		dst[i] = '\0';
}

void copy_n(char dst[], char src[], int n)
{
	int i;

	for(i=0; i<n; i++){
		if(src[i] == '\0')
			dst[i] = '\0';
		else
			dst[i] = src[i];
	}
}

int main(int argc, char *argv[])
{
	char str[20] = "hello world";

	// if new is initialized, all value will be set as 'NULL'.
	//char new[20] = "";
	//char new[20] = { '\0' };
	char new[20];

	print_fix_num(new, 20);

	copy_n(new, str, 8);
	print_fix_num(new, 20);

	copy_n(new, str, 16);
	print_fix_num(new, 20);

	// compare to strncpy, the output should be the same.
	strncpy(new, str, 16);
	print_fix_num(new, 20);

	return 0;
}

