#pragma once
#include <SFML/Graphics.hpp>
#include "primary_assets.h"
#include "game_assets.h"
#include <iostream>

class Player_Weapon
{
	public:
		Primary_Assets::Player_Weapon_Options weapon;
		sf::RectangleShape* weaponShape;
		sf::Vector2f dir;
		float damage;
		float moveSpeed;
		int lifetime;
		bool alive = true;
		
		Player_Weapon(Primary_Assets::Player_Weapon_Options, sf::Vector2f, float, float);

	private:
		void setupFist();
		void setupArrow();
};
