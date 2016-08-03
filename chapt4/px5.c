/*
 * Only output a single line if there is a line appear more than once in the
 * same palce. Line appears one once each time will not be outputed.
 *
 * Chunis Deng @ 2009.10.28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM (128+1)

int main(int argc, char *argv[])
{
	int flag = 0;
	char buf[MAXNUM];
	char newbuf[MAXNUM];

	char *bufp = buf;
	char *newbufp = newbuf;

	while(fgets(bufp, MAXNUM, stdin)){
		//printf("buf: %s", bufp);
		//printf("newbuf: %s", newbufp);

		//if(strcmp(bufp, newbufp)){	// not equal
		if(strncmp(bufp, newbufp, MAXNUM)){	// not equal
			flag = 0;

			newbufp = bufp;
			if(bufp == buf){
				bufp = newbuf;
			} else {
				bufp = buf;
			}
		} else {		// equal
			if(flag == 0){
				flag = 1;
				printf("%s", bufp);
			}
		}
	}

	return 0;
}

