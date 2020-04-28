#pragma once
#include "BaseAgent.h"
#include "Map.h"

class AgentTom : public BaseAgent
{
	//will look for the closest Jerry and will move towards him
	//runs away from Spike but is more focused on Jerry
	//has half armour 

public:
	AgentTom() : BaseAgent(100, 50) {
		type = "T";
		range = 2;
	};
	void move(const Map&);
	void fight();
};


