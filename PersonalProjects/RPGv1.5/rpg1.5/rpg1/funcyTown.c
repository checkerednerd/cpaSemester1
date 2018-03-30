/*
includes functions for rpg1
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include"stats.h"

int menu(void) {
	int choice = -1;

	printf("BATTLE MENU\n");
	printf("-----------\n");
	printf("1 Attack\n");
	printf("2 Magic\n");
	printf("3 Defend\n");
	printf("4 Flee\n");
	printf("Select your command...\n");
	scanf("%d", &choice);
	system("cls");

	return choice;
}

int magicMenu(void) {
	int choice = -1;

	printf("MAGIC SPELLS\n");
	printf("------------\n");
	printf("1 Conflagrate - 3 MP\n");
	printf("2 Snow Storm  - 3 MP\n");
	printf("3 Heal        - 2 MP\n");
	printf("4 Back...\n");
	printf("Select your command...\n");
	scanf("%d", &choice);
	system("cls");
	return choice;
}

void playerAttack(struct Stats * player, struct Stats * enemy) { //function for player attack phase
	int dmg = 0; //rang for damage roll
	int crit; //rng for crit chance
	time_t t;
	srand((unsigned)time(&t));

	dmg = rand() % player->strMin + player->strMaxOff; //damage is a random value, within a range of 3, starting at (0 + 3), so 3-5
	printf("You swing your sword at the approaching skeleton...\n");

	crit = rand() % player->CRIT; //player has CRIT stat of 8

	if (crit < 2) {
		printf("SSHHHHUNK! A critical hit!\n"); //25% chance of a critical for double damage(success for 0, 1, fail for 2 - 7)
		dmg *= 2;
	}

	printf("You dealt %d of damage against the skeleton's armor...\n", dmg);
	dmg -= enemy->ARM;
	printf("The skeleton took %d points of damage.\n", abs(dmg));
	enemy->HP -= abs(dmg); //HP subtracts to ABSOLUTE value of damage (if armour > damage, the damage would restore HP otherwise)
	printf("The skeleton has %d HP remaining...\n", enemy->HP);
	printf("-----------------------------------\n");

	return; //we don't need to return anything because the damage is applied directly through pointers
}

void enemyAttack(struct Stats * player, struct Stats * enemy) { //function for enemy attack phase
	int dmg = 0; //rang for damage roll
	int crit; //rng for crit chance
	time_t t;
	srand((unsigned)time(&t));

	if (enemy->HP > 0) { //if skeleton is not defeated, it will attack
		dmg = rand() % enemy->strMaxOff + enemy->strMin; //2-5 for skeleton
		printf("The skeleton swings its rotting hand at you...\n");

		crit = rand() % enemy->CRIT; //skeleton has CRIT stat 16

		if (crit < 2) {
			printf("CRAACKK! A critical hit!\n"); //12.5% change of critical hit
			dmg *= 2;
		}

		printf("The skeleton dealt %d of damage against your armor...\n", dmg);
		dmg -= player->ARM;
		printf("You took %d points of damage.\n", abs(dmg));
		player->HP -= abs(dmg);

		printf("You have %d HP remaining...\n", player->HP);
		printf("-----------------------------------\n");
	}
	return;
}

void checkPlayer(struct Stats * player) {
	if (player->HP <= 0) { //if skeleton has defeated you
		system("cls");
		printf("You were defeated...\n");
	}
}

void checkEnemy(struct Stats * enemy) {
	if (enemy->HP <= 0) { //if you have defeated skeleton, skeleton will not attack
		system("cls");
		printf("Skeleton defeated...\n");
	}
}

void fireSpell(struct Stats * player, struct Stats * enemy) {
	printf("You begin to chant under your breath...\n");

	return;
}

void iceSpell(struct Stats * player, struct Stats * enemy) {
	if (player->MP >= 3) {
		printf("You begin to chant under your breath...\n");
		printf("A sudden chill fills the room...\n");
		printf("A cold, fierce wind bites away at the enemy...\n");
		printf("-----------------------------------\n");

		enemy->HP -= 4;
		player->MP -= 3;

		printf("The enemy has taken 4 direct damage and cannot move this turn...\n");
		printf("The skeleton has %d HP remaining...\n", enemy->HP);
		printf("-----------------------------------\n");
	}
	else {
		printf("Not enough Magic Points...\n");
		printf("-----------------------------------\n");
	}
	return;
}

void healSpell(struct Stats * player, struct Stats * enemy) {
	if (player->MP >= 2) { //only casts the spell if enough MP
		printf("You begin to chant under your breath...\n");
		printf("A beacon of light descends on you from the sky...\n");
		printf("You feel warm and inspired.\n");
		printf("-----------------------------------\n");

		player->HP += 7;
		player->MP -= 2;

		if (player->HP > 20) { //keeps player HP capped at 20
			player->HP = 20;
		}

		enemyAttack(player, enemy);
	}
	else {
		printf("Not enough Magic Points...\n");
		printf("-----------------------------------\n");
	}

	return;
}