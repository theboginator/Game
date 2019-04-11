#pragma once
#include "Boss.h"

class Mortimer : public Boss
{
public:
	Mortimer();
	~Mortimer();
	int fightBoss(Player* player);
};

