/*populates nameNum.h with values
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"nameNum.h"

//did not declare prototype here

int main(void) {
	struct fullName student1 = { {' '} };
	struct theDeal student2 = { {' '} };

	printf("Name?\n");
	printf("First: ");
	scanf("%s", student1.first);
	printf("Last: ");
	scanf("%s", student1.last);
	
	printf("Status: ");
	scanf("%s", student1.status);

	printf("%s %s is doing %s\n", student1.first, student1.last, student1.status);

	switcheroo(&student1);

	printf("First name of student 1 was: %s\n", student1.first);
	printf("First name of student 2 was: %s\n", student2.firstSwitch);


	return 0;
}