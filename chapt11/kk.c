#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int i;
	struct NODE *next;
};

int main(int argc, char *argv[])
{
	struct NODE a, b, c, *p;

	p = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	a.i = 5;
	b.i = 10;
	c.i = 15;

	while(p != NULL){
		printf("%d ", p->i);
		p = p->next;
	}
	printf("\n");

	return 0;
}

