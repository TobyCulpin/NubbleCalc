/*
ProductSet Class
	This will contain:
		list of all products
		highest product
		highest scoring product(EXTENSION)
	Each turn a new ProductSet will be generated
	This is constructed with the 4 ints inputed by user
*/

#pragma once

#include <vector>
#include "Board.h"

namespace Nubble
{
	class ProductSet
	{
	public:
		ProductSet();
		ProductSet(std::vector<int> v, Board board, Gamemode g); //Takes 4 user inputed ints in a vector
		~ProductSet();
		
		void Calculate(); //Calculates the products
		void Refine(); //Refines to get valid products

		short int GetHvp(); //Getter for highest valid product
		short int GetHs(); //Getter for highest scoring product
		bool setPlayable;
		std::vector<short int> GetValProd();//Getter for valProd
	private:
		std::vector<int> V; //Initial vector containing the 4 ints inputed by the user
		short int hvp; //Highest valid product
		short int hs; //Highest scoring product's score

		std::vector<double> allProd;  //Set or all possible products
		std::vector<short int> valProd;  //Set of all valid products
		std::vector<int> scores;
		std::vector<int> bestPlays; //Set of highest scoring plays

		Board b;
		Gamemode gamemode;
	};
}
