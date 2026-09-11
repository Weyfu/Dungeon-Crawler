#pragma once

#include <iostream>
#include <string> 
#include "Weapon.h"
using namespace std;

enum EnemyType
{
	Redditor,
	Chud,
	YiXuan
};


class Character
{
public:
	string name;
	int damageModifier;
	int health;
	int level;
	int specialUses;
	int potionUses;
	int specialCooldown;
	WeaponType weapon;
	EnemyType enemyType;


	Character(WeaponType wpn)
	{
		name = "Player";
		health = 100;
		level = 1;
		weapon = wpn;
		damageModifier = 0;
		specialUses = 3;
		potionUses = 5;
		specialCooldown = 0;
	}

	Character(EnemyType type)
	{
		enemyType = type;

		switch (type)
		{
		case Redditor:
			name = "Redditor";
			health = 100;
			level = 1;
			weapon = RedditGold; // you deserve it twin
			damageModifier = 0;
			break;

		case Chud:
			name = "Chud";
			health = 200;
			level = 2;
			weapon = Lollipop; // idk they get a lollipop
			damageModifier = 0;
			break;

		case YiXuan:
			name = "Yi Xuan";
			health = 300;
			level = 3;
			weapon = QingMing; // no not the bird
			damageModifier = 0;
			break;
		}
	}

};

