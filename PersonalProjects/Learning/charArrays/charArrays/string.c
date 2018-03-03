/*Ron Vincent
2018-03-03
string.c
Practice declaring, initializing, and using character arrays
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void) {
	int i;
	char name[31] = "Ron Vincent"; //30 chars plus 1 char for the null terminator
	char status[31]; //blank string


	//populate character array status with contents of keyboard input
	scanf("%30s", status); //no "&" before the status because the name of an array is its address
	//records 30 character maximum to status

	for (i = 0; name[i] != '\0'; i++) { //will print until the value at letter is null byte
		printf("%c", name[i]);
	}
	
	printf(" is ");
	
	for (i = 0; status[i] != '\0'; i++) { //will print until the value at letter is null byte
		printf("%c", status[i]);
	}
	printf(".\n");

	/*THE SHORT WAY OF PRINTING STRINGS*/

	printf("%s is %s.\n", name, status);

	return 0;
}