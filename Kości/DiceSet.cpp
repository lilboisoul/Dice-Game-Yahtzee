#include "DiceSet.h"
void DiceSet::print_dices()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << dice_array[i];
	}
	std::cout << "\n";
}
void DiceSet::roll_dices()
{
	for (size_t i = 0; i < size; i++)
	{
		dice_array[i].roll();
	}
	//std::cout << "Nastepuje rzut kostkami...\n";
}
void DiceSet::lock_dices()
{
	for (size_t i = 0; i < size; i++)
	{
		dice_array[i].lock();
	}
}
void DiceSet::unlock_dices()
{
	for (size_t i = 0; i < size; i++)
	{
		dice_array[i].unlock();
	}
}
void DiceSet::sort_values()
{
	int temp;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4 - i; j++)
		{
			if (dice_array[j].getValue() > dice_array[j + 1].getValue()) {
				temp = dice_array[j].getValue();
				dice_array[j].setValue(dice_array[j + 1].getValue());
				dice_array[j + 1].setValue(temp);
			}
		}
	}
}
std::ostream& operator<<(std::ostream& os, const DiceSet _obj)
{
	for (int i = 0; i < _obj.size; i++)
	{
		os << _obj.dice_array[i];
	}
	os << "\n";
	return os;
}
