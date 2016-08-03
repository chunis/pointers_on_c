/*
 * Demonstrate the construction and destruction of struct-list
 * and the usage of malloc()/free().
 *
 * Chunis Deng @ 2009.11.30
 */
 
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int i;
	struct Node *next;
};

// insert value to the list by ascending order
void insert_values(struct Node **s, int value)
{
	struct Node *m, *q, *p;

	p = *s;
	q = NULL;
	while(p!=NULL && p->i < value){
		q = p;
		p = p->next;
	}

	m = (struct Node *)malloc(sizeof(struct Node));
	if(m == NULL)
		return;

	m->i = value;
	m->next = p;
	if(q == NULL)
		*s = m;
	else
		q->next = m;
}

int main(int argc, char *argv[])
{
	struct Node *head = NULL;
	struct Node *p;

	insert_values(&head, 5);
	insert_values(&head, 15);
	insert_values(&head, 10);

	// print values and free the memory
	p = head;
	while(head != NULL){
		printf("%d ", head->i);
		p = head;
		head = head->next;
		free(p);
	}
	printf("\n");

	return 0;
}

