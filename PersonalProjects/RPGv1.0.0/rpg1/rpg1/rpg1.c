/*Ron Vincent
*2018-02-27
*A program to replicate a simple RPG battle system
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	int usrHP = 20;
	int mp = 2;
	int usrARM = 1;
	int skeHP = 20;
	int skeARM = 2;
	int dmg = 0;

	int flee = 0;
	int choice;
	time_t t;

	//initialize RNG
	srand((unsigned)time(&t));

	printf("Out of the shadows a skeleton approaches.\n");
	printf("The skeleton draws its sword as it notices your presence.\n");
	printf("You have no choice but to defend yourself...\n");
	printf("=========================================================\n");

	do {

		printf("BATTLE MENU\n");
		printf("1 Attack\n");
		printf("2 Magic\n");
		printf("3 Defend\n");
		printf("4 Flee\n");
		printf("Select your command...\n");
		scanf("%d", &choice);
		system("cls");

		switch (choice) {
		case 1: //Attack skeleton, skeleton attacks back
			//Player attack
			dmg = rand() % 3 + 3; //damage is a random value, within a range of 3, starting at (0 + 3), so 3-5
			printf("You swing your sword at the approaching skeleton...\n");
			printf("You dealt %d of damage against the skeleton's armor...\n", dmg);
			dmg -= skeARM;
			printf("The skeleton took %d points of damage.\n", dmg);
			skeHP -= dmg;
			printf("The skeleton has %d HP remaining...\n", skeHP);
			printf("\n");

			/*insert code block to validate if you defeated skeleton before it hits you back
			skeleton should only hit you back if you did not defeat it
			can put skeleton attack code block into seperate function*/
			if (skeHP > 0) { //if skeleton is not defeated, it will atack
				dmg = rand() % 4 + 2; //2-5 for skeleton
				printf("The skeleton swings its rotting hang at you...\n");
				printf("The skeleton dealt %d of damage against your armor...\n", dmg);
				dmg -= usrARM;
				printf("You took %d points of damage.\n", dmg);
				usrHP -= dmg;
				printf("You have %d HP remaining...\n", usrHP);
				printf("\n");

				if (usrHP <= 0) { //if skeleton has defeated you
					system("cls");
					printf("You were defeated...\n");
				}

			}
			else if (skeHP <= 0) { //if you have defeated skeleton, skeleton will not attack
				system("cls");
				printf("Skeleton defeated...\n");
			}
			//Skeleton attack
			break;

		case 2: //Bring up magic spell menu
			break;

		case 3: //Defend on your turn, taking reduced damage from skeleton
			usrARM += 2;
			system("cls");
			printf("You bolster your stance defensively...\n");
			printf("Armor +2 for the rest of the turn.\n");

			if (skeHP > 0) { //if skeleton is not defeated, it will atack
				dmg = rand() % 4 + 2; //2-5 for skeleton
				printf("The skeleton swings its rotting hang at you...\n");
				printf("The skeleton dealt %d of damage against your armor...\n", dmg);
				dmg -= usrARM;
				printf("You took %d points of damage.\n", dmg);
				usrHP -= dmg;
				printf("You have %d HP remaining...\n", usrHP);
				printf("\n");

				if (usrHP <= 0) { //if skeleton has defeated you
					system("cls");
					printf("You were defeated...\n");
				}

			}
			else if (skeHP <= 0) { //if you have defeated skeleton, skeleton will not attack
				system("cls");
				printf("Skeleton defeated...\n");
			}
			usrARM -= 2;
			break;

		case 4: //Flee battle
			system("cls");
			printf("You managed to safely get away...\n");
			flee = 1;
			break;

		default: //Incorrect choice
			system("cls");
		}

	} while (flee == 0 && usrHP > 0 && skeHP > 0);

	return 0;
}