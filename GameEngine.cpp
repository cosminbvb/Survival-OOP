#include "GameEngine.h"
#include <ctime>
#include <map>

GameEngine::GameEngine() {
	cout << "Enter map dimensions (minimum 15x15): ";
	int row, col;
	cin >> row >> col;
	if (row < 15 || col < 15) exit(1);
	harta = new Map(row, col);
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
			toAdd = new AgentTom;
		}
		harta->setItem(position.first, position.second, toAdd);
		toAdd->setPosition(position);
		i++;
	}
	cout << *harta;
	cout << endl;
	map<pair<int, int>, vector<BaseAgent*>>dict;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//cout << i << " " << j << endl;
			BaseAgent* current = harta->getItem(i, j);
			if (current != NULL) {
				pair<int, int>nextMove = current->move(*harta);
				if (nextMove.first >= row || nextMove.second >= col) cout << current->getDescription() << endl;
				harta->setItem(i, j, NULL);//remove the agent from current position
				dict[nextMove].push_back(current);
			}
		}
	}

	//assertion error ul e din secventa urmatoare pentru ca una din coordonate iese din boundries (la setitem) deci dictionarul nu e bine construit, aproape 100% din moveul lui tom
	map<pair<int, int>, vector<BaseAgent*>>::iterator it = dict.begin();
	while (it != dict.end()) {
		BaseAgent* winner = it->second[0];
		for (int i = 1; i < it->second.size(); i++) {
			winner = BaseAgent::oneVone(winner, it->second[i]);
		}
		harta->setItem(it->first.first, it->first.second, winner);
		it++;
	}

	cout << endl;
	cout << *harta;
	

}
