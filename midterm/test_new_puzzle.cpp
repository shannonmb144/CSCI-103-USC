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
	//can we allocate and access 1000x1000 puzzle
	char** puzzle = new_puzzle(1000);
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			puzzle[i][j] = (i*j)%256;
		}
	}
	return 0;
}
