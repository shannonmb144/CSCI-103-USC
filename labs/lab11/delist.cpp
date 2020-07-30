#include "delist.h"
#include <iostream>
#include <cstdlib>


using namespace std;

DEList::DEList()
{
	begin=NULL;
    end=begin;
    nodes=0;
}


DEList::~DEList()
{
	DEItem*temp=begin;
	while(temp != end)
    {
		temp=temp->next;
		delete begin;
        begin=temp;
	}
	delete temp;
}


bool DEList::empty()
{
	if(nodes==0)
    {
		return 1;
	}

	else
    {
		return 0;
	}

}


int DEList::size()
{
	return nodes;
}


int DEList::front()
{
	if(empty())
    {
		return -1;
	}
	else
    {
		return begin->val;
	}
}


int DEList::back()
{
	if(empty())
    {
		return -1;
	}
	else
    {
		return end->val;
	}
}


void DEList::push_front(int new_val)
{
	if(empty())
    {
		DEItem*temp = new DEItem;
		temp->prev = NULL;
		temp->val = new_val;
		temp->next = NULL;
		begin=temp;
		end=temp;
	}

	else
    {
		DEItem*temp = new DEItem;
		temp->next = begin;
		temp->val = new_val;
		temp->prev = NULL;
		begin->prev = temp;
		begin=temp;
	}
	nodes++;
}


void DEList::push_back(int new_val)
{
	if(empty())
    {
		DEItem*temp = new DEItem;
		temp->prev = NULL;
		temp->val = new_val; 
		temp->next = NULL;
		end = temp;
		begin = temp;
	}
	else
    {
 		DEItem*temp = new DEItem;
		temp->prev = end;
		temp->val = new_val;
		temp->next = NULL;
		end->next = temp;
		end = temp;
	}
	nodes++;
}


void DEList::pop_front()
{
	if(!empty())
    {
		DEItem*temp = begin;
		begin = temp->next;
		delete temp;
		nodes--;
	}
}

void DEList::pop_back()
{
	if(!empty())
    {
		DEItem*temp = end;
		end = end->prev;
		delete temp;
		nodes--;
	}
}