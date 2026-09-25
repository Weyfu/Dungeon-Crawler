/// variables, conditionals, loops, switches std::strings std::cin/cout
/// structs, classes, now we have arrays happy happy happy
/// enums
// turn based combat
// text based
// 3 encounters to "escape" or death to all of japan
#include <iostream>
#include <fstream>
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

	int score = 0;
	int BeginningChoice;
	int choice;
	int difficultyChoice;
	srand(time(0));

	const string GAME_TITLE = "YaTuza: Like a Programmer";

	cout << "-------------------------" << endl;
	cout << GAME_TITLE << endl;
	cout << "-------------------------" << endl;





	Difficulty difficulty;

	setColor(14);
	cout << "\nChoose your Difficulty: " << endl;
	setColor(2);
	cout << "1. Normal" << endl;
	setColor(6);
	cout << "2. Hard" << endl;
	setColor(4);
	cout << "3. Legend." << endl;
	setColor(15);
	cout << "Choice: ";
	cin >> difficultyChoice;


	switch (difficultyChoice)
	{
	case 1:
		difficulty = Easy;
		score / 2;
		break;

	case 2:
		difficulty = Normal;
		break;

	case 3:
		difficulty = Legend;
		score * 2;
		break;

	default:
		setColor(4);
		cout << "ok then have at it" << endl;
		difficulty = Legend;
		score * 2;
		break;
	}

	setColor(15);
	cout << "Choose your Fighting Style: " << endl;
	setColor(1);
	cout << "1. Brawler" << endl;
	setColor(13);
	cout << "2. Rush" << endl;
	setColor(14);
	cout << "3. Beast" << endl;
	setColor(15);
	cout << "Selected Style: "; cin >> choice;

	WeaponType playerWeapon;
	switch (choice)

	{
	case 1:
		playerWeapon = Brawler;
		score * 3;
		break;

	case 2:
		playerWeapon = Rush;
		score * 2;
		break;

	case 3:
		playerWeapon = Beast;
		break;

	default:
		setColor(8);
		cout << "It seems like have moves like a Brawler." << endl;
		playerWeapon = Brawler;
		score * 3;
		break;
	}


	Character player(playerWeapon);
	setColor(14);
	cout << "\n------------------" << endl; //// ouuuu you can use \n cuz next lineeeeee
	cout << "Your Fighting Stance is now a " << weaponName(player.weapon) << endl;
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
		cout << "1. Use " << weaponName(player.weapon) << endl;
		cout << "2. Use " << specialName(weaponSpecial(player.weapon)) << endl;
		cout << "3. Drink a Toughness Emperor" << endl;
		cout << "4. Use Power Surge" << endl;
		cout << "5. Curse the Enemies entire Bloodline" << endl;
		cout << "6-9. Do nothing" << endl;
		setColor(7);

		cout << "Choose: ";

		cin >> action;

		if (action == 1)
		{
			Attack(player, enemy);
			score += 50;
		}

		else if (action == 2)
		{
			specialAttack(player, enemy);
			score += 100;
		}
		else if (action == 3)
		{
			usePotion(player, potion);
			setColor(10);
			cout << "Your current health is now: " << player.health << endl;
			score -= 100;
			setColor(7);

		}
		else if (action == 4)
		{
			buff(player);
			score += 25;
		}
		else if (action == 5)
		{
			debuff(enemy);
			score += 25;
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

			setColor(10);
			cout << player.name << " Refreshed their Potions and Abilities by 1" << endl;

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
			
			int highScore = 0;
			ifstream inFile("highscore.txt");

			if (inFile.is_open())
			{
				inFile >> highScore;
				inFile.close();
			}

			cout << "\nYou escaped all of New Eridu, Japan!" << " and achieved a score of " << score <<  endl;

			if (score > highScore)
			{
				cout << "NEW HIGH SCORE!" << endl;
				ofstream outFile("highscore.txt");
				outFile << score;
				outFile.close();
			}
			else
			{
				cout << "Your high score is still " << highScore << endl;
			}

			setColor(7);



		}

		if (player.health <= 0)
		{

			int highScore = 0;
			ifstream inFile("highscore.txt");

			if (inFile.is_open())
			{
				inFile >> highScore;
				inFile.close();
			}

			setColor(4);
			cout << player.name << " has died, YOU SUCK MR. PLAYER!" << " Your score was " << score << endl;


			if (score > highScore)
			{
				cout << "NEW HIGH SCORE!" << endl;
				ofstream outFile("highscore.txt");
				outFile << score;
				outFile.close();
			}
			else
			{
				cout << "Your high score is still " << highScore << endl;
			}
			break;

			setColor(7);

		}

		}

	 }
}










