#include "Map.h"
#include <algorithm>

Map::Map(int nrRows, int nrCols) : rows(nrRows), cols(nrCols) {
	matrix.resize(rows);
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].resize(cols);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = (char)223;
		}
	}
}

char Map::getItem(int row, int col) {
	return matrix[row][col];
}

void Map::setItem(int row, int col, char value) {
	matrix[row][col] = value;
}

ostream& operator<<(ostream& out, const Map& map) {
	out << (char)218;
	for (int i = 0; i < 2 * map.cols + 1; i++)
		out << (char)196;
	out << (char)191;
	out << endl;
	for (int i = 0; i < map.rows; i++) {
		out << (char)179;
		out << " ";
		for (int j = 0; j < map.cols; j++) {
			out << map.matrix[i][j] << " ";
		}
		out << (char)179;
		out << endl;
	}
	out << (char)192;
	for (int i = 0; i < 2 * map.cols + 1; i++)
		out << (char)196;
	out << (char)217;

	return out;
}

vector<vector<char>> Map::getProximity(pair<int, int> pos, int range) const {
	int up = min(range, pos.first);
	int down = min(range, this->rows - 1 - pos.first);
	int left = min(range, pos.second);
	int right = min(range, this->cols - 1 - pos.second);
	int height = up + down + 1;
	int width = left + right + 1;
	vector<vector<char>> local(height, vector<char>(width));
	for (int i = pos.first - up; i <= pos.first + down; i++) {
		for (int j = pos.second - left; j <= pos.second + right; j++) {
			//local[i-pos.first+1][j-pos.second+1] = this->matrix[i][j];
			//cout << this->matrix[i][j]<<" ";
			local[i - (pos.first - up)][j - (pos.second - left)] = this->matrix[i][j];

		}
	}
	return local;
}