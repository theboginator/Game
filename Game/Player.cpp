#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::setName() {
	std::cout << "Enter your name: ";
	std::string pname;
	std::getline(std::cin, pname);
	name = pname;
	health = 100;
}

void Player::eat() { //If inventory contains food, consume 1 food item each time the function is called
	if (std::find( inventory.begin(), inventory.end(), "cake") != inventory.end()){
		removeItem("cake", 1);
		heal(20);
	}
	else {
		std::cout << "You have no food in your inventory to consume!";
	}
}
void Player::hit(int damage) {//Used by a boss to damage the player
	health = health - damage;
}
bool Player::inventoryContains(std::string check, int qty) { //Check if inventory contains an item in at least the specified quantity
	int tempqty = 0;
	int size = static_cast<int>(inventory.size());
	for (int ctr = 0; ctr < size; ctr++) {
		if (inventory[ctr] == check) {
			tempqty++;
		}
	}
	if (tempqty == qty) {
		return true;
	}
	else {
		return false;
	}
}
int Player::checkqty(std::string item) { //Check how much of an item the player has; if none returns 0; 
	int tempqty = 0;
	int size = static_cast<int>(inventory.size());
	for (int ctr = 0; ctr < size; ctr++) {
		if (inventory[ctr] == item) {
			tempqty++;
		}
	}
	return tempqty;
}
void Player::addItem(std::string item) { //Add an item to inventory
	inventory.push_back(item);
}
void Player::removeItem(std::string item, int qty) {//Remove a specific amount of an item from inventory
	//
}
void Player::useItem(std::string item) { //Use an item in the inventory; print
}
void Player::showInventory() { //Function to show inventory
	int size = static_cast<int>(inventory.size());
	for (int ctr = 0; ctr < size; ctr++) {
		std::cout << inventory[ctr] << " ";
	}
	std::cout << "\nDone Printing\n";
}
int Player::checkHealth() {
	return health; //Returns health
}
void Player::hurt(int damage){
	health = health - damage;
}// damage the player
void Player::heal(int hp) {
	if (health + hp < 100) {
		std::cout << "\nYour health is already maxed.\n";
	}
	else {
		health = health + hp;
	}
}//heal the player
