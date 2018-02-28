/*Ron Vincent
*2018-02-28
*Simple program to make and call a function
*function takes a value supplied by main and multiplies it by 4
*exits when the user enters 0
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int quadrupler(int val) { //quadruples argument supplied at val
	int result;

	result = val * 4;

	return result;
}

int main(void) {
	int value;
	int answer;

	do {
		printf("Enter a value to quadruple: ");
		scanf("%d", &value);

		if (value > 0) {
			answer = quadrupler(value); //value is supplied as an argument to quadrupler function, result is stored in answer
			printf("%d quadrupled is %d.\n", value, answer);
		}
	} while (value != 0);

	return 0;
}