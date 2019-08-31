#pragma once

#include "Board.h"
#include "ProductSet.h"
#include "Meth.h"

namespace Nubble
{
	class Round
	{
	public:
		Round();
		Round(Board board);
		~Round();
		void Play();
	private:
		Board b;
		ProductSet p;
	};
}