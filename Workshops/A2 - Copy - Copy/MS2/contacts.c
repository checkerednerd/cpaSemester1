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

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"



// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

int choice = ' ';

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name * contactName) {

	printf("Please enter the contact's first name: ");
	scanf("%s", contactName->firstName);

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clearKeyboard(); //clear input buffer
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

	clearKeyboard(); //clear input buffer for whitespace
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", contactAddress->street); //reads text until new line (overrides default until whitespace)

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clearKeyboard(); //clear input buffer
		printf("Do you want to enter an apartment number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contactAddress->apartmentNumber);
	}
	choice = ' '; //clear choice for future use

	clearKeyboard(); //clear input buffer for whitespace
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", contactAddress->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%s", contactAddress->city);

	return;
}


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers * contactNumbers) {

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clearKeyboard(); //clear input buffer
		printf("Do you want to enter a cell phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", contactNumbers->cell);
	}
	choice = ' '; //clear choice for future use

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clearKeyboard();
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", contactNumbers->home);
	}
	choice = ' ';

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clearKeyboard();
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


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(struct Contact * contact) {

}