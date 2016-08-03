#include <stdio.h>
#include <stdlib.h>

float mysqrt(float n)
{
	float ret0 = 1;
	float ret1 = 0;
	float i = 1;

	while(ret0 - ret1 > 0.01) {
		ret0 = (i + n/i)/2;
		i = ret0;
		ret1 = (i + n/i)/2;
	}

	printf("ret: %f\n", ret1);
	return ret1;
}

int main(int argc, char *argv[])
{
	float num;

	printf("Input a number: ");
	scanf("%f", &num);

	if(num < 0){
		printf("Number should be big than 0, try it again!\n");
		return -1;
	}

	printf("sqrt(%f) = %f\n", num, mysqrt(num));

	return 0;
}

