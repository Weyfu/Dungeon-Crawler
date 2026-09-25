#pragma once

#include <iostream>
#include <string> 
#include "Character.h"
using namespace std;

enum WeaponType
{
	Brawler, // SEIYA
	Rush, // i am the epic dodge
	Beast, // i take big damage
	RedditGold,
	Lollipop,
	QingMing
};


enum SpecialType
{
	FinishingBlows,
	RelentlessBarrage, // who is a beta tester
	Torment // PROVOOOOOKINGGG
};


string weaponNames[] =		// this is big brain array to implement
{
	"Brawler",
	"Rush",
	"Beast",
	"Reddit Gold",
	"Lollipop",
	"QingMing"
};

string weaponName(WeaponType weapon)
{
	return weaponNames[weapon];
}

string specialName(SpecialType special) // return better name instead of boring name
{
	switch (special)
	{
	case FinishingBlows:
		return "Essence of Finishing Blows";

	case RelentlessBarrage:
		return "Essence of Relentless Barrage";

	case Torment:
		return "Essence of the Beast: Torment";

		return "Unknown Special";
	}
}


SpecialType weaponSpecial(WeaponType weapon)
{
	switch (weapon)
	{
	case Brawler:
		return FinishingBlows;

	case Rush:
		return RelentlessBarrage;

	case Beast:
		return Torment;

		return FinishingBlows;
	}
}