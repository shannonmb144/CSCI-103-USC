#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wordsearch.h"
#include "wordsearch_sol.h"
using namespace std;


int main(int argc, char const *argv[])
{
	srand(atoi(argv[1]));
	char** puzzle = new_puzzle(5);
	random_puzzle(puzzle, 5);
	
	int x=-1,y=-1;
	char d='X';

	bool p = search_word(puzzle, 5, "KRPR", &x, &y, &d);
	if(!p)
	{
		cout << "search_word() returned wrong value for valid search. Expected to find KRPR 'L'@0,0:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	if( x != 0 || y != 0 || d != 'L')
	{
		cout << "search_word() didn't return correct values. Expected:" << endl;
		cout << "x=0, y=0, d=L" << endl;
		cout << "Found:" << endl;
		cout << "x=" << x << ", y=" << y << ", d=" << d << endl;
	}

	p = search_word(puzzle, 5, "LZG", &x, &y, &d);
	if(!p)
	{
		cout << "search_word() returned wrong value for valid search. Expected to find LZG 'T'@1,1:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	if( x != 1 || y != 1 || d != 'T')
	{
		cout << "search_word() didn't return correct values. Expected:" << endl;
		cout << "x=1, y=1, d=T" << endl;
		cout << "Found:" << endl;
		cout << "x=" << x << ", y=" << y << ", d=" << d << endl;
	}

	p = search_word(puzzle, 5, "MIP", &x, &y, &d);
	if(!p)
	{
		cout << "search_word() returned wrong value for valid search. Expected to find MIP 'D'@2,2:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	if( x != 2 || y != 2 || d != 'D')
	{
		cout << "search_word() didn't return correct values. Expected:" << endl;
		cout << "x=2, y=2, d=D" << endl;
		cout << "Found:" << endl;
		cout << "x=" << x << ", y=" << y << ", d=" << d << endl;
	}
	p = search_word(puzzle, 5, "XYZ", &x, &y, &d);
	if(p)
	{
		cout << "search_word() returned wrong value for invalid search. Expected not to find XYZ:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	
}