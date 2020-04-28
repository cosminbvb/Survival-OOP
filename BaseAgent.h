#pragma once

#include <string>
#include "Map.h"
using namespace std;

class BaseAgent
{
protected:
	int hp;
	int armour;
	pair<int, int>position;
	string type;
	int range;
public:
	BaseAgent() : hp(100), armour(0) {}; //not used
	BaseAgent(int hp, int armour) : hp(hp), armour(armour) {};
	void setHp(int);
	int getHp();
	void setArmour(int);
	int getArmour();
	void setPosition(pair<int, int>);
	pair<int, int> getPosition();
	string getType();
	virtual void move(const Map&) = 0;
	virtual void fight() = 0;
};

