// Survival-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Map.h"
#include "BaseAgent.h"
#include "AgentTom.h"

using namespace std;

int main()
{
    Map m = Map(5, 5);
    AgentTom* Tom = new AgentTom;
    pair<int, int>pozitie1;
    pozitie1.first = 2;
    pozitie1.second = 3;
    Tom->setPosition(pozitie1,m);
    m.setItem(pozitie1.first, pozitie1.second, Tom);
    cout<<m; //why
    
    return 0;
}
