#include "Board.h"
#include "Meth.h"
#include <iostream>

namespace Nubble
{
	Board::Board()
	{
		neighbours.assign(101, {});
		
		states.assign(101, state::EMPTY);
		for (int c1 = 1; c1 <= 100; c1++)
		{
			if (Meth::IsPrime(c1)) { states[c1] = (state::EMPTY_PRIME); }
		}
		

		//creating the sets
		n_sets.assign(20, { 0 });
		for (int c1 = 1; c1 <= 10; c1++)
		{
			n_sets[c1] = Meth::NatVec((n_sets[(c1 - 1)].back() + 1), c1);
		}
		for (int c1 = 11; c1 <= 19; c1++)
		{
			n_sets[c1] = Meth::NatVec((n_sets[(c1 - 1)].back() + 1), (20 - c1));
		}
		
		
		for (int c1 = 1; c1 < 10; c1++)
		{
			for (int c2 = 0; c2 < n_sets[c1].size(); c2++)
			{
				//neighbouring with adjacent in set
				if (c1 != 1)
				{
					if (c2 == 0)
					{
						neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 + 1]);
					}
					else if (c2 == (n_sets[c1].size() - 1))
					{
						neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 - 1]);
					}
					else
					{
						neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 - 1]);
						neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 + 1]);
					}
				}

				//neighbouring with the 2 in next set
				neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2]);
				neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2 + 1]);
				neighbours[n_sets[c1 + 1][c2]].push_back(n_sets[c1][c2]);
				neighbours[n_sets[c1 + 1][c2 + 1]].push_back(n_sets[c1][c2]);
				
			}
		}
		for (int c1 = 10; c1 < 19; c1++)
		{
			for (int c2 = 0; c2 < n_sets[c1].size(); c2++)
			{
				if (c2 == 0)
				{
					//neighbouring with adjacent in set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 + 1]);

					//neighbouring with one in next set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2]);
					neighbours[n_sets[c1 + 1][c2]].push_back(n_sets[c1][c2]);
				}
				else if (c2 == (n_sets[c1].size() - 1))
				{
					//neighbouring with adjacent in set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 - 1]);

					//neighbouring with one in next set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2 - 1]);
					neighbours[n_sets[c1 + 1][c2 - 1]].push_back(n_sets[c1][c2]);
				}
				else
				{
					//neighbouring with adjacent in set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 - 1]);
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1][c2 + 1]);

					//neighbouring with the 2 in next set
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2]);
					neighbours[n_sets[c1][c2]].push_back(n_sets[c1 + 1][c2 - 1]);
					neighbours[n_sets[c1 + 1][c2]].push_back(n_sets[c1][c2]);
					neighbours[n_sets[c1 + 1][c2 - 1]].push_back(n_sets[c1][c2]);
				}
			}
		}

		
				
		
		/*
		for (int i = 1; i < neighbours.size(); i++)
		{
			std::cout << neighbours[i][0];
			for (int j = 1; j < neighbours[i].size(); j++)
			{
				std::cout << ", " << neighbours[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n\n";
		*/

		baseScores.assign(101, 0);
		for (int c1 = 1; c1 < 16; c1++)		{ baseScores[c1] = 10; }
		for (int c1 = 16; c1 < 29; c1++)	{ baseScores[c1] = 20; }
		for (int c1 = 29; c1 < 46; c1++)	{ baseScores[c1] = 50; }
		for (int c1 = 46; c1 < 65; c1++)	{ baseScores[c1] = 100; }
		for (int c1 = 65; c1 < 80; c1++)	{ baseScores[c1] = 200; }
		for (int c1 = 80; c1 < 91; c1++)	{ baseScores[c1] = 300; }
		for (int c1 = 91; c1 < 101; c1++)	{ baseScores[c1] = 500; }
	}

	Board::~Board()
	{

	}
}