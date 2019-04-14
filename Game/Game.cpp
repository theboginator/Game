#include "Game.h"
#include <string>
#include <iostream>
#include <algorithm>



Game::Game()
{
}


Game::~Game()
{
}

void Game::setupRooms() {
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

	rooms[3]->trashman = new Trashman();
	rooms[4]->skinner = new Skinner();
	rooms[6]->mortimer = new Mortimer();
	rooms[9]->ratburn = new Rat();
	std::vector<std::string> items = { "cake", "gas", "gas", "barbecue sauce" };//Items for the first chest
	rooms[5]->chest = new Chest(items, true); //Load the chest in room 5
	items = { "Lean Cuisine", "cake", "gas", "cake", "lighter fluid" };
	rooms[9]->chest = new Chest(items, true); //Load the chest in room 9

	for (int ctr = 0; ctr <= 10; ctr++) {
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
	rooms[7]->setRooms(rooms[6], nullptr, nullptr, rooms[8]);
	rooms[8]->setRooms(nullptr, rooms[7], nullptr, rooms[9]);
	rooms[9]->setRooms(nullptr, rooms[8], rooms[10], nullptr);

	currentRoom = rooms[0];
}

std::string Game::getUserCommand()
{
	std::cout << "\n\n\n";
	std::cout << "What do you want to do? ";
	std::getline(std::cin, userInput);
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	std::cout << "\n\n\n";
	return userInput;
}

void endTheGame(bool victory) {
	if (victory) {
		std::cout << "Congratulations, you successfully navigated the cursed forest! Enjoy your view of the aurora borealis!";
		exit(0);
	}
	else {
		std::cout << "You have died on the trail through the cursed forest.\n\nA. Dang it";
		std::cout << "\n\n\n";
		std::cout << "What do you want to do? ";
		std::string answer;
		std::getline(std::cin, answer);
		exit(0);
	}
	

}
/*
void Game::setupBosses() {
	bosses.push_back(new Boss())
}
*/
void Game::buildMap() {
	Game::setupRooms();
	//Game::setupBosses();
	
}

void Game::processCommand(std::string userInput) {

}

void Game::showLoot(std::vector<std::string> tempItems) {
	std::cout << "You have found.... ";
	for (int ctr = 0; ctr <= tempItems.size; ctr++) {
		std::cout << tempItems[ctr];
	}
}

void Game::beginGame() {
	currentPlayer.setName();
	while (userInput != "quit") {
		if (currentRoom != nullptr) {
			std::cout << currentRoom->getDescription() << std::endl; //Show the current room's description
		}
		if (currentRoom->containsBoss) { //If the player enters a room with a boss the boss fight happens first
			int damage;
			Boss currentBoss = currentRoom->getBoss();
			currentBoss.introduceBoss; //Introduce the boss with his/her introduction
			while (currentBoss.disabled != true && currentPlayer.checkHealth > 0) { //Until the user beats the boss or user dies
				damage = currentBoss.fightBoss(currentPlayer); //Fight the boss, return the damage amount to player
				currentPlayer.hit(damage); //update player damage
				if (damage = 0) { //Player wins
					std::cout << currentBoss.getBossLosesResponse();
					currentBoss.disabled = true; //Mark the boss as disabled to exit the fight
					rooms[currentRoom->getNumber]->containsBoss = false; //Remove the enabled flag from room map
				}
				else if (currentPlayer.checkHealth <= 0) {
					std::cout << currentBoss.getBossWinsResponse();
					endTheGame(false);
				}
				else {
					std::cout << currentBoss.fightContinuesResponse;
				}
			}
		}
		userInput = getUserCommand(); //Get input from the user
		
		if (userInput = direction) { //If the input is a direction
			Room* tempRoom = currentRoom->getRoom(userInput); //Attempt to load in a room in the requested directions
			if(tempRoom->isLocked == true){ //If the next room is locked
				std::cout << "You can't move in that direction, the door is locked.";
			}
			else {
				currentRoom = tempRoom;
			}
			
		}
		else if (userInput = command) { //If the user imput is a command
			processCommand(userInput); //process search/eat/weedwhack/etc
			if (userInput == "search") {
				std::vector<std::string> tempItems = currentRoom->getItems();
				showLoot(tempItems);
				for (int ctr = 0; ctr <= tempItems.size; ctr++) {
					currentPlayer.addItem(tempItems[ctr]);
				}
			}
			else if (userInput == "unlock") {
				if currentRoom.isLocked{ //If the room is locked
					if currentPlayer.inventoryContains("key", 1) { //And if the player has a key
						currentRoom.isLocked = false; //Unlock the room
						currentPlayer.removeItem("key", 1);
						std::cout << "You unlocked the gate!";
					}
					else {
						std::cout << "You don't have anything to unlock the gate with.";
					}

				}
			}
		}
		else { //Prompt user again if command wasn't recognized.
			std::cout << "That command wasn't recognized... try again.";
			userInput = getUserCommand();
		}

	}

	
	/*
	WHILE USERINPUT != QUIT
		if currentRoom contains a boss & boss is enabled
			while boss is not defeated:
				BossFight!!!!!
		else
		print room description
		listen for keyword
		if keyword = north, south, east, west
			attemptToMove
		else if keyword = search, explore, eat, weedwhack, inventory, stats
			switch keyword:
				search the area
					any items in the room are deleted
					add items to playerInventory
				explore
					if room has secret and secret is exposed
					use shortcut set new room to shortcut exit
				eat
					if playerInventory contains cake
					remove 1 cake from inventory
					+20 food to stats
				weedwhack 
					if playerInventory contains weedwhacker
						if room has secret
						expose secret

	*/
	
}