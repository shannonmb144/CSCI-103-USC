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
	char** puzzle_s = new_puzzle(5);
	random_puzzle_s(puzzle_s, 5);

	srand(atoi(argv[1]));
	char** puzzle = new_puzzle(5);
	random_puzzle(puzzle, 5);

	bool passed = true;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(puzzle[i][j] != puzzle_s[i][j])
			{
				passed = false;
			}
		}
	}
	if(!passed)
	{
		cout << "random_puzzle() did not generate the expected result. Expected: " << endl;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout << setw(3) << puzzle_s[i][j]; 
			}
			cout << endl;
		}
		cout << "Your code: " << endl;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				cout << setw(3) << puzzle[i][j]; 
			}
			cout << endl;
		}
	}
	return !passed;
}
