/*
 * testIntegerSet.cpp
 *
 *  Created on: Feb 22, 2014
 *      Author: Ramya Ananth - CMPE 180-92 OOPS
 */


# include<iostream>
# include<stdio.h>
# include "IntegerSet.h"
using namespace std;

int main(void)
{
	cout<<"*** Testing Ramya Ananth's IntegerSet ***\n";

	int set[5] = {3,6,54,78,99};
	//Initializing Set1
	IntegerSet Set1(set,5);
	cout<<"Contents of Set 1: \n";
	Set1.printSet();

	IntegerSet Set2;
	cout<<"Contents of Set2:\n";
	//Set2 is an empty set
	Set2.printSet();

	//Inserting elements into Set2
	Set2.insertElement(78);
	Set2.insertElement(3);
	Set2.insertElement(54);
	Set2.insertElement(47);
	//Printing contents of Set2
	cout<<"Contents of Set 2 after inserting (78,3,54,47) : \n";
	Set2.printSet();

	//Performing Union of sets
	IntegerSet Set3 = Set1.unionOfSets(Set2);
	cout<<"Contents of Set 3 after Union of Set1 and Set2: \n";
	Set3.printSet();

	//Performing intersection of sets
	IntegerSet Set4 = Set1.intersectionOfSets(Set2);
	cout<<"Contents of Set 4 after Intersection of Set1 and Set2: \n";
	Set4.printSet();

	//Inserting and Deleting elements into/from Set1
	cout<<"Inserting elements 120 and 3 into Set1:\n";
	Set1.insertElement(120);
	Set1.insertElement(3);
	cout<<"Deleting element 88 from Set1:\n";
	Set1.deleteElement(88);

	Set1.deleteElement(6);
	Set1.deleteElement(99);
	Set1.insertElement(47);

	cout<<"Contents of Set1 after delete (6,99) and insert (47) operations: \n";
	Set1.printSet();

	//Printing final contents of Set1 and Set2
	cout<<"Final Contents of Set1 \n";
	Set1.printSet();

	cout<<"Final Contents of Set2 \n";
	Set2.printSet();

	//Checking if Set1 is equal to Set2
	cout<<"Checking if Set1 == Set2:\n";
	if (Set1 == Set2)
	{
		cout<<"Set1 is equal to Set2"<<endl;
	}
	else
	{
		cout<<"Set1 is NOT equal to Set2"<<endl;
	}
}
