#include <list>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Game.h"

int main() {

	//std::vector<Room*> rooms;
	//Room* currentRoom = nullptr;
	

	Game theGame; //Create a new game
	Player thePlayer; //Create a new player
	theGame.buildMap(); //Build the game's map
	theGame.beginGame(); //Start the game!
	
}

//Set each room's adjacent rooms; use nullptr for no connections:
	/*MAP:
	5	3
	|	|
	4---1
		|
		2

		while (userInput != "QUIT") {
		if (theGame.currentRoom != nullptr) {
			std::cout << theGame.currentRoom->getDescription() << std::endl;
		}

		std::cout << "Where do you want to go? ";
		std::getline(std::cin, userInput);

		theGame.currentRoom = theGame.currentRoom->getRoom(userInput);
	}
	*/