// Kobe Norcross, CS 260, tools.cpp
// Implementation file for all of the helper functions

#include "tools.h"

void printOptions()
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
	cout << "7. Check if the contact list is empty or not."  	   << endl << endl; 	
	cout << "8. Quit" 					  	   << endl << endl;
	cout << "======================================================="  << endl << endl;
}



void getOption(int& option)
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



int mainFunction(Queue& aQueue, int option)
{
	if (option == 1) 
	{
		aQueue.newGroup();
		return option;
	}

	else if (option == 2) 
	{
		aQueue.dequeue();
		return option;
	}

	else if (option == 3) 
	{
		aQueue.display();
		return option;
	}

	else if (option == 4) 
	{
		aQueue.peek();
		return option;
	}
	else if (option == 5) 
	{
		aQueue.sendEmail();
		return option;
	}
	else if (option == 6)
	{
		aQueue.stackPeek();
	}
	else if (option == 7)
	{
		aQueue.stackPeek();
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

