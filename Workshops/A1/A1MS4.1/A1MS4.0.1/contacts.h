/* -------------------------------------------
Name: Ron Vincent
Student number: 039567078
Email: rmvincent@myseneca.ca
Section: K
Date: 2018-03-18
----------------------------------------------
Assignment: 1
Milestone:  4
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
	char postalCode[8];
	char city[40];
};


// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[20];
	char home[20];
	char business[20];
};

// Structure type Contact declaration
// Place your code here... (from Milestone 3)
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name * contactName);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address * contactAddress);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers * contactNumbers);
