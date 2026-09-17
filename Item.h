#pragma once

#include <iostream>
#include <string> 
#include "Color.h"
#include "Scoreboard.h"
using namespace std;



struct estusFlask
{
	string name;
	int healthback;
};



estusFlask potion
{
	"Estus Flask",
	100
};

void usePotion(Character& player, estusFlask potion)
{

	if (player.health < 50)
	{
		player.health += potion.healthback;

		setColor(2);
		cout << player.name << " Drinks 1 "
			<< potion.name << " and gets "
			<< potion.healthback << " health!" << endl;

		player.potionUses--;
	}
	else if (player.potionUses == 0)
	{
		setColor(12);
		cout << player.name << " has no Estus Flasks left." << endl; /// no more spamming

	}
	else if (player.health > 50)
	{
		setColor(8);
		cout << player.name << " Does not feel the need to drink an Estus Flask." << endl;
	}
	else
		return;
	setColor(14);
	cout << player.name << " has "
		<< player.potionUses
		<< " Drops of Estus left.\n";    /// no more spamming cuz we hate you


}
