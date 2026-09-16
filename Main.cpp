/// variables, conditionals, loops, switches std::strings std::cin/cout
/// structs, classes, now we have arrays happy happy happy
/// enums
// turn based combat
// text based
// 3 encounters to "escape" or death to all of japan
#include <iostream>
#include <string> 
#include <ctime>
#include <cstdlib> // for rand
#include "Character.h"
#include "Item.h"
#include "Weapon.h"
#include "Damage.h"
#include "Difficulty.h"
#include "Color.h"
#include "ScoreBoard.h"




int main()
{ 
	srand(time(0));

	int score = 0;

	int choice;

	Difficulty difficulty;

	int difficultyChoice;

	setColor(14);
	cout << "\nHow would you like to Suffer?:" << endl;
	setColor(2);
	cout << "1. Go easy on me Baby." << endl;
	setColor(6);
	cout << "2. I can take it." << endl;
	setColor(4);
	cout << "3. Let's play rough." << endl;
	setColor(15);
	cout << "Choice: ";
	cin >> difficultyChoice;


	switch (difficultyChoice)
	{
	case 1:
		difficulty = Easy;
		break;

	case 2:
		difficulty = Normal;
		break;

	case 3:
		difficulty = Legend;
		break;

	default:
		setColor(4);
		cout << "ok then have at it" << endl;
		difficulty = Legend;
		break;
	}

	setColor(14);
	cout << "Choose your Weapon: " << endl;
	setColor(8);
	cout << "1. Wooden Sword" << endl;
	setColor(11);
	cout << "2. Elucidator" << endl;
	setColor(9);
	cout << "3. Yamato" << endl;
	setColor(15);
	cout << "Selected Weapon: "; cin >> choice;

	WeaponType playerWeapon;
	switch (choice)

	{
	case 1:
		playerWeapon = WoodenSword;
		break;

	case 2:
		playerWeapon = Elucidator;
		break;

	case 3:
		playerWeapon = Yamato;
		break;

	default:
		setColor(8);
		cout << "tung tung tung sahur is calling your name." << endl;
		playerWeapon = WoodenSword;
		break;
	}


	Character player(playerWeapon);
	setColor(14);
	cout << "\n------------------" << endl; //// ouuuu you can use \n cuz next lineeeeee
	cout << "Your Weapon is now a " << weaponName(player.weapon) << endl;
	cout << "------------------" << endl;

int stage = 1;



	while (stage <= 3 && player.health > 0)
	{
		Character enemy = createEnemy(stage, difficulty);


		setColor(9);
		cout << "\n--------------------" << endl;
		cout << "WAVE " << stage << endl;
		cout << enemy.name << " has entered the Battlefield!" << endl;
		cout << "----------------------" << endl;

		while (player.health > 0 && enemy.health > 0)

		{

		int action;
		setColor(10);
		cout << "\n--------------------" << endl;
		cout << player.name << " HP: " << player.health << endl;
		cout << enemy.name << " HP: " << enemy.health << endl;
		cout << "--------------------" << endl;
		setColor(14);
		cout << "\nIt is now your Turn!" << endl;
		cout << "1. Swing your " << weaponName(player.weapon) << endl;
		cout << "2. Use " << specialName(weaponSpecial(player.weapon)) << endl;
		cout << "3. Drink a Estus Flask" << endl;
		cout << "4. Use a Buff Spell" << endl;
		cout << "5. Curse the Enemies entire Bloodline" << endl;
		cout << "6-9. Do nothing" << endl;
		setColor(7);

		cout << "Choose: ";

		cin >> action;

		if (action == 1)
		{
			Attack(player, enemy);
		}

		else if (action == 2)
		{
			specialAttack(player, enemy);
		}
		else if (action == 3)
		{
			usePotion(player, potion);
			setColor(10);
			cout << "Your current health is now: " << player.health << endl;
			setColor(7);

		}
		else if (action == 4)
		{
			buff(player);
		}
		else if (action == 5)
		{
			debuff(enemy);
		}
		else
		{
			setColor(8);
			cout << "You do nothing." << endl;
			setColor(7);

		}


		if (enemy.health > 0)
		{
			setColor(12);
			cout << "\nIt's the Enemy's Turn" << endl;

			int effectChance = rand() % 100;

			if (effectChance < 45)
			{
				buff(enemy);
			}
			else if (effectChance < 25)
			{
				debuff(player);
			}

			Attack(enemy, player);

			setColor(7);
		}


		if (enemy.health <= 0)
		{
			setColor(12);
			cout << enemy.name << " is death the deathly of all deaths." << endl;
			stage++;
			player.potionUses++;
			player.buffUses++;
			player.debuffUses++;
			player.specialUses++;
			score += 500;

			setColor(7);
		}


		if (stage > 3 && player.health > 0)
		{
			setColor(3);
			cout << "\nYou escaped all of New Eridu, Japan!" << " and achieved a score of " << score << endl;
			setColor(7);

		}

		if (player.health <= 0)
		{

			setColor(4);
			cout << player.name << " has died, YOU SUCK MR. PLAYER!" << " Your score was " << score << endl;
			break;
			setColor(7);

		}

		}

	 }
}










