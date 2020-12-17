// Kobe Norcross, CS 260, group.cpp
// This is the implementation file of the Group class

#include "group.h"

//===========================================================================================
//				Constructor/Destructors
//===========================================================================================
Group::Group() : groupName(nullptr), specialSeating(nullptr), numPeople(0) {}



Group::Group(Group *& newGroup)
{
	setGroupName(newGroup->groupName);
	setNumPeople(newGroup->numPeople);
	setSpecialSeating(newGroup->specialSeating);
}



Group::~Group()
{
	if (groupName)
	{
		delete [] groupName;
		groupName = nullptr;
	}
	if (specialSeating) 
	{
		delete [] specialSeating;
		groupName = nullptr;
	}
	numPeople = 0;
}




//===========================================================================================
//				Accessors
//===========================================================================================
char * Group::getGroupName() const
{
	return groupName;
}



char * Group::getSpecialSeating() const
{
	return specialSeating;
}



int Group::getNumPeople() const
{
	return numPeople;
}



//===========================================================================================
//				Mutators
//===========================================================================================
void Group::setGroupName(char * name)
{
	if (groupName) delete [] groupName;
	groupName = new char[strlen(name)+1];
	strcpy(groupName, name);
}


void Group::setSpecialSeating(char seating[])
{
	if (specialSeating) delete [] specialSeating;
	specialSeating = new char[strlen(seating)+1];
	strcpy(specialSeating, seating);
}



void Group::setNumPeople(int num)
{
	numPeople = num;
}
