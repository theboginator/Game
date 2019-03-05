#pragma once
#include <vector>
#include <string>
#include "Room.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void buildMap();
	void beginGame();
	std::vector<Room*> rooms; //the map of rooms in the game
	Room* currentRoom; //the room the player is currently in
};

