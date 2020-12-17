// Kobe Norcross, CS 260, contact.cpp
// implementation file for my contact.h file
#include "contact.h"
//===========================================================================================
//				Constructor/Destructor
//===========================================================================================
Contact::Contact()
{
	name = nullptr;
	email = nullptr;
}



Contact::Contact(Contact*& newContact)
{
	setName(newContact->name);
	setEmail(newContact->email);
}



Contact::Contact(char * name, char * email)
{
	setName(name);
	setEmail(email);
}



Contact::~Contact()
{
//	writeToFile();
	if (name) delete [] name;
	if (email) delete [] email;
}



//===========================================================================================
//					Accessors
//===========================================================================================
char * Contact::getName() const
{
	return name;
}



char * Contact::getEmail() const
{
	return email;
}



//===========================================================================================
//					Mutators
//===========================================================================================
void Contact::setName(char * newName)
{
	if (name) delete [] name;
	name = new char[strlen(newName)+1];
	strcpy(name, newName);
}



void Contact::setEmail(char * newEmail)
{
	if (email) delete [] email;
	email = new char[strlen(newEmail)+1];
	strcpy(email, newEmail);
}



void Contact::operator=(const Contact& newContact)
{
	setName(newContact.name);
	setEmail(newContact.email);
}



ofstream Contact::writeToFile()
{
	std::ofstream out;
	out.open("contacts.txt", ios::app);
	out << name << ';' << email << std::endl;
	out.close();
	return out;
}
