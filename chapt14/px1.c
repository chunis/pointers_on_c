/*
 * Demonstrate conditional express
 *
 * Chunis Deng @ 2009.11.27
 */

#include <stdio.h>
#include <stdlib.h>

//#define OPTION_DETAILED
//#define OPTION_LONG

void print_ledger_long(int x) { puts("in print_ledger_long()"); }
void print_ledger_detailed(int x) { puts("in print_ledger_detailed()"); }
void print_ledger_default(int x) { puts("in print_ledger_default()"); }
 
void print_ledger(int x)
{
#if defined(OPTION_LONG) || defined(OPTION_DETAILED)
#ifdef OPTION_LONG
	print_ledger_long(x);
#endif
#ifdef OPTION_DETAILED
	print_ledger_detailed(x);
#endif

#else
	print_ledger_default(x);
#endif	/* defined(OPTION_LONG) || defined(OPTION_DETAILED) */
}

int main(int argc, char *argv[])
{
	print_ledger(5);

	return 0;
}
