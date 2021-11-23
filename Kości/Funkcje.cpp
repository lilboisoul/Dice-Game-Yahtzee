#include "Funkcje.h"
void parameters(int arg, char* argv[], int& numOfPlayers)
{
	std::stringstream s;
	if (arg == 2)
	{
		s << argv[1];
		if ((s >> numOfPlayers).fail()) {
			std::cerr << "Blad w wczytywaniu liczby graczy.\n";
			std::exit(0);
		}
	}
}
void instruction()
{
	std::cout << "Program nalezy wywolac przy uzyciu 1 przelacznika okreslajacego liczbe graczy.\n"
		<< "Przykladowe wywolanie programu:\n"
		<< "\"sciezka_do_wywolywanego_pliku\" 2";
}
