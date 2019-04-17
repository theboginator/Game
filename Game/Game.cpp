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
	rooms.push_back(new Room("Room 10", true));
	rooms.push_back(new Room("Room 11", false));

	//Set items to be found in each room:
	rooms[0]->setItems({"cake", "gas", "hockey stick"});
	rooms[1]->setItems({ "gas", "gas", "gas", "cake", "gold", "gold", "glasses" });
	rooms[2]->setItems({ "onion", "cake", "key" });
	rooms[3]->setItems({ "garbage", "egg", "steak", "a copy of Police Academy: mission to Moscow!"});
	rooms[4]->setItems({"cake", "water", "spices"});
	rooms[5]->setItems({"hamburger", "cake", "shovel"});
	rooms[6]->setItems({"matches", "newspaper"});
	rooms[7]->setItems({"cake", "cake", "water", "key"});
	rooms[8]->setItems({"Special Sauce", "lighter fluid", "charcoal"});
	rooms[9]->setItems({"textbook", "cookbook"});
	rooms[10]->setItems({"matches", "grill"});


	rooms[3]->trashman = new Trashman();
	rooms[4]->skinner = new Skinner();
	rooms[6]->mortimer = new Mortimer();
	rooms[9]->ratburn = new Rat();
	rooms[10]->fieri = new Fieri();

	std::vector<std::string> items = { "cake", "gas", "gas", "barbecue sauce" };//Items for the first chest
	rooms[5]->chest.setChest(items, true);; //Load the chest in room 5
	items = { "Lean Cuisine", "cake", "gas", "cake", "lighter fluid" };
	rooms[9]->chest.setChest(items, true); //Load the chest in room 9

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
	rooms[10]->setRooms(rooms[9], nullptr, nullptr, nullptr);

	currentRoom = rooms[0];
}

std::string Game::getUserCommand()
{
	std::string text;
	std::cout << "\n\n\n";
	std::cout << "What do you want to do? ";
	std::getline(std::cin, text);
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);
	std::cout << "\n\n\n";
	return text;
}

void Game::endTheGame(bool victory) {
	if (victory) {
		std::cout << "Congratulations, you successfully navigated the cursed forest! Enjoy your view of the aurora borealis!";
		exit(0);
	}
	else {
		std::cout << "You have DIED on the trail through the cursed forest.\n\nA. Dang it";
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
	int size = static_cast<int>(tempItems.size());
	for (int ctr = 0; ctr < size; ctr++) {
		std::cout << tempItems[ctr] << " ";
	}
	std::cout << "\ndone printing\n";
}

void Game::beginGame() {
	currentPlayer.setName();
	while (userInput != "quit") {
		if (currentRoom != nullptr) {
			std::cout << currentRoom->getDescription() << std::endl; //Show the current room's description
		}
		if (currentRoom->containsBoss) { //If the player enters a room with a boss the boss fight happens first
			battle(currentRoom, 
			int damage;
			if (currentRoom->getNumber == 3) {
				Trashman* boss = currentRoom->getTrashman;
				boss->introduceBoss();

			}
			else if (currentRoom->getNumber == 4){
				Skinner* boss = currentRoom->getSkinner;

			}
			else if (currentRoom->getNumber == 6){
				Mortimer* boss = currentRoom->getMortimer();
			}
			else if (currentRoom->getNumber == 9) {
				Rat* boss = currentRoom->getRat();
			}
			else if (currentRoom->getNumber == 10) {
				Fieri* boss = currentRoom->getFieri();
			}
			boss->introduceBoss(); //Introduce the boss with his/her introduction
			while (currentBoss.disabled != true && currentPlayer.checkHealth() > 0) { //Until the user beats the boss or user dies
				damage = currentBoss.fightBoss(currentPlayer); //Fight the boss, return the damage amount to player
				currentPlayer.hit(damage); //update player damage
				if (damage = 0) { //Player winssz
					std::cout << currentBoss.getBossLosesResponse();
					currentBoss.disabled = true; //Mark the boss as disabled to exit the fight
					rooms[currentRoom->getNumber]->containsBoss = false; //Remove the enabled flag from room map
				}
				else if (currentPlayer.checkHealth() <= 0) { //End the game if the boss wins
					std::cout << currentBoss.getBossWinsResponse();
					endTheGame(false);
				}
				else {
					std::cout << currentBoss.fightContinuesResponse;
				}
			}
		}
		userInput = getUserCommand(); //Get input from the user
		
		if (userInput == "north" || userInput == "south" || userInput == "east" || userInput == "west") { //If the input is a direction
			std::cout << "User entered a direction\n";
			currentRoom = currentRoom->getRoom(userInput); //Attempt to load in a room in the requested direction
		}

		else if (userInput == "search") {
			std::cout << "User entered search\n";
			std::vector<std::string> tempItems = currentRoom->getItems();
			showLoot(tempItems);
			int size = static_cast<int>(tempItems.size());
			for (int ctr = 0; ctr < size; ctr++) {
				currentPlayer.addItem(tempItems[ctr]);
			}
		}
		else if (userInput == "unlock") {
			std::cout << "user attempted to unlock a chest\n";
			if(currentRoom->containsChest){ //If the room contains a chest
				if(currentPlayer.inventoryContains("key", 1)) { //And if the player has a key
					currentPlayer.removeItem("key", 1); //Remove the key from inventory
					std::cout << "You unlocked the chest! You gained: ";
					Chest currentChest = currentRoom->getChest();; //Load the chest into temporary object
					std::vector<std::string> tempItems = currentRoom->returnChestItems(); //Get the items from the chest
					int size = static_cast<int>(tempItems.size());
					for (int ctr = 0; ctr <= size; ctr++) {
						currentPlayer.addItem(tempItems[ctr]); //Load each item in the chest into the player's inventory
						std::cout << tempItems[ctr]; //Print it to the screen
					}
					currentRoom->containsChest = false; //Deactivate the chest
				}
				else {
					std::cout << "You don't have anything to unlock the chest with.";
				}

			}
			else {
				std::cout << "There's no chest in here to unlock...";
			}
		}
		else if (userInput == "inventory") {
			currentPlayer.showInventory();
		}
		else if (userInput == "health") {
			std::cout << "\nYour health is ";
			int health = currentPlayer.checkHealth();
		}
		else if (userInput == "showroom") {
			std::cout << "\nYou are in room " << currentRoom->getNumber << "\n";
		}
		else if (userInput == "hacksetroom") {
			std::cout << "\nWhich room would you like to go to? ";
			int hacknum;
			std::cin >> hacknum;
			std::cout << "\nAttempting move...";
			currentRoom = rooms[hacknum];
			std::cout << "\n\mSuccessfully moved!\n";
		}
		else if (userInput == "quit") {
			endTheGame(false);
		}
		else { //Prompt user again if command wasn't recognized.
			std::cout << "That command wasn't recognized... try again.";
			userInput = getUserCommand();
		}

		std::cout << "\n\n\n";

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