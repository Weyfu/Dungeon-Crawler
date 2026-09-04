/// variables, conditionals, loops, switches std::strings std::cin/cout
/// structs, classes
/// enums
// turn based combat
// text based
// 3 encounters to "escape" or death to all of japan
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
	StarburstStream, // who is a beta tester
	JudgementCut // PROVOOOOOKINGGG
};

enum EnemyType
{
	Redditor,
	Chud,
	YiXuan
};

struct Item
{
	string name;
	int healthback;
};


string weaponName(WeaponType weapon)
{
	switch (weapon)
	{
	case WoodenSword:
		return "Wooden Sword";

	case Elucidator:
		return "Elucidator";

	case Yamato:
		return "Yamato"; // BLACK CLOUDS IN ISOLATION

	case RedditGold:
		return "Reddit Gold";

	case Lollipop:
		return "Lollipop";

	case QingMing:
		return "QingMing";
	}

	return "Unknown Weapon";
}

SpecialType weaponSpecial(WeaponType weapon)
{
	switch (weapon)
	{
	case WoodenSword:
		return BigSwing;

	case Elucidator:
		return StarburstStream;

	case Yamato:
		return JudgementCut;

		return StarburstStream;
	}
}


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

	Character (WeaponType wpn)
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

	Character (EnemyType type)
	{
		enemyType = type;

		switch (type)
		{
		case Redditor:
			name = "Redditor";
			health = 100;
			level = 1;
			weapon = RedditGold;
			damageModifier = 0;
			break;

		case Chud:
			name = "Chud";
			health = 200;
			level = 2;
			weapon = Lollipop;
			damageModifier = 0;
			break;

		case YiXuan:
			name = "Yi Xuan";
			health = 300;
			level = 3;
			weapon = QingMing;
			damageModifier = 0;
			break;
		}
	}

};

int weaponDamage(WeaponType weapon)
{
	switch (weapon)
	{
	case WoodenSword:
		return 10;
	case Elucidator:
		return 15;
	case Yamato:
		return 20;
	case RedditGold:
		return 15;
	case Lollipop:
		return 15;
	case QingMing:
		return 15;
	}
}

int specialDamage(WeaponType weapon)
{
	switch (weapon)
	{
	case WoodenSword:
		return 25;
	case Elucidator:
		return 50;
	case Yamato:
		return 80;
	}
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
		cout << attacker.name << " takes a big swing!\n";
		target.health -= 30;
		break;

	case StarburstStream:
		cout << attacker.name << " used Starburst Stream!\n";
		target.health -= 50;
		break;

	case JudgementCut:
		cout << attacker.name << " used Judgement Cut!\n";
		target.health -= 80;
		break;

	}

	attacker.specialUses--;
	attacker.specialCooldown--;

	cout << attacker.name << " has "
		<< attacker.specialUses
		<< " Special Uses remaining.\n";

	if (target.health < 0)
		target.health = 0;

	cout << target.name << " has " << target.health << " HP remaining.\n";
}

string specialName(SpecialType special)
{
	switch (special)
	{
	case BigSwing:
		return "Big Swing";

	case StarburstStream:
		return "Starburst Stream";

	case JudgementCut:
		return "Judgement Cut";

		return "Unknown Special";
	}
}

void buff(Character& character)
{
	int buffAmount = rand() % 50 + 1;

	character.damageModifier += buffAmount;

	cout << character.name << " got buffed by the devs for "
		<< buffAmount << " damage!" << endl;
}

void debuff(Character& character)
{
	int debuffAmount = rand() % 50 + 1;

	character.damageModifier -= debuffAmount;

	cout << character.name << " got nerfed to the ground for "
		<< debuffAmount << " damage!" << endl;
}



Item potion
{
	"Estus Flask",
	50
};

void usePotion(Character& player, Item potion)
{
	if (player.health < 50)
	{
		player.health += potion.healthback;

		cout << player.name << " Drinks 1 "
			<< potion.name << " and restores "
			<< potion.healthback << " health!" << endl;
	}
	else if (player.potionUses == 0)
	{

		cout << player.name <<  " has no Potions left" << endl;

	}
	else if (player.health > 50)
	{
		cout << player.name << " Is too full to restore their Health." << endl;
	}
	else
		return;

	player.potionUses--;
			

}

Character createEnemy(int stage)
{
	if (stage == 1)
	{
		return Character(Redditor);
	}
	else if (stage == 2)
	{
		return Character(Chud);
	}
	else
	{
		return Character(YiXuan);
	}
}

int main()
{ 

	srand(time(0));



	int choice;
	cout << "Choose your Weapon: " << endl;
	cout << "1. Wooden Sword" << endl;
	cout << "2. Elucidator" << endl;
	cout << "3. Yamato" << endl;
	cout << "Selected Weapon: "; cin >> choice;

	WeaponType playerWeapon;
	switch (choice)

	{
	case 1:
		playerWeapon = WoodenSword;
		break;

	case 2:
		playerWeapon = Elucidator;
		break;

	case 3:
		playerWeapon = Yamato;
		break;
	}

	Character player(playerWeapon);
	cout << "\n------------------" << endl;
	cout << "Your Weapon is now a " << weaponName(player.weapon) << endl;
	cout << "------------------" << endl;

int stage = 1;

	while (stage <= 100 && player.health > 0)
	{
		Character enemy = createEnemy(stage);


		cout << "\n--------------------" << endl;

		cout << "WAVE " << stage << endl;
		cout << enemy.name << " approaches!" << endl;
		cout << "----------------------" << endl;

		while (player.health > 0 && enemy.health > 0)

		{

		int action;

		cout << "\n--------------------" << endl;
		cout << player.name << " HP: " << player.health << endl;
		cout << enemy.name << " HP: " << enemy.health << endl;
		cout << "--------------------" << endl;

		cout << "\nYour turn!" << endl;
		cout << "1. Swing your " << weaponName(player.weapon) << endl;
		cout << "2. Use " << specialName(weaponSpecial(player.weapon)) << endl; //gets name of the special, checks weapon tied to the weapon, checks the player weapon
		cout << "3. Drink a Health Potion" << endl;
		cout << "4. Buff yourself" << endl;
		cout << "5. Debuff enemy" << endl;
		cout << "6-9. Do nothing" << endl;
		cout << "Choose: ";
		cin >> action;

		if (action == 1)
		{
			Attack(player, enemy);
		}

		else if (action == 2)
		{
			specialAttack(player, enemy);
		}
		else if (action == 3)
		{
			usePotion(player, potion);
			cout << "Your current health is now: " << player.health << endl;
		}
		else if (action == 4)
		{
			buff(player);
		}
		else if (action == 5)
		{
			debuff(enemy);
		}
		else
		{
			cout << "You do nothing." << endl;
		}

		if (enemy.health <= 0)
		{
			cout << enemy.name << " has been defeated!" << endl;
			stage++;
		}



		cout << "\nEnemy's turn!" << endl;

		int effectChance = rand() % 100;

		if (effectChance < 25)
		{
			buff(enemy);
		}
		else if (effectChance < 20)
		{
			debuff(player);
		}

		Attack(enemy, player);


		if (stage > 100 && player.health > 0)
		{
			cout << "\nYou escaped all of New Eridu, Japan!" << endl;
		}


		if (player.health <= 0)
		{
			cout << player.name << " was Vanquished!" << endl;
			break;
		}
		}

	 }
}










