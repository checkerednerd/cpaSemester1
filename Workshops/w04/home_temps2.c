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
	int highest = -40;
	int lowest = 40;
	int highDay = 0;
	int lowDay = 0;
	int i;
	int total = 0;
	int dayRange = 0;

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

		if (highs[i] > highest) {
			highest = highs[i];
			highDay = i + 1;
		}

		if (lows[i] < lowest) {
			lowest = lows[i];
			lowDay = i + 1;
		}
	}

	printf("\nThe highest temperature was %d, on day %d\n", highest, highDay);
	printf("The lowest temperature was %d, on day %d\n\n", lowest, lowDay);

	while (dayRange >= 0) { // runs while dayRange is not negative
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &dayRange);
		printf("\n");

		while (dayRange > days || dayRange == 0) { // checks if dayRange is within the number of days
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &dayRange);
			printf("\n");
		}

		for (i = 0; i < dayRange; i++) {
			total += highs[i] + lows[i];
		}

		if (dayRange > 0) { //prevents printing result upon negative or zero input
			printf("The average temperature up to day %d is: %.2lf\n\n", dayRange, (double)total / (dayRange * 2)); //2 temperatures per day, therefore dayRange * 2
			total = 0; //reset total for future iterations of the loop
		}
	}

	printf("Goodbye!\n");

	return 0;
}