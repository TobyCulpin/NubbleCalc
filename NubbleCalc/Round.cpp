#include "Round.h"

namespace Nubble
{
	Round::Round()
	{

	}

	Round::Round(Board board)
	{
		this->b = board;
	}

	Round::~Round()
	{

	}

	void Round::Play(Gamemode g)
	{
		this->p = ProductSet(Meth::InputValues(g), this->b, g);

		p.Calculate();
		p.Refine();

		if (p.setPlayable == true)
		{
			int input;
			std::string blank;

			std::cout << "Enter number played: ";
			
			while (true)
			{
				int x = Meth::whereX();
				int y = Meth::whereY();

				input = Meth::InputInt(g);

				if (Meth::InVec(p.GetValProd(), input))
				{
					this->b.states[input] = state::TAKEN;
					if (g == NubbleSingleplayer || g == Nubble64Singleplayer)
					{
						return;
					}
					else if (g == NubbleMultiplayer || g == Nubble64Multiplayer)
					{
						std::cout << "\n\nEnter number played by opponent: ";

						while (true)
						{
							int x = Meth::whereX();
							int y = Meth::whereY();

							input = Meth::InputInt(g);

							if (this->b.states[input] != state::TAKEN)
							{
								this->b.states[input] = state::TAKEN;
								return;
							}

							Meth::goToXY(x, y);
							for (int c1 = 0; c1 < floor(log10(input)) + 1; c1++)
							{
								std::cout << " ";
							}
							Meth::goToXY(x, y);
						}
					}
				}

				Meth::goToXY(x, y);
				for (int c1 = 0; c1 < floor(log10(input)) + 1; c1++)
				{
					std::cout << " ";
				}
				Meth::goToXY(x, y);
			}
		}
		else
		{
			std::cout << "There are no possible moves.\n\nPress Enter to continue\n";

			std::string blank;

			std::getline(std::cin, blank);
		}
	}

}