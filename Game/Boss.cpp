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


void Boss::introduceBoss() {
	std::cout << intro;
}

std::string Boss::getBossWinsResponse() {
	return bossWinsResponse;
}

std::string Boss::getBossLosesResponse() {
	return bossLosesResponse;
}

int Boss::fightBoss(Player player) { //Logic for fighting an enemy! Returns a damage amount (0 = win; 100 = death)
	return 0;
}

void Boss::configureBosses(std::string name, std::string playerName) { //Set up the bosses and their challenges!
	
}
void Boss::setFightOptions(std::string name, std::string playerName) { //Set up the fight options for each boss!

}
