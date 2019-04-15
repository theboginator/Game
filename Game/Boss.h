#pragma once
#include <string>
#include "player.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Mortimer.h"
#include "Skinner.h"
#include "Trashman.h"
#include "Rat.h"


class Boss
{
public:
	Boss();
	~Boss();
	static std::string name; //Name of the boss
	static std::string intro; //Boss's intro line
	static std::string challenge; //The Boss's challenge to the player
	static std::string fightOptions; //The list of fight options to be used against the boss
	void introduceBoss(); //Print the boss introduction
	std::string bossWinsResponse; //The boss's response to the player's move if the boss wins
	std::string bossLosesResponse; //The boss's response to the player if the boss loses
	static std::string fightContinuesResponse; //The boss's response if the fight continues
	int damageCapacity; //How much damage boss can take 
	int roomNumber;
	bool disabled;

	void configureBosses(std::string name, std::string playerName);
	void setFightOptions(std::string name, std::string playerName);
	std::string getBossWinsResponse(); //Return the boss's win response
	std::string getBossLosesResponse(); //Return the boss's loss response
	int fightBoss(Player player); //Fight a boss! Returns the amount of damage as a result, or death (100) or success(0)!

};

