#include "game_assets.h"

Game_Assets::Game_Assets(sf::RenderWindow* window)
{
	// Background sprite
	sf::Vector2f backgroundSize(window->getSize().x, window->getSize().y);
	background = new sf::RectangleShape(backgroundSize);
	background->setFillColor(sf::Color(75, 75, 255));
}
