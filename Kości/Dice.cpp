#include <iostream>
#include <chrono>
#include <random>
#include "Dice.h"
void Dice::setValue(int _value)
{
	this->value = _value;
}
void Dice::lock()
{
	this->isLocked = true;
}
void Dice::unlock()
{
	this->isLocked = false;
}
int Dice::getValue()
{
	return value;
}
bool Dice::checkifLocked()
{
	return isLocked;
}
void Dice::roll()
{
	static unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	static std::default_random_engine eng(seed);
	std::uniform_int_distribution<int> rand(1, 6);
	if (isLocked == false) {
		this->value = rand(eng);
	}
}
void Dice::print(const Dice& _obj)
{
	std::cout << _obj << "\n";
}

std::ostream& operator<<(std::ostream& os, const Dice& _obj)
{
	os  << "[" << _obj.value << "] ";
	return os;
}
