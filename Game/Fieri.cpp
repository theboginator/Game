#include "Fieri.h"



Fieri::Fieri()
{
	intro = "Hey man, Guy Fieri here and we got a problem.\nAfter filiming a bunch of Diners, Drive Ins, and Dives, I've become bored of reviewing other people's food. I want a grill off!!!";
	challenge = "Bet you cant grill a meaner barbecue than me!\nIf you can cook I'll let you pass... if you cant, I'm gonna stuff you into this here rocket, dunk it in barbecue sauce, and send you off to flavortown!!";
	fightOptions = "A. Hit Guy Fieri\tB. Accept his challenge and grill!\nC. Run away";
	bossLosesResponse = "\nGuy fieri tries your barbecue!'\nDamn! You can really grill! All right there cowboy take this LEAN CUISINE that I've autographed and be on your way!'\n";
}


Fieri::~Fieri()
{
}

int Fieri::fightBoss(Player player) {
	std::cout << Fieri::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	//a = hit. b = grill off. c = run away
	if (response == "a") {
		std::cout << "\nYou attempt to HIT Guy Fieri. He catches your arm mid-swing and stuffs you into the rocket!!\nHe dunks the rocket in barbecue sauce and launches you off to Flavortown!!!!.";
		std::cout << "\nYou are KILLED!";
		return 100;
	}
	else if (response == "b") {
		std::cout << "\nYou attempt to try your hand at barbecuing for Guy Fieri";
		if (player.inventoryContains("steamed hams", 1)){
			if (player.inventoryContains("barbecue sauce", 1)) {
				std::cout << "\nYou throw the steamed hams Skinner gave you onto the grill and cover them in barbecue sauce\n";
				std::cout << "\nGuy Fieri is IMPRESSED!\n";
				std::cout << bossLosesResponse;
				return 0;
			}
			else {
				std::cout << "\nYou throw the steamed hams Skinner gave you onto the grill";
				std::cout << "\nGuy Fieri is not impressed! He very quickly grills up a thick triple cheeseburger.\n'I call this the triple-bypasss burger!' He easily beats you in the grill off!\n";
				std::cout << "\nYou LOSE!!!! Guy Fieri stuffs you into the rocket!!\nHe dunks the rocket in barbecue sauce and launches you off to Flavortown!!!!";
				std::cout << "\nYou are KILLED!!!!";
				return 100;
			}
		}
		else if (player.inventoryContains("steak", 1)) {
			std::cout << "\nYou throw your STEAK on the grill! Guy Fieri is impressed!!!\n";
			if (player.inventoryContains("barbecue sauce", 1) || player.inventoryContains("spices", 1)) {
				std::cout << "\nYou cover the steak in BARBECUE SAUCE!!! Guy Fieri sniffs the air and smiles!";
				std::cout << bossLosesResponse;
				return 0;
			}
			else {
				std::cout << "\nGuy Fieri is not impressed! He very quickly grills up a thick triple cheeseburger.\n'I call this the triple-bypasss burger!' He easily beats you in the grill off!\n";
				std::cout << "\nYou LOSE!!!! Guy Fieri stuffs you into the rocket!!\nHe dunks the rocket in barbecue sauce and launches you off to Flavortown!!!!";
				std::cout << "\nYou are KILLED!!!!";
				return 100;
			}
			
		}
	}
	else if (response == "c") {
		std::cout << "\nYou attempt to flee from Guy Fieri!";
		std::cout << "\nAs you run suddenly you're lifted up into the air! Guy has caught you!!!\nGuy Fieri stuffs you into the rocket!!\nHe dunks the rocket in barbecue sauce and launches you off to Flavortown!!!!"; 
		std::cout << "\nYou are KILLED!";
		return 100;
	}
}
