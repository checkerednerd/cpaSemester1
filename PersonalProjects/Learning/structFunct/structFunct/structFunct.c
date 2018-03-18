/*populates nameNum.h with values
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"nameNum.h"

//did not declare prototype here

int main(void) {
	struct fullName student1 = { {' '} };
	struct fullName student2 = { {' '} };
	struct Number num1 = { 0 };
	struct Number num2 = { 0 };

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
	printf("First name of student 2 was: \n");


	return 0;
}