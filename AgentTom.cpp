#include "AgentTom.h"
#include <vector>
#include <cmath>

void AgentTom::move(const Map& map) {
	vector<vector<char>> fov = map.getProximity(this->position, this->range);
	int distJerry = range + 1;
	int distSpike = 1;
	int d1, d2;
	pair<int, int> Jerry(-1, -1); //closest Jerry
	pair<int, int> Spike(-1, -1); //closest Spike
	for (int i = 0; i < fov.size(); i++) {
		for (int j = 0; j < fov.size(); j++) {
			if (fov[i][j] == 'J') {
				d1 = sqrt((this->position.first - this->position.second) ^ 2 + (j - i) ^ 2);
				if (d1 < distJerry) {
					distJerry = d1;
					Jerry.first = i;
					Jerry.second = j;
				}
			}
			else if (fov[i][j] == 'S') {
				d2 = sqrt((this->position.first - this->position.second) ^ 2 + (j - i) ^ 2);
				if (d2 < distSpike) {
					distSpike = d2;
					Spike.first = i;
					Spike.second = j;
				}
			}
		}
	}
	pair<int, int> newPosition;
	if (Jerry.first != -1 && Spike.first == -1) {
		//meaning that Tom only sees Jerry and will move towards him
		newPosition = Jerry;
	}
	if (Jerry.first != -1 && Spike.first == -1) {
		//if he can see both
		if (this->position.first == Jerry.first && Jerry.first == Spike.first) {
			//if they all are on the same line
			if (Spike.second<Jerry.second && Spike.second>this->position.second) {
				//meaning that Tom will meet Spike if he runs towards Jerry
				//he needs to run away

			}
		}
		if (this->position.second == Jerry.first && Jerry.second == Spike.second) {
			//if they all are on the same column
			if (Spike.first<Jerry.first && Spike.first>this->position.first) {
				//meaning that Tom will meet Spike if he runs towards Jerry
				//he needs to run away around

			}
		}
		if (abs(Jerry.first - Spike.first) == abs(Jerry.second - Spike.second) && abs(this->position.first - Spike.first) == abs(this->position.second - Spike.second)) {
			//if they all are on the same diagonal
			if (Spike.first<Jerry.first && Spike.first>this->position.first) {
				//meaning that Tom will meet Spike if he runs towards Jerry
				//he needs to run away

			}
		}
	}

}