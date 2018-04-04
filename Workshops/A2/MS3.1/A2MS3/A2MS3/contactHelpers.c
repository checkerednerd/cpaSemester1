/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-27
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
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

// getIntInRange:
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

// yes:
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

// menu:
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

// ContactManagerSystem:
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

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int val)
{
	
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact[], int val)
{

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact[], int val)
{

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact[], int val)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact[], int val)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact[], int val)
{

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact[], int val)
{

}