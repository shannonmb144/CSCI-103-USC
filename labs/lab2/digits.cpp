#include <iostream>
using namespace std;
    int main()
    {
    int number; // initialize variables
    int ones_digit;
    int tens_digit;
    int hunds_digit;
      
        
    cout << "Enter an integer between 0 and 999: "; // prompt user
    
    cin >> number;
    
       ones_digit = number%10; // mathematical formulas
       tens_digit = (number%100-ones_digit)/10;
       hunds_digit = (number - (tens_digit*10 )- ones_digit)/100;
        
     
    cout << " The ones digit is " << ones_digit << endl; // format output
    cout << " The tens digit is " << tens_digit << endl;
    cout << "The hundreds digit is " << hunds_digit << endl;
   
   return 0;
        
    }