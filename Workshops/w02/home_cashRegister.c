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
	int loonies, quarters, dimes, nickels, pennies, remainder;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amtDue); //amtDue is taken in as a double

	printf("GST: 1.13\n");
	amtDue = (amtDue * 1.13) + .005;
	printf("Balance owing: $%.2lf\n", amtDue); //print amtDue with tax

	loonies = amtDue; //decimal portion will be lost due to truncation
	printf("Loonies required: %d", loonies);
	amtDue -= loonies;
	printf(", balance owing $%.2lf\n", (amtDue));

	remainder = (int)(amtDue * 100); //casts the remainder as an integer

	if (loonies != 0)
		remainder = remainder % (loonies * 100);

	quarters = remainder / 25;
	if (quarters != 0) //check against 'divide by 0' if no quarters
		remainder = remainder % (quarters * 25);

	printf("Quarters required: %d", quarters);
	printf(", balance owing $%1.2f\n", (float)remainder / 100); //outputs int value in form of 2 decimal place float

	dimes = remainder / 10;
	if (dimes != 0)
		remainder = remainder % (dimes * 10);

	printf("Dimes required: %d", dimes);
	printf(", balance owing $%1.2f\n", (float)remainder / 100);

	nickels = remainder / 5;
	if (nickels != 0)
		remainder = remainder % (nickels * 5);

	printf("Nickels required: %d", nickels);
	printf(", balance owing $%1.2f\n", (float)remainder / 100);

	pennies = remainder;
	if (pennies != 0)
		remainder = remainder % (pennies);

	printf("Pennies required: %d", pennies);
	printf(", balance owing $%1.2f\n", (float)remainder / 100);

	return 0;
}