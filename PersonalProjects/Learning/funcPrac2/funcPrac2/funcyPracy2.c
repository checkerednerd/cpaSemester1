/*Ron Vincent
*2018-02-28
*supplies a value to be quadrupled
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"quadrupler.c"

int quadrupler(int);

int main(void) {
	int value, answer;

	do {
	printf("Enter a value to quadruple: ");
	scanf("%d", &value);

	if (value > 0) {
		answer = quadrupler(value);
		printf("%d quadrupled is %d.\n", value, answer);
	}

	} while (value != 0);
	
	return 0;
}