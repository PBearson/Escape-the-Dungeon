#pragma once
#include "primary_assets.h"
#include "player_weapon.h"
#include <vector>

class Player_Logic
{
	public:
		int moveSpeed = 3;
		int attackDelta = 0;
		int attackSpeed = 60;
		bool attacking = false;
		bool movingLeft = false;
		bool movingRight = false;
		bool movingUp = false;
		bool movingDown = false;

		Primary_Assets::Player_Weapon_Options currentWeapon = Primary_Assets::Player_Weapon_Options::FIST;

		std::vector<Player_Weapon*> bullets;

		Player_Logic();
};
