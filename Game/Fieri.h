#pragma once
#include "Boss.h"
class Fieri : public Boss
{
public:
	Fieri();
	~Fieri();
	int fightBoss(Player* player);
};

