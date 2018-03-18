/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-11
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

void clear(void) { //empties the input buffer when called
	while (getchar() != '\n')
		;
}

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name * name) { //currently reads from Name structure, we want to change this so it puts values into Name structure
	
	char choice = ' '; 

	printf("Please enter the contact's first name: ");
	scanf("%s", name->firstName);


	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", name->middleInitial);
	}
	choice = ' '; //clear choice for future use

	printf("Please enter the contact's last name: ");
	scanf("%s", name->lastName);
	
	return;
}



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address * address) {
	char choice = ' ';

	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);

	clear(); //clear input buffer for whitespace
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", address->street); //reads text until new line (overrides default until whitespace)

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter an apartment number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &address->apartmentNumber);
	}
	choice = ' '; //clear choice for future use

	clear(); //clear input buffer for whitespace
	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%s", address->city);

	return;
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers * numbers) {
	char choice = ' ';
	
	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a cell phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", numbers->cell);
	}
	choice = ' '; //clear choice for future use

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", numbers->home);
	}
	choice = ' ';

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a business phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", numbers->business);
	}
	choice = ' ';

	return;
}
