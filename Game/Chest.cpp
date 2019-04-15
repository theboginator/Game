#include "Chest.h"



Chest::Chest(std::vector<std::string> loot, bool isLocked)
{
	items = loot;
	locked = isLocked;
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
