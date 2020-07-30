/* 
maze.cpp

Author: Shannon Brownlee

Short description of this file:
Defines the functions for creating and determining the best path(s) for the maze
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
    
   int rows,cols,result; //initialize variables
   char** mymaze; 
    
    
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
   
   ofstream myfile;
   myfile.open();
   //string filename = argv[2];
   //ifstream ifile(filename);
   mymaze = read_maze(argv[2] ,&rows,&cols); // FILL THIS IN
 
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
    for (int i = 1; i <=rows; i++) 
	{
		delete [] mymaze[i];
	}
	delete [] mymaze;

   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
    Location start;
    int count_start = 0;
    int count_finish = 0;
	bool path_found = false;
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (maze[i][j] == 'S')
			{
				start.row = i;
				start.col = j;
		    	count_start++; //counts how many starts found
			}
    		else if (maze[i][j] == 'F')
    		{
    			count_finish++; //counts how many finishes found

    		}
		}
	}

    if (count_start != 1 || count_finish != 1)

    {
    	return -1; // if not one start and one finish, returns -1
    }

    
	Queue q(rows * cols); //create a queue
	q.add_to_back(start); //add a start to the end

    int ** done;
	done = new int* [rows]; //dynamimcally alloacate a 2D array

	for (int i = 0; i < rows; i++) //put 0 into the array
	{
		done[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			done[i][j] = 0;
		}
	}

    done[start.row][start.col] = 1;

	Location start_pred;
	start_pred.row = -1;
	start_pred.col = -1;

	Location ** predecessor; //initialize another 2D array

	predecessor = new Location* [rows];
       
	for (int i = 0; i < rows; i++)
	{
		predecessor[i] = new Location[cols];
	}

	for (int i = 0; i < rows; i++) //make all array values -1
	{
		for (int j = 0; j < cols; j++)
		{
			predecessor[i][j] = start_pred;
		}
	}

	while(!q.is_empty()) //when queue is empty
	{
		Location curr = q.remove_from_front();
		Location one_above;

		one_above.row = curr.row - 1; //variables to check path above
    	one_above.col = curr.col;

		if(one_above.row >= 0 && one_above.row < rows && one_above.col >= 0 && one_above.col < cols)
		{
			if (maze[one_above.row][one_above.col] == 'F') //backtracks from finish
			{
				while(maze[curr.row][curr.col] != 'S') //while a start is found, go through paths
				{
                	maze[curr.row][curr.col] = '*';
                    curr = predecessor[curr.row][curr.col];
				}
				path_found = true; //if path from S to T is found, break
				break;
			}
			else if (maze[one_above.row][one_above.col] == '.' && done[one_above.row][one_above.col] == 0)
			{
				done[one_above.row][one_above.col] = 1; //add more paths to queue if not finding valid path
				predecessor[one_above.row][one_above.col] = curr;
				q.add_to_back(one_above);
			}
		}

		Location one_left; //variables to check path left
		one_left.row = curr.row;
		one_left.col = curr.col - 1;

		if(one_left.row >= 0 && one_left.row < rows && one_left.col >= 0 && one_left.col < cols)
		{
			if (maze[one_left.row][one_left.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S') //go through paths from start to finish
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true; //when a path is found, break
				break;
			}
			else if (maze[one_left.row][one_left.col] == '.' && done[one_left.row][one_left.col] == 0)
			{
		    	done[one_left.row][one_left.col] = 1;
				predecessor[one_left.row][one_left.col] = curr;  //if you can go left, go one path left
				q.add_to_back(one_left);
			}
		}
		Location one_below;
		one_below.row = curr.row + 1; //variables to check path down
		one_below.col = curr.col;

		if(one_below.row >= 0 && one_below.row < rows && one_below.col >= 0 && one_below.col < cols)
		{
			if (maze[one_below.row][one_below.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S') //go from start to finish
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
            	path_found = true; //break when a valid path is found
				break;
			}
			else if (maze[one_below.row][one_below.col] == '.' && done[one_below.row][one_below.col] == 0)
            {
				done[one_below.row][one_below.col] = 1;
				predecessor[one_below.row][one_below.col] = curr; //adds one space below to back of queue
				q.add_to_back(one_below);
			}
		}

		Location one_right; //initialize variables for checking movement right
		one_right.row = curr.row;
		one_right.col = curr.col + 1;

		if(one_right.row >= 0 && one_right.row < rows && one_right.col >= 0 && one_right.col < cols)
		{
			if (maze[one_right.row][one_right.col] == 'F')
			{
				while(maze[curr.row][curr.col] != 'S') //iterate from start to finish
				{
					maze[curr.row][curr.col] = '*';
					curr = predecessor[curr.row][curr.col];
				}
				path_found = true;
				break; //break when a path is found
			}

			else if(maze[one_right.row][one_right.col] == '.' && done[one_right.row][one_right.col] == 0)
			{
				done[one_right.row][one_right.col] = 1;
				predecessor[one_right.row][one_right.col] = curr;
				q.add_to_back(one_right); // add to back of queue to be checked if valid
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete [] predecessor[i]; //delete dynamically allocated memory
		delete [] done[i];
	}

	delete [] predecessor;
	delete [] done;

	if (path_found == true)
	{
		return 1; //return true if path was found
	}
	else
	{
		return 0; //if no path found, return false
	}
}
