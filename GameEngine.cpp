#include "GameEngine.h"
#include <ctime>

GameEngine::GameEngine() {
	cout << "Enter map dimensions (minimum 15x15) :";
	int row, col;
	cin >> row >> col;
	if (row < 15 || col < 15) exit(1);
	map = new Map(row, col);
	cout << "Enter the number of agents: ";
	int nrAgents;
	cin >> nrAgents;
	if (nrAgents > row * col) {
		cout << "Too many agents";
		exit(1);
	}
	//nrAgents = (int)row * col / 10; alternative
	
	//randomly placing agents
	srand(time(NULL));
	int i = 0;
	vector<pair<int, int>>takenPositions;
	while (i < nrAgents) {
		pair<int, int>position;
		bool taken = true;
		while (taken == true) {
			position.first = rand() % row;
			position.second = rand() % col;
			bool found = false;
			for (auto p : takenPositions) {
				if (p == position) {
					found = true;
					break;
				}
			}
			if (found == false) {
				//the position is not taken
				taken = false;
				takenPositions.push_back(position);
			}
		}
		BaseAgent* toAdd=NULL;
		if (i % 3 == 0) {
			//generate AgentTom
			toAdd = new AgentTom;
		}
		if (i % 3 == 1) {
			//generate AgentJerry
			toAdd = new AgentJerry;
		}
		if (i % 3 == 2) {
			//generate AgentSpike
			
		}
		map->setItem(position.first, position.second, toAdd);
		i++;
	}
	cout << *map;

}
