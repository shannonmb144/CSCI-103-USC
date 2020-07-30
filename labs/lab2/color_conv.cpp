/* Author: Shannon Brownlee
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    double white1; // initialize all variables
    double white;
    int red;
    int green;
    int blue;
    double cyan;
    double magenta;
    double yellow;
    double black;
    
    cout << "Enter RGB values with a space in between: "; // user input
    cin >> red ; cin >> green; cin >> blue;
    
    
    white1= max((red/(255.0)), (green/(255.0))); // determines maximum between red and green over 255
    white = max(white1,(blue/(255.0))); // determines ultimate maximum of RGB values
 
    cyan = (white-(red/255.0))/white; // given formulas
    magenta = (white-(green/255.0))/white;
    yellow = (white-(blue/255.0))/white;
    black = 1-white;
    
    cout << "cyan: " << cyan << endl;
    cout << "magenta: " << magenta << endl;
    cout << "yellow: " << yellow << endl;
    cout<< "black: " << black << endl;
   
   
   
   
   
   return 0;
}
