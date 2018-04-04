/*
practice string functions on array of structs
models some of the functionality of A2M4
*/

#define _CRT_SECURE_NO_WARNINGS
#define RECORDSIZE 4

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Names {
	char first[21];
	char last[21];
};

struct Numbers {
	char cell[11];
	char home[11];
};

struct Records {
	struct Names full;
	struct Numbers numbers;
};

int main(void) {
	int i = 0;
	int compareTo = 0;
	char firstNames[41] = "";

	printf("Here we go!\n");

	struct Records recordList[] = { //creates array of structures called recordList
		{ { "RJ", "Vincent" },
	{ "1112223333", "2223334444" } },
	{
		{ "Zaria", "Pucknell" },
	{ "4445556666", "7778889999" } },
	{
		{ "Ronny", "Slamboni" },
	{ "1112223333", "5556669999" } },
	{
		{ "Zimmy", "Golgamiet" },
	{ "4445556666", "8885554444" } },
	};

	printf("%s\n", recordList[0].full.first); //should print Ron
	printf("%s\n", recordList[1].full.first); //should print Zaria

	//practice string functions
	printf("%d\n", strlen(recordList[0].full.last)); //should print length of Vincent, 7

	for (i = 0; i < RECORDSIZE; i++) {
		strcat(firstNames, recordList[i].full.first);
	}

	printf("Both first names are: %s\n", firstNames);

	for (compareTo = 0; compareTo < RECORDSIZE; compareTo++) { //iterates the compareTo to compare i to every compareTo
		if (strcmp(recordList[i].numbers.cell, recordList[compareTo].numbers.cell) == 0) { //only prints a match if it didn't match itself
			if (i != compareTo) {
				printf("%s's cell phone number matched %s's.\n", recordList[i].full.first, recordList[compareTo].full.first);
			}
		}
	}

	return 0;
}