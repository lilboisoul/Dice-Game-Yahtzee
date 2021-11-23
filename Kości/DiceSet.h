#pragma once
#include <string>
#include <iostream>
#include "Dice.h"
class DiceSet
{
private:
	int size = 5;
public:
	friend std::ostream& operator<<(std::ostream& os, const DiceSet _obj);
	Dice dice_array[5];
	//constructors
	DiceSet() {};

	//destructors
	~DiceSet() {};

	//methods
	void print_dices();
	void roll_dices();
	void lock_dices();
	void unlock_dices();
	void sort_values();
};