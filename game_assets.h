# pragma once
#include <SFML/Graphics.hpp>

class Game_Assets
{
	public:
		sf::RectangleShape* background;
		sf::RectangleShape* player;

		Game_Assets(sf::RenderWindow*);
};
