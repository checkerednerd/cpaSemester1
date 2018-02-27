/* Ron Vincent
* 2018-02-27
* Build a simple RNG program
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void) {
	int i, input;
	time_t t;

	//Initialize RNG
	srand((unsigned)time(&t));

	//Print 5 numbers between 1 and input;
	printf("Let's calculate 5 numbers between 1 and ");
	scanf("%d", &input);

	for (i = 0; i < 5; i++) {
		printf("%d\n", rand() % input);
	}

	return 0;
}