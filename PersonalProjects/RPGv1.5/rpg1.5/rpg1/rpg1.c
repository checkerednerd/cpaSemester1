/*Ron Vincent
*2018-03-30
*A program to replicate a simple RPG battle system, update to v1.0.0
Implements structures from stats.h - DONE
Implements functions - DONE
Implements magic
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"stats.h"

//function prototypes, consider moving to seperate header file to save room
int menu(void); //function prototype for menu
void playerAttack(struct Stats *player, struct Stats *enemy); //creates pointers of Stats type that gets passed the addresses for player and skele
void enemyAttack(struct Stats *player, struct Stats *enemy);
void checkEnemy(struct Stats * enemy);
void checkPlayer(struct Stats * player);
int magicMenu(void);
void fireSpell(struct Stats * player, struct Stats * enemy);
void iceSpell(struct Stats * player, struct Stats * enemy);
void healSpell(struct Stats * player, struct Stats * enemy);

int main(void) {
	struct Stats player = { 20, 6, 1, 8, 3, 3 }; //HP, MP, ARM, CRIT, strMin, strMaxOff
	struct Stats skele = { 20, 0, 2, 16, 2, 4 };
	time_t t;
	int flee = 0; //rng for flee chance
	int choice = -1;
	
	//initialize RNG
	srand((unsigned)time(&t));

	printf("Out of the shadows a skeleton approaches.\n");
	printf("The skeleton draws its sword as it notices your presence.\n");
	printf("You have no choice but to defend yourself...\n");
	printf("=========================================================\n");

	do {
		choice = menu();

		switch (choice) {
		case 1: //Attack skeleton, skeleton attacks back
			playerAttack(&player, &skele);
			/*insert code block to validate if you defeated skeleton before it hits you back skeleton 
			should only hit you back if you did not defeat it can put skeleton attack code block into seperate function*/
			checkEnemy(&skele);
			enemyAttack(&player, &skele);
			checkPlayer(&player);
			break;

		case 2: //Bring up magic spell menu
			system("cls");

			do {
				choice = magicMenu();

				switch (choice) {
				case 1: //fire
					fireSpell(&player, &skele);
					checkEnemy(&skele);
					enemyAttack(&player, &skele);
					checkPlayer(&player);
					break;

				case 2: //ice
					iceSpell(&player, &skele);
					checkEnemy(&skele);
					break;

				case 3: //heal
					healSpell(&player, &skele);
					checkPlayer(&player);
					break;

				case 4: //back
					break;

				default:
					system("cls");
				}
			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

			break;

		case 3: //Defend on your turn, taking reduced damage from skeleton
			player.ARM += 2;
			system("cls");
			printf("You bolster your stance defensively...\n");
			printf("Armor +2 for the rest of the turn.\n");
			printf("Your armor is now %d \n", player.ARM);
			printf("-----------------------------------\n");
			enemyAttack(&player, &skele);
			checkPlayer(&player);
			player.ARM -= 2; //armour goes back to normal
			break;

		case 4: //Flee battle
			system("cls");
			flee = rand() % 2; //50% chance to escape (flee will be either 0 (false) or true (1))

			if (flee == 1) { //success ends battle
				printf("You managed to safely get away...\n");
			}
			else { //failure gets attacked
				printf("The Skeleton blocked your path, you could not escape.\n");
				enemyAttack(&player, &skele);
				checkPlayer(&player);
			}
			break;

		default: //Incorrect choice
			system("cls");
		}

	} while (flee == 0 && player.HP > 0 && skele.HP > 0); //terminates when user flees or usr/skele.HP is 0 or less

	return 0;
}