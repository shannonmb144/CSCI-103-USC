#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int getRandomNumber();
int roll();
int n; // num rolls



int roll () {
   
 int num = rand() % 6+1;
      
   return num;    
}

void printHistogram(int counts[]) {
    for (int i=4; i<=24; i++) 
    {
        cout << i << ":";
        for (int j=0; j<counts[i-4];j++)
        {

        cout << "X" ;
        }
        cout << endl;
    }
    
}

int main () { 
   int counts[21];
   srand((int) time(0));
   cout<< "How many rolls?" << endl;
   cin >> n ; 
   
   for (int i=0;i<=20;i++)
   {
   counts[i] = 0;
   }

  
   for (int j=1;j<=n;j++)
   {
       int x=0;
       for (int i=1;i<=4;i++)
       {
           x+=roll();
           
       }
       counts[x-4]++;
   }
   printHistogram(counts);
   
   
   return 0;
}

 

