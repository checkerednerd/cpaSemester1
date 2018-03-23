/*
call a function in a function
supplimental learning for A2M2
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"info.h"

struct Info player1 = { {' '}, {' '} };
struct Info player2 = { {' '}, {' '} };
char choice = 'n';

int main(void) {
	printf("Hello, ugly!\n");

	printf("Player 1, please log in...\n");
	getName(&player1.playerName); //sends in the address of player1.playerName to the function, which takes as satisfactory to its pointer contactName

	getJob(&player1.playerJob); //sends in the address of player1.playerJob to the function, which is waiting with a pointer

	printf("Is there a second player (y or n)? ");
	scanf("%c", &choice);

	if (choice == 'Y' || choice == 'y') {
		printf("Player 2, please log in...\n");
		getName(&player2.playerName); //sends in address of player2.playerName to the function...

		getJob(&player2.playerJob);
	}

	printf("Player one is logged in as: %s %s\n", player1.playerName.FirstName, player1.playerName.lastName);
	printf("Player one is a %s at %s\n", player1.playerJob.title, player1.playerJob.company);

	if (choice == 'Y' || choice == 'y') {
		printf("Player two is logged in as: %s %s\n", player2.playerName.FirstName, player2.playerName.lastName);
		printf("Player two is a %s at %s\n", player2.playerJob.title, player2.playerJob.company);
	}

	return 0;
}