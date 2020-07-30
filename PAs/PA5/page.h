#ifndef PAGE_H
#define PAGE_H
#include <string>
using std::string;
#include<vector>
using std::vector;
class Page { 
public:
  Page();
  //setters and getters
  void set_id (int id);
  int get_id ();
  void set_url(string pageurl);
  string get_url();
  void set_rank(double pagerank);
  double get_rank();
  void set_links(vector<int> pagelinks);
  vector<int> get_links();
private:
  int page_id;
  string url;
  double rank;
  vector<int> links; 
  
  //Data members: id, url, pagerank, links , .. etc
};  
#endif
