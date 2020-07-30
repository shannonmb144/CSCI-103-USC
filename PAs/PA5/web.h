#ifndef WEB_H
#define WEB_H
#include "page.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

class Web { 

public:
    Web();
    ~Web();
    /*
     reads in and parse graph from a file.
     @filename: is the name of the file describing the webgraph.
     @return: true in success , and false in failure.
    */
    bool read_graph(const char *filename);
    /*
     writes out webgraph to a file.
     @filename: is the name of the file to write to.
     @return: true in success , and false in failure
    */
 
    bool write_graph(const char *filename);
    /*
     calculates the rank of the pages
     @S: is the number of simulation iteration.
     @N: is the number of surfer
    */
    void calculate_rank(int S,int N);
private:    
    Page* page_list; //Array or list of Pages
    int count; //track total number of pages
};  
#endif
