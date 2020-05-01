#include "AgentJerry.h"
#include <vector>
#include <cmath>

pair<int,int> AgentJerry::move(Map& map) {
	vector<vector<BaseAgent*>> fov = map.getProximity(this->position, this->range);
	pair<int, int>jerryFovPoisition = map.getProximityNewCentre(this->position, this->range); //his coordinates in fov
	vector<pair<int, int>> Toms;//coordinates of each Tom in his range
	pair<int,int>current;
	pair<int, int>newPosition;
	for (unsigned i = 0; i < fov.size(); i++) {
		for (unsigned j = 0; j < fov.size(); j++) {
			if (fov[i][j]->getDescription() == 'T') {
				current.first = i;
				current.second = j;
				Toms.push_back(current);
			}
		}
	}
	int maxDist = 0;
	for (unsigned i = 0; i < fov.size(); i++) {
		for (unsigned j = 0; j < fov.size(); j++) {
			int minDist = 3;//best case being diagonal
			int d = 0;
			current.first = i;
			current.second = j;
			for (auto pair : Toms) {
				d = (int)sqrt((current.second-current.first) ^ 2 + (j - i) ^ 2);
				if (d < minDist) minDist = d;
			}
			//minDist will now be distance between Jerry and the closest Tom
			if (minDist > maxDist) {
				maxDist = minDist;
				newPosition = current;
			}
		}
	}
	//this->position.first -= jerryFovPoisition.first - newPosition.first;
	//this->position.second -= jerryFovPoisition.second - newPosition.second;
	pair<int, int> returnPosition;
	returnPosition.first = this->position.first - (jerryFovPoisition.first - newPosition.first);
	returnPosition.second = this->position.second - (jerryFovPoisition.second - newPosition.second);
	return returnPosition;
}

//BaseAgent* AgentJerry::fight(BaseAgent* enemy) {
//	if (enemy->getDescription() == 'T') {
//		if (hp >= enemy->getHp()) {
//			//Jerry Wins
//		}
//		else {
//			//Tom Wins
//		}
//	}
//	else {
//		//Jerry Wins
//	}
//}