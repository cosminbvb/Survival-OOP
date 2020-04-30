#pragma once

#include <string>
#include "Map.h"
using namespace std;

class Map;

class BaseAgent
{
	//derivde classes: AgentTom, AgentJerry, AgentSpike. 
protected:
	int hp;
	pair<int, int>position;
	char description; 
	int range;
public:
	BaseAgent() : hp(100),range(0),description(' '){};
	BaseAgent(int hp,int range, char description) : hp(hp),range(range),description(description){};
	void setHp(int);
	int getHp();
	void setPosition(pair<int, int>, Map&);
	pair<int, int> getPosition();
	char getDescription();
	virtual void move(Map&) = 0;
	virtual void fight(pair<int,int>) = 0;
	~BaseAgent() {};
};

