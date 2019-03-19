#pragma once
#include "Boss.h"
#include <iostream>
#include <string>
#include <algorithm>

Boss::Boss(std::string name, bool isEnabled, int roomNumber) {
	this->name = name;
	this->disabled = isEnabled;
	this->roomNumber = roomNumber;
}

Boss::~Boss()
{
}

int Boss::fightBoss(std::string name, Player* player) { //Logic for fighting an enemy! Returns a damage amount (0 = win; 100 = death)
	
	std::cout << challenge;
	std::cout << fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	if (name == "trashman") {
		if (response == "A" || response == "a") {
			if(player->inventoryContains("hockey_stick") ){
				std::cout << "You hit Danny DeVito with a hockey stick. It's not very effective.\nDanny DeVito throws the trash can at you!";
				//delay(2000);
				std::cout << "You are INJURED \(-20 health\) but at least you can now attempt to escape...";
				disabled = true;
				return 20;				
			}
			else {
				std::cout << "You hit Danny DeVito with your bare hands. It's not very effective.\nDanny DeVito throws the trash can at you!";
				//delay(2000);
				std::cout << "You are KILLED!";
				return 100;
			}
		}
		else if (response == "B" || response == "b") {
			std::cout << "You attempt to run from Danny DeVito. He throws the garbage can at you!";
			//delay(2000);
			std::cout << "You are KILLED!";
			return 100;
		}
		else if (response == "C" || response == "c") {
			if (player->inventoryContains("glasses")) {
				player->removeItem("glasses");
				std::cout << "You give Danny DeVito the glasses; he puts them on and realizes you're not the man he's looking for";
				disabled = true;
				return 0;
			}
			else {
				std::cout << "You don't have anything in your inventory to give the trashman! He sees you reaching for your pockets and throws the trash can at you!";
				//delay(2000);
				std::cout << "You are KILLED!";
				return 100;
			}
		}
	}
	else if (name == "skinner") {
		if (response == "A" || response == "a") {
		std:cout << "You IGNORE Principal Skinner. He seems offended you weren't interested in having steamed hams but doesnt bother you further.";
		disabled = true;
		return 0;
		}
		else if (
	}
	
	return 0;
}

void Boss::configureBosses(std::string name, std::string playerName) { //Set up the bosses and their challenges!
	if (name == "trashman") {
		intro = "DANNY DEVITO would like to battle!!!!!";
		challenge = "I'm the trashman!!! I eat garbage!";
		bossResponse = "Careful kid, you reminded me of Cricket and I almost hit you with a trash can. You'd better watch out. I'M THE TRASHMAN!\nNow's your chance to escape. He seems to have lost interest in you!";
	}
	else if (name == "skinner") {
		intro = "You run into a strange yellow man in a suit. \"Ahh, Superintendant Chalmers! Welcome! I hope you're prepared for an unforgettable luncheon!\"";
		challenge = "For lunch today we're having Steamed Hams! And if you tip me well, say, how about 4 gold coins... I might be able to get you through a shortcut!";
		bossResponse = "You offer Principal Skinner 2 gold coins for the shortcut instead of four.\nYou drive a hard bargain, Superintendent! But I shall accept. Here, enjoy these Steamed hams on your trip!";
	}
	else if (name == "mortimer") {
		intro = "Well, Ha cha cha! Another bridge-crosser! Here I was thinking I'd have to scrouge around for another meal but, lucky me! I find another fool to extort!";
		challenge = "Listen kid, here's the deal. I'll let you cross the bridge if you give me half of your food... and that key I see sticking out of your pocket! Them's my terms!\nOh, and if you try anything funny... I'll push you off the edge!";
		bossResponse = "Alright, alright kid. Don't burn my bridge, you can cross the stupid ravine.";
	}
	else if (name == "rat") {
		intro = "\"Good morning my son!\" cries a voice from the clearing. A large rat wearing a tacky green suit appears, holding a platter of cake!";
		challenge = "Mmm! " + playerName + " Ratburn, are you having cake?!?\nThe rat seems to think you have more cake in your inventory. It's unclear what will happen if you don't give it to him...";
	}
}
void Boss::setFightOptions(std::string name, std::string playerName) { //Set up the fight options for each boss!
	if (name == "trashman") {
		fightOptions = "A. Hit Danny DeVito\tB. Run!\nC. Offer Danny DeVito a pair of glasses";
	}
	else if (name == "skinner") {
		fightOptions = "A. Ignore Principal Skinner\tB. Hit Principal Skinner\nC. Barter with Principal Skinner";
	}
	else if (name == "mortimer") {
		fightOptions = "A. Give in to Mortimer Mouse's demands\tB. Hit Mortimer Mouse\n C. " + playerName + " threatens to burn down the bridge";
	}
	else if (name == "rat") {
		fightOptions = "A. Ignore Mr. Ratburn\tB. Offer Mr. Ratburn some of your food\n C. Hit Mr. Ratburn";
	}
}
