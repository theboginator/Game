#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void eat() { //If inventory contains food, consume 1 food item each time the function is called
	if (std::find( inventory.begin(), inventory.end(), "cake") != inventory.end())
	{
		removeItem("cake", 1);
	}
}
void hit(int damage); //Used by a boss to damage the player
bool inventoryContains(std::string check, int qty); //Check if inventory contains an item in at least the specified quantity
int checkqty(std::string item); //Check how much of an item the player has; if none returns 0; 
void addItem(std::string item) { //Add an item to inventory
	inventory.push_back(item);
}
void removeItem(std::string item, int qty) {//Remove a specific amount of an item from inventory
	//
}
void useItem(std::string item); //Use an item in the inventory; print
std::string showInventory(); //Function to show inventory
int checkHealth; //Returns health
void hurt(int damage); // damage the player
void heal(int hp); //heal the player
int checkHunger; //Returns hunger