#pragma once
#include "Boss.h"

class Rat : public Boss
{
public:
	Rat();
	~Rat();
	int fightBoss(Player player);
};

