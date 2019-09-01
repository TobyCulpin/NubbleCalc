#pragma once

#include <vector>
#include <string>

enum Gamemode
{
	NubbleSingleplayer = 0,
	NubbleMultiplayer = 1,
	Nubble64Singleplayer = 3,
	Nubble64Multiplayer = 4
};

namespace Nubble
{

	class Level
	{
	public:
		Level();
		Level(Gamemode g);
		~Level();

		void SetGamemode(Gamemode g);
		Gamemode GetGamemode();

		void DisplayMenu();

		void EnterLevel(Gamemode g);

		void RefreshMenu(std::vector<std::string>* gamemodes, int selection);
	private:
		Gamemode gamemode;

	};
}