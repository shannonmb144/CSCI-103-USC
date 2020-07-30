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

	print_puzzle_s(puzzle,5);
	cout << "---" << endl;
	print_puzzle(puzzle,5);
}