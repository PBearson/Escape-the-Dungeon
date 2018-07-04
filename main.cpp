#include <SFML/Graphics.hpp>
#include "primary_assets.h"
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

// Main window
sf::RenderWindow* window;

// Load assets
Primary_Assets* primaryAssets;
Game_Assets* gameAssets;

// Set game state
Primary_Assets::Game_State currentState = Primary_Assets::Game_State::IN_GAME;

// Handle everything in the game
void handleAll()
{
	switch(currentState)
	{
		case Primary_Assets::Game_State::IN_MAIN_MENU:
			handleMainMenuEvents();
			handleMainMenuLogic();
			handleMainMenuView();
			break;

		case Primary_Assets::Game_State::IN_GAME:
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
	window->draw(*(gameAssets->ground));
	window->draw(*(gameAssets->wallLeft));
	window->draw(*(gameAssets->wallBar1));
	window->draw(*(gameAssets->wallBar2));
	window->draw(*(gameAssets->player));
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
	// Load primary assets
	primaryAssets = new Primary_Assets();

	// Load window
	int wWidth = primaryAssets->windowWidth;
	int wHeight = primaryAssets->windowHeight;
	std::string wName = primaryAssets->windowName;	
	window = new sf::RenderWindow(sf::VideoMode(wWidth, wHeight), wName);

	// Load other assets
	gameAssets = new Game_Assets(window);
	
	// Set clock interval
	sf::Clock clock;
	float timer = 0;
	float spf = 1.0f / primaryAssets->fps;
	
	// Run window
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
