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
	bool p = find_word(puzzle, 5, "KRPR", 'L', 0 , 0);
	if(!p)
	{
		cout << "Failed find_word() test. Expected to find KRPR 'L' @0,0" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	p = find_word(puzzle, 5, "LZGU", 'T', 1 , 1);
	if(!p)
	{
		cout << "Failed find_word() test. Expected to find LZGU 'T' @1,1" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	p = find_word(puzzle, 5, "MIP", 'D', 2 , 2);
	if(!p)
	{
		cout << "Failed find_word() test. Expected to find MIP 'D' @2,2" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}

	p = find_word(puzzle, 5, "XYZ", 'L', 4 , 4);
	if(p)
	{
		cout << "Failed find_word() test. Expected 'false' for invalid search: XYZ 'L'@4,4" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	p = find_word(puzzle, 5, "XYZ", 'T', 4 , 4);
	if(p)
	{
		cout << "Failed find_word() test. Expected 'false' for invalid search: XYZ 'T'@4,4" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	p = find_word(puzzle, 5, "XYZ", 'D', 4 , 4);
	if(p)
	{
		cout << "Failed find_word() test. Expected 'false' for invalid search: XYZ 'D'@4,4" << endl;
		cout << "Puzzle is:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	return 0;
}