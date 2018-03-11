/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-11
----------------------------------------------
Assignment: 1
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

void clear(void) { //empties the input buffer when called
	while (getchar() != '\n')
		;
}

int main(void)
{
	// Declare variables here:
	struct Name fullName = { {' '}, {' '}, {' '} };
	struct Address fullAddr = { {0}, {' '}, {0}, {' '}, {' '} };
	struct Numbers phoneNum = { {' '}, {' '}, {' '} };

	char choice = ' ';
	int streetNum, aptNum;
	int hasMid = 0;
	int hasApt = 0;
	int hasCell = 0;
	int hasHome = 0;
	int hasBus = 0;

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%s", fullName.firstName);


	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a middle initial(s)? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", fullName.middleInitial);
		hasMid = 1;
	}
	choice = ' '; //clear choice for future use

	printf("Please enter the contact's last name: ");
	scanf("%s", fullName.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &streetNum);
	fullAddr.streetNumber = streetNum;

	printf("Please enter the contact's street name: "); //NEED TO ADJUST FOR SPACES
	scanf("%s", fullAddr.street);

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter an apartment number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &aptNum);
		fullAddr.apartmentNumber = aptNum;
		hasApt = 1;
	}
	choice = ' '; //clear choice for future use

	printf("Please enter the contact's postal code: "); //NEED TO ADJUST FOR SPACES
	scanf("%s", fullAddr.postalCode);
	clear(); //clear input buffer for spaces

	printf("Please enter the contact's city: ");
	scanf("%s", fullAddr.city);

	// Contact Numbers Input:

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear(); //clear input buffer
		printf("Do you want to enter a cell phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", phoneNum.cell);
		hasCell = 1;
	}
	choice = ' '; //clear choice for future use

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a home phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", phoneNum.home);
		hasHome = 1;
	}
	choice = ' ';

	while (choice != 'n' && choice != 'y' && choice != 'N' && choice != 'Y') {
		clear();
		printf("Do you want to enter a business phone number? (y or n): ");
		choice = getchar();
	}

	if (choice == 'y' || choice == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", phoneNum.business);
		hasBus = 1;
	}
	choice = ' ';

	// Display Contact Summary Details
	putchar('\n');
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", fullName.firstName);

	if (hasMid == 1) {
		printf("Middle initial(s): %s\n", fullName.middleInitial);
	}
	
	printf("Last name: %s\n", fullName.lastName);
	putchar('\n');

	printf("Address Details\n");
	printf("Street number: %d\n", fullAddr.streetNumber);
	printf("Street name: %s\n", fullAddr.street);

	if (hasApt == 1) {
		printf("Apartment: %d\n", fullAddr.apartmentNumber);
	}

	printf("Postal code: %s\n", fullAddr.postalCode);
	printf("City: %s\n", fullAddr.city);
	putchar('\n');

	printf("Phone Numbers:\n");
	if (hasCell == 1) {
		printf("Cell phone number: %s\n", phoneNum.cell);
	}
	if (hasHome == 1) {
		printf("Home phone number: %s\n", phoneNum.home);
	}
	if (hasBus == 1) {
		printf("Business phone number: %s\n", phoneNum.business);
	}
	putchar('\n');

	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");


	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/