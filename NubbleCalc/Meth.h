//Conatains all Mathmatical functions for this program

#pragma once

#include <vector>
#include "Board.h"
#include <iostream>
#include <string>

enum OP
{
	ADD = 0,
	SUB = 1,
	MUL = 2,
	DIV = 3
};

static class Meth
{
public:
	static void goToXY(int column, int row);
	static int whereX();
	static int whereY();

	double Add(double a, double b);
	double Subtract(double a, double b);
	double Multiply(double a, double b);
	double Divide(double a, double b);

	static std::vector<short int> Ascend(std::vector<short int> v);
	static std::vector<int> Ascend(std::vector<int> v);
	static bool IsPrime(int a);
	static std::vector<int> NatVec(int start, int len);
	static void VecOut(std::vector<int> v);
	static void VecOut(std::vector<state> v);

	static std::vector<short int> cycle(unsigned char a);//Values are 0 to 63
	static std::vector<unsigned char> cycleDistinct(unsigned char a);//Values are 0 to 23

	static std::vector<int> cycle64(int a);
	static std::vector<int> cycleDistinct64(int a);

	static std::vector<std::vector<unsigned char>> V;
	static std::vector<std::vector<int>> V64;

	static unsigned char checkForNubble(unsigned char a, Nubble::Board b);
	static std::vector<int> InputValues(Gamemode g);
	static int InputInt(Gamemode g);
	static int InputDigit(Gamemode g);
	static bool InVec(std::vector<short int> v, int a);

	static int ReturnInput();
	static void ShowConsoleCursor(bool showFlag);

private:
};

namespace Nubble
{
	static bool valid;
}