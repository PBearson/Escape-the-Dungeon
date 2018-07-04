#include "game_assets.h"

Game_Assets::Game_Assets(sf::RenderWindow* window)
{
	// Background sprite
	sf::Vector2f backgroundSize(window->getSize().x, window->getSize().y);
	background = new sf::RectangleShape(backgroundSize);
	background->setFillColor(sf::Color(75, 75, 255));

	// Ground sprite
	sf::Vector2f groundSize(window->getSize().x, window->getSize().y/1.5);
	ground = new sf::RectangleShape(groundSize);
	ground->setPosition(0, window->getSize().y - ground->getSize().y);
	ground->setFillColor(sf::Color(65, 43, 21));

	// Window sprite
	int wallWindowOrigin = window->getSize().x/2;
	sf::Vector2f wallWindowSize(80, 100);
	sf::Vector2f wallBarSize(2, 100);
	float wallWindowOffset = wallWindowSize.x / 4;
	sf::Color windowColor(50, 50, 50);
	wallBar1 = new sf::RectangleShape(wallBarSize);
	wallBar1->setPosition(wallWindowOrigin - wallWindowOffset, 50);
	wallBar1->setFillColor(windowColor);
	wallBar2 = new sf::RectangleShape(wallBarSize);
	wallBar2->setPosition(wallWindowOrigin + wallWindowOffset, 50);
	wallBar2->setFillColor(windowColor);

	// Wall sprite
	float wallLeftEnd = wallWindowOrigin - wallWindowSize.x / 2;
	float wallRightStart = wallWindowOrigin + wallWindowSize.x / 2;
	sf::Vector2f wallLeftSize(wallLeftEnd, window->getSize().y - groundSize.y);
	wallLeft = new sf::RectangleShape(wallLeftSize);
	wallLeft->setFillColor(windowColor);

	// Player sprite
	player = new sf::RectangleShape(sf::Vector2f(25, 50));
	player->setPosition(25, backgroundSize.y/2);
	player->setOutlineColor(sf::Color(0, 0, 0));
	player->setFillColor(sf::Color(0, 255, 0));
}
