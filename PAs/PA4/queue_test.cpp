/* 
queue_test.cpp

Author: CS 103 Course Staff

Description: Tests whether the Queue class is working.

Expected output:

true
false
3 1
2 2
true
*/

#include "queue.h"
#include <iostream>
using namespace std;

int main() {
   // create some locations;
   Location three_one, two_two;
   three_one.row = 3; three_one.col = 1;
   two_two.row = 2; two_two.col = 2;

   // create an Queue with max capacity 5
   Queue q(5);

   cout << boolalpha;
   cout << q.is_empty() << endl;           // true
   q.add_to_back(three_one);
   cout << q.is_empty() << endl;           // false
   q.add_to_back(two_two);

   Location loc = q.remove_from_front();
   cout << loc.row << " " << loc.col << endl; // 3 1
   loc = q.remove_from_front();
   cout << loc.row << " " << loc.col << endl; // 2 2
   cout << q.is_empty() << endl;           // true
}
