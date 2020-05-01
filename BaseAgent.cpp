#include "BaseAgent.h"

void BaseAgent::setHp(int hp) {
	this->hp = hp;
}
void BaseAgent::setPosition(pair<int, int> position, Map& map) {
	this->position = position;
}
int BaseAgent::getHp() {
	return hp;
}
pair<int, int> BaseAgent::getPosition() {
	return position;
}
char BaseAgent::getDescription() {
	return description;
}
BaseAgent* BaseAgent::oneVone(BaseAgent* a1, BaseAgent* a2) {
	return a1;
}