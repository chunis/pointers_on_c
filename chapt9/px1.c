/*
 * Count the percentage of all kinds of chars get from stdin.
 * You may run it using this command: $ cat px1* | ./px1
 *
 * Chunis Deng @ 2009.11.21
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int ch;
	int cch = 0, wch = 0;	// control-chars, whitespace-chars
	int dch = 0, pch = 0;	// digital-chars, punctuation-chars
	int lch = 0, upch = 0;	// lowercase and uppercase chars
	int unch = 0;		// unprintable chars
	int count = 0;		// how many chars totally?

	while( (ch=getchar()) != EOF ) {
		count++;

		if(iscntrl(ch)){
			cch++;
		} else if(isspace(ch)){
			wch++;
		} else if(isdigit(ch)){
			dch++;
		} else if(islower(ch)){
			lch++;
		} else if(isupper(ch)){
			upch++;
		} else if(ispunct(ch)){
			pch++;
		} else if(! isspace(ch)){
			unch++;
		}
	}

	printf("the total number of chars is:\t\t %d\n", count);
	printf("the percent of control chars is:\t %.2f\n", cch*1.0/count);
	printf("the percent of whitespace chars is:\t %.2f\n", wch*1.0/count);
	printf("the percent of digital chars is:\t %.2f\n", dch*1.0/count);
	printf("the percent of lowercase chars is:\t %.2f\n", lch*1.0/count);
	printf("the percent of uppercase chars is:\t %.2f\n", upch*1.0/count);
	printf("the percent of punctuation chars is:\t %.2f\n", pch*1.0/count);
	printf("the percent of unprintable chars is:\t %.2f\n", unch*1.0/count);

	return 0;
}

