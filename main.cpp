#include <SFML/Graphics.hpp>
#include "game_assets.h"
#include <iostream>
using namespace std;

void handleAll();
void handleMiscEvents();
void handleMainMenuLogic();
void handleMainMenuEvents();
void handleMainMenuView();
void handleGameLogic();
void handleGameEvents();
void handleGameView();

Game_Assets* gameAssets = new Game_Assets();
sf::RenderWindow* window;
Game_Assets::Game_State currentState = Game_Assets::Game_State::IN_GAME;

// Handle everything in the game
void handleAll()
{
	switch(currentState)
	{
		case Game_Assets::Game_State::IN_MAIN_MENU:
			handleMainMenuEvents();
			handleMainMenuLogic();
			handleMainMenuView();
			break;

		case Game_Assets::Game_State::IN_GAME:
			  handleGameEvents();
			  handleGameLogic();
			  handleGameView();
			  break;

		default:
			  cout << "Error: Game condition not handled" << endl;
			  exit(1);
	}
}

// Handle window events while in main menu
void handleMainMenuEvents()
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
void handleGameEvents()
{
	//TODO
}

// Handle window logic while in main game
void handleGameLogic()
{
	//TODO
}

// Handle window logic while in main game
void handleGameView()
{
	window->clear();
	window->draw(*(gameAssets->background));
	window->display();
}

// Miscellaneous events
void handleMiscEvents()
{
	sf::Event e;
	int closed = sf::Event::Closed;

	// No events - ignore
	if(!window->pollEvent(e)) return;

	// Close window
	if(e.type == closed) window->close();	
}

int main()
{
	int wWidth = gameAssets->windowWidth;
	int wHeight = gameAssets->windowHeight;
	std::string wName = gameAssets->windowName;	
	window = new sf::RenderWindow(sf::VideoMode(wWidth, wHeight), wName);

	sf::Clock clock;
	float timer = 0;
	float spf = 1.0f / gameAssets->fps;

	while(window->isOpen())
	{
		handleMiscEvents();
		if(clock.getElapsedTime().asSeconds() >= spf)
		{
			handleAll();
			clock.restart();
		}
	}
}
