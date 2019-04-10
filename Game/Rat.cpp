#include "Rat.h"



Rat::Rat()
{
	intro = "'Good morning my son!' cries a voice from the clearing. A large rat wearing a tacky green suit appears, holding a platter of cake!";
	challenge = "Mmm! Are you having cake?!?\nThe rat seems to think you have more cake in your inventory. It's unclear what will happen if you don't give it to him...";
	fightOptions = "A. Ignore Mr. Ratburn\tB. Offer Mr. Ratburn some of your food\n C. Hit Mr. Ratburn";
}


Rat::~Rat()
{
}

int Rat::fightBoss(Player* player) {
	std::cout << Rat::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
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
				std::cout << "You notice Mr. Ratburn has somehow not only eaten the one slice you offered him but has taken all the cake in your inventory!";
				player->removeItem("cake", total);
			}
			else {
				player->removeItem("cake", 1);
			}
		}
		disabled = true;
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