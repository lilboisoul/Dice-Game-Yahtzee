#pragma once
#include <iostream>
#include <utility>
class Table
{
private:
	std::pair<int, int> categories[13] = {};
	std::string categories_names[13];
public:
	//constructor
	Table();
	//destructor
	~Table() {};
	//getters
	int getPoints(int index);
	int getIfChosen(int index);
	std::pair<int, int> getCategory(int index);
	//setters
	void setPoints(int _points, int index);
	void setIfChosen(int _ifchosen, int index);
	void setCategory(std::pair<int, int> _pair, int index);
	//methods
	int sumPoints();
	void printNotChosenCategories();
	void printAllCategories();
};