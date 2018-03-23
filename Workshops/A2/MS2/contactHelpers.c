/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-25
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int value = 0;
	char NL = 'x';

	while (NL != '\n') {
		scanf("%d%c", &value, &NL); //validates that the first value is an integer
		
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int value = 0;

	while (value < min || value > max) {
		value = getInt();
		
		if (value < min || value > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	}
	return value;
}

// yes function definition goes here:
int yes(void)
{
	char choice = ' ';
	char NL = 'x';

	while ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' && NL != '\n') || NL != '\n') {
		scanf("%c%c", &choice, &NL);

		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}
	return 0;
}

// menu function definition goes here:
int menu(void)
{
	return 0;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void)
{

}