#include "player_weapon.h"

Player_Weapon::Player_Weapon(Primary_Assets::Player_Weapon_Options w, sf::Vector2f d, float d2, float m)
{
	weapon = w;
	dir = d;
	damage = d2;
	moveSpeed = m;
	
	switch(weapon)
	{
		case Primary_Assets::Player_Weapon_Options::FIST:
			setupFist();
			break;

		case Primary_Assets::Player_Weapon_Options::ARROW:
			setupArrow();
			break;
	}
}

void Player_Weapon::setupFist()
{
	lifetime = 60;
	damage *= 0.25;
	weaponShape = new sf::RectangleShape(sf::Vector2f(10, 10));
	weaponShape->setPosition(dir);
	weaponShape->setFillColor(sf::Color(0, 255, 0));
}

void Player_Weapon::setupArrow()
{
	//TODO
}
