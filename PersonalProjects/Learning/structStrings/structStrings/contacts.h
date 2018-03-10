/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-06
----------------------------------------------
Assignment: 1
Milestone:  1
---------------------------------------------- */

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	char street[40];
	int apartmentNumber;
	char postalCode[7];
	char city[40];
};


// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[20];
	char home[20];
	char business[20];
};