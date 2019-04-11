#pragma once
#include "Boss.h"
#include <iostream>
#include <string>
#include <algorithm>

Boss::Boss() {

}

Boss::~Boss()
{
}

void introduceBoss(Boss* boss) {
	std::cout << boss->challenge;
}

std::string getBossWinsResponse() {
	return bossWinsResponse;
}

std::string getBossLosesResponse() {
	return bossLosesResponse;
}

int Boss::fightBoss(Player player) { //Logic for fighting an enemy! Returns a damage amount (0 = win; 100 = death)

}

void Boss::configureBosses(std::string name, std::string playerName) { //Set up the bosses and their challenges!
	
}
void Boss::setFightOptions(std::string name, std::string playerName) { //Set up the fight options for each boss!

}
