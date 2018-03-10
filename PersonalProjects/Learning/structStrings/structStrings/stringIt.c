/*Ron Vincent
*stringIt.c
*practice calling a String and character array from a function
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

int main(void) {

	struct Name fullName = { { "First" },{ 'M' },{ "Last" } }; //double quotes for strings, single quotes for characters
	printf("%s %s %s\n", fullName.firstName, fullName.middleInitial, fullName.lastName);

	return 0;
}