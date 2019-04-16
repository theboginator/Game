#pragma once
#include <string>
#include <vector>
#include <iostream>

class Player
{
public:
	
	Player();
	~Player();
	
	std::string name;
	
	void eat(); //If inventory contains food, consume 1 food item each time the function is called
	void hit(int damage); //Used by a boss to damage the player
	bool inventoryContains(std::string check, int qty); //Check if inventory contains an item in at least the specified quantity
	int checkqty(std::string item); //Check how much of an item the player has; if none returns 0; 
	void addItem(std::string item); //Add an item to inventory
	void removeItem(std::string item, int qty); //Remove a specific amount of an item from inventory
	void useItem(std::string item); //Use an item in the inventory; print
	void showInventory(); //Function to show inventory
	int checkHealth();
	void hurt(int damage); // damage the player
	void heal(int hp); //heal the player
	int checkHunger; //Returns hunger
	void feed(int food); //increments hunger by specified amount
	void setName(); //Set the name of the player
	
	
private:
	int health; //Player's health out of 100
	int hunger; //Player's hunger out of 100
	std::vector<std::string> inventory; //holds the player's inventory
};

