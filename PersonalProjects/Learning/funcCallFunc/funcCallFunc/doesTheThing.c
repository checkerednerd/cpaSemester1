/*one function to get the name
one function to get the */
#define _CRT_SECURE_NO_WARNINGS

#include "info.h"
#include <stdio.h>

/*BECAUSE we know that the only way to return multiple values with a function
is through pointers, consider the pointer contactName that we create below*/

/* Takes first name from user and sends it to the firstName member of 
*/
void getName(struct Name *contactName) { //Name type pointer contactName
	printf("Enter your first name: ");
	scanf("%s", contactName->FirstName);
	clear();

	printf("Enter your last name: ");
	scanf("%s", contactName->lastName);
	putchar('\n');
	clear();
}

void getJob(struct Job *contactJob) { //we named the pointer contactJob, it will receive an address to point to
	printf("What do you do for a living? ");
	scanf("%[^\n]s", contactJob->title);
	clear();

	printf("And whereabouts do you do that? ");
	scanf("%[^\n]s", contactJob->company);
	putchar('\n');
	clear();
}

void clear(void) {
	while (getchar() != '\n') {
		;
	}
}