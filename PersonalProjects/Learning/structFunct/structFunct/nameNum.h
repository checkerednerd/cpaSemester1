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

struct theDeal {
	struct fullName firstSwitch[21];
	struct fullName lastSwitch[21];
};

//declared prototype
void switcheroo(struct fullName *); //function prototype. WITHOUT THIS, THIS FILE DOESN'T KNOW ABOUT THE SWITCHEROO FUNCTION
//THEREFORE CANNOT SEND IT THE DATA FROM student1
void fillSecond(struct fullName *, struct theDeal *);