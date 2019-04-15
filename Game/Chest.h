#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Chest
{
public:
	Chest(std::vector<std::string> items, bool locked);
	~Chest();
	bool locked;
	void setChest(std::vector<std::string> items, bool locked); //function to configure chest
	std::vector<std::string> returnItems();

private:
	std::vector<std::string> items;
};

