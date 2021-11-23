#pragma once
#include <iostream>
class Dice
{
private:
	int value = 0;
	bool isLocked = false;
public:
	friend std::ostream& operator<<(std::ostream& os, const Dice& _obj);
	//constructor
	Dice() {};
	//destructor
	~Dice() {};
	//setters
	void setValue(int _value);
	//getters
	int getValue();
	bool checkifLocked();
	//methods
	void unlock();
	void lock();
	void roll();
	void print(const Dice& _obj);
};