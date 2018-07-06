#include "player_weapon.h"

Player_Weapon::Player_Weapon(Primary_Assets::Player_Weapon_Options w, sf::Vector2f* d, float d2, float m)
{
	weapon = w;
	dir = d;
	damage = d2;
	moveSpeed = m;
	cout << "New weapon yay" << endl;
	
	switch(weapon)
	{
		case Primary_Assets::Primary_Weapon_Options::FIST:
			setupFist();
			break;

		case Primary_Assets::Primary_Weapon_Options::ARROW:
			setupArrow();
			break;
	}
}

void Player_Weapon::setupFist()
{
	lifetime = 60;
	damage *= 0.25;
	cout << "Using fists" << endl;
}

void Player_Weapon::setupArrow()
{
	//TODO
}
