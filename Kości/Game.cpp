//#include <Windows.h>
#include <thread>
#include <chrono>
#include "Game.h"
#include "Funkcje.h"
Game::Game(int _numOfPlayers): numOfPlayers(_numOfPlayers), players(_numOfPlayers)
{
	main_menu();
}
void Game::main_menu()
{
	//-------------------------------------------
	std::cout << "GRA W KOSCI\n"
	<< "---------------\n"
	<< "1. Rozpocznij gre\n"
	<< "2. Zasady gry w kosci\n"
	<< "3. Zakoncz program\n"
	<< "---------------\n";
	//-------------------------------------------
	char option;
	bool valid_option = false;
	while (valid_option == false)
	{
		std::cin >> option;
		switch (option)
		{
			case '1':
			{
				start_game();
				valid_option = true;
				break;
			}
			case '2':
			{
				show_rules();
				valid_option = true;
				break;
			}
			case '3':
			{
				valid_option = true;
				std::exit(0);
				break;
			}
			default:
			{
				std::cout << "Nieprawidlowa opcja!\n";
				break;
			}
		}
	}
}
void Game::show_rules()
{
	std::cout << "ZASADY GRY\n"
	 << "Gra trwa 13 kolejek.\n"
	 << "Na poczatku kolejki, gracz rzuca 5 kostkami, a nastepnie ma mozliwosc dwukrotnego powtorzenia rzutu.\n"
	 << "Przy trzecim rzucie mozna rzucic tylko koscmi, ktore zostaly rzucone podczas drugiego rzutu.\n"
	 << "Nastepnie gracz wybiera jedna z 13 kategorii. Kazda kategoria moze zostac wybrana tylko raz.\n"
	 << "Gracz otrzymuje punkty zaleznie od wybranej kategorii i wyrzuconego ukladu kosci.\n"
	 << "Przykladowo: gracz wyrzucil kostki: (1 2 1 1 5) oraz wybral kategorie: [Jedynki] - gracz otrzyma 3 punkty.\n"
	 << "Jesli gracz uzyska 63 lub wiecej punktow z kategorii o numerach 1-6, otrzymuje 35 punktow premii."
	 << "Wygrywa gracz o najwiekszej ilosci punktow.\n"
	 << "------------------\n"
	 << "1. Wroc do menu\n";
	char option;
	bool valid_option = false;
	while (!valid_option)
	{
		std::cin >> option;
		if (option == '1')
		{
			system("CLS");
			main_menu();
			valid_option = true;
		}
		else
		{
			std::cout << "Nieprawidlowa opcja!\n";
		}
	}
}
void Game::start_game()
{
	system("CLS");
	players.set_id_and_name_of_players(numOfPlayers);

	while (numOfTurn != 3)
	{
		numOfTurn++;
		turn();
	}
	end_game();
}
void Game::turn()
{
	for (int i = 0; i < numOfPlayers; i++)
	{
		system("CLS");
		std::cout << "-- TURA NR " << numOfTurn << " --\n";
		std::cout << "Tura gracza: " << players.player_array[i].getName() << "\n";
		dices.unlock_dices();
		dices.roll_dices();
		std::cout << dices;
		std::cout << "Wpisz ile kostek chcesz rzucic ponownie:\n";
		reroll_choice();

		system("CLS");
		std::cout << dices;
		players.player_array[i].table.printNotChosenCategories();
		chooseCategory(players.player_array[i]);

		system("CLS");
		std::cout << "Tabela wynikow gracza " << players.player_array[i].getName() << "\n";
		players.player_array[i].table.printAllCategories();
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}
void Game::end_game()
{
	system("CLS");
	int points;
	cout << "TABELA WYNIKOW\n" << "(id,nazwa,liczba punktow)\n";
	for (int i = 0; i < numOfPlayers; i++)
	{
		players.player_array[i].setPoints(players.player_array[i].table.sumPoints());
	}
	players.print_all_players();
}
void Game::reroll(int dices_to_reroll)
{
	if (dices_to_reroll == 5) dices.roll_dices();
	else
	{
		char temp;
		cout << "Nastapi wymiana " << dices_to_reroll << " kostek.\n";
		cout << "Wpisz numery kostek, ktorymi chcesz rzucic ponownie: \n";
		for (int i = 0; i < dices_to_reroll; i++)
		{
			cin >> temp;
			//cout << "temp " << temp << " inttemp " <<(int)(temp) << "\n";
			dices.dice_array[(int)(temp)-49].unlock();
			dices.dice_array[(int)(temp)-49].roll();
		}	
		cin.ignore();
	}
	std::cout << dices;
}
void Game::reroll_choice()
{
	bool valid_choice = false;
	char howManyToReroll;
	while (!valid_choice)
	{
		cin >> howManyToReroll;
		if ((int)(howManyToReroll)-48 > 0 && (int)(howManyToReroll)-48 < 6) {
			reroll((int)(howManyToReroll)-48);
			bool valid_choice1 = false;
			cout << "Wpisz ile kostek chcesz rzucic ponownie:\n";
			while (!valid_choice1)
			{
				cin >> howManyToReroll;
				if ((int)(howManyToReroll)-48 > 0 && (int)(howManyToReroll)-48 < 6) {
					reroll((int)(howManyToReroll)-48);
					valid_choice1 = true;
				}
				else if ((int)(howManyToReroll)-48 == 0)
					valid_choice1 = true;
				else
					cout << "Nieprawidlowa ilosc!\n";
			}
			valid_choice = true;
		}
		else if ((int)(howManyToReroll)-48 == 0)
			valid_choice = true;
		else
			cout << "Nieprawidlowa ilosc!\n";
	}

}
void Game::chooseCategory(Player& player)
{
	int category;
	cout << "Wybierz kategorie: \n";
	bool valid_choice = false;
	while (!valid_choice) {
		cin >> category;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Nieprawidlowa kategoria!\n";
		}
		else if(category > 0 && category < 14 && player.table.getIfChosen(category - 1) == 0) {
			updateCategory(player, category);
			valid_choice = true;
		}
		else cout << "Nieprawidlowa kategoria!\n";
	}
}
void Game::updateCategory(Player& player, int category)
{
	int points = 0, cnt;
	bool is1 = false, is2 = false, is3 = false, is4 = false, is5 = false, is6 = false;
	pair<int, int> p;
	if (category > 0 && category < 7)
	{
		for (int i = 0; i < 5; i++)
		{
			if (dices.dice_array[i].getValue() == category) {
				points += category;
			}
		}
	}
	else
	{
		switch (category)
		{
		case 7: //3 jednakowe
			dices.sort_values();
			cnt = 1;
			for (int i = 0; i < 4; i++)
			{
				if (dices.dice_array[i].getValue() == dices.dice_array[i + 1].getValue())
				{
					cnt++;
					if (cnt == 3)
					{
						points += (dices.dice_array[0].getValue() + dices.dice_array[1].getValue() + dices.dice_array[2].getValue() + dices.dice_array[3].getValue() + dices.dice_array[4].getValue());
						break;
					}
				}
				else
				{
					cnt = 1;
				}
			}
			break;
		case 8: //4 jednakowe
			dices.sort_values();
			cnt = 1;
			for (int i = 0; i < 4; i++)
			{
				if (dices.dice_array[i].getValue() == dices.dice_array[i + 1].getValue())
				{
					cnt++;
					if (cnt == 4)
					{
						points += (dices.dice_array[0].getValue() + dices.dice_array[1].getValue() + dices.dice_array[2].getValue() + dices.dice_array[3].getValue() + dices.dice_array[4].getValue());
						break;
					}
				}
				else
				{
					cnt = 1;
				}
			}
			break;
		case 9: //full
			dices.sort_values();
			if (dices.dice_array[0].getValue() == dices.dice_array[1].getValue() && dices.dice_array[0].getValue() == dices.dice_array[2].getValue())
			{
				if (dices.dice_array[3].getValue() == dices.dice_array[4].getValue())
				{
					points = 25;
					break;
				}
			}
			else if (dices.dice_array[0].getValue() == dices.dice_array[1].getValue())
			{
				if (dices.dice_array[2].getValue() == dices.dice_array[3].getValue() && dices.dice_array[2].getValue() == dices.dice_array[4].getValue())
				{
					points = 25;
					break;
				}
			}
			break;
		case 10: //maly strit
			for (int i = 0; i < 5; i++)
			{
				switch (dices.dice_array[i].getValue())
				{
				case 1:
					is1 = true;
					break;
				case 2:
					is2 = true;
					break;
				case 3:
					is3 = true;
					break;
				case 4:
					is4 = true;
					break;
				case 5:
					is5 = true;
					break;
				case 6:
					is6 = true;
					break;
				}
			}
			if ((is1 && is2 && is3 && is4) || (is2 && is3 && is4 && is5) || (is3 && is4 && is5 && is6)) {
				points = 30;
			}
			break;
		case 11: // du¿y strit
			for (int i = 0; i < 5; i++)
			{
				switch (dices.dice_array[i].getValue())
				{
				case 1:
					is1 = true;
					break;
				case 2:
					is2 = true;
					break;
				case 3:
					is3 = true;
					break;
				case 4:
					is4 = true;
					break;
				case 5:
					is5 = true;
					break;
				case 6:
					is6 = true;
					break;
				}
			}
			if ((is1 && is2 && is3 && is4 && is5) || (is2 && is3 && is4 && is5 && is6)) {
				points = 40;
			}
			break;

		case 12: //genera³
			dices.sort_values();
			if (dices.dice_array[0].getValue() == dices.dice_array[4].getValue()) {
				points = 50;
			}
			break;

		case 13: //szansa
			points += dices.dice_array[0].getValue() + dices.dice_array[1].getValue() + dices.dice_array[2].getValue() + dices.dice_array[3].getValue() + dices.dice_array[4].getValue();
			break;
		}
	}
	p.first = points;
	p.second = 1;
	player.table.setCategory(p, (category - 1));
}
