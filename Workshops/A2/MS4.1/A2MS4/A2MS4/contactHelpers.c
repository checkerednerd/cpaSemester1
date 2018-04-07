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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
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

	struct Contact contactList[MAXCONTACTS] = { //create an array of structs, an array of Contact structurs called contactList
		{ { "Rick", { '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	{
		{ "Sasha", { '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};


	while (menuChoice != 0) {//while menuChoice is not the exit (case 0)...
		menuChoice = menu(); //...get another menu choice, calls the menu() so it always shows once
		clearKeyboard();

		switch (menuChoice) {
		case 1:
			putchar('\n');
			displayContacts(contactList, MAXCONTACTS);
			pause();
			putchar('\n');
			break;
		case 2:
			putchar('\n');
			addContact(contactList, MAXCONTACTS);
			pause();
			putchar('\n');
			break;
		case 3:
			putchar('\n');
			updateContact(contactList, MAXCONTACTS);
			pause();
			putchar('\n');
			break;
		case 4:
			putchar('\n');
			deleteContact(contactList, MAXCONTACTS);
			pause();
			putchar('\n');
			break;
		case 5:
			putchar('\n');
			searchContacts(contactList, MAXCONTACTS);
			pause();
			putchar('\n');
			break;
		case 6:
			putchar('\n');
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
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%s", telNum); //changed %10s to %s, otherwise only validated less than 10, more than 10 always went through
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contactList[], int size, const char cellNum[]) //an array of structs
{
	int i = 0;
	int matchIndex = -1;

	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contactList[i].numbers.cell) == 0) {
			matchIndex = i;
		}

	}
	return matchIndex;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

	return;
}

// displayContactFooter
void displayContactFooter(int size)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d", size);
	printf("\n\n");
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	if (strlen(contact->name.middleInitial) > 0) { //if there is a middle initial

		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
		printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

		if (contact->address.apartmentNumber > 0) { //if there is an apartment number
			printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
		}
		else { //if no apartment number
			printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
		}
	}

	else { //if there is no middle initial

		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
		printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

		if (contact->address.apartmentNumber > 0) { //if there is an apartment number
			printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
		}
		else { //if no apartment number
			printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
		}
	}
}

// displayContacts:
void displayContacts(const struct Contact contactList[], int size) //an array of structs
{
	int i = 0;
	int validContacts = 0;

	displayContactHeader();
	//put the rest
	for (i = 0; i < size; i++) { //for each contactList entry up until size
		if (strlen(contactList[i].numbers.cell) > 0) { //validate for proper cell phone number
			displayContact(&contactList[i]);
			validContacts++;
		}
	}
	displayContactFooter(validContacts);
}

// searchContacts:
void searchContacts(const struct Contact contactList[], int size) //an array of structs
{
	char numSearch[50];
	int matchIndex = -1;

	printf("Enter the cell number for the contact: ");

	getTenDigitPhone(numSearch); //does not return anything, just holds you up until you enter a valid entry
	matchIndex = findContactIndex(contactList, MAXCONTACTS, numSearch);
	putchar('\n');

	if (matchIndex != -1) {
		displayContact(&contactList[matchIndex]);
		putchar('\n');
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
		putchar('\n');

	}

}

// addContact:
void addContact(struct Contact contactList[], int size) //an array of structs
{
	int i;
	int emptyIndex = -1;

	for (i = 0; i < size; i++) {
		if (strlen(contactList[i].numbers.cell) == 0) { //search if an empty string
			emptyIndex = i;
		}
	}
	if (emptyIndex == -1) {
		printf("*** ERROR: The contact list is full! ***\n");
	}
	else {
		getContact(&contactList[emptyIndex]);
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
void updateContact(struct Contact contactList[], int size) //an array of structs
{
	char numSearch[50];
	int choice = 0;
	int matchIndex = -1;

	printf("Enter the cell number for the contact: ");

	getTenDigitPhone(numSearch); //does not return anything, just holds you up until you enter a valid entry
	matchIndex = findContactIndex(contactList, MAXCONTACTS, numSearch);

	if (matchIndex != -1) {
		printf("\nContact found:\n");
		displayContact(&contactList[matchIndex]);
		putchar('\n');

		printf("Do you want to update the name? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getName(&contactList[matchIndex].name);
		}

		printf("Do you want to update the address? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getAddress(&contactList[matchIndex].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getNumbers(&contactList[matchIndex].numbers);
		}
		printf("--- Contact Updated! ---\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contactList[], int size) //an array of structs
{
	char numSearch[50];
	int matchIndex = -1;
	int choice = 0;

	printf("Enter the cell number for the contact: ");

	getTenDigitPhone(numSearch); //does not return anything, just holds you up until you enter a valid entry
	matchIndex = findContactIndex(contactList, MAXCONTACTS, numSearch);
	putchar('\n');

	if (matchIndex != -1) {
		printf("Contact found:\n");
		displayContact(&contactList[matchIndex]);
		putchar('\n');

		printf("CONFIRM: Delete this contact? (y or n): ");
		choice = yes();

		if (choice == 1) {
			*contactList[matchIndex].numbers.cell = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
		putchar('\n');
	}
}

// sortContacts:
void sortContacts(struct Contact contactList[], int size) //an array of structs
{
	//optional
}