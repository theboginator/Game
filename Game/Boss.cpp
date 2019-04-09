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

int Boss::fightBoss(Boss* boss, Player* player) { //Logic for fighting an enemy! Returns a damage amount (0 = win; 100 = death)
	/*NEW PLAN: fight boss is defined in each different subclass.
	while boss !disabled
		print fightoptions
		get user response
		do fight logic
		print reponse
		update damage and such

		
	*/
	std::cout << boss->fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	if (boss->name == "trashman") {
		if (response == "A" || response == "a") {
			if(player->inventoryContains("hockey_stick") ){
				std::cout << "You hit Danny DeVito with a hockey stick. It's not very effective.\nDanny DeVito throws the trash can at you!";
				//delay(2000);
				std::cout << "You are INJURED \(-20 health\) but at least you can now attempt to escape...";
				boss->disabled = true;
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
			if (player->inventoryContains("glasses", 1)) {
				player->removeItem("glasses");
				std::cout << "You give Danny DeVito the glasses; he puts them on and realizes you're not the man he's looking for";
				boss->disabled = true;
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
		std::cout << "You IGNORE Principal Skinner. He seems offended you weren't interested in having steamed hams but doesnt bother you further.";
		boss->disabled = true;
		return 0;
		}
		else if (response == "b") {
			std::cout << "You HIT Principal Skinner causing the plate of steamed hams to fall!\n'EGAD! My roast is ruined!' Skinner yells.";
			boss->disabled = true;
			return 0;

		}
		else if (response == "c") {
			std::cout << "You decide to try to barter with Principal Skinner and offer 2 coins instead of 4.";
			if (player->inventoryContains("coin", 2)) {
				disabled = true;
					return 0;
			}
			else {
				std::cout << "'Don't try to kid with me!' Yells Skinner. He clearly sees you don't have any coins. Skinner drags you into his cottage and stuffs you into the oven!\n'You'll make an excellent roast for the Superintendent when he comes along!'";
				std::cout << "You are KILLED!";
				return 100;
			}
		}
	}
	else if (name == "mortimer") {
		//a = give in. b = hit mortimer. c = you threaten to burn down the bridge
		if (response == "a") {
			std::cout << "You decide to give into Mortimer Mouse's demands. He allows you to cross the ravine.";
			int penalty = player->checkqty("food"); //Get the total amount of food a player has
			player->removeItem("food", (penalty / 2)); //Remove half the food
			player->removeItem("key", 1); //Remove a key (if present)
		}
		else if (response == "b") {
			if (player->inventoryContains("hockey_stick", 1)) {
				std::cout << "You HIT Mortimer Mouse with the hockey stick! He is angered by your attack and decides to hit back!";
				std::cout << "Mortimer grabs the newspaper he stole from Mickey Mouse and hits back! You are INJURED!";
				return 25;
			}
			else {
				std::cout << "You HIT Mortimer Mouse with your bare hands! It's not very effective.";
				std::cout << "'I bet you'll scream just like Goofy huh? Ha Cha Cha!' Mortimer pushes you off the bridge!";
				std::cout << "You are KILLED!";
				return 100;
			}
		}
		else if (response == "c") {
			std::cout << "You threaten to burn down the bridge!";
			if (player->inventoryContains("gas", 2)) {
				boss->disabled = true;
				return 0;
			}
			else {
				std::cout << "Mortimer is not fooled, he can see you have no way to realistically burn the bridge down.";
				std::cout << "'Threaten to burn my bridge, eh? I bet you scream just like Goofy when I throw you over the edge!'\nMortimer pushes you off the edge!";
				std::cout << "You are KILLED!";
				return 100;
			}
		}
	}
	else if (name == "rat") {
		//a ignore. b. offer food. c. hit mr ratburn
		if (response == "a") {
			std::cout << "You attempt to ignore Mr. Ratburn.\nBefore you know it he's right in front of you with those glowing red eyes! As you look into them you're turned into stone!";
			std::cout << "You are KILLED!";
			return 100;
		}
		else if (response == "b") {
			std::cout << "You offer Mr. Ratburn some of your food. It's unlikely this will be very effective unless you have cake.";
			if (player->inventoryContains("cake", 1)) {
				std::cout << "'You made cake?? For ME?!'\nMr. Ratburn is thrilled that you had cake to give him and decides to let you go!";
				int total = player->checkqty("cake");
				if (total > 1) {
					std::cout << "You notice Mr. Ratburn has somehow not only eaten the one slice you offered him but somehow has taken all the cake in your inventory!";
					player->removeItem("cake", total);
				}
				else {
					player->removeItem("cake", 1);
				}
			}
			boss->disabled = true;
			return 0;
		}
		else if (response == "c") {
			if (player->inventoryContains("hockey_stick", 1)) {
				std::cout << "You HIT Mr. Ratburn with the hockey stick. The hockey stick breaks.";
				player->removeItem("hockey_stick", 1);
				std::cout << "Mr. Ratburn is not happy. 'For today's lesson, we'll multiply your suffering by compounding this book with your head!'\nMr. Ratburn takes a large math book out of his jacket and hits you with it!";
				std::cout << "You are INJURED!";
				return 50;
			}
			else {
				std::cout << "You HIT Mr. Ratburn with your bare hands. It's not very effective.\nMr. Ratburn takes out a history book and raises it high above your head. 'Maybe the authors will write you into the next edition!' he yells as he brings it down hard!";
				std::cout << "You are KILLED!";
				return 100;
			}
		}
	}
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
		bossResponse = "You drive a hard bargain, Superintendent! But I shall accept. Here, enjoy these Steamed hams on your trip!";
	}
	else if (name == "mortimer") {
		intro = "Well, Ha cha cha! Another bridge-crosser! Here I was thinking I'd have to scrouge around for another meal but, lucky me! I find another fool to extort!";
		challenge = "Listen kid, here's the deal. I'll let you cross the bridge if you give me half of your food... and that key I see sticking out of your pocket! Them's my terms!\nOh, and if you try anything funny... I'll push you off the edge!";
		bossResponse = "Alright, alright kid. Don't burn my bridge, you can cross the stupid ravine.\n\n\n You cross the ravine. After you exit at the other side, you burn the bridge down anyway.";
	}
	else if (name == "rat") {
		intro = "'Good morning my son!' cries a voice from the clearing. A large rat wearing a tacky green suit appears, holding a platter of cake!";
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
