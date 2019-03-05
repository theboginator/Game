#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::buildMap() {
	/*Game Map:
	0
	|
	1--2
	   |
	   3
	   |
	   4--5
	      |
		  6
		  |
	9--8--7
	|
	10
	Build the array of rooms, and set the "has boss" parameter
	*/
	
	rooms.push_back(new Room("Room 0", false));
	rooms.push_back(new Room("Room 1", false));
	rooms.push_back(new Room("Room 2", false));
	rooms.push_back(new Room("Room 3", true));
	rooms.push_back(new Room("Room 4", true));
	rooms.push_back(new Room("Room 5", false));
	rooms.push_back(new Room("Room 6", true));
	rooms.push_back(new Room("Room 7", false));
	rooms.push_back(new Room("Room 8", false));
	rooms.push_back(new Room("Room 9", true));
	rooms.push_back(new Room("Room 10", false));

	for (int ctr = 0; ctr <= rooms.size; ctr++) {
		rooms[ctr]->setDescription(ctr);
	}

	//Set each room's adjacent rooms
	//					North	East	South	West
						
	rooms[0]->setRooms(nullptr, nullptr, rooms[1], nullptr);
	rooms[1]->setRooms(rooms[0], rooms[2], nullptr, nullptr);
	rooms[2]->setRooms(nullptr, nullptr, rooms[3], rooms[1]);
	rooms[3]->setRooms(rooms[2], nullptr, rooms[4], nullptr);
	rooms[4]->setRooms(rooms[3], rooms[5], nullptr, nullptr);
	rooms[5]->setRooms(nullptr, nullptr, rooms[6], rooms[4]);
	rooms[6]->setRooms(rooms[5], nullptr, rooms[7], nullptr);
	rooms[7]->setRooms(nullptr, nullptr, rooms[3], rooms[1]);
	rooms[8]->setRooms(rooms[2], nullptr, rooms[4], nullptr);
	rooms[9]->setRooms(rooms[3], rooms[5], nullptr, nullptr);

	currentRoom = rooms[0];
}