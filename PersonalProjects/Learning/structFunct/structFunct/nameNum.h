/*Holds a full name and a number in two seperate structures
*/

struct fullName {
	char first[21];
	char last[21];
	char status[21];
};

struct Number {
	int numOne;
	int numTwo;
	int numThree;
};

//declared prototype
void switcheroo(struct fullName student1); //function prototype. WITHOUT THIS, THIS FILE DOESN'T KNOW ABOUT THE SWITCHEROO FUNCTION
//THEREFORE CANNOT SEND IT THE DATA FROM student1