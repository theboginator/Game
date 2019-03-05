#include "Room.h"



Room::Room(std::string description)
{
	this->description = description;
}


Room::~Room()
{
}

std::string Room::getDescription() {
	return this->description;
}

void Room::setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom) {
	this->northRoom = northRoom;
	this->southRoom = southRoom;
	this->eastRoom = eastRoom;
	this->westRoom = westRoom;
}

void Room::setDescription(int roomNum) { //Set each room's description!
	if(roomNum == 0){
		this->description = "Welcome to the cursed forest!\nYour objective: Brave the deadly trail to the observatory to view the Aurora Borealis, an incredibly rare phenomenon at this time of year, at this time of day, localized entirely in this area...\n.Use keywords NORTH, SOUTH, EAST, WEST to indicate direction.\nUse SEARCH to search an area, UNLOCK to open doors \(if you have a key!\), and WHEEDWHACK to use your weedwhacker.\n If you enter an area with an enemy, you MUST neutralize the enemy before going on. Good Luck!";
	}
	else if (roomNum == 1) {
		this->description = "Open clearing with some grass, a river, and an odd-looking shrubbery";
	}
	else if (roomNum == 2) {
		this->description = "You're really in the woods now... the sun is completely blocked by the thick trees, and the forest floor is very swampy and slick here... try not to fall!";
	
	}
	else if (roomNum == 3) {
		this->description = "Lots of woods, nothing but trees; but the trail is plainly marked and clear. Sure is an odd smell of trash in the area though...";
	}
	else if (roomNum == 4) {
		this->description = "There's a cute little cottage sitting at the edge of the trail here. Principal Skinner is probably hiding out inside.";
	}
	else if (roomNum == 5) {
		this->description = "You've run into a large wall running right through the woods. Supposedly, the most dangerous parts of the forest are behind it. There's a door blocking the trail, maybe it can be unlocked...";
	}
	else if (roomNum == 6) {
		this->description = "There's a very deep ravine blocking the trail... Good thing the bridge isn't out!";
	}
	else if (roomNum == 7) {
		this->description = "";
	}
	else if (roomNum == 8) {
		this->description = "";
	}
	else if (roomNum == 9) {
		this->description = "";
	}
	else if (roomNum == 10) {
		this->description = "";
	}
}	

Room* Room::getRoom(std::string direction) {
	if (direction == "North" && this->northRoom != nullptr) {
		return this->northRoom;
	}
	else if (direction == "East" && this->eastRoom != nullptr) {
		return this->eastRoom;
	}
	else if (direction == "South" && this->southRoom != nullptr) {
		return this->southRoom;
	}
	else if (direction == "West" && this->westRoom != nullptr) {
		return this->westRoom;
	}
	else {
		return this;
	}
}

