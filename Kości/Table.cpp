#include "Table.h"
Table::Table()
{
	categories_names[0] = "Jedynki";
	categories_names[1] = "Dwojki";
	categories_names[2] = "Trojki";
	categories_names[3] = "Czworki";
	categories_names[4] = "Piatki";
	categories_names[5] = "Szostki";
	categories_names[6] = "3 jednakowe";
	categories_names[7] = "4 jednakowe";
	categories_names[8] = "Full";
	categories_names[9] = "Maly strit";
	categories_names[10] = "Duzy strit";
	categories_names[11] = "General";
	categories_names[12] = "Szansa";
}
int Table::getPoints(int index)
{
	return categories[index].first;
}
int Table::getIfChosen(int index)
{
	return categories[index].second;
}
std::pair<int, int> Table::getCategory(int index)
{
	return categories[index];
}
void Table::setCategory(std::pair<int, int> _pair, int index)
{
	categories[index].first = _pair.first;
	categories[index].second = _pair.second;
}
void Table::setPoints(int _points, int index)
{
	categories[index].first = _points;
}
void Table::setIfChosen(int _ifchosen, int index)
{
	categories[index].second = _ifchosen;
}
int Table::sumPoints()
{
	int points=0;
	for (int i = 0; i < 13; i++)
	{
		if (i == 6 && points >= 63) { points += 35; }
		points += categories[i].first;
	}
	return points;
}
void Table::printNotChosenCategories()
{
	for (int i = 0; i < 13; i++)
	{
		if (categories[i].second == 0)
		{
			std::cout << i + 1 << ". " << categories_names[i] << "\n";
		}
	}
}
void Table::printAllCategories()
{
	std::cout << "[Nazwa kategorii] ; [Punkty]\n";
	for (int i = 0; i < 13; i++)
	{
		std::cout <<"[" << categories_names[i] << "]: [" << categories[i].first << "]\n";
	}
}
