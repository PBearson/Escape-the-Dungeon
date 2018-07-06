#include "game_assets.h"
#include <random>

Game_Assets::Game_Assets(sf::RenderWindow* window)
{
	// Initialize RNG
	std::random_device rd;

	// Background sprite
	sf::Vector2f backgroundSize(window->getSize().x, window->getSize().y);
	background = new sf::RectangleShape(backgroundSize);
	background->setFillColor(sf::Color(75, 75, 255));

	// Ground sprite
	sf::Vector2f groundSize(window->getSize().x, window->getSize().y/1.5);
	ground = new sf::RectangleShape(groundSize);
	ground->setPosition(0, window->getSize().y - ground->getSize().y);
	ground->setFillColor(sf::Color(55, 43, 21));

	// Ceiling
	sf::Vector2f ceilingSize(window->getSize().x, 30);
	ceiling = new sf::RectangleShape(ceilingSize);
	ceiling->setFillColor(sf::Color(25, 25, 25));

	// Window sprite
	int wallWindowOrigin = rd() % window->getSize().x;
	sf::Vector2f wallWindowSize(rd() % 40 + 90, rd() % 40 + 90);
	sf::Vector2f wallBarSize(2, wallWindowSize.y);
	float wallWindowOffset = wallWindowSize.x / 4;
	sf::Color windowColor(50, 50, 50);
	wallBar1 = new sf::RectangleShape(wallBarSize);
	wallBar1->setPosition(wallWindowOrigin - wallWindowOffset, 50);
	wallBar1->setFillColor(windowColor);
	wallBar2 = new sf::RectangleShape(wallBarSize);
	wallBar2->setPosition(wallWindowOrigin + wallWindowOffset, 50);
	wallBar2->setFillColor(windowColor);
	wallBar3 = new sf::RectangleShape(wallBarSize);
	wallBar3->setPosition(wallWindowOrigin, 50);
	wallBar3->setFillColor(windowColor);

	// Wall sprite
	float wallLeftEnd = wallWindowOrigin - wallWindowSize.x / 2;
	float wallRightStart = wallWindowOrigin + wallWindowSize.x / 2;
	float wallBottomStart = 50 + wallBarSize.y;
	sf::Vector2f wallLeftSize(wallLeftEnd, window->getSize().y - groundSize.y);
	sf::Vector2f wallRightSize(window->getSize().x - wallRightStart, window->getSize().y - groundSize.y);
	sf::Vector2f wallTopSize(wallRightStart - wallLeftEnd, 50);
	sf::Vector2f wallBottomSize(wallRightStart - wallLeftEnd, ground->getPosition().y - wallBottomStart);
	wallLeft = new sf::RectangleShape(wallLeftSize);
	wallLeft->setFillColor(windowColor);
	wallRight = new sf::RectangleShape(wallRightSize);
	wallRight->setPosition(sf::Vector2f(wallRightStart, 0));
	wallRight->setFillColor(windowColor);
	wallTop = new sf::RectangleShape(wallTopSize);
	wallTop->setPosition(sf::Vector2f(wallLeftEnd, 0));
	wallTop->setFillColor(windowColor);
	wallBottom = new sf::RectangleShape(wallBottomSize);
	wallBottom->setPosition(sf::Vector2f(wallLeftEnd, wallBottomStart));
	wallBottom->setFillColor(windowColor);

	// Player sprite
	player = new sf::RectangleShape(sf::Vector2f(25, 50));
	player->setPosition(25, backgroundSize.y/2);
	player->setOutlineColor(sf::Color(0, 0, 0));
	player->setFillColor(sf::Color(0, 255, 0));
}
