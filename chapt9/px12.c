/*
 * Generate the new key from a char-array argument
 *
 * Note: change 'main_px12' to 'main' to run the test
 *
 * Chunis Deng @ 2009.11.26
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int prepare_key(char *key)
{
	char chs[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *p, *q, *s;
	char ch;

	if(key == NULL || *key == '\0')
		return 0;

	s = key;
	for(p = key; *p != '\0'; p++){
		if(! isalpha(*p))	// not a char
			return 0;

		q = key;
		while(*q != toupper(*p) && q < p)
			q++;

		if(q >= p){	// *p doesn't appear yet
			ch = toupper(*p);
			chs[ch-'A'] = '-';	// make it not a char
			*s++ = ch;
		}
	}

	for(q=chs; *q; q++){
		if(*q != '-')
			*s++ = *q;
	}

	return 1;
}

static void test(char *key)
{
	int ret;

	ret = prepare_key(key);
	if(ret) {
		printf("key: %s\n", key);
	} else {
		printf("key '%s' error!\n", key);
	}
}

int main_px12(int argc, char *argv[])
{
	char str1[27] = "TRAILblazERS";
	char str2[27] = "TRAILbl,zERS";
	char str3[27] = "";
	char str4[27] = "eoji	k";
	char str5[27] = ",*@!%^&*(";

	test(str1);
	test(str2);
	test(str3);
	test(str4);
	test(str5);

	return 0;
}
