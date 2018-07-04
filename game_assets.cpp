#include "game_assets.h"

Game_Assets::Game_Assets()
{
	// Background sprite
	background = new sf::RectangleShape(sf::Vector2f(windowWidth, windowHeight));
	background->setFillColor(sf::Color(75, 75, 255));
}
