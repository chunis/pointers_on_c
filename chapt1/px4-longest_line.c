/*
 * Find the longest line in a file
 * practice pointers and fgets
 *
 * don't forget to initialize pointers!
 *
 * Chunis Deng @ 2009.10.28
 *
 * Todo: add pipe support
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHR (1000+1)

void find_longest_line(FILE *fp, char *p)
{
	char buf[MAXCHR];
	char tmpbuf[MAXCHR];
	char *bufp = buf;	// don't forget to initialize the pointers!
	char *retp = NULL;	// point to buffer with longest line
	int len = 0, tmplen;

	while(fgets(bufp, MAXCHR, fp)){
		tmplen = strlen(bufp);
		if(tmplen > len){
			len = tmplen;
			retp = bufp;
			if(bufp == buf)
				bufp = tmpbuf;
			else
				bufp = buf;
		}
	}

	// strip the last char if it is a '\n'
	if(retp[len-1] == '\n')
		retp[len-1] = '\0';

	strncpy(p, retp, len);

	return;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char cmd[MAXCHR];

	if(argc == 1){
		printf("usage: %s <filename>\n", argv[0]);
		return 0;
	}

	fp = fopen(argv[1], "r");
	if(! fp){
		printf("open file '%s' failed!\n", argv[1]);
		return -1;
	}

	find_longest_line(fp, cmd);
	printf("The longest line in file '%s':\n%s\n", argv[1], cmd);

	return 0;
}

