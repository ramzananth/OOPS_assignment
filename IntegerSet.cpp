/*
 * IntegerSet.cpp
 *
 *  Created on: Feb 22, 2014
 *      Author: Ramya Ananth - CMPE 180-92 OOPS
 */

# include <iostream>
# include <stdio.h>
# include "IntegerSet.h"

using namespace std;

//Default constructor
IntegerSet::IntegerSet() : a(MAXSIZE,false)
{
}

//Parameterized Constructor with array and size of array
IntegerSet::IntegerSet(const int b[], const int& n) : a(MAXSIZE,false)
{
	int i;

	if(n >0 && n < MAXSIZE)
	{

		for (i = 0; i < n; i++)
		{
			if ( (b[i] >= 0) && (b[i] < MAXSIZE) )
			{
				a[b[i]] = 1;
			}
			else
			{
				cerr<<"ERROR b["<<i<<"] not in the range 0,"<<MAXSIZE<<endl;
			}
		}
	}
	else
	{
		cerr<<"ERROR n (array length parameter for constructor) = "<<n<<" is not in the range 1,"<<MAXSIZE<<endl;
	}
}

// Performs union of the two sets by combining all the elements of both sets together without duplication
IntegerSet IntegerSet::unionOfSets(const IntegerSet& Set2) const
{
	IntegerSet Set3;

	for (int i = 0; i < MAXSIZE ; i++)
	{

		Set3.a[i] = a[i] || Set2.a[i];

	}
	return Set3;
}

// Performs intersection of the two sets by considering the elements that exists in both sets
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& Set2) const
{
	IntegerSet Set3;
	for (int i = 0; i < MAXSIZE ; i++)
	{
		Set3.a[i] = a[i] && Set2.a[i];
	}
	return Set3;
}

//Inserts element K into the set if it does not exist already and if it is within the vector range
void IntegerSet::insertElement(const int& k)
{
	if(k >=0 && k < MAXSIZE)
	{
		if(a[k])
		{
			cerr<<"ERROR : Element "<<k<<" already present in the set"<<endl;
			return;
		}
		a[k] = true;
	}
	else
	{
		cerr<<"ERROR : Element "<<k<<" lies outside the allowed range of 0,"<<MAXSIZE-1<<endl;
	}
}

//Deletes element K from the set if it exists in the set
void IntegerSet::deleteElement(const int& k)
{
	if (a[k])
	{
		a[k] = false;
	}
	else
	{
		cout<<"ERROR : Element "<<k<<" not present in Set"<<endl;
	}
}

//Prints the contents of the set with spaces in between elements. Prints -- for an empty set
void IntegerSet::printSet() const
{
	int count = 0;
	for(int i = 0; i< MAXSIZE; i++)
	{
		if(a[i] == 1)
		{
			count++;
			cout<<i<<" ";
		}
	}
	if (count == 0)
	{
		cout<<"--"<<endl;
	}
	else
	{
		cout<<"\n";
	}
}

//Compares the two sets and checks if they are equal(have the same elements)
bool IntegerSet::operator==(const IntegerSet& Set2) const
{
	bool isEqual = true ;
	for (int i = 0; i < MAXSIZE ; i++)
	{
		if (a[i] != Set2.a[i])
		{
			isEqual = false ;
			break;
		}
	}
	return isEqual;
}
