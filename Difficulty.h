#pragma once
#include <iostream>
#include <string> 
#include "Character.h"

using namespace std;

enum Difficulty
{
	Easy,
	Normal,
	Legend
};

Character createEnemy(int stage, Difficulty difficulty)
{
	Character enemy(Redditor);

	if (stage == 1)
	{
		enemy = Character(Redditor);
	}
	else if (stage == 2)
	{
		enemy = Character(Chud);
	}
	else
	{
		enemy = Character(YiXuan);
	}


	if (difficulty == Easy)
	{
		enemy.health = enemy.health -= 50;
		enemy.damageModifier -= 20;
	}
	else if (difficulty == Normal)
	{
		enemy.health == enemy.health;
		enemy.damageModifier == enemy.damageModifier;

	}
	else if (difficulty == Legend)
	{
		enemy.health = enemy.health * 5;
		enemy.damageModifier += 20;
	}

	return enemy;
}
