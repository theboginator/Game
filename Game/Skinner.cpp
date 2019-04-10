#include "Skinner.h"



Skinner::Skinner()
{
	intro = "You run into a strange yellow man in a suit. \"Ahh, Superintendant Chalmers! Welcome! I hope you're prepared for an unforgettable luncheon!\"";
	challenge = "For lunch today we're having Steamed Hams! And if you tip me well, say, how about 4 gold coins... I might be able to get you through a shortcut!";
	fightOptions = "A. Ignore Principal Skinner\tB. Hit Principal Skinner\nC. Barter with Principal Skinner";
	bossLosesResponse = "You drive a hard bargain, Superintendent! But I shall accept. Here, enjoy these Steamed hams on your trip!";
}


Skinner::~Skinner()
{
}

int Skinner::fightBoss(Player* player) {
	std::cout << Skinner::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	if (response == "A" || response == "a") {
		std::cout << "You IGNORE Principal Skinner. He seems offended you weren't interested in having steamed hams but doesnt bother you further.";
		disabled = true;
		return 0;
	}
	else if (response == "b") {
		std::cout << "You HIT Principal Skinner causing the plate of steamed hams to fall!\n'EGAD! My roast is ruined!' Skinner yells.";
		disabled = true;
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