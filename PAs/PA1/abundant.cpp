/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Shannon
 * USC email: sbrownle@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /* Your code here */
    int num = 0;  // define input number, sum(abundance), and count (number of abundant inputs) variables
    int sum = 0;
    int count = 1;
    while (cin >> num) // starts sum at 0; 
    {
        sum = 0;
        
        if (num == 0) { // deals with test case of 0
            break;
        }
        
        for(int i=1; i<num; i++) // iterates to find the abundance 
        {
            if (num%i==0)
            {
                sum +=i; // increases sum with each increment
            }
        }
        if (sum>num) // defines what to do if the sum is greater than the number, helps to determine if number is abundant
         {
            num_abundant = count++; // counts number of abundant numbers inputted by counting number of iterations
            int curr_a = sum;
            if (a3<curr_a) // these three if statments define what to do if current number has a greater abundance than the other numbers, defines how they should be                                     replaced on the list of rankings (if the current number has a greater abundance than that with the least abundnace in ranking)
            {
                if (a2<curr_a) //if the current number has a greater abundance than that with the second least abundnace in ranking
                {
                    if (a1<curr_a) //if the current number has a greater abundance than that with the greatest abundnace in ranking
                    {
                        n3 = n2;
                        a3 = a2;
                        n2 = n1;
                        a2 = a1;
                        n1 = num;
                        a1 = curr_a;
                    }
                    else // if current number is more abundant than two of the numbers on the ranking, defines how ranking should be changed
                    {
                        n3 = n2;
                        a3 = a2;
                        n2 = num;
                        a2 = curr_a;
                    }
                }
                else // if current number is more abundant than one of the numbers on the ranking, defines how ranking should be changed
                {
                    n3 = num;
                    a3 = curr_a;
                }
            }
        }
    }

    /* End of your code */

    cout << "Abundant number count: " << num_abundant << endl;
    cout << "Top 3 most abundant numbers: " << endl;
    cout << n1 << " : " << a1 << endl;
    cout << n2 << " : " << a2 << endl;
    cout << n3 << " : " << a3 << endl;


    return 0;

}
