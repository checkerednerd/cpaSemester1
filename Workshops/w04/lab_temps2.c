//--------------------------------------------------
// Name: Ron Vincent          
// Student Number: 039567078
// Email: rmvincent@myseneca.ca         
// Section: K
// Workshop: 4      
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Place your code below

int main(void) {
	int days;
	int highs[10];
	int lows[10];
	int i;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);

	while (days > 10 || days < 3) { //validate days is between 3 and 10
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}

	printf("\n");

	for (i = 0; i < days; i++) { //populate the arrays
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highs[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lows[i]);
	}

	printf("\n");

	printf("Day  Hi  Low\n"); //print output of arrays
	for (i = 0; i < days; i++) {
		printf("%d %4d %5d\n", i + 1, highs[i], lows[i]);
	}

	return 0;
}