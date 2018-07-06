#pragma once
#include "primary_assets.h"
#include "player_weapon.h"
#include <vector>

class Weapons_Logic
{
	public:

		Primary_Assets::Player_Weapon_Options currentWeapon = Primary_Assets::Player_Weapon_Options::FIST;
	
		std::vector<Player_Weapon*> bullets;
	
		Weapons_Logic();
};
