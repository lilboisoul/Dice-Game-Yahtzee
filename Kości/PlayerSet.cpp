#include "PlayerSet.h"
#include "Player.h"
PlayerSet::PlayerSet(int _size): size(_size)
{
	player_array = new Player[size];
	
}
PlayerSet::~PlayerSet()
{
	delete[] player_array;
}
void PlayerSet::print_all_players()
{
	for (int i = 0; i < size; i++)
	{
		player_array[i].print_player_fields();
	}
}
Player PlayerSet::getPlayer(int index)
{
	return player_array[index];
}
void PlayerSet::set_id_and_name_of_players(int numofPlayers)
{
	string n;
	system("CLS");
	for (int i = 0; i < numofPlayers; i++)
	{
		player_array[i].setID(i + 1);
		cout << "Podaj nazwe gracza " << player_array[i].getID() << "\n";
		cin >> n;
		player_array[i].setName(n);
		system("CLS");
	}
}