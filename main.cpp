#include <SFML/Graphics.hpp>
#include "primary_assets.h"
#include "game_assets.h"
#include "player_logic.h"
#include <iostream>
using namespace std;

void handleLogicAndView();
void handleMiscEvents(sf::Event);
void handleMainMenuLogic();
void handleMainMenuEvents(sf::Event);
void handleMainMenuView();
void handleGameLogic();
void handleGameEvents(sf::Event);
void handleGameView();

// Main window
sf::RenderWindow* window;

// Load assets
Primary_Assets* primaryAssets;
Game_Assets* gameAssets;
Player_Logic* playerLogic;

// Set game state
Primary_Assets::Game_State currentState = Primary_Assets::Game_State::IN_GAME;

// Handle all event-related stuff in the game
void handleEvents(sf::Event e)
{
	handleMiscEvents(e);
	switch(currentState)
	{
		case Primary_Assets::Game_State::IN_MAIN_MENU:
			handleMainMenuEvents(e);
			break;

		case Primary_Assets::Game_State::IN_GAME:
			handleGameEvents(e);
			break;

		default:
			cout << "Error: Cannot handle events related to game state" << endl;
			break;
	}
}


// Handle logic and drawing in the game
void handleLogicAndView()
{
	switch(currentState)
	{
		case Primary_Assets::Game_State::IN_MAIN_MENU:
			handleMainMenuLogic();
			handleMainMenuView();
			break;

		case Primary_Assets::Game_State::IN_GAME:
			  handleGameLogic();
			  handleGameView();
			  break;

		default:
			  cout << "Error: Game condition not handled" << endl;
			  exit(1);
	}
}

// Handle window events while in main menu
void handleMainMenuEvents(sf::Event e)
{
	//TODO
}

// Handle window logic while in main menu
void handleMainMenuLogic()
{
	//TODO
}

// Handle window drawing while in main menu
void handleMainMenuView()
{
	//TODO
}

// Handle window events while in main game
void handleGameEvents(sf::Event e)
{
	// Establish events
	int keyPressed = sf::Event::KeyPressed;
	int keyReleased = sf::Event::KeyReleased;
	int mousePressed = sf::Event::MouseButtonPressed;
	int mouseReleased = sf::Event::MouseButtonReleased;
	
	// Movement values
	int movedRightD = sf::Keyboard::D, movedRight = sf::Keyboard::Right;
	int movedLeftA = sf::Keyboard::A, movedLeft = sf::Keyboard::Left;
	int movedUpW = sf::Keyboard::W, movedUp = sf::Keyboard::Up;
	int movedDownS = sf::Keyboard::S, movedDown = sf::Keyboard::Down;
	bool pressing = false;

	// Check movement
	if(e.type == keyPressed) pressing = true;
	else if(e.type == keyReleased) pressing = false;

	if(e.key.code == movedRight || e.key.code == movedRightD) playerLogic->movingRight = pressing;
	if(e.key.code == movedLeft || e.key.code == movedLeftA) playerLogic->movingLeft = pressing;
	if(e.key.code == movedUp || e.key.code == movedUpW) playerLogic->movingUp = pressing;
	if(e.key.code == movedDown || e.key.code == movedDownS) playerLogic->movingDown = pressing;

	// Check shooting
	if(e.type == mousePressed) playerLogic->attacking = true;	
	if(e.type == mouseReleased) playerLogic->attacking = false;
}

// Handle window logic while in main game
void handleGameLogic()
{
	sf::Vector2f playerMoveDelta = {0, 0};
	float playerMoveSpeed = playerLogic->moveSpeed;

	// Decide player movement
	if(playerLogic->movingRight) playerMoveDelta += {playerMoveSpeed, 0};
	if(playerLogic->movingLeft) playerMoveDelta += {-playerMoveSpeed, 0};
	if(playerLogic->movingUp) playerMoveDelta += {0, -playerMoveSpeed};
	if(playerLogic->movingDown) playerMoveDelta += {0, playerMoveSpeed};

	// Handle player movement
	gameAssets->player->move(playerMoveDelta);

	// Bounds parameters
	sf::Vector2f playerPosition = gameAssets->player->getPosition();
	sf::Vector2f playerSize = gameAssets->player->getSize();
	sf::Vector2f groundPosition = gameAssets->ground->getPosition();
	sf::Vector2f groundSize = gameAssets->ground->getSize();

	// Check Top
	if(playerPosition.y + playerSize.y < groundPosition.y)
	{
		gameAssets->player->setPosition(playerPosition.x, groundPosition.y - playerSize.y);
	}

	// Check bottom
	if(playerPosition.y + playerSize.y > groundPosition.y + groundSize.y)
	{
		gameAssets->player->setPosition(playerPosition.x, groundPosition.y + groundSize.y - playerSize.y);
	}

	// Check left TODO
	
	// Check right TODO
	
	// Check shooting
	if(playerLogic->attackDelta > 0) playerLogic->attackDelta--;
	else if(playerLogic->attacking)
	{
		sf::Vector2f playerPosition = gameAssets->player->getPosition();
		sf::Vector2f playerSize = gameAssets->player->getSize();
		sf::Vector2f playerCenter(playerPosition.x + playerSize.x/2, playerPosition.y + playerSize.y/2);
		playerLogic->attack(playerCenter, sf::Mouse::getPosition(*window));
		playerLogic->attackDelta = playerLogic->attackSpeed;
	}

	// Handle attacks
	playerLogic->updateWeapons();
}

// Handle window logic while in main game
void handleGameView()
{
	window->clear();
	window->draw(*(gameAssets->background));
	window->draw(*(gameAssets->ground));
	window->draw(*(gameAssets->wallLeft));
	window->draw(*(gameAssets->wallRight));
	window->draw(*(gameAssets->wallTop));
	window->draw(*(gameAssets->wallBottom));
	window->draw(*(gameAssets->wallBar1));
	window->draw(*(gameAssets->wallBar2));
	window->draw(*(gameAssets->wallBar3));
	window->draw(*(gameAssets->ceiling));
	window->draw(*(gameAssets->player));
	for(Player_Weapon* bullet : playerLogic->bullets) window->draw(*(bullet->weaponShape));
	window->display();
}

// Miscellaneous events
void handleMiscEvents(sf::Event e)
{
	int closed = sf::Event::Closed;

	// Close window
	if(e.type == closed) window->close();	
}

int main()
{
	// Load primary assets
	primaryAssets = new Primary_Assets();

	// Load window
	int wWidth = primaryAssets->windowWidth;
	int wHeight = primaryAssets->windowHeight;
	std::string wName = primaryAssets->windowName;	
	window = new sf::RenderWindow(sf::VideoMode(wWidth, wHeight), wName);

	// Load other assets
	gameAssets = new Game_Assets(window);

	// Load player logic
	playerLogic = new Player_Logic();

	// Set clock interval
	sf::Clock clock;
	float timer = 0;
	float spf = 1.0f / primaryAssets->fps;
	
	// Run window
	while(window->isOpen())
	{
		sf::Event e;
		while(window->pollEvent(e)) handleEvents(e);

		if(clock.getElapsedTime().asSeconds() >= spf)
		{
			handleLogicAndView();
			clock.restart();
		}
	}
}
