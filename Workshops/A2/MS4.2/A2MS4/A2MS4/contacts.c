/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-04-07
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

int choice = -1;
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * contactName) {

	printf("Please enter the contact's first name: ");
	scanf("%[^\n]s", contactName->firstName);

	while (choice != 1 && choice != 0) {
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		choice = yes();
	}

	if (choice == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", contactName->middleInitial);
		clearKeyboard(); //needed to add to deal with hangups on two word inputs
	}
	else {
		*contactName->middleInitial = '\0'; //added for MS4, when updating, will overwrite existing optional fields with \0
	}
	choice = -1; //clear choice for future use

	printf("Please enter the contact's last name: ");
	scanf("%[^\n]s", contactName->lastName);

	return;
}

// getAddress:
void getAddress(struct Address * contactAddress) {

	printf("Please enter the contact's street number: ");
	contactAddress->streetNumber = getInt();

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", contactAddress->street); //reads text until new line (overrides default until whitespace)

	while (choice != 1 && choice != 0) {
		printf("Do you want to enter an apartment number? (y or n): ");
		choice = yes();
	}

	if (choice == 1) {
		printf("Please enter the contact's apartment number: ");
		contactAddress->apartmentNumber = getInt();
	}
	else {
		contactAddress->apartmentNumber = '\0'; //added for MS4, when updating, will overwrite existing optional fields with \0
	}
	choice = -1; //clear choice for future use

	printf("Please enter the contact's postal code: ");
	scanf("%[^\n]s", contactAddress->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%[^\n]s", contactAddress->city);
	clearKeyboard();

	return;
}

// getNumbers:
void getNumbers(struct Numbers * contactNumbers) {
	char examplePhone[11];

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(examplePhone);
	strcpy(contactNumbers->cell, examplePhone); //forgot to add these in MS3, was validating, but not storing anywhere

	while (choice != 1 && choice != 0) {
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = yes();
	}

	if (choice == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(examplePhone);
		strcpy(contactNumbers->home, examplePhone);
	}
	else {
		*contactNumbers->home = '\0'; //added for MS4, when updating, will overwrite existing optional fields with \0
	}
	choice = -1;

	while (choice != 1 && choice != 0) {
		printf("Do you want to enter a business phone number? (y or n): ");
		choice = yes();
	}

	if (choice == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(examplePhone);
		strcpy(contactNumbers->business, examplePhone);
	}
	else {
		*contactNumbers->business = '\0'; //added for MS4, when updating, will overwrite existing optional fields with \0
	}
	choice = -1;

	return;
}

// getContact:
void getContact(struct Contact * contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}