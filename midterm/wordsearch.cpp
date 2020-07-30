#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "wordsearch.h"

using namespace std;

#ifndef TEST
#define RL
#define NP
#define RP
#define PP
#define PW
#define LW
#define FW
#define SW
#endif

#ifdef RL
char random_letter()
{
   char letter = 65 + rand()%26; // starting at A (ascii), randomize, all possible outputs are A-Z
   return letter;
}

#endif

#ifdef NP 
char** new_puzzle(int n)
{
   /* for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            {
               char** puzzle = new char*[i][j];    
            }
    }
    return 0; */
    char** puzzle = new char*[n];  // initialize first array of pointers
    for(int i = 0; i < n;i++)
    {
        puzzle[i] = new char[n]; // each pointer points to a new array
    }
    return puzzle;
}
	
#endif

#ifdef RP
void random_puzzle(char** puzzle, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) // iterated over the entire puzzle matrix
        {
            puzzle[i][j] = random_letter(); // each value in puzzle initialized to a random letter
        }
    }
}
#endif

#ifdef PP
void print_puzzle(char** puzzle, int n)
{
	//setw(3);
    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<n;j++) // iterate over puzzle
        {
           if (j != n-1) // for all letters except the last in a row, print the letter
            {
               cout << setw(3); 
               cout << puzzle[i][j];
            }
            else // for the last letter in the row, print letter and new line
            {
                cout << setw(3); 
                cout << puzzle[i][j]<< endl;
            }
        }
    }
}
#endif

#ifdef PW
bool place_word(char** puzzle, int n, string word, char dir, int r, int c)
{
    if(dir == 'L')
    {
	    if ((word.length()+c-1)>=n) // makes sure word fits within puzzle boundary
        { 
            cout << "Invalid word placement: " << word << " ";
            cout << dir << "@" << r << "," << c << endl;

            return false;
        }
        for(int x=0; x<word.length(); x++) // if it fits, place word
        {
            
            puzzle[r][c+x] = word[x];
            //return true;
        }
    }
    else if (dir == 'T') // makes sure word fits within puzzle boundary
    {
        if((word.length()+r-1)>=n)
        {
            cout << "Invalid word placement: " << word << " ";
            cout << dir << "@" << r << "," << c << endl;

            return false;
        }
        for(int x=0; x<word.length(); x++) // if it fits, place word
        {
            
            puzzle[r+x][c] = word[x];
            //return true;
        }
    }
    else if (dir == 'D') // makes sure word fits within puzzle boundary
    {
        if((word.length()+r-1)>=n || (word.length()+c-1) >= n)
        {
            cout << "Invalid word placement: " << word << " ";
            cout << dir << "@" << r << "," << c << endl;

            return false;
        }
        for(int x=0; x<word.length(); x++) // if it fits, place word
        {
            
            puzzle[r+x][c+x] = word[x];
            //return true;
        }
    }
    return true;
}
#endif

#ifdef LW
bool load_words(char** puzzle, int n, const char* fname)
{
    ifstream ifile(fname);
    bool works = false; // open file
    
	if(ifile.fail())
    {
        cout << "File could not be opened" << endl;
        return false;
    }
    int numWords, row, col; // declare the variables to be read in from the file
    char dir;
    string word;
    
    ifile >> numWords;
    
    if(ifile.fail()) // number of words invalid
    {
        cout << "Incorrect formatting: The text file's first line does not contain the number of words" << endl;
        return false;
    }
    for(int i = 0; i<numWords; i++)
    {
        ifile >> row >> col >> dir >> word;
        if(ifile.fail()) // wrong formatting on inputs in flie
        {
            cout << "Incorrect formatting! Information must be in this order: Row Column Direction Word"<< endl;
            return false;
        }
        if(place_word(puzzle,n, word, dir, row, col)) // checks if word can fit in specified place
        {
            works = true;
        }
        else
        {
            return false;
        }
    }
    ifile.close(); //close file
    if(works == true) 
    {
        return true; // return true if it passed all tests to be opened and used
    }
    return false;   
}
#endif

#ifdef FW
bool find_word(char** puzzle, int n, string word, char dir, int r, int c)
{
    // I tired but couldn't get midterm solution to work
    int letter_num = 0; // counter used to see which letter of the word is being used
    if(dir=='L') // if direction is L
    {
        for(int i = 0; i<n; i++)
        {
            int placement = c+i; //placement where letter would be is column+iterator since it is horizontal
            if(placement >=n) // checks to make sure word will fit
            {
                return false;
            }
            if(puzzle[r][placement] == word[letter_num]) //checks if letter in puzzle is same as letter in word
            {
                letter_num++; // //goes through all letters
                if(letter_num == (word.length())) //if all letters match until end of word, returns true
                   {
                       return true;
                   }
            }
        }
    }
    if(dir=='T') // for direction T
    {
        for(int i = 0; i<n; i++)
        {
            int placement = r+i; //placement where letter would be is row+iterator since it is vertical
            if(placement >=n) //checks to make sure word will fit
            {
                return false;
            }
            if(puzzle[placement][c] == word[letter_num]) //checks if letter in puzzle is same as letter in word
            {
                letter_num++;
                if(letter_num == (word.length())) //if all letters match until end of word, returns true
                   {
                       return true;
                   }
            }
        }
    }
    if(dir=='D') // for direction D
    {
        for(int i = 0; i<n; i++)
        {
            int placement1 = c+i; //placement of letter when going horizontal
            int placement2 = r+i; //placement of letter when going vertical
            if(placement1 >=n || placement2>=n) //makes sure word will fit in both directions
            {
                return false;
            }
            if(puzzle[placement2][placement1] == word[letter_num]) //checks if letter in puzzle is same as letter in word
            {
                letter_num++;
                if(letter_num == (word.length())) //if all letters match until end of word, returns true
                   {
                       return true;
                   }
            }
        }
    }
    return false; 
}
#endif

#ifdef SW
bool search_word(char** puzzle, int n, string word, int *x, int* y, char* d)
{	
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++) //iterates over entire puzzle
        {
            if(find_word(puzzle, n, word, 'L', i, j) == true) // if the word found in dir L
            {
                    *x = i;
                    *y = j;
                    *d = 'L';
                    // sets all pointers to hold value of where + dir in which word is found
                
                    cout << word << " found at " << x << "," << y << d << endl;
                    // tells user where word is and which direction
                    return true;
             }
             else if(find_word(puzzle, n, word, 'T', i, j) == true) // if word found in dir T
             {
                    *x = i;
                    *y = j;
                    *d = 'T';
                    // sets all pointers to hold value of where + dir in which word is found
                
                    cout << word << " found at " << x << "," << y << d << endl;
                   // tells user where word is and which direction
                    return true;
              }
            
              else if(find_word(puzzle, n, word, 'D', i, j) == true) // if word found in dir D
              {
                    *x = i;
                    *y = j;
                    *d = 'D';
                    // sets all pointers to hold value of where + dir in which word is found
                
                    cout << word << " found at " << x << "," << y << d << endl;
                   // tells user where word is and which direction
                    return true;
              }
            
            
        }
    }
	return false; 
    // if the word is not found anywhere in puzzle in any direction, return false
}
#endif
