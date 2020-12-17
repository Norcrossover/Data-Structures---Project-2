// Kobe Norcross, CS 260, line.h
// This is the header file for the queue ADT

#ifndef LINE_H
#define LINE_H
#include "group.h"

class Queue
{
public:
	// constructor
	Queue(const char * fileName);

	// destructor
	~Queue();

	// accessors
	bool peek();
	bool display();

	// mutators
	bool enqueue(Group *& newGroup);
	bool dequeue();
	void newGroup();

private:
	struct node
	{
		// node constructor
		node(Group *& newGroup)
		{
			data = newGroup;
		}
		// node destructor
		~node()
		{
			if (data != nullptr) delete data;
		}
		node * next;
		Group * data;
	};
	node * front;
	node * back;

	// recursive functions
	bool display(node * curr, int& index);

	// initialization functions
	void waitingListInit(const char * fileName);
	void newGroupInit();
	
	// helper functions
	void getChoice(char& choice);
	bool promoCheck();
};
#endif
