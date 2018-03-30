/*Ron Vincent
*2018-03-30
*A program to replicate a simple RPG battle system, update to v1.0.0
Implements structures from stats.h - DONE
Implements functions
Implements magic
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stats.h"

int main(void) {
	struct Stats player = { 20, 2, 1 };
	struct Stats skele = { 20, 0, 2 };

	int dmg = 0; //rang for damage roll
	int crit = 0; //rng for crit chance
	int flee = 0; //rng for flee chance
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
			crit = rand() % 5;
			if (crit == 4) {
				printf("SSHHHHUNK! A critical hit!\n"); //20% chance of a critical for double damage (rolls 0-4)
				dmg *= 2;
			}
			dmg -= skele.ARM;
			printf("The skeleton took %d points of damage.\n", abs(dmg));
			skele.HP -= abs(dmg); //HP subtracts to ABSOLUTE value of damage (if armour > damage, the damage would restore HP otherwise)
			printf("The skeleton has %d HP remaining...\n", skele.HP);
			printf("\n");

			/*insert code block to validate if you defeated skeleton before it hits you back
			skeleton should only hit you back if you did not defeat it
			can put skeleton attack code block into seperate function*/
			if (skele.HP > 0) { //if skeleton is not defeated, it will attack
				dmg = rand() % 4 + 2; //2-5 for skeleton
				printf("The skeleton swings its rotting hand at you...\n");
				printf("The skeleton dealt %d of damage against your armor...\n", dmg);
				dmg -= player.ARM;
				printf("You took %d points of damage.\n", abs(dmg));
				player.HP -= abs(dmg);

				printf("You have %d HP remaining...\n", player.HP);
				printf("\n");

				if (player.HP <= 0) { //if skeleton has defeated you
					system("cls");
					printf("You were defeated...\n");
				}

			}
			else if (skele.HP <= 0) { //if you have defeated skeleton, skeleton will not attack
				system("cls");
				printf("Skeleton defeated...\n");
			}
			//Skeleton attack
			break;

		case 2: //Bring up magic spell menu
			break;

		case 3: //Defend on your turn, taking reduced damage from skeleton
			player.ARM += 2;
			system("cls");
			printf("You bolster your stance defensively...\n");
			printf("Armor +2 for the rest of the turn.\n");

			if (skele.HP > 0) { //if skeleton is not defeated, it will attack
				dmg = rand() % 4 + 2; //2-5 for skeleton
				printf("The skeleton swings its rotting hand at you...\n");
				printf("The skeleton dealt %d of damage against your armor...\n", dmg);

				if (dmg < player.ARM) { //if damage is lower than armour, make damage 0
					dmg = 0;
				}
				else { //else damage will mitigated by armour
					dmg -= player.ARM; 
				}

				printf("You took %d points of damage.\n", dmg);
				player.HP -= dmg;
				printf("You have %d HP remaining...\n", player.HP);
				printf("\n");

				if (player.HP <= 0) { //if skeleton has defeated you
					system("cls");
					printf("You were defeated...\n");
				}

			}
			else if (skele.HP <= 0) { //if you have defeated skeleton, skeleton will not attack
				system("cls");
				printf("Skeleton defeated...\n");
			}
			player.ARM -= 2;
			break;

		case 4: //Flee battle
			system("cls");
			flee = rand() % 2; //50% chance to escape (flee will be either 0 (false) or true (1))

			if (flee == 1) {
				printf("You managed to safely get away...\n");
			}
			else {
				printf("The Skeleton blocked your path, you could not escape.\n");
			}
			break;

		default: //Incorrect choice
			system("cls");
		}

	} while (flee == 0 && player.HP > 0 && skele.HP > 0); //terminates when user flees or usr/skele.HP is 0 or less

	return 0;
}