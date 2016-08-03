/*
 * Demonstrate the construction and destruction of struct-list
 * and the usage of malloc()/free().
 *
 * This is another solution to Exercise 11.4, by change the usage of pointers
 * in insert_values() compare to px4.c.
 * Please refer to book in chapter 12, program 12.3 for more explains.
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
	struct Node *m, *p;

	p = *s;
	while((p=*s)!=NULL && p->i < value){
		s = &p->next;
	}

	m = (struct Node *)malloc(sizeof(struct Node));
	if(m == NULL)
		return;

	m->i = value;
	m->next = p;
	*s = m;
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

