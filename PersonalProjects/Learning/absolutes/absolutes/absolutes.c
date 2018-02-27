/*Ron Vincent
*2018-02-27
*A simple program to practice writing an absolute.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h> //must be included for abs function

int main(void) {
	int neg;
	
	printf("Enter a negative integer: ");
	scanf("%d", &neg);

	printf("Absolute value of %d is %d.\n", neg, abs(neg));

	return 0;
}