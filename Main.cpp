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
using namespace std;

int main()
{ 

	srand(time(0));

	int choice;

	Difficulty difficulty;

	int difficultyChoice;

	cout << "\nHow would you like to Suffer?:" << endl;
	cout << "1. Go easy on me Baby." << endl;
	cout << "2. I can take it." << endl;
	cout << "3. Let's play rough." << endl;
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
		cout << "Invalid choice. Defaulting to Normal." << endl;
		difficulty = Normal;
		break;
	}

	cout << "Choose your Weapon: " << endl;
	cout << "1. Wooden Sword" << endl;
	cout << "2. Elucidator" << endl;
	cout << "3. Yamato" << endl;
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
	}

	Character player(playerWeapon);
	cout << "\n------------------" << endl; //// ouuuu you can use \n cuz next lineeeeee
	cout << "Your Weapon is now a " << weaponName(player.weapon) << endl;
	cout << "------------------" << endl;

int stage = 1;



	while (stage <= 3 && player.health > 0)
	{
		Character enemy = createEnemy(stage, difficulty);


		cout << "\n--------------------" << endl;

		cout << "WAVE " << stage << endl;
		cout << enemy.name << " has entered the Battlefield!" << endl;
		cout << "----------------------" << endl;

		while (player.health > 0 && enemy.health > 0)

		{

		int action;

		cout << "\n--------------------" << endl;
		cout << player.name << " HP: " << player.health << endl;
		cout << enemy.name << " HP: " << enemy.health << endl;
		cout << "--------------------" << endl;

		cout << "\nIt is now your Turn!" << endl;
		cout << "1. Swing your " << weaponName(player.weapon) << endl;
		cout << "2. Use " << specialName(weaponSpecial(player.weapon)) << endl;
		cout << "3. Drink a Estus Flask" << endl;
		cout << "4. Use a Buff Spell" << endl;
		cout << "5. Curse the Enemies entire Bloodline" << endl;
		cout << "6-9. Do nothing" << endl;
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
			cout << "Your current health is now: " << player.health << endl;
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
			cout << "You do nothing." << endl;
		}


		if (enemy.health > 0)
		{
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
		}


		if (enemy.health <= 0)
		{
			cout << enemy.name << " is death the deathly of all deaths." << endl;
			stage++;
			player.potionUses++;
			player.buffUses++;
			player.debuffUses++;
			player.specialUses++;
			player.score += 500;
		}


		if (stage > 3 && player.health > 0)
		{
			cout << "\nYou escaped all of New Eridu, Japan!" << " and achieved a score of " << player.score << endl;
		}

		if (player.health <= 0)
		{
			cout << player.name << " has died, YOU SUCK MR. PLAYER!" << endl;
			break;
		}

		}

	 }
}










