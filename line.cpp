// Kobe Norcross, CS 260, line.cpp
// This is the implementation file of the Queue ADT

#include "line.h"

//==========================================================================================================
//					Constructor/Destructor
//==========================================================================================================
Queue::Queue(const char * fileName) : front(nullptr), back(nullptr)
{
	waitingListInit(fileName);
}


Queue::~Queue()
{
	while (front != back)
	{
		node * next = front->next;
		delete front;
		front = next;
	}
	delete back;
	back = front = nullptr;
}



//==========================================================================================================
//					Accessors
//==========================================================================================================
bool Queue::peek()
{
	if (front)
	{
		cout << endl << "		Next group in line" << endl;
		cout << " 		------------------" << endl;
		cout << "Name: 	  " << front->data->getGroupName() << endl;
		cout << "Size: 	  " << front->data->getNumPeople() << endl;
		cout << "Seating: " << front->data->getSpecialSeating() << endl << endl;
		return true;
	}
	else
	{
		return false;
	}
}



// Display function and it's recursive call below it
bool Queue::display()
{
	if (front)
	{
		int index = 1; 
		cout << endl;
		cout << "		  ------------" << endl;
		cout << "		  WAITING LIST" << endl;
		cout << "		  ------------" << endl << endl;
		return display(front, index);
	}
	cout << endl;
	cout << "No one is in the waiting list." << endl;
	cout << endl;
	return false;
}



// recursive display function
bool Queue::display(node * curr, int& index)
{
	if (curr->next != front)
	{
		cout << "LINE NUMBER: " << index << endl;
		cout << "\t" << "Name:    " << curr->data->getGroupName() << endl;
		cout << "\t" << "Size:    " << curr->data->getNumPeople() << endl;
		cout << "\t" << "Seating: " << curr->data->getSpecialSeating() << endl << endl;
		index++;
		display(curr->next, index);
	}
	return true;
}



//==========================================================================================================
//					Mutators
//==========================================================================================================
// Add group to the end of the list
bool Queue::enqueue(Group *& newGroup)
{
	// get data for a new group and add it to the list
	node * newNode = new node(newGroup);
	
	// Case 1: List is empty initialize first node to front
	if (front == nullptr)
	{
		front = newNode; 
		return true;
	}
	// Case 2: back is empty (2nd iteration of initliazation)
	else if (back == nullptr)
	{
		back = newNode;
		front->next = back;
		back->next = front;
		return true;
	}
	else if (back)
	{
		// Case 3: list has more than two elements and can be added normally
		back->next = newNode; 
		back = back->next;
		back->next = front;
		return true;
	}
	// Case 4: ERROR
	else
	{
		return false;
	}
}



// deletes from the front
bool Queue::dequeue()
{
	bool promo = false;
	// Case 4: The list is empty
	if (front == nullptr)
	{
		cout << "The waiting list is empty." << endl << endl;
		return promo;
	}
	// Case 3: Only one node left
	else if (front == back)
	{
		promo = promoCheck();
		delete front;
		front = back = nullptr;
		return promo;
	}
	// Case 2: There are only two nodes left in the list
	else if (front->next == back)
	{
		promo = promoCheck();
		delete front;
		back->next = nullptr;
		front = back;
		return promo;
	}
	// Case 1: There are at least three nodes in the list
	else if (back)
	{
		back->next = front->next;
		promo = promoCheck();
		delete front;
		front = back->next;
		return promo;
	}
	else
	{
		return promo;
	}
}




// creates a new group and adds them to the waiting list
void Queue::newGroup()
{
	newGroupInit();
}



//==========================================================================================================
//					Init functions
//==========================================================================================================
void Queue::waitingListInit(const char * fileName)
{
	char buffer[MAXSIZE];
	int num;
	ifstream inputFile;
	inputFile.open(fileName);
	if (inputFile.good())
	{
		while (inputFile.peek() != EOF)
		{
			if (!inputFile.eof())
			{
			Group * group = new Group();
			inputFile.getline(buffer, MAXSIZE, ';');
			group->setGroupName(buffer);
			inputFile.getline(buffer, MAXSIZE, ';');
			group->setSpecialSeating(buffer);
			inputFile >> num;
			group->setNumPeople(num);
			if (inputFile.peek() == '\n') inputFile.get();
			enqueue(group);
			}

		}
	}
	inputFile.close();
}



void Queue::newGroupInit()
{
	Group * newGroup = new Group;
        char buffer[MAXSIZE];
        char choice;
        int num = 0;

        // Init group name
	cin.ignore(MAXSIZE, '\n');
        cout << "Enter the name of the group -> ";
        cin.getline(buffer, MAXSIZE, '\n');
        newGroup->setGroupName(buffer);

        // Init num people
        cout << "Enter the number of people in the group -> ";
        cin >> num;
        while (!cin || num < 1)
        {
                cin.clear();
                cin.ignore(MAXSIZE, '\n');
                cout << endl << "Invalid input, enter the number of people in the group -> ";
                cin >> num;
        }
        newGroup->setNumPeople(num);

        // Init special seating if needed
        cout << "Is special seating needed? (y or n) -> ";
        getChoice(choice);
        // if choice is yes get input on what seating is needed
        if (tolower(choice) == 'y')
        {
		cin.ignore(MAXSIZE, '\n');
                cout << "Enter what seating will be needed (eg. high chair, wheel chair) -> ";
                cin.getline(buffer, MAXSIZE, '\n');
                newGroup->setSpecialSeating(buffer);
        }      
        else if (tolower(choice) == 'n')
        {
                strcpy(buffer, "no special seating needed");
                newGroup->setSpecialSeating(buffer);
        }
	enqueue(newGroup);
}



//==========================================================================================================
//				Helper functions
//==========================================================================================================
void Queue::getChoice(char& choice)
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



bool Queue::promoCheck()
{
	char choice = '\0';
	cout << endl << "Does anyone in the group want promotional materials? [y/n] -> ";
	getChoice(choice);
	if (choice == 'y') return true;
	else if (choice == 'n') return false;
	return false;
}
