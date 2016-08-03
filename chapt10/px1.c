/*
 * Demonstrate struct in struct, with struct's initialition and other usage.
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>

struct PHONE {
	int section;
	int exchange;
	int station;
};

enum PN_TYPE { USING, CALL, PAY };

struct PHONE_RECORD {
	short year;
	short month;
	short day;
	short hour;
	short minute;
	short second;

	struct PHONE phone_num[3];
};

int main(int argc, char *argv[])
{
	struct PHONE_RECORD recode = {
			2009, 11, 28,
			10, 20, 30,
			{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } },
		};

	printf("recode.year: %d\n", recode.year);
	printf("recode.hour: %d\n", recode.hour);
	printf("phone[0].section: %d\n", recode.phone_num[USING].section);
	printf("phone[1].station: %d\n", recode.phone_num[CALL].station);

	// change member's value in struct
	recode.hour = 23;
	recode.phone_num[CALL].station = 20;

	printf("\n");
	printf("recode.year: %d\n", recode.year);
	printf("recode.hour: %d\n", recode.hour);
	printf("phone[0].section: %d\n", recode.phone_num[USING].section);
	printf("phone[1].station: %d\n", recode.phone_num[CALL].station);

	return 0;
}

