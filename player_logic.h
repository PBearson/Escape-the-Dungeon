#pragma once
#include "primary_assets.h"
#include "player_weapon.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player_Logic
{
	public:
		float moveSpeed = 3;
		float attackMoveSpeed = 10;
		float attackDamage = 2;
		int attackDelta = 0;
		int attackSpeed = 20;
		bool attacking = false;
		bool movingLeft = false;
		bool movingRight = false;
		bool movingUp = false;
		bool movingDown = false;

		Primary_Assets::Player_Weapon_Options currentWeapon;

		std::vector<Player_Weapon*> bullets;

		Player_Logic();

		void attack(sf::Vector2f, sf::Vector2i);
		void updateWeapons();
};
