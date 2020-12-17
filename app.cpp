// Kobe Norcross, CS 260, app.cpp
// This is the main function of the program
//

#include "mgr.h"

int main ()
{
	int option = 0;
	AppManager * manage = new AppManager();
	while (option != 8)
	{
		manage->printOptions();
		manage->getOption(option);
		manage->mainFunction(option);
	}	
	delete manage;
	return 0;
}
