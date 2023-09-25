#ifndef H_doublyLinkedList
#define H_doublyLinkedList

#include <iostream>

using namespace std;

template <class T>

class doublyLinkedList
{
private:
	struct ListNode
	{
		T value;
		struct ListNode* next;
		struct ListNode* prev;
	};

	ListNode* head;
	ListNode* tail;
	
	int numberOfUsers;

public:

	doublyLinkedList<T>()
	{
		// If there is nothing to be passed in
		// Since they can't be properly initialized, point these two to nulls
		head = nullptr;
		tail = nullptr;
	}

	// list operations
	
	void appendNodeFront(T);
	void appendNodeEnd(T);
	void deleteNode(T);
	void print();
	void detailedPrint();
	bool search(T&);
	void searchByID(T&, int);
	void searchByLastName(T&, string);

	int getUserNum();

	void searchToUpdate(T&, int id);

};
/**
template <class T>
void doublyLinkedList<T>::insertNodeAfter(T num, int loc)
{
	ListNode* newNode, * nodePtr = nullptr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	newNode->next = head;
	while (newNode->next)

} 
**/

template <class T>
void doublyLinkedList<T>::appendNodeFront(T num)
{
	ListNode* newNode, * nodePtr = nullptr;

	// allocate a new node and store num

	newNode = new ListNode;
	newNode->value = num;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (!head) // if there is no node in the list 
		head = newNode;
	// insert a new node in the front of the existing list
	else
	{
		newNode->next = head;

		// previous of head is the new node

		head->prev = newNode;
		
		head = newNode;
	}
	numberOfUsers++;
}

template <class T>
void doublyLinkedList<T>::appendNodeEnd(T num)
{
	ListNode* newNode, * nodePtr = nullptr;

	// allocate a new node and store num

	newNode = new ListNode;
	newNode->value = num;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	
	if (!head)
		head = newNode;
	else
	{ 
		nodePtr = head;
		while (nodePtr->next) 
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
		newNode->next = nullptr;
		tail = newNode;
	}
	numberOfUsers++;
}

template <class T>
void doublyLinkedList<T>::print()
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr)
	{
		cout << (nodePtr->value).getLastName() << ", " <<(nodePtr->value).getFirstName() << endl;
		nodePtr = nodePtr->next;
	}
}


template <class T>
void doublyLinkedList<T>::deleteNode(T item)
{
	ListNode newNode, * nodePtr = nullptr, * previousNode = nullptr;

	// if the list is empty - print error and return
	if (!head)
	{
		cout << "Error: Employee List is Empty." << endl;
		return;
	}

	// checks the head value + removes it if it matches the required item
	if (((head->value).getID()) == item.getID() && ((head->value).getLastName() == item.getLastName()))
	{
		nodePtr = head->next;
		if (head->next)
		{
			delete head;
			head = nodePtr;
			head->prev = nullptr;
			numberOfUsers--;
			cout << "Employee deleted." << endl;
		}
		else
		{
			delete head;
			head = nullptr;
			numberOfUsers--;
			cout << "Employee deleted." << endl;
		}
	}
	else
	{
		nodePtr = head->next;

		// loops through the rest of the linked list + finds the required item (if it exists)
		while (nodePtr != nullptr && (((nodePtr->value).getID() != item.getID()) || ((nodePtr->value).getLastName() != item.getLastName())))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// if the required item was found - remove it.
		// print error if it is not found.
		if (nodePtr)
		{
			// checks if the item is the second item in the list so the item can be removed properly
			if (nodePtr != head->next)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
				numberOfUsers--;
				cout << "Employee deleted." << endl;
			}
			else
			{
				head->next = nodePtr->next;
				delete nodePtr;
				numberOfUsers--;
				cout << "Employee deleted." << endl;
			}
		}
		else
			cout << "Error: Employee not found." << endl << endl;
	}
}

template <class T>
void doublyLinkedList<T>::detailedPrint()
{
	ListNode* nodePtr = nullptr;

	nodePtr = head;
	cout << "==========================================" << endl;
	cout << "Number of employees: " << numberOfUsers << endl;
	cout << "==========================================" << endl;
	while (nodePtr)
	{
		cout << "==========================================" << endl;
		cout << "Name: " << (nodePtr->value).getFirstName() << " " << (nodePtr->value).getLastName() << endl;
		cout << "User Name: " << (nodePtr->value).getUserName() << endl;
		cout << "User ID: " << (nodePtr->value).getID() << endl;
		cout << "Department: " << (nodePtr->value).getDepartment() << endl;
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

template <class T>
bool doublyLinkedList<T>::search(T& item)
{
	bool found = false;
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr && !found)
	{
		if (nodePtr->value == item)
			found = true;
		else
			nodePtr = nodePtr->next;
	}

	if (found)
		found = (nodePtr->value == item);

	return found;
}

template <class T>
void doublyLinkedList<T>::searchByID(T&, int id)
{
	bool matchFound = false;
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		if ((nodePtr->value).getID() == id)
		{
			matchFound = true;

			cout << "==========================================" << endl;
			cout << "Name: " << (nodePtr->value).getFirstName() << " " << (nodePtr->value).getLastName() << endl;
			cout << "User Name: " << (nodePtr->value).getUserName() << endl;
			cout << "User ID: " << (nodePtr->value).getID() << endl;
			cout << "Department: " << (nodePtr->value).getDepartment() << endl;
			cout << "==========================================" << endl;

			nodePtr = nodePtr->next;
		}
		else
			nodePtr = nodePtr->next;
	}
	if (!matchFound)
		cout << "No employee with the ID of \"" << id << "\" found." << endl;
	return;
}

template <class T>
void doublyLinkedList<T>::searchByLastName(T&, string lastName)
{
	bool matchFound = false;

	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		if ((nodePtr->value).getLastName() == lastName)
		{
			matchFound = true;
				cout << "==========================================" << endl;
				cout << "Name: " << (nodePtr->value).getFirstName() << " " << (nodePtr->value).getLastName() << endl;
				cout << "User Name: " << (nodePtr->value).getUserName() << endl;
				cout << "User ID: " << (nodePtr->value).getID() << endl;
				cout << "Department: " << (nodePtr->value).getDepartment() << endl;
				cout << "==========================================" << endl;
			
			nodePtr = nodePtr->next;
		}
		else
			nodePtr = nodePtr->next;
	}

	if (!matchFound)
		cout << "No employee with the last name of \"" << lastName << "\" found." << endl;
	return;
}

template <class T>
int doublyLinkedList<T>::getUserNum() 
{
	
	return numberOfUsers;
}

template <class T>
void doublyLinkedList<T>::searchToUpdate(T&, int id)
{
	string firstName;
	string lastName;
	string userName;
	string department;
	int idNum;

	int userChoice;

	bool matchFound = false;
	ListNode* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		if ((nodePtr->value).getID() == id)
		{
			matchFound = true;

			cout << "==========================================" << endl;
			cout << "Enter the field to update for " << (nodePtr->value).getFirstName() << " " << (nodePtr->value).getLastName() << "." << endl;
			cout << "1: First Name" << endl;
			cout << "2: Last Name" << endl;
			cout << "3: User Name" << endl;
			cout << "4: Department" << endl;
			cout << "5: ID" << endl;
			cout << "==========================================" << endl;
			cout << "Your selection: ";
			cin >> userChoice;
			cout << endl;

			switch (userChoice)
			{
				case 1:
				{
					cout << "Enter a new first name for the employee." << endl;
					cout << "First name: ";
					cin >> firstName;
					cout << endl;
					(nodePtr->value).setFirstName(firstName);
					break;
				}
				case 2:
				{
					cout << "Enter a new last name for the employee." << endl;
					cout << "Last name: ";
					cin >> lastName;
					cout << endl;
					(nodePtr->value).setLastName(lastName);
					break;
				}
				case 3:
				{
					cout << "Enter a new user name for the employee." << endl;
					cout << "User name: ";
					cin >> userName;
					cout << endl;
					(nodePtr->value).setUserName(userName);
					break;
				}
				case 4:
				{
					cout << "Enter a new department for the employee." << endl;
					cout << "Department: ";
					cin.ignore();
					getline(cin, department);
					cout << endl;
					(nodePtr->value).setDepartment(department);
					break;
				}
				case 5:
				{
					cout << "Enter a new ID number for the employee." << endl;
					cout << "ID number: ";
					cin >> idNum;
					cout << endl;
					(nodePtr->value).setID(idNum);
					break;
				}
			}
			cout << "Employee information successfully updated." << endl;
			nodePtr = nodePtr->next;

		}
		else
			nodePtr = nodePtr->next;
	}
	if (!matchFound)
		cout << "No employee with the ID of \"" << id << "\" found." << endl;
	return;
}
#endif