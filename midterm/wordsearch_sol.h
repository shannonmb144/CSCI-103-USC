#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

char random_letter_s();
char** new_puzzle_s(int);
void random_puzzle_s(char**, int);
void print_puzzle_s(char**, int);
bool place_word_s(char**, int, string, char, int, int);
bool load_words_s(char**, int, const char*);
bool find_word_s(char**, int, string, char, int, int);
bool search_word_s(char**, int, string, int *, int*, char*);

