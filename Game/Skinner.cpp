#include "Skinner.h"



Skinner::Skinner()
{
	intro = "\nYou run into a strange yellow man in a suit. \"Ahh, Superintendant Chalmers! Welcome! I hope you're prepared for an unforgettable luncheon!\n";
	challenge = "\nFor lunch today we're having Steamed Hams! And if you tip me well, say, how about 4 gold coins... I might be able to spare you some extra hams!\n";
	fightOptions = "\nA. Ignore Principal Skinner\tB. Hit Principal Skinner\nC. Barter with Principal Skinner";
	bossLosesResponse = "You drive a hard bargain, Superintendent! But I shall accept. Here, enjoy these Steamed hams on your trip!";
}


Skinner::~Skinner()
{
}

int Skinner::fightBoss(Player player) {
	std::cout << Skinner::challenge;
	std::cout << Skinner::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
	if (response == "A" || response == "a") {
		std::cout << "\nYou IGNORE Principal Skinner. He seems offended you weren't interested in having steamed hams but doesnt bother you further.";
		disabled = true;
		return 0;
	}
	else if (response == "b") {
		std::cout << "\nYou HIT Principal Skinner causing the plate of steamed hams to fall!\n'EGAD! My roast is ruined!' Skinner yells.";
		disabled = true;
		return 0;

	}
	else if (response == "c") {
		std::cout << "\nYou decide to try to barter with Principal Skinner and offer 2 coins instead of 4.";
		if (player.inventoryContains("gold", 2)) {
			std::cout << Skinner::bossLosesResponse;
			disabled = true;
			return 0;
		}
		else {
			std::cout << "\n'Don't try to kid with me!' Yells Skinner. \nHe clearly sees you don't have any coins. \nSkinner drags you into his cottage and stuffs you into the oven!\n'You'll make an excellent roast for the Superintendent when he comes along! Delightfully devilish, Seymour!'";
			std::cout << "\nYou are KILLED!";
			return 100;
		}
	}
}