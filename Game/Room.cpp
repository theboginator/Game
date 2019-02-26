#include "Room.h"
using namespace std;



Room::Room(std::string description)
{
}


Room::~Room()
{
}

std::string Room::getDescription() {
}

Room* Room::getRoom(std::string direction) {
	if (direction == "North" && this->northRoom != nullptr) {
		return this -> northRoom;
	}
	if (direction == "East" && this->eastRoom != nullptr) {
		return this->northRoom;
	}
	if (direction == "South" && this->southRoom != nullptr) {
		return this->northRoom;
	}
	if (direction == "West" && this->westRoom != nullptr) {
		return this->northRoom;
	}
	else {
		return this;
	}
}