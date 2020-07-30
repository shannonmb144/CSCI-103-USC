/* 
queue.h

Author: CS 103 Course Staff

Description: Declares two new data types,
- Location, a data type containing a row and column number
- Queue, a list of Locations organized chronologically

You shouldn't change this file.
*/

#ifndef QUEUE_H
#define QUEUE_H

// e.g. position [3][5] in an array would have row 3, col 5
struct Location {
   int row;
   int col;
};

// a class that contains a series of Locations
class Queue {
   public: // API:
   
   // constructor. maxlen must be as large as the total number
   // of Locations that will ever be entered into this Queue.
   Queue(int maxlen);
   
   // destructor. releases resources. C++ will call it automatically.
   ~Queue();
   
   // insert a new Location at the end/back of our list   
   void add_to_back(Location loc);

   // return and "remove" the oldest Location not already extracted
   Location remove_from_front();

   // is this Queue empty? (did we extract everything added?)
   bool is_empty();

   // member variables of an Queue, for implementation:
   private:
   Location* contents; // ptr to dynamically-allocated array
   int tail; // how many Locations were added so far?
             // (index of next free item at the end)
   int head; // how many Locations were extracted so far?
             // (index of the first occupied location)
};

#endif
