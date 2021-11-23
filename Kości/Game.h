#pragma once
#include <iostream>
#include "DiceSet.h"
#include "PlayerSet.h"
#include <vector>
class Game
{
private:
	int numOfTurn = 0;
	int numOfPlayers;
	DiceSet dices;
	PlayerSet players;
public:
	//constructor
	Game(int _numOfPlayers);
	//destructor
	~Game() {};
	//interface
	void main_menu();
	void show_rules();
	//methods
	void start_game();
	void turn();
	void end_game();
	void reroll(int dices_to_reroll);
	void reroll_choice();
	void chooseCategory(Player& player);
	void updateCategory(Player& player, int category);


};