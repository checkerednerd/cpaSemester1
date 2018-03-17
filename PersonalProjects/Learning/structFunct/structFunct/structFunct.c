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

	switcheroo(student1);
	return 0;
}

void switcheroo(struct fullName student1) { //takes the student1 structure and outputs the data in reverse order
	putchar('\n');

	printf("GIVE EM THE OL' SWITCHEROO!\n");
	printf("%s doing is %s %s\n", student1.status, student1.last, student1.first);
	return;
}