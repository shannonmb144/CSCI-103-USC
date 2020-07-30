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
	bool passed = true;
	char x[5], y[5];
	for(int i=0;i<5;i++)
	{
		x[i] = random_letter();
	}
	srand(atoi(argv[1]));
	for(int i=0;i<5;i++)
	{
		y[i] = random_letter_s();
		if(x[i] != y[i])
		{
			passed = false;
		}
	}
	if(!passed)
	{
		cout << "random_letter() doesn't generate expected sequence." << endl;
		cout << "expected: ";
		for(int i=0;i<5;i++)
		{
			cout << y[i] << " ";
		} 
		cout << "found: ";
		for(int i=0;i<5;i++)
		{
			cout << x[i] << " ";
		}
		cout << endl;
		return 1;
	}
	return 0;
}