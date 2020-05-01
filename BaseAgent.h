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
	virtual pair<int,int> move(Map&) = 0; //return his next posititon
	//virtual BaseAgent* fight(BaseAgent*) = 0; //return the winning agent in a 1v1
	static BaseAgent* oneVone(BaseAgent*, BaseAgent*);
	~BaseAgent() {};
};

