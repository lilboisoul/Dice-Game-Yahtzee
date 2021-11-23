#pragma once
#include <iostream>
#include "Table.h"
using namespace std;
class Player
{
private:
	int id;
	int points = 0;
	string name;
public:
	Table table;
	//constructors
	Player() {};

	//destructor
	~Player() {};
	//setters
	void setID(unsigned int _id);
	void setPoints(int _points);
	void setName(string _name);

	//getters
	int getID();
	int getPoints();
	string getName();

	//methods
	void print_player_fields(); // id << " " << name << " " << points << "\n";
	//void printPlayerTable();
};