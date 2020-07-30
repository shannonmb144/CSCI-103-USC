#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wordsearch.h"
#include "wordsearch_sol.h"
using namespace std;

bool compare_puzzles(char** a, char** b, int n)
{
	bool passed = true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j] != b[i][j])
			{
				passed = false;
			}
		}
	}
	return passed;
}

int main(int argc, char const *argv[])
{
	srand(atoi(argv[1]));
	char** puzzle = new_puzzle(5);
	random_puzzle(puzzle, 5);

	bool p = place_word(puzzle, 5, "test", 'L', 0, 0);
	
	if(!p) { 
		cout << "Wrong return value for valid place_word(): 'test' L@0,0 on 5x5 puzzle." << endl;
		return 1;
	}
	p = place_word(puzzle, 5, "test", 'T', 0, 0);
	if(!p) { 
		cout << "Wrong return value for valid place_word(): 'test' T@0,0 on 5x5 puzzle." << endl;
		return 1;
	}
	p = place_word(puzzle, 5, "test", 'D', 0, 0);
	if(!p) {  
		cout << "Wrong return value for valid place_word(): 'test' D@0,0 on 5x5 puzzle." << endl;
		return 1;
	}

	p = place_word(puzzle, 5, "test", 'L', 2, 2);
	if(p) { 
		cout << "Wrong return value for invalid place_word(): 'test' L@2,2 on 5x5 puzzle." << endl;
		return 1;
	}
	p = place_word(puzzle, 5, "test", 'T', 2, 2);
	if(p) { 
		cout << "Wrong return value for invalid place_word(): 'test' T@2,2 on 5x5 puzzle." << endl;
		return 1;
	}
	p = place_word(puzzle, 5, "test", 'D', 2, 2);
	if(p) {  
		cout << "Wrong return value for invalid place_word(): 'test' D@2,2 on 5x5 puzzle." << endl;
		return 1;
	}

	srand(atoi(argv[1]));
	random_puzzle(puzzle, 5);

	srand(atoi(argv[1]));
	char** puzzle_s = new_puzzle(5);
	random_puzzle(puzzle_s, 5);

	p = place_word(puzzle, 5, "test", 'L', 0, 0);
	bool q = place_word_s(puzzle_s, 5, "test", 'L', 0,0);

	bool passed = compare_puzzles(puzzle, puzzle_s, 5);
	if(!passed)
	{
		cout << "Failed place_word() 'test' L@0,0 on 5x5 puzzle." << endl;
		cout << "Expected:" << endl;
		print_puzzle(puzzle_s, 5);
		cout << "Found:" << endl;
		print_puzzle(puzzle, 5);
		return 1;
	}

	srand(atoi(argv[1]));
	random_puzzle(puzzle, 5);

	srand(atoi(argv[1]));
	random_puzzle(puzzle_s, 5);
	p = place_word(puzzle, 5, "test", 'T', 1, 1);
	q = place_word_s(puzzle_s, 5, "test", 'T', 1,1);

	passed = compare_puzzles(puzzle, puzzle_s, 5);
	if(!passed)
	{
		cout << "Failed place_word() 'test' T@1,1 on 5x5 puzzle." << endl;
		cout << "Expected:" << endl;
		print_puzzle(puzzle_s, 5);
		cout << "Found:" << endl;
		print_puzzle(puzzle, 5);
		return 1;
	}

	srand(atoi(argv[1]));
	random_puzzle(puzzle, 5);

	srand(atoi(argv[1]));
	random_puzzle(puzzle_s, 5);

	p = place_word(puzzle, 5, "test", 'D', 0, 1);
	q = place_word_s(puzzle_s, 5, "test", 'D', 0,1);

	passed = compare_puzzles(puzzle, puzzle_s, 5);
	if(!passed)
	{
		cout << "Failed place_word() 'test' D@0,1 on 5x5 puzzle." << endl;
		cout << "Expected:" << endl;
		print_puzzle(puzzle_s, 5);
		cout << "Found:" << endl;
		print_puzzle(puzzle, 5);
		return 1;
	}
}
