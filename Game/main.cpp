#include <list>
#include <vector>
#include <iostream>
#include "Room.h"

int main() {
	std::vector<Room*> rooms;
	Room* currentRoom = nullptr; //Set the starting room
	std::string userInput;

	//declare each room and push it into the vector of rooms:
	rooms.push_back(new Room("Room 1"));
	rooms.push_back(new Room("Room 2"));
	rooms.push_back(new Room("Room 3"));
	rooms.push_back(new Room("Room 4"));
	rooms.push_back(new Room("Room 5"));

	//Set each room's adjacent rooms; use nullptr for no connections:
	/*MAP:
	5	3
	|	|
	4---1
		|
		2
	*/
	rooms[0]->setRooms(rooms[2], nullptr, rooms[1], rooms[3]);
	rooms[1]->setRooms(rooms[0], nullptr, nullptr, nullptr);
	rooms[2]->setRooms(nullptr, nullptr, rooms[1], nullptr);
	rooms[3]->setRooms(rooms[4], rooms[0], nullptr, nullptr);
	rooms[4]->setRooms(nullptr, nullptr, rooms[3], nullptr);

	currentRoom = rooms[0]; //start the player in the first room

	while (userInput != "QUIT") {
		std::cout << currentRoom->getDescription() << std::endl;
		
		std::cout << "Where do you want to go? ";
		userInput = std::getLine(std::cin, userInput);
		currentRoom = currentRoom->getRoom(userInput);
	}

}