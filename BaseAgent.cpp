#include "BaseAgent.h"

void BaseAgent::setHp(int hp) {
	this->hp = hp;
}
void BaseAgent::setPosition(pair<int, int> position) {
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
	if (a1->getDescription() == 'J') return a1;
	else return a2;
}