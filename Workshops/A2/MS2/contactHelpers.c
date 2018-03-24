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
	while (getchar() != '\n'); // empty execution code block on purpose
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
		scanf(" %d%c", &value, &NL); //validates that the first value is an integer

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
	char NL = ' ';
	int valid = 0;

	do {
		scanf(" %c%c", &choice, &NL); //first space ignores whitespace characters

		if (NL == '\n') { //first check if the second character is a newline
			if (choice == 'Y' || choice == 'N' || choice == 'y' || choice == 'n') { 
				valid = 1; //choice is valid
				if (choice == 'Y' || choice == 'y') {
					return 1;
				}
				else if (choice == 'N' || choice == 'n') {
					return 0;
				}
			}
			else {
				//used to have clearKeyboard() here, but caused some newline problems when accepting incorrect input
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
				valid = 0;
			}
		}
		else { //if second character not a new line, clears the keyboard, prints error, reprompts
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			valid = 0;
		}
	} while (valid == 0); //runs while the valid flag is false

	return 0;
}

// menu function definition goes here:
int menu(void)
{
	int menuChoice = -1;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	putchar('\n');
	printf("Select an option:> ");

	while (menuChoice < 0 || menuChoice > 6) {
		scanf("%d", &menuChoice);

		if (menuChoice < 0 || menuChoice > 6) {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	}
	return menuChoice;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void)
{
	int menuChoice = -1;
	int quitChoice = -1;

	while (menuChoice != 0) {//while menuChoice is not the exit (case 0)...
		menuChoice = menu(); //...get another menu choice, calls the menu() so it always shows once
		clearKeyboard();

		switch (menuChoice) {
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			putchar('\n');
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			quitChoice = yes();

			if (quitChoice == 1) {
				printf("\nContact Management System: terminated\n");
				break;
			}
			else if (quitChoice == 0) {
				menuChoice = -1;
				putchar('\n');
			}
		}
	}
}