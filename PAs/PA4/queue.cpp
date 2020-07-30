/* 
queue.cpp

Author: Shannon Brownlee

Short description of this file:
Function definitions for dealing with queue
*/

#include "queue.h"

// constructor. maxlen must be as large as the total number
// of Locations that will ever be entered into this Queue.
// this is complete, you don't need to change it.
Queue::Queue(int maxlen) {
   contents = new Location[maxlen];
   head = 0;
   tail = 0;
}

// destructor. releases resources. C++ will call it automatically.
// this is complete, you don't need to change it.
Queue::~Queue() {
   delete[] contents;
}

// insert a new Location at the end/back of our list   
void Queue::add_to_back(Location place) 
{
	tail++;
	contents[tail] = place; //new place on end of list
}

// return and "remove" the oldest Location not already extracted
Location Queue::remove_from_front() 
{
    	head += 1;
        return contents[head];
}

// is this Queue empty? (did we extract everything added?)
// this is complete, you don't need to change it.
bool Queue::is_empty() {
   return head == tail;
}

