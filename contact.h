// Kobe Norcross, CS 260, contact.h
// This is the contact info for each element of the Stack ADT

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;
const int MAXSIZE = 256;
#include <fstream>
#include <cstring>

class Contact
{
public:
	// constructor
	Contact();
	Contact(Contact*& newContact);
	Contact(char * name, char * email);

	// destructor
	~Contact();

	// accessors
	char * getName() const;
	char * getEmail() const;

	// mutators
	void setName(char * newName);
	void setEmail(char * newEmail);	

	// operator overload
	void operator=(const Contact& newContact);

	// write to file
	ofstream writeToFile();

private:
	char * name;
	char * email;
};
#endif
