/*
 * IntegerSet.h
 *
 *  Created on: Feb 22, 2014
 *      Author: Ramya Ananth - CMPE 180-92 OOPS
 */

#ifndef INTEGERSET_H_
#define INTEGERSET_H_

#include <vector>
# define MAXSIZE 101

class IntegerSet
{
	std::vector<bool> a;

public:

	//Default constructor
	IntegerSet();

	//Additional Constructor
	IntegerSet(const int b[],const int& n);

	IntegerSet unionOfSets(const IntegerSet& Set2) const;

	IntegerSet intersectionOfSets(const IntegerSet& Set2) const;

	void insertElement(const int& k);

	void deleteElement(const int& k);

	void printSet() const;

	bool operator==(const IntegerSet& Set2) const;

};


#endif /* INTEGERSET_H_ */



