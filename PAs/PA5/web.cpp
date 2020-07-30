#include "web.h"
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

Web::Web() 
{ 
    
}

Web::~Web() 
{ 
    delete[] page_list; //deallocated the memory of page_list
}

bool Web::read_graph(const char *filename)
{
    //input file to ifstream
    ifstream ifile(filename);
   
    //if program can't open file, returns false
    if (ifile.fail())
      return false;
   
    /*declare temp variables to store
      information while reading in values*/
    int tempid;
    string tempurl;
    double temprank;
    string templinks;
    vector<int> linksvec;
    Page newpage;
    int tempint;
   
    //read in number of pages from file
    ifile >> count;
    //if file is malformed, return false
    if (ifile.fail())
      return false;
   
    //initializes allpages with the correct number of pages
    page_list = new Page[count];
   
    //for every page in allpages,
    for(int i = 0; i < count; i++){
        //read in temp id, url, and rank variables from file
        ifile >> tempid >> tempurl >> temprank;
       
        //read in the line of links into a string
        getline(ifile, templinks);
        getline(ifile, templinks);
        /*create a stringstream for the temp
          string of links for this page*/
        stringstream ss(templinks);
       
        //goes through stringstream, reading in ints
        while(ss >> tempint){
            //add these ints to back of temp links vector
            linksvec.push_back(tempint);
        }
       
        //assign all temp variables to 'newpage'
        newpage.set_id(tempid);
        newpage.set_url(tempurl);
        newpage.set_rank(temprank);
        newpage.set_links(linksvec);
       
        //assign the corresponding page in allpages to 'newpage'
        page_list[i] = newpage;
       
        //clear the temp link vector
        linksvec.clear();
    }
   
    //close the file and return true
    ifile.close();
    return true;
     
}

bool Web::write_graph(const char *filename)
{
    //output file to ofstream
    ofstream outfile(filename);
   
    //declares temp variables to store info
    Page currpage;
    vector<int> currlinks;
   
    //if program can't open file, returns false
    if(outfile.fail())
        return false;
   
    //outputs the number of pages and new line
    outfile << count << '\n';
   
    //for each page,
    for (int i = 0; i < count; i++){
        //set currpage to corresponding page in allpages
        currpage = page_list[i];
       
        //outputs currpage's id, url, and rank in correct format
        outfile << currpage.get_id() << '\n';
        outfile << '\t' << currpage.get_url() << '\n';
        outfile << '\t' << currpage.get_rank() << '\n' << '\t';
       
        //set currlinks to currpage's links vector
        currlinks = currpage.get_links();
        //output each element of currlinks in correct format
        for (int j = 0; j < currlinks.size(); j++)
            outfile << currlinks[j] << " ";
        outfile << '\n';
    }
   
    //close output file and return true
    outfile.close();
    return true;
}

void Web::calculate_rank(int S,int N)
{
    //declare and initialize variables
    int randlink;
    //divide walkers evenly between pages
    int wpp = N/count;
    //create arrays to hold the walkers on each page
    int* pages = new int[count];
    int* temp = new int[count];
   
    for (int i = 0; i < count; i++){
        /*initializes pages array elements to wpp
          (evenly distributed walkers)*/
        pages[i] = wpp;
        //initializes temp array elements to 0
        temp[i] = 0;
    }
   
    //for each simulation iteration,
    for (int i = 1; i <= S; i++){
       
        //goes through every page in allpages
        for (int p = 0; p < count; p++){
           
            //goes through all the walkers on current page
            for (int j = 0; j < pages[p]; j++){
               
                //declare and set current page
                Page currpage = page_list[p];
               
                //set currlinks to the current page's link vector
                vector<int> currlinks = currpage.get_links();
               
                //picks a random link from currlinks
                randlink = currlinks[rand() % currlinks.size()];
               
                //adds walker to the temp page that corresponds with randlink
                temp[randlink]++;
               
                //subtracts the walker from the current page
                temp[p]--;
            }
        }
       
        /*at the end of this simulation iteration, adds the walkers in the
         temp array to the pages array, and reinitializes temp to 0*/
        for(int s = 0; s < count; s++){
            pages[s] += temp[s];
            temp[s] = 0;
        }
    }
   
    //for each page in allpages,
    for (int i = 0; i < count; i++){
        //finds proportion of walkers in that page to all walkers
        double prop = (double)pages[i] / (double)N;
        //sets rank of that page to the proportion
        page_list[i].set_rank(prop);
    }
   
    //deallocates memory
    delete [] pages;
    delete[] temp;
}
