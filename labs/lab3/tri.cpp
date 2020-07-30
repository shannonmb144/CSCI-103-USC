#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int n = 31;
   double degrees;
    
    cout<<"Enter the angle theta in degrees: " << endl; 
    cin>> degrees;
    
    double radians = degrees*(M_PI/180);
    
   for (int i=0; i<=n;i++ ) {
       double current_line = i*tan(radians);
       
       if (floor(current_line)>=20 && floor(current_line)<=30)
       {
           current_line = 20;
       }
       
      for (int j=0;j<floor(current_line);j++   ) {
         cout <<  '*' ;
      }
      cout <<  endl; ;
   }
}