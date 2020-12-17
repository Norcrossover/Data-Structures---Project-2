// Kobe Norcross, CS 260, group.h
// This is the header file of the group class

#ifndef GROUP_H
#define GROUP_H
#include "stack.h"

class Group
{
public:
	// constructor
	Group();
	Group(Group *& newGroup);

	// destructor
	~Group();

	// operator overload

	// accessors
	char * getGroupName() const;
	char * getSpecialSeating() const;
	int getNumPeople() const;

	// mutators
	void setGroupName(char name[]);
	void setSpecialSeating(char seating[]);
	void setNumPeople(int num);

private:
	char * groupName;
	char * specialSeating;
	int numPeople;
};
#endif
