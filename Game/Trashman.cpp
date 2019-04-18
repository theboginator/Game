#include "Trashman.h"
#include <iostream>
#include <string>
#include <algorithm>


Trashman::Trashman()
{
	intro = "\nDANNY DEVITO would like to battle!!!!!\n";
	challenge = "\n'I'm the trashman!!! I eat garbage!'\n";
	fightOptions = "\nA. Hit Danny DeVito\tB. Run!\nC. Offer Danny DeVito a pair of glasses\n";
	bossWinsResponse = "";
	bossLosesResponse = "\n'Careful kid, you reminded me of Cricket and I almost hit you with a trash can. You'd better watch out. I'M THE TRASHMAN!'\nNow's your chance to escape. He seems to have lost interest in you!";
}


Trashman::~Trashman()
{
}

int Trashman::fightBoss(Player player) {
	std::cout << Trashman::challenge;
	std::cout << Trashman::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
		if (response == "A" || response == "a") {
			if (player.inventoryContains("hockey stick", 1)) {
				std::cout << "You hit Danny DeVito with a hockey stick. It's not very effective.\nDanny DeVito throws the trash can at you!";
				//delay(2000);
				std::cout << "\nYou are INJURED (-20 health) but at least you can now attempt to escape...";
				disabled = true;
				return 20;
			}
			else {
				std::cout << "You hit Danny DeVito with your bare hands. It's not very effective.\nDanny DeVito throws the trash can at you!";
				//delay(2000);
				std::cout << "\nYou are KILLED!";
				return 100;
			}
		}
		else if (response == "B" || response == "b") {
			std::cout << "You attempt to run from Danny DeVito. He throws the garbage can at you!";
			//delay(2000);
			std::cout << "\nYou are KILLED!";
			return 100;
		}
		else if (response == "C" || response == "c") {
			if (player.inventoryContains("glasses", 1)) {
				//player.removeItem("glasses", 1);
				std::cout << "You give Danny DeVito the glasses; he puts them on and realizes you're not the man he's looking for";
				std::cout << bossLosesResponse;
				disabled = true;
				return 0;
			}
			else {
				std::cout << "You don't have anything in your inventory to give the trashman! He sees you reaching for your pockets and throws the trash can at you!";
				//delay(2000);
				std::cout << "\nYou are KILLED!";
				return 100;
			}
		}
}

void configureBoss() {

}