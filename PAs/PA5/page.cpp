#include "page.h"
using namespace std;


Page::Page() 
{
    page_id = 0; //initialize variables to 0
    rank = 0.0;   
}

void Page::set_id(int id)
{
    page_id = id; //sets page id to input variable
}

int Page::get_id()
{
    return page_id; //gets page id
}

void Page::set_url(string pageurl)
{
    url = pageurl; //sets url to input varaiable
}

string Page::get_url()
{
    return url; //gets url
}

void Page::set_rank(double pagerank)
{
    rank = pagerank; //sets rank to input parameter
}

double Page::get_rank()
{
    return rank; //gets rank
}

void Page::set_links(vector<int> pagelinks)
{
    links = pagelinks; //sets links vector to input parameter
}

vector<int> Page::get_links()
{
    return links; //gets links
}