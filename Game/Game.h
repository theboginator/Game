#pragma once
#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"
#include "Boss.h"

class Game
{
public:
	Game();
	~Game();
	void buildMap();
	void beginGame();
	void endTheGame(bool win); //End the game, true = win, false = lose
	void processCommand(std::string command); //Handles a user command
	void showLoot(std::vector<std::string> tempItems); //Prints all the items a player just acquired via search function
	std::vector<Room*> rooms; //the map of rooms in the game
	std::vector<Boss*> bosses; //the array of bosses in the game
	Room* currentRoom; //the room the player is currently in
	Player currentPlayer; //Set up a player

private:
	std::string userInput = "";
	void setupRooms();
	std::string getUserCommand();
	//void setupBosses();
};

