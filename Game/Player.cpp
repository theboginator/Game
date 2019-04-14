#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::eat() { //If inventory contains food, consume 1 food item each time the function is called
	if (std::find( inventory.begin(), inventory.end(), "cake") != inventory.end()){
		removeItem("cake", 1);
	}
	else {
		std::cout << "You have no food in your inventory to consume!";
	}
}
void Player::hit(int damage) {//Used by a boss to damage the player
	health = health - damage;
}
bool Player::inventoryContains(std::string check, int qty) { //Check if inventory contains an item in at least the specified quantity
	
}
int Player::checkqty(std::string item) { //Check how much of an item the player has; if none returns 0; 

}
void Player::addItem(std::string item) { //Add an item to inventory
	inventory.push_back(item);
}
void Player::removeItem(std::string item, int qty) {//Remove a specific amount of an item from inventory
	//
}
void Player::useItem(std::string item) { //Use an item in the inventory; print
}
std::string Player::showInventory() { //Function to show inventory
	
}
int checkHealth; //Returns health
void hurt(int damage); // damage the player
void heal(int hp); //heal the player
int checkHunger; //Returns hunger