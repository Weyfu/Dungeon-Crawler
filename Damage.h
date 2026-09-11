#pragma once

#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;



int weaponDamages[] =		// this is big brain array to implement
{
	10, // WoodenSword
	15, // Elucidator
	20, // Yamato
	15, // RedditGold
	15, // Lollipop
	15  // QingMing
};

int weaponDamage(WeaponType weapon)
{
	return weaponDamages[weapon];   /// HOW WILL I KNOW THE DAMAGE NUMBER IF THERE IS NO NUMBER
}


int specialDamages[] =
{
	25, // Big Swing
	50, // Vorpal Strike
	80, // Judgement Cut
};


int specialDamage(WeaponType weapon)
{
	return specialDamages[weapon];
}

void Attack(Character& attacker, Character& target)
{
	int chance = rand() % 100;

	if (chance < 20)
	{
		cout << attacker.name << " Missed their Attack!" << endl;
		return;
	}

	int damage = weaponDamage(attacker.weapon) + attacker.damageModifier;

	target.health -= damage;

	cout << attacker.name << " attacks "
		<< target.name << " for "
		<< damage << " damage!" << endl;
}

void specialAttack(Character& attacker, Character& target)
{

	if (attacker.specialUses <= 0)
	{
		cout << attacker.name << " has no Special Uses left!\n";
		return;
	}

	if (attacker.specialCooldown > 0)
	{
		cout << attacker.name << "'s Special is on cooldown for "
			<< attacker.specialCooldown << " more turn(s)!\n";
		return;
	}

	int specialattack = rand() % 100;

	if (specialattack < 20)
	{
		cout << attacker.name << " couldn't use their Special.\n";
		return;
	}

	int damage = specialDamage(attacker.weapon);

	target.health -= damage;

	SpecialType special = weaponSpecial(attacker.weapon);

	switch (special)
	{
	case BigSwing:
		cout << attacker.name << " triple t swing\n";
		target.health -= 30;
		break;

	case VorpalStrike:
		cout << attacker.name << " STARRRRBURRSST STREAAAMMMMMUUUUUU!!!!\n";
		target.health -= 50;
		break;

	case JudgementCut:
		cout << attacker.name << " Kneel before me!\n";
		target.health -= 80;
		break;

	}

	attacker.specialUses--;
	attacker.specialCooldown--;

	cout << attacker.name << " has "
		<< attacker.specialUses
		<< " Special Uses remaining.\n";    /// no more spamming cuz we hate you

	if (target.health < 0)
		target.health = 0;

	cout << target.name << " has " << target.health << " HP remaining.\n";
}

void buff(Character& character)
{
	int buffAmount = rand() % 100 + 1; 


	if (character.buffUses > 0)
	{
		character.damageModifier += buffAmount;

		cout << character.name << " blessed by rngesus for "
			<< buffAmount << " damage!" << endl;

		character.buffUses--;
	}
	else
	{
		cout << character.name << " Cannot Buff themselves anymore." << endl;
	}

}

void debuff(Character& character)
{
	int debuffAmount = rand() % 100 + 1; 


	if (character.debuffUses > 0)
	{
		character.damageModifier -= debuffAmount;

		cout << character.name << " got nerfed to the ground for "
			<< debuffAmount << " damage!" << endl;

		character.debuffUses--;
	}
	else
	{
		cout << character.name << " cannot nerf their opponent." << endl;
	}
}