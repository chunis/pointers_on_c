/*
 * fake array with arbitrary subindexes, with error checks.
 *
 * Chunis Deng @ 2009.11.20
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ROW 9
#define COL 3

int array_offset(int arrayinfo[], ...)
{
	va_list varg;
	int count;
	int hl, al;	// hl=(high-low+1), al=(argu-low)
	int col;	// the return value
	int *arrp = NULL;
	int *p = NULL;

	// test if the dimension is between 1 and 10
	count = arrayinfo[0];
	if(count < 1 || count > 10)
		return -1;

	// prepare storage space to save the variable arguments
	p = malloc(sizeof(int) * count);
	if(p == NULL)
		return -1;

	// the start of array space saved at arrp
	arrp = p;

	// save arguments now
	va_start(varg, arrayinfo);
	while(count-- > 0){
		*p++ = va_arg(varg, int);
	}
	va_end(varg);

	/*
	// print the arguments to check if we did it right
	p = arrp;
	for(count = arrayinfo[0]; count>0; count--)
		printf("%d\t", *p++);
	*/

	// check error arguments now
	for(count = 0; count < arrayinfo[0]; count++){
		if((arrayinfo[count*2+1] > arrayinfo[count*2 + 2]) ||
		   (arrayinfo[count*2+1] > arrp[count]))
			return -1;
	}

	// now we do the real business
	hl = 0;
	p = arrp+arrayinfo[0];
	col = 0;
	for(count=arrayinfo[0]; count > 0; count--){
		hl = arrayinfo[count*2] - arrayinfo[count*2-1] + 1;
		al = (*--p) - arrayinfo[count*2-1];
		col *= hl;
		col += al;
	}

	return col;
}

int main(int argc, char *argv[])
{
	int ret, i;
	int ar[7] = { 3, 4, 6, 1, 5, -3, 3 };
	int argu[ROW][COL] = {
				{ 4, 1, -3 },
				{ 5, 1, -3 },
				{ 6, 1, -3 },
				{ 4, 2, -3 },
				{ 4, 3, -3 },
				{ 4, 1, -2 },
				{ 4, 1, -1 },
				{ 5, 3, -1 },
				{ 6, 5, 3 } };
	int (*p)[COL];

	p = argu;
	for(i=0; i<ROW; i++){
		ret = array_offset(ar, (*p)[0], (*p)[1], (*p)[2]);
		printf("subindex: %d, %d, %d\t", (*p)[0], (*p)[1], (*p)[2]);
		printf("ret: %d\n", ret);
		p++;
	}

	return 0;
}

