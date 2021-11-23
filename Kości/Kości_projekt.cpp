#include <iostream>
#include "Funkcje.h"
#include "Game.h"
int main(int arg, char* args[])
{
    int numOfPlayers;
    if (arg == 1)
    {
        instruction();
        return 0;
    }
    parameters(arg, args, numOfPlayers);
    Game game(numOfPlayers);
}
