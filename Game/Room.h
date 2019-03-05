#pragma once
#include <string>
using namespace std;

class Room
{
public:
	Room(std::string description);
	~Room();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
	Room* getRoom(std::string direction);
	std::string getDescription();

private:
	//List of items
	std::string description;
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;


};

