#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wordsearch.h"

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc < 4)
	{
		cout << "Usage: wordsearch <random seed> <puzzle size> <file to load words>" << endl;
		return 1;
	}
	srand(atoi(argv[1]));
	int n = atoi(argv[2]);

	char** my_puzzle = new_puzzle(n);
	random_puzzle(my_puzzle,n);
	load_words(my_puzzle, n, argv[3]);
	print_puzzle(my_puzzle,n);

	string look;
	cout << "Enter a word: " << endl;
	while(cin >> look)
	{
		int x=0;
		int y=0;
		char d='X';
		if(search_word(my_puzzle, n, look, &x, &y, &d))
		{
			cout << "Word " << look << " found @ " << x << " " << y << " direction " << d << endl;
		}
		else
		{
			cout << "Word " << look << " not found." << endl;
		}
	}
    /* You need to add the proper code to delete the dynamically allocated data */
    for(int i=0; i<n; i++)
    {
        delete [] my_puzzle[i]; 
        //iterate over my_puzzle, same as how new_puzzle is made
        //free the arrays within the initial array
    }
    delete [] my_puzzle;
    //free the memory taken up by the initial 1D array
    
    /* This code will be graded manually */
    
	return 0;
}

