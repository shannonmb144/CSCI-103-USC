# include <iostream>
using namespace std;
     int main ()
     { 
         int number;
         int factor_2=0;
         int factor_3=0;
             
     cout << "Enter a positive integer: ";
         cin >> number;

         while (number%2==0)
         {
         number = number/2;
             factor_2++;
         }
         while(number%3==0)
         {
         number = number/3;
             factor_3++;
         }
         if (factor_2+factor_3>0 && number==1)
         {
             cout <<  "Yes" << endl;
             cout<< "Twos=" << factor_2 << "  "<< "Threes=" << factor_3<< endl;
             }
         
         else 
             {
                 cout << "No" << endl;
             }
     
     
     }