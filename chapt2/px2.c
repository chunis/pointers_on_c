#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int ch;
	int brace = 0;

	while((ch = getchar()) != EOF){
		switch(ch){
			case '{':
				brace++;
				break;
			case '}':
				if(brace <= 0){
					printf("Error, no '{' for '}'.\n");
					return -1;
				}

				brace--;
				break;
			default:
				break;
		}
	}

	if(brace > 0){
		printf("Error, too many '{'.\n");
		return -1;
	}


	return 0;
}
