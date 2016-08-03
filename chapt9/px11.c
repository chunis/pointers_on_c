/*
 * count how many 'the' appears in the standin
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_the(char *str)
{
	int ret = 0;
	char *wc = " \t\f\r\v\n";
	char *p;

	for(p=strtok(str, wc); p!=NULL; p=strtok(NULL, wc)){
		if(strcmp(p, "the") == 0)
			ret++;
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int cnt = 0;
	char input[101];

	//while(gets(input)){	// OK for the requirement, but dangerous!
	while(fgets(input, 101, stdin)){
		cnt += count_the(input);
	}

	printf("counts: %d\n", cnt);

	return 0;
}

