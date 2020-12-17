// Kobe Norcross, CS 260, mgr.h
// This is a header file for the app manager

#ifndef MANAGER_H
#define MANAGER_H
#include "line.h"
#include "stack.h"

class AppManager
{
public:
	// constructor
	AppManager();

	// destructor	
	~AppManager();

	// Queue Calls
	void qPeek();
	void qDisplay();
	void newGroup();
	void seatGroup();

	// Stack Calls
	void sPeek();
	void sDisplay();
	void sPush();
	void sPop();

	// Main function routine 
	void printOptions();
	void getOption(int& option);
	int mainFunction(int &option);

private:
	Queue * queue;
	Stack * stack;
	
	// initialization of lists
	void initLists();
};
#endif
