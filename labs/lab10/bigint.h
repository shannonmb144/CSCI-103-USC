#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
      BigInt(string s);   // convert string to BigInt
      string to_string(); // get string representation
      void add(BigInt b); // add another BigInt to this one
      BigInt(string s, int base01);
      int size();
      int get(int i);
      string message;
   private:
      string in_string;
      vector <int> in_vector; 
      int base;
     // int size();
      
    // whatever you need

};
