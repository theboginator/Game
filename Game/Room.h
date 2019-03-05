#pragma once

#include <string>

class Room
{
public:
	Room(std::string description);
	~Room();

	std::string getDescription();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(std::string direction);


private:
	// List of items
	std::string description;
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
};

