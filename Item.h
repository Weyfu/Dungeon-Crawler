#pragma once

#include <iostream>
#include <string> 
using namespace std;


struct Item
{
	string name;
	int healthback;
};



Item potion
{
	"Estus Flask",
	100
};

void usePotion(Character& player, Item potion)
{
	if (player.health < 50)
	{
		player.health += potion.healthback;

		cout << player.name << " Drinks 1 "
			<< potion.name << " and gets "
			<< potion.healthback << " health!" << endl;

		player.potionUses--;
		player.score - 150;
	}
	else if (player.potionUses == 0)
	{

		cout << player.name << " has no Estus Flasks left." << endl; /// no more spamming

	}
	else if (player.health > 50)
	{
		cout << player.name << " Does not feel the need to drink an Estus Flask." << endl;
	}
	else
		return;


	cout << player.name << " has "
		<< player.potionUses
		<< " Drops of Estus left.\n";    /// no more spamming cuz we hate you


}
