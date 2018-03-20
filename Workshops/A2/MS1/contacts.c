/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-20
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

char choice = ' ';

void clear(void) { //empties the input buffer when called
	while (getchar() != '\n')
		;
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name * contactName) {

	printf("Please enter the contact's first name: ");
	scanf("%s", contactName->firstName);

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", contactName->middleInitial);
	}
	choice = ' '; //clear choice for future use

	printf("Please enter the contact's last name: ");
	scanf("%s", contactName->lastName);

	return;
}

// getAddress:
void getAddress(struct Address * contactAddress) {

	printf("Please enter the contact's street number: ");
	scanf("%d", &contactAddress->streetNumber);

	clear(); //clear input buffer for whitespace
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", contactAddress->street); //reads text until new line (overrides default until whitespace)

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter an apartment number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contactAddress->apartmentNumber);
	}
	choice = ' '; //clear choice for future use

	clear(); //clear input buffer for whitespace
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", contactAddress->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%s", contactAddress->city);

	return;
}

// getNumbers:
void getNumbers(struct Numbers * contactNumbers) {

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a cell phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", contactNumbers->cell);
	}
	choice = ' '; //clear choice for future use

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", contactNumbers->home);
	}
	choice = ' ';

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a business phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", contactNumbers->business);
	}
	choice = ' ';

	return;
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact) {
	
}