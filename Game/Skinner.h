#pragma once
#include "Boss.h"


class Skinner : public Boss
{
public:
	Skinner();
	~Skinner();
	int fightBoss(Player* player);
};

