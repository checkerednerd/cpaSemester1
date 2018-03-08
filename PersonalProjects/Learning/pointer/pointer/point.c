/*Working With Pointers
point.c
*/

#include<stdio.h>

int  main(void) {
	int y = 8;
	int *z = &y;

	printf("%d\n", *z);

	*z = 12; //change value at pointer z to 12

	printf("%d\n", y);

	return 0;
}