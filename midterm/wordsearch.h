#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

char random_letter();
char** new_puzzle(int);
void random_puzzle(char**, int);
void print_puzzle(char**, int);
bool place_word(char**, int, string, char, int, int);
bool load_words(char**, int, const char*);
bool find_word(char**, int, string, char, int, int);
bool search_word(char**, int, string, int *, int*, char*);


