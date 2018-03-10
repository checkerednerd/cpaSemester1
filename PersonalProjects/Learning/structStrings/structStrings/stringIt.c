/*Ron Vincent
*stringIt.c
*practice calling a String and character array from a function
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

int main(void) {

	struct Name fullName = { { "Ronald" },{ "MR" },{ "Vincent" } };
	struct Address fullAddr = { { 136 },{ "Medland Street" },{ 0 },{ "M6P2N5" },{ "Toronto" } };
	struct Numbers phoneNum = { { "1231231234" },{ "1112223334" },{ "1234567890" } };

	printf("%d %s %d\n", fullAddr.streetNumber, phoneNum.business, fullAddr.apartmentNumber);

	return 0;
}