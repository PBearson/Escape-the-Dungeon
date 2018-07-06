#pragma once
#include <SFML/Graphics.hpp>
#include "weapons_logic.h"
#include "primary_assets.h"
#include <iostream>

class Player_Weapon
{
	public:
		Primary_Assets::Player_Weapon_Options weapon;
		float damage;
		sf::Vector2f* dir;
		float speed;
		sf::RectangleShape* weaponShape;
		
		Player_Weapon(Primary_Assets::Player_Weapon_Options, float, sf::Vector2f*, float);
};
