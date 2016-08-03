#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// check by index
int array_check(void)
{
	char buffer[SIZE] = "beautifullufituaeb";
	int front, rear;

	front = 0;
	rear = strlen(buffer) - 1;
	while(front < rear){
		if(buffer[front] != buffer[rear])
			break;

		front += 1;
		rear -= 1;
	}

	if(front >= rear){
		printf("It is a palindrome!\n");
	}

	return 0;
}

// check by pointers
int pointer_check(void)
{
	char *buffer = "beautifullufituaeb";
	char *front, *rear;

	front = buffer;
	rear = buffer + (strlen(buffer)-1);

	while(front < rear){
		if(*buffer != *buffer)
			break;

		front++;
		rear--;
	}

	if(front >= rear){
		printf("It is a palindrome!\n");
	}

	return 0;
}

int main(int argc, char *argv[])
{
	array_check();
	pointer_check();

	return 0;
}
