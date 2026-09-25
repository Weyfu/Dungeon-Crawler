#pragma once

#include <iostream>
#include <string>
#include "Weapon.h"
#include "Color.h"

using namespace std;



int weaponDamages[] =		// this is big brain array to implement
{
	25, // Brawler Style
	10, // Rush Style
	40, // Beast Style
	5, // RedditGold
	10, // Lollipop
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
		setColor(6);
		cout << attacker.name << " Whiffed and did no damage." << endl; // thats bad aim
		return;
	}

	int damage = weaponDamage(attacker.weapon) + attacker.damageModifier;

	target.health -= damage;
	setColor(4);
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

	int specialattack = rand() % 100;

	if (specialattack < 20)
	{
		cout << attacker.name << " couldn't use their Special.\n";
		return;
	}

	int damage = specialDamage(attacker.weapon) + attacker.specialdamageModifier;

	target.health -= damage;

	SpecialType special = weaponSpecial(attacker.weapon);

	switch (special)
	{
	case BigSwing:
		setColor(8);
		cout << attacker.name << " says triple t swing!" << " And deals the damage of " << damage << endl;
		target.health -= 30;
		setColor(7);
		break;

	case VorpalStrike:
		setColor(11);
		cout << attacker.name << " says STARRRRBURRSST STREAAAMMMMMUUUUUU!!!!" << " And deals the damage of " << damage << endl;
		target.health -= 50;
		setColor(7);
		break;

	case JudgementCut:
		setColor(9);
		cout << attacker.name << " says Kneel before me!" << " And deals the damage of " << damage << endl;
		target.health -= 80;
		setColor(7);
		break;

	}

	attacker.specialUses--;

	setColor(14);
	cout << attacker.name << " has "
		<< attacker.specialUses
		<< " Special Uses remaining.\n";    /// no more spamming cuz we hate you

	if (target.health < 0)
		target.health = 0;

	setColor(2);
	cout << target.name << " has " << target.health << " HP remaining.\n";
}

void buff(Character& character)
{
	int buffAmount = rand() % 50 + 1; 


	if (character.buffUses > 0)
	{
		character.damageModifier += buffAmount;
		character.specialdamageModifier += buffAmount;

		setColor(6);
		cout << character.name << " blessed by rngesus for "
			<< buffAmount << " damage!" << endl;
		setColor(4);
		character.buffUses--;
	}
	else
	{
		setColor(4);
		cout << character.name << " Cannot Buff themselves anymore." << endl;
	}

}

void debuff(Character& character)
{
	int debuffAmount = rand() % 50 + 1; 


	if (character.debuffUses > 0)
	{
		character.damageModifier -= debuffAmount;
		character.specialdamageModifier -= debuffAmount;
		setColor(5);
		cout << character.name << " got nerfed to the ground for "
			<< debuffAmount << " damage!" << endl;

		character.debuffUses--;
	}
	else
	{
		setColor(4);
		cout << character.name << " cannot nerf their opponent." << endl;
	}
}