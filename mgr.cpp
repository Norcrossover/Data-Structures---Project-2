// Kobe Norcross, CS 260, tools.cpp
// Implementation file for the app manager 

#include "mgr.h"



//====================================================================================================
//				Constructor/Initilization
//====================================================================================================
AppManager::AppManager() : queue(nullptr), stack(nullptr) 
{
	initLists();
}



void AppManager::initLists()
{
	queue = new Queue("line.txt");
	stack = new Stack(10);
}



//====================================================================================================
//					Destructor
//====================================================================================================
AppManager::~AppManager()
{
	delete queue;
	delete stack;
}



//====================================================================================================
//					Queue Calls
//====================================================================================================
void AppManager::qPeek()
{
	queue->peek();
}


void AppManager::qDisplay()
{
	queue->display();
}



void AppManager::newGroup()
{
	queue->newGroup();
}



void AppManager::seatGroup()
{
	bool promo;
	promo = queue->dequeue();
	if (promo == true) stack->addContact();
}



//====================================================================================================
//					Stack Calls
//====================================================================================================
void AppManager::sPeek()
{
	cout << endl << endl << "----------------------------------------------------------------" << endl << endl;
	cout << "               Next contact in list" << endl;
        cout << "               --------------------" << endl << endl;
        if (stack->isEmpty() == true) 
	{
		cout << "The contact list is empty." << endl << endl;
	}	
	else 
	{
		stack->peek();
	}
        cout << "----------------------------------------------------------------" << endl ;
}



void AppManager::sDisplay()
{
	cout << endl << endl << "----------------------------------------------------------------" << endl << endl;
	cout << "               Waiting List" << endl;
        cout << "               ------------"<< endl << endl;
	if (stack->isEmpty() == true)
        {
                cout << "The contact list is empty." << endl << endl;
        }
        else
        {
		stack->display();
        }
        cout << "----------------------------------------------------------------" << endl ;
}



void AppManager::sPush()
{
	stack->getContactInfo();
}




void AppManager::sPop()
{
	stack->pop();
}



//====================================================================================================
//	 			    Main function routine
//====================================================================================================
void AppManager::printOptions()
{
	cout << endl << endl << endl;
	cout << "======================================================="  << endl << endl;
	cout << "	  	          OPTIONS"	      		   << endl;
	cout << " 		          -------"			   << endl << endl;
	cout << "1. Add a new group to the waiting list." 		   << endl << endl;
	cout << "2. Seat the next group in the waiting list." 		   << endl << endl;
	cout << "3. Display the waiting list." 			  	   << endl << endl;
	cout << "4. Display the next group to be seated." 	  	   << endl << endl;
	cout << "5. Send promotional material to the newest contact." 	   << endl << endl;
       	cout << "6. Display newest contact. "   	   		   << endl << endl;
	cout << "7. Display the contact list."			  	   << endl << endl; 	
	cout << "8. Quit" 					  	   << endl << endl;
	cout << "======================================================="  << endl << endl;
}



void AppManager::getOption(int& option)
{
	cout << "Enter an option listed -> ";
	cin >> option;
	while (!cin || option < 1 || option > 8)
	{
		cin.clear();
		cin.ignore(MAXSIZE, '\n');
		cout << "Invalid option, try again -> ";
		cin >> option;
		cout << endl;
	}
}



int AppManager::mainFunction(int& option)
{
	if (option == 1) 
	{
		newGroup();
		return option;
	}

	else if (option == 2) 
	{
		seatGroup();
		return option;
	}

	else if (option == 3) 
	{
		qDisplay();
		return option;
	}

	else if (option == 4) 
	{
		qPeek();
		return option;
	}
	else if (option == 5) 
	{
		sPop();
		return option;
	}
	else if (option == 6)
	{
		sPeek();
		return option;
	}
	else if (option == 7)
	{
		sDisplay();
		return option;
	}
	else if (option == 8)
	{
		return option;
	}
	else
	{
		cout << "Invalid option, try again" << endl << endl;
		return option;
	}
}

