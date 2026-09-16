#pragma once
#include <iostream>
#include <string> 
#include "Character.h"
#include "Scoreboard.h"
extern int score;


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
		score *= 1;
		
	}
	else if (difficulty == Normal)
	{
		enemy.health == enemy.health;
		enemy.damageModifier == enemy.damageModifier;
		score *= 2;
	}
	else if (difficulty == Legend)
	{
		enemy.health = enemy.health * 3;
		enemy.damageModifier += 15;
		score *= 3;
		
	}

	return enemy;
}
