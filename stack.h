// Kobe Norcross, CS 260, stack.h
// This is the header file of the stack ADT. 

#ifndef STACK_H
#define STACK_H 
#include "contact.h"

class Stack
{
public:
	// constructor
	Stack();
	Stack(int newCapacity);
	Stack(const Contact& aList); 
	
	// destructor
	~Stack();


	// accessors
	bool display();
	bool peek();
	bool isEmpty();

	// mutators
	void addContact();
	void getContactInfo();
	void push(Contact*& data);
	bool pop();

	// operator overload
	const Stack& operator=(const Stack& newStack);

private:
	int top;
	int capacity;
	const static int initialSize = 5;
	const static int growthFactor = 2;
	Contact ** aStack;

	void destroy();
	void grow();
	void getChoice(char& choice);
};
#endif
