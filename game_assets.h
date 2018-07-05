# pragma once
#include <SFML/Graphics.hpp>

class Game_Assets
{
	public:
		sf::RectangleShape* background;
		sf::RectangleShape* player;
		sf::RectangleShape* ground;
		sf::RectangleShape* wallLeft;
		sf::RectangleShape* wallRight;
		sf::RectangleShape* wallTop;
		sf::RectangleShape* wallBottom;
		sf::RectangleShape* wallBar1;
		sf::RectangleShape* wallBar2;
		sf::RectangleShape* wallBar3;

		Game_Assets(sf::RenderWindow*);
};
