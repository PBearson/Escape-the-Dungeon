#include "player_logic.h"

Player_Logic::Player_Logic()
{
	currentWeapon = Primary_Assets::Player_Weapon_Options::FIST;
}

void Player_Logic::attack(sf::Vector2f src)
{
	switch(currentWeapon)
	{
		case Primary_Assets::Player_Weapon_Options::FIST:
		{
			Player_Weapon* newFist = new Player_Weapon(currentWeapon, src, attackDamage, attackMoveSpeed);
			bullets.push_back(newFist);
			break;
		}

		case Primary_Assets::Player_Weapon_Options::ARROW:
			//TODO
			break;

		default:
		{
			printf("%s\n", "You haven't handled that weapon yet.");
			exit(1);
		}
	}
}

void Player_Logic::updateWeapons()
{
	for(int i = 0; i < bullets.size(); i++)
	{
		// TODO
	}
}
