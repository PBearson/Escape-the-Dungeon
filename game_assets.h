# pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game_Assets
{
	public:
		int windowWidth = 800, windowHeight = 600;
		std::string windowName = "Escape the Dungeon";
		int fps = 60;
		enum Game_State
		{
			IN_GAME,
			IN_SHOP,
			IN_SPIRIT_SHOP,
			IN_MAIN_MENU,
			IN_PAUSE_MENU
		};

		sf::RectangleShape* background;
		Game_Assets();
};
