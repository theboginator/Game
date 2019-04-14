#pragma once
#include "Boss.h"
#include <string>
#include <iostream>
#include <algorithm>

class Room
{
public:
	Room(std::string description, bool containsBoss, bool isLocked);
	~Room();

	std::string getDescription();

	void setDescription(int roomNum);
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(std::string direction); //Returns a room in the requested direction
	Boss getBoss(); //Returns the boss in the room
	Rat* ratburn; //Boss object to hold Mr. Ratburn
	Mortimer* mortimer; //Boss object to hold Mortimer Mouse
	Skinner* skinner; //Boss object to hold Seymour Skinner
	Trashman* trashman; //Boss object to hold Danny DeVito

	bool containsBoss; //Boolean to show if there is a boss in this room
	bool isLocked; //Boolean to show if the room has a locked gate/door
	int getNumber; //Returns the room number
	std::vector<std::string> getItems(); //Returns the items in a room

private:
	// Boss (if any)
	Boss boss;
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

