#pragma once
#include "Player.h"
class PlayerSet
{
private:
	int size;
public:
	Player* player_array;
	//constructors
	PlayerSet(int _size);
	//destructors
	~PlayerSet();
	//getters
	Player getPlayer(int index);
	//methods

	void set_id_and_name_of_players(int numofPlayers);
	void print_all_players();
};