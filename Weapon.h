#pragma once

#include <iostream>
#include <string> 
#include "Character.h"
using namespace std;

enum WeaponType
{
	WoodenSword,
	Elucidator, // the black swordsman
	Yamato, // I AM THE STORM THAT IS APPROACHING
	RedditGold,
	Lollipop,
	QingMing
};


enum SpecialType
{
	BigSwing,
	VorpalStrike, // who is a beta tester
	JudgementCut // PROVOOOOOKINGGG
};


string weaponNames[] =		// this is big brain array to implement
{
	"Wooden Sword",
	"Elucidator",
	"Yamato",
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
	case BigSwing:
		return "Big Swing";

	case VorpalStrike:
		return "Vorpal Strike";

	case JudgementCut:
		return "Judgement Cut";

		return "Unknown Special";
	}
}


SpecialType weaponSpecial(WeaponType weapon)
{
	switch (weapon)
	{
	case WoodenSword:
		return BigSwing;

	case Elucidator:
		return VorpalStrike;

	case Yamato:
		return JudgementCut;

		return BigSwing;
	}
}