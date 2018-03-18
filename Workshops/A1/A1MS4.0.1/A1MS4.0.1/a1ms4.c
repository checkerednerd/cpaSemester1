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

int main(void)
{
	// Declare variables here:
	struct Name fullName = { { ' ' },{ ' ' },{ ' ' } };
	struct Address fullAddr = { 0,{ ' ' }, 0,{ ' ' },{ ' ' } };
	struct Numbers phoneNum = { { ' ' },{ ' ' },{ ' ' } };

	char choice = ' ';

	// Create a variable of type Contact and call it something self-describing like "contact"
	// - HINT: Be sure to initialize the values to 0 and empty C strings
	//struct Contact contact = {};

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Call the Contact function getName to store the values for the Name member
	getName(&fullName); //sends the address of fullName to the pointer argument for the getName function in contacts.c
	printf("%s %s %s\n", fullName.firstName, fullName.middleInitial, fullName.lastName);
	
	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&fullAddr);
	printf("%d\n%s\n%d\n%s\n%s\n", fullAddr.streetNumber, fullAddr.street, fullAddr.apartmentNumber, fullAddr.postalCode, fullAddr.city);
	
	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&phoneNum);
	printf("%s\n%s\n%s\n", phoneNum.cell, phoneNum.home, phoneNum.business);

	// Display Contact summary details


	// Display Completion Message
	printf("Structure test for Contact using functions done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Wilma
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Dino
Please enter the contact's last name: Flintstone
Please enter the contact's street number: 100
Please enter the contact's street name: Bedrock
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 14
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: Markham
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 647-505-5555
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 905-222-3333
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-491-5050

Contact Details
---------------
Name Details
First name: Wilma
Middle initial(s): Dino
Last name: Flintstone

Address Details
Street number: 100
Street name: Bedrock
Apartment: 14
Postal code: Z8Z 7R7
City: Markham

Phone Numbers:
Cell phone number: 647-505-5555
Home phone number: 905-222-3333
Business phone number: 416-491-5050

Structure test for Contact using functions done!
*/