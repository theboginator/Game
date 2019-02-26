#pragma once
using namespace std;

class Room
{
public:
	Room(std::string description);
	~Room();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);
	void getRoom(std::string direction);
	std::string getDescription();

private:
	//List of items
	std::string description;
	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;


};

