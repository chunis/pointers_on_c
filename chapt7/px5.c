/*
 * Function do things like printf(), but very simplified compares to printf().
 *
 * Chunis Deng @ 2009.11.10
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_float(float n)
{
	printf("%f", n);
}

void print_integer(int n)
{
	printf("%d", n);
}

void myprintf(char *fmt, ...)
{
	va_list varg;
	char *p;

	va_start(varg, fmt);
	while(*fmt != '\0'){
		switch(*fmt){
			case '%':
				fmt++;
				if(*fmt == 'd'){
					print_integer(va_arg(varg, int));
				} else if(*fmt == 'f'){
					print_float(va_arg(varg, double));

				} else if(*fmt == 's'){	// TODO
					p = (char *)va_arg(varg, int);
					while(*p != '\0')
						putchar(*p++);
				} else if(*fmt == 'c'){
					putchar(va_arg(varg, int));
				} else if(*fmt == '%'){
					putchar('%');
				} else {
					myprintf("%s\n", "format error!");
					exit(-1);
				}

				fmt++;
				break;
			default:
				putchar(*fmt);
				fmt++;
				break;
		}
	}

	va_end(varg);
}

int main(int argc, char *argv[])
{
	char str = "test strings";
	float pi = 3.14159265;

	myprintf("%f\n", pi);	// test %f
	myprintf("%%%c\n", 'K');	// test %% and %c
	myprintf("The number is: %d\n", 19);	// test %d and other chars
	myprintf("%s\n", "hello");	// test %s

	myprintf("%z\n", "hello");	// test errors

	// comment above line to test this one, but it will fail. need improve
	myprintf("str = %s\n", str);	// test %s, but will fail!  )-:

	return 0;
}

