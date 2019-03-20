#pragma once
#include "Boss.h"
#include <string>

class Room
{
public:
	Room(std::string description, bool containsBoss);
	~Room();

	std::string getDescription();

	void setDescription(int roomNum);
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(std::string direction);
	Boss* getBoss(Room* currentRoom);
	bool containsBoss; //Boolean to show if there is a boss in this room
	int getNumber; //Returns the room number

private:
	// Boss (if any)

	// List of items
	std::vector<std::string> items;
	// Room description
	std::string description;
	// The adjacent Rooms
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
};

