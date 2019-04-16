#include "Chest.h"



Chest::Chest()
{
	items = { "gas", "cake", "hockey_stick", "bat", "barbecue sauce" };
	locked = true;
}

std::vector<std::string> Chest::returnItems() {
	return items;
}

void Chest::setChest(std::vector<std::string> loot, bool isLocked)
{
	items = loot;
	locked = isLocked;
}


Chest::~Chest()
{
	
}