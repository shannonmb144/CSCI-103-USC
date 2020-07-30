#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <string.h>
#include <vector>
#include "os.h"

using namespace std;

//function prototypes
void run_command(OS*,vector<string>*,string);
void test_mlist(int,char**);
void test_os(int,char**);


void usage() { 
    cerr << "usage: ./filesys <options>"<< endl;
    cerr << "Examples:" << endl;
    cerr << "./filesys test_mlist <0-6>" << endl;
    cerr << "./filesys test_os <0-2>"<<endl;
    cerr << "./filesys terminal" << endl;
}

/*
	Main function - This is complete
   -------------------------------------------
   - DO NOT CHANGE ANYTHING IN THIS FUNCTION -
   -------------------------------------------
*/
int main(int argc, char* argv[])
{
    if(argc < 2){
    	usage();
    	return -1;
    }
    if(strcmp("terminal",argv[1])==0){
	    cout<<"--------------------------------"<<endl;
	    cout<<"Initailizing 103L OS ..........."<<endl;
	    OS terminal;
	    while(true){
	        string token;
	        string input;
	        vector<string> cmd;
	        cout << "\e[1m\e[38;5;54mCS103L_PA6_shell:\e[0m\e[1m";
	        terminal.present_working_dir();
	        cout<<"$\e[0m ";
	        getline(cin,input);
	        stringstream ss(input);
	        while(ss>>token){
	            cmd.push_back(token);
	        }
	        if(cmd.size() > 0){
	            string command = cmd.at(0);
	            if(command == "exit" || command == "quit"){
	                cout<<"Good bye!!"<<endl;
	                break;
	            }else{
	                run_command(&terminal,&cmd,command);
	            }
	        }
	    }
	    cout<<"--------------------------------"<<endl;
    	cout<<"Shutting down CS103L OS........."<<endl;
	    cout<<"--------------------------------"<<endl;
	}
	else if(strcmp("test_mlist",argv[1])==0){
		test_mlist(argc, argv);
	}else if(strcmp("test_os",argv[1])==0){
		test_os(argc,argv);
	}else{
		usage();
		return -1;
	}
    return 0;
}

/*
   List of commmands and invokation of functions
   -------------------------------------------
   - DO NOT CHANGE ANYTHING IN THIS FUNCTION -
   -------------------------------------------
*/
void run_command(OS* terminal,vector<string> *cmd,string command){
    if(command == "cd"){
        if(cmd->size() < 2){
            terminal->cd_dir("~");
        }else{
            terminal->cd_dir(cmd->at(1));
        }
    }else if(command == "ls")
    {
        if(cmd->size() < 2){
            //default option
            terminal->ls("-d");
        }else{
            terminal->ls(cmd->at(1));
        }
        cout<<endl;
    }else if(command == "pwd")
    {
        terminal->present_working_dir();
        cout<<endl;
    }else if(command == "write")
    {
        if(cmd->size()<2){
            cout<<"usage: write [filename]"<<endl;
        }
        else{
            terminal->file(cmd->at(1),false);
        }
    }else if(command == "read")
    {
        if(cmd->size()<2){
            cout<<"usage: read [filename]"<<endl;
        }else{
            terminal->file(cmd->at(1),true);
        }
    }else if(command == "rm")
    {
        if(cmd->size()<2){
            cout<<"usage: rm [file or directory name]"<<endl;
        }else{
            terminal->del(cmd->at(1));
        }
    }
    else if(command == "mkfile")
    {
        if(cmd->size()<2){
            cout<<"usage: mkfile [filename]"<<endl;
        }else{
            terminal->create_item(cmd->at(1),false);
        }
    }else if(command == "mkdir")
    {
        if(cmd->size()<2){
            cout<<"usage: mkdir [directory]"<<endl;
        }else{
            terminal->create_item(cmd->at(1),true);
        }
    }
    else if(command == "help")
    {
        cout<<"*---------------------------"<<endl;
        cout<<"*----Available Commands:----*"<<endl;
        cout<<"*---------------------------"<<endl;
        cout<<"cd - change directory"<<endl;
        cout<<"pwd - present working director"<<endl;
        cout<<"ls - list everything in the directory"<<endl;
        cout<<"mkfile - make a file"<<endl;
        cout<<"mkdir - make a directory"<<endl;
        cout<<"write - write to a file"<<endl;
        cout<<"read - read a file"<<endl;
        cout<<"rm - delete a file or directory"<<endl;
        cout<<"help - list all available commands"<<endl;
        cout<<"quit or exit - to terminate the program"<<endl;
    }else{
        cout<<"command: '"<<command<<"' not found"<<endl;
    }
}

/*
   This function is used to test your List class.
   -------------------------------------------
   - DO NOT CHANGE ANYTHING IN THIS FUNCTION -
   -------------------------------------------
*/
void test_mlist(int argc, char** argv){
    MList list;
    //statically allocate these data obj to be used for this function
    Data a = {}; //a way to zero intialize = all fields are zero
    Data b = {}; Data c = {}; Data d = {}; Data e = {};
    Data f = {}; Data g = {}; Data h = {}; Data i = {}; 
    Data j = {}; Data k = {}; Data l = {}; Data m = {};
    a.name = "a"; a.size = 3; b.name = "b"; b.size = 6;
    c.name = "c"; c.size = 1; d.name = "d"; d.size = 4;
    e.name = "e"; e.size = 19; f.name = "f"; f.size = 7;
 	g.name = "g"; h.name = "h"; i.name = "i"; j.name = "j";
 	k.name = "k"; l.name = "l"; m.name ="m"; m.size = 10;
 	c.isFolder = true;l.isFolder=true;
    cout<<boolalpha;
    bool all = false;
    if(argc == 2 || atoi(argv[2]) == 0){
    	all = true;
    }
    if(all || atoi(argv[2]) == 1){
	    cout<<"- \e[35mBASIC CHECKING - MODE 1\e[0m -----"<<endl;
	    //Start our test ----------------------------
	    cout<<list.isEmpty()<<endl;//is empty? true
	    list.push_top(&g);
	    cout<<list.top()->nodeData->name<<endl;//g
	    cout<<list.bottom()->nodeData->name<<endl;//g
	    cout<<list.isEmpty()<<endl;//false
        list.pop_top();
        list.push_top(&g);
        list.pop_bottom();
	    list.push_top(&g);
	    list.push_top(&f);
	    list.push_bottom(&k);
	    cout<<list.top()->nodeData->name<<endl;//f
	    cout<<list.bottom()->nodeData->name<<endl;//k
	    list.pop_bottom();list.pop_top();list.pop_top();
	    cout<<list.isEmpty()<<endl;//true
    }
    if(all || atoi(argv[2]) == 2){
	    cout<<"- \e[35mPRINT CHECKING - MODE 2\e[0m -----"<<endl;
	    list.clear();
	    list.push_top(&l);list.push_top(&d);list.push_top(&c);
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;//c and l are a folder: T-> c d(4) l <-B
	    cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;//c and l are a folder: B-> l d(4) c <-B
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);
	    list.push_bottom(&g);list.push_top(&b);list.push_bottom(&f);
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;
	    cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	}
	if(all || atoi(argv[2]) == 3){
	    cout<<"- \e[35mSWAP AND INSERT AFTER CHECKING - MODE 3\e[0m -----"<<endl;
	    list.clear();
        list.push_top(&c);
        list.swapNode(list.top(),list.bottom());
        cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
        list.clear();
	    list.push_top(&d);list.push_top(&e);//before swap: T-> e d <-B
	    list.swapNode(list.top(),list.bottom());//a before b//now T-> d e <-B
	    list.swapNode(list.bottom(),list.top());//b before a//expect the same as starting, since we swap two times: T-> e d <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);list.push_bottom(&g);
	    list.swapNode(list.top()->next,list.bottom());
	    //before swap: T-> e d m g <-B
	    //expect: T-> e g m d <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    //moving node m to the top. Expect: T-> m e g d <-B
	    Node * tmp = list.bottom()->prev;list.removeNode(tmp);list.insertAfter(tmp,NULL);
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    //moving node e to bottom. Expect: T-> m g d e <-
		tmp = list.top()->next;list.removeNode(tmp);list.insertAfter(tmp,list.bottom());
		cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	}	
	if(all || atoi(argv[2]) == 4){
	    cout<<"- \e[35mSORT CHECKING - MODE 4\e[0m -----"<<endl;
	    //each sort 3 steps: 1). when it's empty 2). when there's one element, 3). when there're many elements
	    //SELECTION SORT
	    list.clear();
	    list.sortByNameSelection();//no item to sort, shouldn't do anything
	    list.push_top(&m);list.sortByNameSelection();//one element, sort should be the same: T-> m <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);list.push_bottom(&g);list.push_top(&b);list.push_bottom(&f);
	    //before sort: T-> b e d m g f <-B
	    //expect after: T-> b d e f g m <-B
	    list.sortByNameSelection();
        list.sortByNameSelection();//sort on a sorted list
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    //SortBySize
	    list.clear();
	    list.sortBySizeSelection();//no item to sort, dont do anything
		list.push_top(&m);list.sortBySizeSelection();//one element, sort should be the same: T-> m <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);list.push_bottom(&g);list.push_top(&b);list.push_bottom(&f);
	    //before sort: T-> 6 19 4 10 0 7 <-B
	    //expect after: T-> 0 4 6 7 10 19 <-B
	    list.sortBySizeSelection();
        list.sortBySizeSelection();//sort on a sorted list
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
		//INSERTION SORT
	    list.clear();
	    list.sortByNameInsertion();//no item to sort, dont do anything
	    list.push_bottom(&m);list.sortByNameInsertion();//one element, sort should be the same: T-> m <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);list.push_bottom(&g);list.push_top(&b);list.push_bottom(&f);
	    //before sort: T-> b e d m g f <-B
	    //expect after: T-> b d e f g m <-B
	    list.sortByNameInsertion();
        list.sortByNameInsertion();//sort on a sorted list
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	}
	if(all || atoi(argv[2]) == 5){
	    cout<<"- \e[35mDELETE CHECKING - MODE 5\e[0m -----"<<endl;
	    //4 cases - delete one element, delete top, delete bottom, delete middle
	    list.clear();
	    list.push_top(&m);cout<<list.isEmpty()<<endl;//not empty = false
	    list.deleteNode(list.top());cout<<list.isEmpty()<<endl;//now empty = true
	    list.clear();
	    list.push_top(&f);list.push_top(&d);cout<<(list.top()==list.bottom())<<endl;//top != bottom; false
	    list.deleteNode(list.top());cout<<(list.top()==list.bottom())<<endl;//now top == bottom; true
	    //expect T-> f <-B, since we delete top which is d
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&f);list.push_top(&d);
	    list.deleteNode(list.bottom());cout<<(list.top()==list.bottom())<<endl;//now bottom == top; true
	    //expect T-> d <-B, since we delete bottom which is f
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.clear();
	    list.push_top(&m);list.push_top(&d);list.push_top(&e);//before delete: T->e d m<-B
	    list.deleteNode(list.top()->next);
	    //expect after delete: T-> e m <-B
	    cout<<"T-> ";list.printTtB(" ");cout<<"<-B"<<endl;cout<<"B-> ";list.printBtT(" ");cout<<"<-T"<<endl;
	    list.deleteNode(list.top());list.deleteNode(list.top());cout<<list.isEmpty()<<endl;//delete everything, should be an empty list
	}
	if(all || atoi(argv[2]) == 6){
	    cout<<"- \e[35mSEARCH CHECKING - MODE 6\e[0m -----"<<endl;
	    list.clear();
	    cout<<((list.search(list.top(),"a")==NULL)?true:false)<<endl;//search on empty list, not found? -> true
	    list.push_top(&m);list.push_top(&d);
	    cout<<((list.search(list.top(),"a")==NULL)?true:false)<<endl;//a is not in the list, not found? -> true
	    cout<<((list.search(list.top(),"m")==NULL)?true:false)<<endl;//m is in the list, not found? -> false
	}
}


/*
   This function tests a basic functionality of your OS class.
   -------------------------------------------
   - DO NOT CHANGE ANYTHING IN THIS FUNCTION -
   -------------------------------------------
*/
void test_os(int argc, char** argv){
    bool all = false;
    cout<<boolalpha;
    if(argc == 2 || atoi(argv[2]) == 0){
    	all = true;
    }
    if(all || atoi(argv[2]) == 1){
    	OS t;
    	cout<<"- \e[33mTEST BASIC 1\e[0m -----"<<endl;
    	//test basic add files and folders, move into folders, print working directory, go back to root
    	cout<<((t.search_item("itemsearch")==NULL)? true:false)<<endl;//true, nothing in the directory yet.
    	t.create_item("Paola",false);t.create_item("Bonny",true);
    	t.create_item("Shaunta",true);t.create_item("Holl",false);
    	t.create_item("Federico",false);t.create_item("Terrian",false);
    	t.create_item("Marie",true);t.create_item("Charlie",true);
    	//Bonny Charlie Federico(0) Holl(0) Marie Paola(0) Shaunta Terrian(0) - list should already be sorted ascending order
    	t.ls("-d");cout<<endl;
    	//reverse of above: Terrian(0) Shaunta Paola(0) Marie Holl(0) Federico(0) Charlie Bonny
    	t.ls("-r");cout<<endl;
    	t.cd_dir("Marie");t.create_item("Shuan",true);t.cd_dir("Shuan");
    	t.create_item("Jarrod",true);t.create_item("Reinaldo",false);
    	//Jarrod Reinaldo(0)
    	t.ls("-d");cout<<endl;
    	cout<<((t.search_item("Jarrod")==NULL)? true:false)<<endl;//true, item found
    	t.cd_dir("Jarrod");
    	t.present_working_dir();cout<<endl;//root/Marie/Shuan/Jarrod/
    	t.cd_dir("..");//back up one step
    	t.ls("-r");cout<<endl;//reverse print = Reinaldo(0) Jarrod
    	t.present_working_dir();cout<<endl;//root/Marie/Shuan/
    	t.cd_dir("~");//back to root
    	t.present_working_dir();cout<<endl;//root/
    	t.ls("-d");cout<<endl;//
    }
    if(all || atoi(argv[2]) == 2){
    	OS t;
    	cout<<"- \e[33mTEST BASIC 2\e[0m -----"<<endl;
        t.cd_dir("..");
        t.present_working_dir();cout<<endl;//root/
        t.cd_dir("..");
        t.present_working_dir();cout<<endl;//root/
    	t.create_item("o",true);t.cd_dir("o");//root/o/
    	t.create_item("o",true);t.cd_dir("o");//root/o/o/
    	t.create_item("o",true);t.create_item("d",false);//root/o/o/(d(0) o)
    	t.ls("-d");cout<<endl;//d(0) o
    	t.cd_dir("o");
    	t.create_item("o",true);//root/o/o/(d o)/o
		t.cd_dir("o");t.create_item("o",true);//root/o/o/(d o)/o/o
    	t.cd_dir("o");t.create_item("o",false);//root/o/o/(d o)/o/
    	t.ls("-r");cout<<endl;//o(0)
    	t.present_working_dir();cout<<endl;//root/o/o/o/o/o/
    	t.create_item("a",true);t.create_item("c",false);
    	t.ls("-r");cout<<endl;//o(0) c(0) a
    	t.cd_dir("a");t.cd_dir("~");//back to root
    	t.create_item("b",true);t.create_item("c",false);
    	t.ls("-d");cout<<endl;//b c(0) o(0)
    	t.del("b");t.del("orange");t.del("o");
    	t.ls("-sort=size");cout<<endl;//c(0)
    }
}