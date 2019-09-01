#include <iostream>
#include <string>
#include <windows.h>

#include "Level.h"
#include "Meth.h"
#include "Round.h"


namespace Nubble
{
	const char* version = "1.1";

	Level::Level()
	{

	}

	Level::Level(Gamemode g)
	{
		this->gamemode = g;
	}

	Level::~Level()
	{

	}

	void Level::EnterLevel(Gamemode g)
	{
		Meth::ShowConsoleCursor(true);

		this->gamemode = g;

		Nubble::Board board = Nubble::Board();
		Nubble::Round round = Nubble::Round(board);

		switch (g)
		{
		case NubbleSingleplayer:

			while (true)
			{
				round.Play(g);
			}

		case NubbleMultiplayer:

			while (true)
			{
				round.Play(g);
			}

		case Nubble64Singleplayer:
		{

		}

		case Nubble64Multiplayer:
		{

		}
		}
	}

	void Level::SetGamemode(Gamemode g)
	{
		this->gamemode = g;
	}

	Gamemode Level::GetGamemode()
	{
		return this->gamemode;
	}

	void Level::DisplayMenu()
	{
		Meth::ShowConsoleCursor(false);

		std::vector<std::string> gamemodes;
		gamemodes.push_back("Nubble - Singleplayer");
		gamemodes.push_back("Nubble - Multiplayer");
		//gamemodes.push_back("Nubble64 - Singleplayer");
		//gamemodes.push_back("Nubble64 - Multiplayer");

		int selection = 0;
		int input;

		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 7);//7 is white
		system("CLS");

		std::cout << "Welcome to the Nubble Calculator V" << version << "\n\n";
		std::cout << "Choose what mode you're playing in:\n\n";

		RefreshMenu(&gamemodes, selection);

		while (true)
		{
			input = Meth::ReturnInput();
 			switch (input)
			{
			case 72://Up Arrow
			{
				selection = max(0, selection - 1);
				RefreshMenu(&gamemodes, selection);
				continue;
			}
			case 80://Down Arrow
			{
				selection = min(gamemodes.size() - 1, selection + 1);
				RefreshMenu(&gamemodes, selection);
				continue;
			}
			case 13://Enter Key
			{
				switch (selection)
				{
				case 0:
					EnterLevel(Gamemode::NubbleSingleplayer);
				case 1:
					EnterLevel(Gamemode::NubbleMultiplayer);
				case 2:
					EnterLevel(Gamemode::Nubble64Singleplayer);
				case 3:
					EnterLevel(Gamemode::Nubble64Multiplayer);
				}
				continue;
			}
			}
		}
	}

	void Level::RefreshMenu(std::vector<std::string>* gamemodes, int selection)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		for (int c1 = 0; c1 < (*gamemodes).size(); c1++)
		{
			Meth::goToXY(0, (4 + c1));
			if (c1 == selection)
			{
				SetConsoleTextAttribute(hConsole, 10);//10 is green
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 7);//7 is white
			}
			std::cout << (*gamemodes)[c1];
		}
		SetConsoleTextAttribute(hConsole, 7);//7 is white
	}
}