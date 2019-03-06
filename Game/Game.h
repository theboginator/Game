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
	std::vector<Room*> rooms; //the map of rooms in the game
	std::vector<Boss*> bosses; //the array of bosses in the game
	Room* currentRoom; //the room the player is currently in
private:
	void setupRooms();
	//void setupBosses();
};

