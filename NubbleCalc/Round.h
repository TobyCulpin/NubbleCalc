#pragma once

#include "Board.h"
#include "ProductSet.h"
#include "Meth.h"
#include "Level.h"

namespace Nubble
{
	class Round
	{
	public:
		Round();
		Round(Board board);
		~Round();
		void Play(Gamemode g);
		void Play64(Gamemode g);

	private:
		Board b;
		ProductSet p;
	};
}