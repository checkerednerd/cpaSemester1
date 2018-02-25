/*
Name:      Ron Vincent
Student#:  039567078
Section:   K
*/

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:

#include<stdio.h>

int main(void)
{
	double amtDue;
	int loonies, quarters;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amtDue); //amtDue is taken in as a double

	loonies = amtDue;
	printf("Loonies required: %d", loonies);
	amtDue -= loonies;
	printf(", balance owing $%.2lf\n", (amtDue));

	quarters = (amtDue * 100) / 25; //takes remaining amount, converts to whole number, find number of quarters

	printf("Quarters required: %d", quarters);
	printf(", balance owing $%.2lf\n", (amtDue - (quarters * 0.25))); // subtracts dollar value of quarters from remaining amount

	return 0;
}