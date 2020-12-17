// Kobe Norcrosss, CS 260, promo.cpp
// This is the implementation file of the Stack ADT

#include "stack.h"

//===========================================================================================
//			   Constructor/Destructor
//===========================================================================================
Stack::Stack() : top(0), capacity(initialSize) 
{
	aStack = new Contact * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		aStack[i] = nullptr;
	}
}



Stack::Stack(int newCapacity) : top(0), capacity(newCapacity)
{
	aStack = new Contact * [capacity];	
	for (int i = 0; i < capacity; i++)
	{
		aStack[i] = nullptr;
	}
}



Stack::Stack(const Contact& aList) : top(0)
{
	*this = aList;
}



Stack::~Stack()
{
	destroy();
}



void Stack::destroy()
{
	for (int i = 0; i < top; i++)
	{
		if (aStack[i]) delete aStack[i];
	}
	if (aStack) delete [] aStack;
	capacity = 0;
	top = 0;
}


//===========================================================================================
//				Accessors
//===========================================================================================
bool Stack::display()
{
	if (aStack)
	{
		//cout << "Displayed from most recent person to sign up, to oldest sign up:" << endl << endl;
		for (int i = 0; i < top; i++)
		{
			cout << "NAME:  " << aStack[i]->getName() << endl;
                	cout << "EMAIL: " << aStack[i]->getEmail() <<  endl << endl;
		}
		return true;
	}
	return false;
}

bool Stack::peek()
{
	if (isEmpty() == false)
	{
		cout << "NAME:  " << aStack[top-1]->getName() << endl;
		cout << "EMAIL: " << aStack[top-1]->getEmail() << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}


bool Stack::isEmpty()
{
	if (top == 0)
		return true;
	else
		return false;
}



//===========================================================================================
//				Mutators
//===========================================================================================
// Push will be invoked with a new data type from the queue
// then size will be incremented and grow will be invoked with the new data
void Stack::push(Contact*& data)
{
	if (top == capacity)
	{
		grow();
	}
	aStack[top] = data;
	top++;
}



void Stack::grow()
{
	// increase the capacity
	capacity *= growthFactor;

	// create a temporary stack to copy the data into
	Contact ** tempStack = new Contact * [capacity];
	
	// copy the array into the stack's new array
	for (int i = 0; i < top; i++)
	{
		tempStack[i] = aStack[i];	
	}
	if (aStack) delete [] aStack;
	aStack = tempStack;
}



bool Stack::pop()
{
	if (isEmpty() == true) return false;
	aStack[top-1]->writeToFile();
	delete aStack[top-1];
	top--;
	return true;
}




//===========================================================================================
//				Operator Overload
//===========================================================================================
const Stack& Stack::operator=(const Stack& newStack)
{
	if (this == &newStack)
	{
		return *this;
	}
	destroy();
	top = newStack.top;
	capacity = newStack.capacity;
	aStack = new Contact * [capacity];
	for (int i = 0; i < top; i++)
	{
		aStack[i] = new Contact(*(newStack.aStack[i])); 
	}
	return *this;
}
	



void Stack::getContactInfo()
{
	char buffer[MAXSIZE];
        Contact * newContact = new Contact();

        // get contact info and push it to the list
        cin.ignore(MAXSIZE, '\n');
        cout << endl << "Enter the name of the customer -> ";
        cin.getline(buffer, MAXSIZE, '\n');
        newContact->setName(buffer);
        cout << endl <<  "Enter the customer's email -> ";
        cin.getline(buffer, MAXSIZE, '\n');
        newContact->setEmail(buffer);
        push(newContact);
}



void Stack::addContact()
{
	getContactInfo();
	char choice = '\0';
	while (choice != 'n')
	{
		cout << endl << "Does anyone else in the group want promotional materials? [y/n] -> ";
		getChoice(choice);
		if (choice == 'y') getContactInfo(); 
	}
}



void Stack::getChoice(char& choice)
{
        cin >> choice;
        while (!cin || (choice != 'y' && choice != 'n'))
        {
                cin.clear();
                cin.ignore(MAXSIZE, '\n');
                cout << endl << "Invalid input, enter only \'y\' or \'n\' -> ";
                cin >> choice;
        }
}
