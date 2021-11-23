#include "Player.h"

void Player::setID(unsigned int _id)
{
	this->id = _id;
}
void Player::setName(string _name)
{
	this->name = _name;
}
void Player::setPoints(int _points)
{
	this->points = _points;
}
int Player::getID()
{
	return this->id;
}
string Player::getName()
{
	return this->name;
}
void Player::print_player_fields()
{
	std::cout <<"[" << id << "] [" << name << "] [" << points << "]\n";
}
int Player::getPoints()
{
	return this->points;
}