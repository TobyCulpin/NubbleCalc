#include <iostream>

#include "ProductSet.h"
#include "Meth.h"
#include "Round.h"

namespace Nubble
{
	ProductSet::ProductSet()
	{
	
	}

	ProductSet::ProductSet(std::vector<int> v, Board board)
	{
		this->V = v;
		this->b = board;
		this->setPlayable = true;
	}

	ProductSet::~ProductSet()
	{

	}

	void ProductSet::Calculate()
	{
		std::vector<double (Meth::*)(double, double)> pVec = {&Meth::Add, &Meth::Subtract, &Meth::Multiply, &Meth::Divide};
		Meth inst;

		for (int c1 = 0; c1 < 64; c1++)
		{
			std::vector<short int> c = Meth::cycle(c1);
			for (int c2 = 0; c2 < 24; c2++)
			{
				std::vector<unsigned char> cD = Meth::cycleDistinct(c2);
				Nubble::valid = true;
				if (Nubble::valid) { allProd.push_back((inst.*pVec[c[0]])((inst.*pVec[c[1]])((inst.*pVec[c[2]])(V[cD[0]], V[cD[1]]), V[cD[2]]), V[cD[3]])); }

				Nubble::valid = true;
				if (Nubble::valid) { allProd.push_back((inst.*pVec[c[0]])((inst.*pVec[c[1]])(V[cD[0]], V[cD[1]]), (inst.*pVec[c[2]])(V[cD[2]], V[cD[3]]))); }
			}
		}
	}

	void ProductSet::Refine()
	{
		for (int c1 = 0; c1 < allProd.size(); c1++)
		{
			if (std::floor(allProd[c1]) == allProd[c1] && allProd[c1] > 0 && allProd[c1] <= 100)
			{
				Nubble::valid = true;
				bool boo = true;
				bool cunt = int(b.states[int(allProd[c1])]) == int(TAKEN);
				
				for (int c2 = 0; c2 < valProd.size(); c2++)
				{
					if (valProd[c2] == allProd[c1])
					{
						boo = false;
					}
				}
				
				if (cunt == true)
				{
					boo == false;
				}
				if (boo && !(int(b.states[int(allProd[c1])]) == int(TAKEN)))
				{
					valProd.push_back(allProd[c1]);
				}

				//Well this fucking mess works so that's good
			}
		}

 		if (valProd.size() == 0)
		{
			this->setPlayable = false;
			return;
		}

		valProd = Meth::Ascend(valProd);
		
		scores.assign(101, 0);
		bestPlays.assign(1, 0);
		for (int c1 = 0; c1 < valProd.size(); c1++)
		{
			scores[valProd[c1]] = b.baseScores[valProd[c1]] + Meth::checkForNubble(valProd[c1], b);
			
			if (scores[valProd[c1]] > scores[bestPlays[0]])
			{
				bestPlays.clear();
				bestPlays.push_back(valProd[c1]);
			}
			else if (scores[valProd[c1]] == scores[bestPlays[0]])
			{
				bestPlays.push_back(valProd[c1]);
			}
		}

		std::vector<int> orderedScores = Meth::Ascend(scores);
		hs = orderedScores.back();
		
		hvp = valProd.back();

		if (bestPlays.size() == 1)
		{
			std::cout << "The highest scoring number is ";
			Meth::VecOut(bestPlays);
			std::cout << " with a score of " << hs << "\n\n";
		}
		else
		{
			std::cout << "The highest scoring numbers are ";
			Meth::VecOut(bestPlays);
			std::cout << " with a score of " << hs << "\n\n";
		}
	}

	short int ProductSet::GetHvp()
	{
		return hvp;
	}

	short int ProductSet::GetHs()
	{
		return hs;
	}

	std::vector<short int> ProductSet::GetValProd()
	{
		return valProd;
	}
}