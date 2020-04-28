#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Map
{
	int rows, cols;
	vector<vector<char>> matrix;
public:
	Map(int, int);
	int getNrRows() { return this->rows; }
	int getNrCols() { return this->cols; }
	char getItem(int, int);
	void setItem(int, int, char);
	vector<vector<char>> getProximity(pair<int, int>, int) const;
	friend ostream& operator<<(ostream& out, const Map&);

	friend class AgentTom;
};

