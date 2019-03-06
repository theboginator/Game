#pragma once
#include <string>
#include <vector>
class Player
{
public:
	Player();
	~Player();
<<<<<<< HEAD
	std::string name;
	std::vector<std::string> inventory;
	int health; //Player's health out of 100
	int hunger; //Player's hunger out of 100
	void eat(); //If inventory contains food, consume 1 food item each time the function is called
	void hit(int damage); //Used by a boss to damage the player
	bool inventoryContains(std::string check); //Check if inventory contains an item
	void addItem(std::string item); //Add an item to inventory
	void removeItem(std::string item); //Remove an item from inventory
	void useItem(std::string item); //Use an item in the inventory; print
=======
	std::vector<std::string> inventory;

>>>>>>> 8574591994b0842f7593183b33c57ae4e7536239
};

