#pragma once
#include "BaseAgent.h"
#include "Map.h"

class AgentTom : public BaseAgent
{
	//will look for the closest Jerry and will move towards him
	//runs away from Spike but is more focused on Jerry 
	//has a movement range of 2 blocks
public:
	AgentTom() : BaseAgent(100, 2, 'T') {};
	void move(Map&);
	void fight(pair<int,int>);
};


