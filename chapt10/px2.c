/*
 * Demonstrate union and struct usage, and malloc()/free()
 *
 * Chunis Deng @ 2009.11.28
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cash {
	float sug_price;
	float sel_price;
	float sales_tax;
	float fee;
}Cashinfo;

typedef struct _lease {
	float sug_price;
	float sel_price;
	float doun_payment;
	float deposit;
	float mon_payment;
	int lease_term;
}Leaseinfo;

typedef struct _loan {
	float sug_price;
	float sel_price;
	float sales_tax;
	float fee;
	float doun_payment;
	int loan_duration;
	float interest_rate;
	float mon_payment;
	char bankname[21];
}Loaninfo;

typedef struct _recode {
	char name[21];
	char address[41];
	char mode[21];

	enum { CASH, LEASE, LOAN } type;
	union { 
		Cashinfo *csi;
		Leaseinfo *lsi;
		Loaninfo *lni;
	} info;
} RECORD;

int main(int argc, char *argv[])
{
	RECORD rec;
	Leaseinfo *p;
	
	// I'll show you how to initialize recode whose type is 'LEASE'
	strncpy(rec.name, "IBM", 20);
	strncpy(rec.address, "No. 4, WAS STREET", 40);
	strncpy(rec.mode, "automobile", 20);

	rec.type = LEASE;

	p = malloc(sizeof(Leaseinfo));
	if(p == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p->sug_price = 345.6;
	p->sel_price = 340.0;
	p->doun_payment = 4.4E12;
	p->deposit = 4.0E10;
	p->mon_payment = 400000;
	p->lease_term = 200;

	rec.info.lsi = p;

	printf("customer's name is: %s\n", rec.name);
	printf("actual selling price is: %.2f\n", rec.info.lsi->sel_price);
	printf("doun payment is: %.2f\n", rec.info.lsi->doun_payment);
	printf("monthly payment is: %.2f\n", rec.info.lsi->mon_payment);

	// don't forget free the memory got from malloc()!
	rec.info.lsi = NULL;
	free(p);

	return 0;
}

