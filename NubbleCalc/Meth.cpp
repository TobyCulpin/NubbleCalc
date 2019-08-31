#include "Meth.h"
#include <conio.h>
#include <windows.h>


void Meth::goToXY(int column, int row)
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

int Meth::whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}

int Meth::whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}

double Meth::Add(double a, double b)
{
	return (a + b);
}

double Meth::Subtract(double a, double b)
{
	return (a - b);
}

double Meth::Multiply(double a, double b)
{
	return (a * b);
}

double Meth::Divide(double a, double b)
{
	
	if (b == 0)
	{
		Nubble::valid = false;
		return 0;
	}
	return double(static_cast<double>(a) / static_cast<double>(b));
}

std::vector<short int> Meth::cycle(unsigned char a)
{
	if (a > 63) { return { 3, 3, 3 }; };

	short int v = a;
	short int v1, v2, v3;

	v1 = v / 16;	v = v - (v1 * 16);
	v2 = v / 4;		v = v - (v2 * 4);
	v3 = v;

	return { v1, v2, v3 };
}

std::vector<std::vector<unsigned char>> Meth::V = {
		{ 0, 1, 2, 3 },
		{ 0, 1, 3, 2 },
		{ 0, 2, 1, 3 },
		{ 0, 2, 3, 1 },
		{ 0, 3, 1, 2 },
		{ 0, 3, 2, 1 },
		{ 1, 0, 2, 3 },
		{ 1, 0, 3, 2 },
		{ 1, 2, 0, 3 },
		{ 1, 2, 3, 0 },
		{ 1, 3, 0, 2 },
		{ 1, 3, 2, 0 },
		{ 2, 0, 1, 3 },
		{ 2, 0, 3, 1 },
		{ 2, 1, 0, 3 },
		{ 2, 1, 3, 0 },
		{ 2, 3, 0, 1 },
		{ 2, 3, 1, 0 },
		{ 3, 0, 1, 2 },
		{ 3, 0, 2, 1 },
		{ 3, 1, 0, 2 },
		{ 3, 1, 2, 0 },
		{ 3, 2, 0, 1 },
		{ 3, 2, 1, 0 } };


std::vector<unsigned char> Meth::cycleDistinct(unsigned char a)
{
	if (a > 23) { return { 0, 1, 2, 3 }; };

	return Meth::V[a];
}

std::vector<short int> Meth::Ascend(std::vector<short int> vec)
{

	std::vector<short int> t;
	std::vector<short int> v = vec;

	int p;
	
	while (v != t)
	{
		t = v;

		for (int c1 = 0; c1 < (v.size() - 1); c1++)
		{
			if (v[c1] > v[c1 + 1])
			{
				p = v[c1 + 1];
				v[c1 + 1] = v[c1];
				v[c1] = p;
			}
		}
	}

	return v;
}

std::vector<int> Meth::Ascend(std::vector<int> vec)
{

	std::vector<int> t;
	std::vector<int> v = vec;

	int p;

	while (v != t)
	{
		t = v;

		for (int c1 = 0; c1 < (v.size() - 1); c1++)
		{
			if (v[c1] > v[c1 + 1])
			{
				p = v[c1 + 1];
				v[c1 + 1] = v[c1];
				v[c1] = p;
			}
		}
	}

	return v;
}


bool Meth::IsPrime(int a)
{
	if (a == 1) { return false; }
	bool isPrime = true;
	for (int c1 = 2; c1 <= a / 2; c1++)
	{
		if (a % c1 == 0)
		{
			isPrime = false;
			break;
		}
	}
	
	return isPrime;
}


std::vector<int> Meth::NatVec(int start, int len)
{
	std::vector<int> v;
	for (int c1 = 0; c1 < len; c1++)
	{
		v.push_back(start + c1);
	}
	return v;
}

unsigned char Meth::checkForNubble(unsigned char a, Nubble::Board b)
{
	std::vector<int> takenNeighbours;

	for (int c1 = 0; c1 < b.neighbours[a].size(); c1++)
	{
		if (b.states[b.neighbours[a][c1]] == state::TAKEN) { takenNeighbours.push_back(b.neighbours[a][c1]); }
	}
	for (int c1 = 0; c1 < takenNeighbours.size(); c1++)
	{
		for (int c2 = 0; c2 < b.neighbours[takenNeighbours[c1]].size(); c2++)
		{
			for (int c3 = 0; c3 < takenNeighbours.size(); c3++)
			{
				if (b.neighbours[takenNeighbours[c1]][c2] == takenNeighbours[c3])
				{
					if (IsPrime(a)) { return 200; }//Double Nubble
					else { return 100; }//Nubble
				}
			}
		}
	}

	return 0;//No Nubble
}

void Meth::VecOut(std::vector<int> v)
{
	std::cout << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << ", " << v[i];
	}
}

void Meth::VecOut(std::vector<state> v)
{
	std::cout << v[0];
	for (int i = 1; i < v.size(); i++)
	{
		std::cout << ", " << v[i];
	}
}

int Meth::InputInt()
{
	while (true)
	{
		int x = Meth::whereX();
		int y = Meth::whereY();

		std::string input;
		std::getline(std::cin, input);
				
		int i = 0;
		try
		{
			i = std::stoi(input);
		}
		catch (std::invalid_argument e)
		{
			Meth::goToXY(x, y);
			for (int c1 = 0; c1 < input.length(); c1++)
			{
				std::cout << " ";
			}
			Meth::goToXY(x, y);
			continue;
		}
		return i;
	}
}

int Meth::InputDigit()
{
	while (true)
	{
		if (_kbhit() != 0)
		{
			//Using ASCII.  Zero is 48
			auto input = _getch() - 48;

			if (input > 0 && input < 6)
			{
				std::cout << (int)input;
				return input;
			}
		}
	}
}

std::vector<int> Meth::InputValues()
{
	system("CLS");

	std::vector<int> v;

	std::cout << "Enter the first number  : ";
	v.push_back(Meth::InputDigit());
	std::cout << "\n";
	std::cout << "Enter the second number : ";
	v.push_back(Meth::InputDigit());
	std::cout << "\n";
	std::cout << "Enter the third number  : ";
	v.push_back(Meth::InputDigit());
	std::cout << "\n";
	std::cout << "Enter the forth number  : ";
	v.push_back(Meth::InputDigit());
	std::cout << "\n";

	return v;
}

bool Meth::InVec(std::vector<short int> v, int a)
{
	for (int c1 = 0; c1 < v.size(); c1++)
	{
		if (v[c1] == a)
		{
			return true;
		}
	}
	return false;
}