/*
 * Translate numbers into English words
 *
 * Chunis Deng @ 2009.11.10
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1024

char *nums[] = {
	"ZERO ",		// 0
	"ONE ",
	"TWO ",
	"THREE ",
	"FOUR ",
	"FIVE ",
	"SIX ",
	"SEVEN ",
	"EIGHT ",
	"NINE ",
	"TEN ",
	"ELEVEN ",	// 11
	"TWELVE ",
	"THIRTEEN ",
	"FOURTEEN ",
	"FIFTEEN ",
	"SIXTEEN ",
	"SEVENTEEN ",
	"EIGHTEEN ",
	"NINETEEN ",	// 19
	"TWENTY ",	// 18+2
	"THIRTY ",	// 18+3
	"FOURTY ",
	"FIFTY ",
	"SIXTY ",
	"SEVENTY ",
	"EIGHTY ",
	"NINETY ",	// 18+9
	"HUNDRED ",	// 28
	"THOUSAND ",	// 29
	"MILLION ",	// 30
	"BILLION "	// 31
};


// translate integer xxx to chars, make sure the integer is less than 1000
void written_smallnum(unsigned int amt, char *p)
{
	int hnd = amt / 100;
	int left = amt % 100;
	//printf("hnd: %d, left: %d\n", hnd, left);

	// process x hundreds
	if(hnd > 0){
		printf("nums[hnd]: %s\n", nums[hnd]);
		strcat(p, nums[hnd]);
		strcat(p, nums[28]);
	}

	if(left <= 20){
		printf("nums[left]: %s\n", nums[left]);
		strcat(p, nums[left]);
	} else {
		strcat(p, nums[18+left/10]);
		strcat(p, nums[left%10]);
	}
}

// make sure the buffer is big enough, or strcat will make things strange.
// also, I'm not sure if my understand to express numbers is right.
void written_amount(unsigned int amount, char *buffer)
{
	if(amount > 1000000000){
		written_smallnum(amount/1000000000, buffer);
		strcat(buffer, nums[31]);
		amount %= 1000000000;
	}

	if(amount > 1000000){
		written_smallnum(amount/1000000, buffer);
		strcat(buffer, nums[30]);
		amount %= 1000000;
	}

	if(amount > 1000){
		written_smallnum(amount/1000, buffer);
		strcat(buffer, nums[29]);
		amount %= 1000;
	}

	written_smallnum(amount, buffer);
}

int main(int argc, char *argv[])
{
	int amnt = 16312;
	//int amnt = 6716312;
	//int amnt = 16372;
	char buf[MAXCHAR] = "";

	written_amount(amnt, buf);
	printf("buf: %s\n", buf);

	return 0;
}
