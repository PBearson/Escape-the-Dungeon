#include "player_weapon.h"
#include <math.h>

Player_Weapon::Player_Weapon(Primary_Assets::Player_Weapon_Options w, sf::Vector2f s, sf::Vector2i d, float d2, float m)
{
	weapon = w;
	src = s;
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

void Player_Weapon::updateWeapon()
{
	switch(weapon)
	{
		case Primary_Assets::Player_Weapon_Options::FIST:
			updateFist();
			break;

		case Primary_Assets::Player_Weapon_Options::ARROW:
			setupArrow();
			break;
	}
}

void Player_Weapon::setupFist()
{
	lifetime = 10;
	damage *= 0.25;
	sf::Vector2f size(15, 15);
	sf::Vector2f center(src.x - size.x/2, src.y - size.y/2);
	weaponShape = new sf::RectangleShape(size);
	weaponShape->setPosition(center);
	weaponShape->setFillColor(sf::Color(0, 255, 0));
}

void Player_Weapon::setupArrow()
{
	//TODO
}

void Player_Weapon::updateFist()
{
	sf::Vector2f moveDir(0, 0);
	double moveAngle = atan2(dir.y - src.y, dir.x - src.x);
	weaponShape->move(cos(moveAngle) * moveSpeed, sin(moveAngle) * moveSpeed);
}

void Player_Weapon::updateArrow()
{
	//TODO
}
