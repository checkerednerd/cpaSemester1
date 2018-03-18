#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"nameNum.h"

void switcheroo(struct fullName * student1) { //takes the student1 structure and outputs the data in reverse order
	putchar('\n');

	printf("GIVE EM THE OL' SWITCHEROO!\n");
	printf("%s doing is %s %s\n", student1->status, student1->last, student1->first);
	return;
}

void fillSecond(struct fullName * student1, struct theDeal * student2) {
	putchar('\n');

	printf("Let's fill student 2...\n");

	scanf(student1->first, &student2->firstSwitch);
}