#include "BaseAgent.h"

void BaseAgent::setHp(int hp) {
	this->hp = hp;
}
void BaseAgent::setArmour(int armour) {
	this->armour = armour;
}
void BaseAgent::setPosition(pair<int, int> position) {
	this->position = position;
}
int BaseAgent::getHp() {
	return hp;
}
int BaseAgent::getArmour() {
	return armour;
}
pair<int, int> BaseAgent::getPosition() {
	return position;
}
string BaseAgent::getType() {
	return type;
}