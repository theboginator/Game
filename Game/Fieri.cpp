#include "Fieri.h"



Fieri::Fieri()
{
	intro = "Hey man, Guy Fieri here and we got a problem.\nAfter filiming a bunch of Diners, Drive Ins, and Dives, I've become bored of reviewing other people's food. I want a grill off!!!";
	challenge = "Bet you cant grill a meaner barbecue than me!\nIf you can cook I'll let you pass... if you cant, I'm gonna stuff you into this here rocket, dunk it in barbecue sauce, and send you off to flavortown!!";
	fightOptions = "A. Hit Guy Fieri\tB. Accept his challenge and grill!\nC. Run away";

}


Fieri::~Fieri()
{
}

int Fieri::fightBoss(Player* player) {
	std::cout << Fieri::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	//a = hit. b = grill off. c = run away
	if (response == "a") {
		std::cout << "You attempt to HIT Guy Fieri. He catches your arm mid-swing and stuffs you into the rocket!!\nHe dunks the rocket in barbecue sauce and launches you off to Flavortown!!!!.";
		std::cout << "\nYou are KILLED!";
		return 100;
	}
	else if (response == "b") {
		std::cout << "You attempt to try your hand at barbecuing for Guy Fieri";
		if (player->inventoryContains("steamed hams", 1)){
			if (player->inventoryContains("barbecue sauce", 1)) {
				std::cout << "You throw the steamed hams Skinner gave you onto the grill and cover them in barbecue sauce\n";
				std::cout << "Guy Fieri is IMPRESSED!\n";

			}
			else {
				std::cout << "You throw the steamed hams Skinner gave you onto the grill";
				std::cout << "Guy Fieri is not impressed!";
			}
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
			disabled = true;
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
