#include "Mortimer.h"



Mortimer::Mortimer()
{
	intro = "Well, Ha cha cha! Another bridge-crosser! Here I was thinking I'd have to scrouge around for another meal but, lucky me! I find another fool to extort!";
	challenge = "Listen kid, here's the deal. I'll let you cross the bridge if you give me half of your food... and that key I see sticking out of your pocket! Them's my terms!\nOh, and if you try anything funny... I'll push you off the edge!";
	fightOptions = "A. Give in to Mortimer Mouse's demands\tB. Hit Mortimer Mouse\n C.You threaten to burn down the bridge";
	bossLosesResponse = "Alright, alright kid. Don't burn my bridge, you can cross the stupid ravine.\n\n\n You cross the ravine. After you exit at the other side, you burn the bridge down anyway.";
}


Mortimer::~Mortimer()
{
}

int Mortimer::fightBoss(Player* player) {
	std::cout << Mortimer::fightOptions;
	std::string response = "";
	std::getline(std::cin, response);
	std::transform(response.begin(), response.end(), response.begin(), ::tolower);
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