// Name: Ron Vincent
// Student Number: 039567078
// Email: rmvincent@myseneca.ca
// Section: K
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#define NUMS 3

#include<stdio.h>

int main(void) {
	int i = 0;
	int high, low;
	int total = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	while (i < NUMS) {
		while (i < NUMS) { //get values for high/low per day
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");

			if (low > -41 && high < 41 && low < high) { //checking for correct input
				total += high;
				total += low;
				i++;
			}
			else
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
		}
	}

	printf("The average (mean) temperature was: %.2lf\n", (double)total / 6);

	return 0;
}