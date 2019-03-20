#pragma once
#include <string>
#include "player.h"

class Boss
{
public:
	Boss(std::string name, bool isEnabled, int roomNumber);
	~Boss();
	std::string name; //Name of the boss
	std::string intro; //Boss's intro line
	std::string challenge; //The Boss's challenge to the player
	std::string fightOptions; //The list of fight options to be used against the boss
	std::string bossResponse; //The boss's response to the player's move if the player wins
	int damageCapacity; //How much damage boss can take 
	int roomNumber;
	bool disabled;

	void configureBosses(std::string name, std::string playerName);
	void setFightOptions(std::string name, std::string playerName);
	void introduceBoss(Boss* boss);
	int fightBoss(Boss* boss, Player* player); //Fight a boss! Returns the amount of damage as a result, or death (100) or success(0)!

};

