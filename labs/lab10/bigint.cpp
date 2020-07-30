#include "bigint.h"
#include <iostream>
#include <stdexcept>


using namespace std;

BigInt::BigInt(string s, int base01)
{
	base = base01;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i]  <= '9')
		{
			in_vector.push_back(s[i] - '0');
		}
		else
		{
			in_vector.push_back((s[i] - 'A')+10);
		}
	} 	
} 

BigInt::BigInt(string s)
{
	base = 10;
	for (int i = s.size()-1; i >= 0; i--)
	{
		in_vector.push_back(s[i] - '0');
	}		 	
} 

string BigInt::to_string()
{
	string temporaryString;
	for (int i = in_vector.size() - 1; i >= 0; i--)
	{
		char c;
		if (in_vector[i] >= 0 && in_vector[i]  <= 9)
		{
			 c = (char) in_vector[i] + '0';
		}
		else
		{
			 c = (char) (in_vector[i] - 10) + 'A' ;
		}
		temporaryString.push_back(c);
	}
	return temporaryString;
}

void BigInt::add(BigInt b)
{
	int carry=0;
	if (in_vector.size() < b.size())
	{
		int size_difference;
		size_difference = b.size() - in_vector.size();
		for(int i = 0; i < size_difference; i++)
		{
			in_vector.push_back(0);
		}
	}
	else 
	{
		int size_difference;
		size_difference = in_vector.size() - b.size();
		for(int i = 0; i < size_difference; i++)
		{
			b.in_vector.push_back(0);
		}
	}	

	for (int i = 0; i < b.size(); i++) 
	{
		int sum;
		sum = in_vector[i] + b.get(i) + carry;
		in_vector[i] = sum % base;
		if (sum > base - 1)
		{
			carry = 1;
		}
		else 
		{
			carry = 0;
		}	
	}
	if (carry != 0)
	{
		in_vector.push_back(carry);
	}
}	

int BigInt::size()
{
	return in_vector.size();
}

int BigInt::get(int i)
{
	return in_vector[i];
}