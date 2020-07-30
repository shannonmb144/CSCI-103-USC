/* Author: Shannon Brownlee
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */
#include <iostream>
#include <cmath>

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main(int argc, char *argv[])
{
    double x; // Declares variable x
    double sinx; // Declares variable sinx
    
        
        
   
   
   
   // Prompt the user
   cout << "Enter x in radians:  ";
   
   // get input
   cin >> x;
   
   // Do some operations
   for (int i=1, j=0; i<8; i+=2,j++) // i increases by 2 until it reaches 7, j increases by 1
    {
    double sign = pow(-1,j);
        sinx += (sign*(pow(x,i)))/fact(i);
    }
   
   // Print the result to the user
   cout << " The approximate value of sin(x) is " << sinx << endl;
   
   // You're done
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

