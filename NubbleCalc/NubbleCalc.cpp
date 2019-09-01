#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

#include "ProductSet.h"
#include "Meth.h"
#include "Board.h"
#include "Round.h"
#include "Level.h"


int main()
{
	/*
    std::cout << "\nSTART\n";

	Nubble::Board board = Nubble::Board();
	Nubble::Round round = Nubble::Round(board);

	while (true)
	{
		round.Play();
	}

	std::cout << "\nFINISH\n";

	
	return 0;
	*/

	Nubble::Level level = Nubble::Level();

	level.DisplayMenu();
}




/*
	--------OVERVIEW------------------------------------------------------------------------------------------------------------------------

	Input 4 ints between 1 and 6 inclusively.
	Calculate all possible products of these ints (all must be used).
	Display them.

	--------EXTENSION-----------------------------------------------------------------------------------------------------------------------

	Calculate highest scoring number to play.  
	The program will need to know all numbers that have been played before, either by user entry or linking it with Nubble.

	--------CLASSES-------------------------------------------------------------------------------------------------------------------------

	ProductSet Class
		This will contain:
			list of all products
			highest product
			highest scoring product(EXTENSION)
		Each turn a new ProductSet will be generated
		This is constructed with the 4 ints inputed by user

	Board Class
		This will contain data on all tiles
		tiles have a state(Enums?) empty, taken by user, taken by opponent
		tiles have a list of neighbours(EXTENSION)
*/