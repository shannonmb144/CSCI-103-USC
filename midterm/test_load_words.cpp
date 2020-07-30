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

	srand(atoi(argv[1]));
	char** puzzle_s = new_puzzle(5);
	random_puzzle(puzzle_s, 5);

	bool p = load_words(puzzle,5, "words.txt");
	if(!p)
	{
		cout << "Wrong return value for valid input file." << endl;
		return 1;
	}

	bool q = load_words_s(puzzle_s,5,"words.txt");
	bool passed = compare_puzzles(puzzle, puzzle_s, 5);
	if(!passed)
	{
		cout << "load_words() failed to load words as expected." << endl;
		cout << "Expected:" << endl;
		print_puzzle(puzzle_s,5);
		cout << "Found:" << endl;
		print_puzzle(puzzle,5);
		return 1;
	}
	p = load_words(puzzle,5, "bad1.txt");
	if(p)
	{
		cout << "Wrong return value for invalid input file: bad1.txt" << endl;
		return 1;
	}
	p = load_words(puzzle,5, "bad2.txt");
	if(p)
	{
		cout << "Wrong return value for malformed input file: bad2.txt" << endl;
		return 1;
	}
    p = load_words(puzzle,5,"big.txt");
    if(p)
    {
        cout << "Wrong return value for file with invalid placements. load_words(puzzle,5,\"big.txt\") should return false." << endl;
        return 1;
    }
	return 0;

}
