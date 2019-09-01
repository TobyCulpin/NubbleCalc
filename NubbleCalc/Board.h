/*
	Board Class
	This will contain data on all tiles
	tiles have a state(Enums ? ) empty, taken by user, taken by opponent
	tiles have a list of neighbours(EXTENSION)
*/

#pragma once
#include <vector>

#include "Level.h"

enum state
{
	EMPTY = 0,
	EMPTY_PRIME = 1,
	TAKEN = 2
};

namespace Nubble
{
	class Board
	{
	public:
		Board();
		Board(Gamemode g);
		~Board();
		std::vector<state> states;
		std::vector<std::vector<int>> neighbours;
		std::vector<std::vector<int>> n_sets;
		std::vector<int> baseScores;
	private:
	};
}
