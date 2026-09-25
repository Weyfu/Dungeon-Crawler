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
	10, // RedditGold
	15, // Lollipop
	20,  // QingMing
};

int weaponDamage(WeaponType weapon)
{
	return weaponDamages[weapon];   /// HOW WILL I KNOW THE DAMAGE NUMBER IF THERE IS NO NUMBER
}


int specialDamages[] =
{
	40, // Essence of Finishing Blows
	35, // Essence of Relentless Barrage
	80, // Essence of the Beast: Torment
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
	cout << attacker.name << " hurts "
		<< target.name << " for "
		<< damage << " damage!" << endl;
}

void specialAttack(Character& attacker, Character& target)
{

	if (attacker.specialUses <= 0)
	{
		cout << attacker.name << " has no Heat left!\n";
		return;
	}

	int specialattack = rand() % 100;

	if (specialattack < 20)
	{
		cout << attacker.name << " couldn't use their Essence Move.\n";
		return;
	}

	int damage = specialDamage(attacker.weapon) + attacker.specialdamageModifier;

	target.health -= damage;

	SpecialType special = weaponSpecial(attacker.weapon);

	switch (special)
	{
	case FinishingBlows:
		setColor(1);
		cout << attacker.name << " Runs up to their Opponent and Superman Punches them" << " dealing " << damage << " damage!" << endl;
		target.health -= 30;
		setColor(7);
		break;

	case RelentlessBarrage:
		setColor(13);
		cout << attacker.name << " Punches their Opponent in the head, Gut punches them and kicks them in the Head for " << damage << " damage!" << endl;
		target.health -= 50;
		setColor(7);
		break;

	case Torment:
		setColor(14);
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