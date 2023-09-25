// Justin Rice || Joan Martinez
// CS - 222: Data Structures
// Final Project || main.cpp, version 1.1

#include "createUser.h"
#include "doubly linked list.h"

#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

doublyLinkedList<user> currentUsers;

// Useful function prototypes
int menu();
void createNewUser();
void printList();
void searchForUser(); 
void deleteUser();
void readInUsers();
void updateExistingUser();

// "Easter egg" functions prototypes
void shutdownProtocol();
void flowProtocol();
void leagueProtocol();
void undefeatableProtocol();

int main()
{
	
	int userChoice; // A variable to store the user's choice for the menu system

	/*
	* Loop Details
	* This loop keeps a track of the user's menu choices.
	* The loop will exit if the user enters a 0, which ends the program.
	* 
	* Input validation does work. If the user inputs anything under 0 or over 6, it will throw back an error.
	* (There are some exceptions to this rule.)
	* 
	*/ 
	do
	{
		userChoice = menu();

		// This very much will shut down your computer on Windows. 
		// Please do not run this.
		// 525600 from Rent's "Seasons of Love", 24601 from Les Miserables' Jean Valjean, 8675309 from Tommy Tutone's "Jenny"
		// Quote from Portal 2's Wheatley 
		if (userChoice == 525600 || userChoice == 24601 || userChoice == 8675309)
		{
			shutdownProtocol();
		}
		
		// String "Flow" / "flow"
		// This will print out the lyrics to the song "Flow" from Final Fantasy XIV: Endwalker
		if (userChoice == 440 || userChoice == 312)
			flowProtocol();

		// String "League of Legends" / "league of legends"
		// This will print out the lyrics to the song "Dynasties and Dystopias" from Arcane
		if (userChoice == 1546 || userChoice == 1542)	
		{
			leagueProtocol();
		}

		// String "undefeatable" / "Undefeatable"
		// This will print out the lyrics to the song "Undefeatable" from Sonic Frontiers (probably the only thing keeping me going for this project tbh - Justin) 
		if (userChoice == 1248 || userChoice == 1216)
		{
			undefeatableProtocol();
		}

		// *Actual* input validation
		if (userChoice > 6 || userChoice < 0)
		{
			if (userChoice == 1248 || userChoice == 1216 || userChoice == 1546 || userChoice == 1542 || userChoice == 440 || userChoice == 312 || userChoice == 525600 || userChoice == 24601 || userChoice == 8675309)
				cout << "Very clever, but please select an option listed!" << endl;
			else
				cout << "Invalid option. Please select an option listed." << endl;
		}
		else
		{
			switch (userChoice)
			{
			case 1:
				cout << "Creating a new employee." << endl;
				createNewUser();
				break;
			case 2:
				updateExistingUser();
				break;
			case 3:
				readInUsers();
				break;
			case 4:
				searchForUser();
				break;
			case 5:
				deleteUser();
				break;
			case 6:
				printList();
				break;

			default:
				break;

			}
		}
	} while (userChoice != 0);
	
	// If the user input 0 at the menu screen.
	if (userChoice == 0)
		cout << "Thank you for using our software. Goodbye." << endl;

	return 0;
}

int menu()
{
	// Blank variable for storing the user's input 
	int userChoice;

	cout << "____________________________________" << endl;
	cout << "|== Employee Management Software ==|" << endl;
	cout << "|__________________________________|" << endl;
	cout << "|         Choose an option         |" << endl;
	cout << "|                                  |" << endl;
	cout << "|1: Create a new employee          |" << endl;
	cout << "|2: Update a existing employee     |" << endl;
	cout << "|3: Read in employees from a file  |" << endl;
	cout << "|4: Search for an employee         |" << endl;
	cout << "|5: Delete an employee             |" << endl;
	cout << "|6: Print out current employees    |" << endl;
	cout << "|0: Quit the program               |" << endl;
	cout << "|__________________________________|" << endl;

	
	cout << "Your selection: "; // This line purely is for looks, hence the lack of an 'endl' or \n character. - Justin
	cin >> userChoice;

	return userChoice;
}

/*
Calls the createUser constructor to create a new user. 
Eventually, this will add the user to the list of pre-existing users.

Preconditions: None 
Postconditions: A new node will be added to a linked list of users
Parameters: None
Inputs: The desired first name, last name, user name, department, and ID of a user
Outputs: None
Returns: None

*/
void createNewUser()
{
	user newUser;

	string firstName;
	string lastName;
	string userName;
	string department;
	int id;

	cout << "Please enter the employee's first name." << endl;
	cout << "First name: ";
	cin >> firstName;
	cout << endl;

	cout << "Please enter the employee's last name." << endl;
	cout << "Last name: ";
	cin >> lastName;
	cout << endl;

	cout << "Please enter the employee's desired user name." << endl;
	cout << "User name: ";
	cin >> userName;
	cout << endl;

	cout << "Please enter the employee's department." << endl;
	cout << "Department: ";
	cin.ignore();
	getline(cin, department);
	cout << endl;

	cout << "Please enter the employee's ID." << endl;
	cout << "User ID: ";
	cin >> id;
	cout << endl;

	
	newUser.setInfo(firstName, lastName, userName, department, id);
	currentUsers.appendNodeFront(newUser);

	cout << "Employee successfully created." << endl;
	cout << endl;
}


void searchForUser()
{
	user searchTarget;

	string lastName;
	int id;

	int userOption;
	if (currentUsers.getUserNum() != 0)
	{
		do
		{
			cout << "How would you like to find an employee?" << endl;
			cout << "__________________________________" << endl;
			cout << "|1: By Last Name                 |" << endl;
			cout << "|2: By ID                        |" << endl;
			cout << "|0: Quit to Menu                 |" << endl;
			cout << "|________________________________|" << endl;
			cin >> userOption;
			if (userOption > 3 || userOption < -1)
				cout << "Invalid option. Please select an option from the list above." << endl;
			else if (userOption == 0)
			{
				cout << "Returning to main menu." << endl;
				return;
			}
		} while (!(userOption == 2 || userOption == 1));

		switch (userOption)
		{
		case 1:
			cout << "Enter the employee's last name: ";
			cin >> lastName;
			currentUsers.searchByLastName(searchTarget, lastName);
			break;
		case 2:
			cout << "Enter the employee's ID: ";
			cin >> id;
			currentUsers.searchByID(searchTarget, id);
			break;
		}
	}
	else
		cout << "There are no employees to search for." << endl;
	
}

void printList()
{
	if (currentUsers.getUserNum() != 0)
	{
		cout << "Printing current employees." << endl;
		currentUsers.detailedPrint();
		cout << endl;
	}
	else
		cout << "There are no employees." << endl;
}


void deleteUser()
{
	user selectedUser;

	string firstName = "";
	string lastName;
	string userName = "";
	string department = "";
	int id;
	if (currentUsers.getUserNum() != 0)
	{
		cout << "Deleting an employee." << endl;
		currentUsers.detailedPrint();

		cout << "Please enter the information of the employee you would like to delete." << endl;
		cout << "Enter 0 to go back to the main menu." << endl;
		cout << endl;

		cout << "Please enter the employee's last name." << endl;
		cout << "Last name: ";
		cin >> lastName;
		cout << endl;

		if (lastName == "0")
		{
			cout << "Returning to main menu." << endl;
			return;
		}
			

		cout << "Please enter the employee's ID." << endl;
		cout << "User ID: ";
		cin >> id;

		if (id == 0)
		{
			cout << "Returning to main menu." << endl;
			return;
		}

		cout << endl;

		selectedUser.setInfo(firstName, lastName, userName, department, id);

		currentUsers.deleteNode(selectedUser);
	}
	else
		cout << "The list of employees is empty." << endl;
}

void readInUsers()
{
	user newUser;

	string firstName;
	string lastName;
	string userName;
	string department;
	int id;

	ifstream inFile;
	string filePath;

	cout << "Please enter the data path for the file.\nBe sure to include the file itself at the end of the path." << endl;
	cin.ignore();
	cout << "File path: ";
	getline(cin, filePath);

	// Debugging Path
	if (filePath == "1")
		filePath = "D:\\Class Notes Fall 2022\\CS-222\\Visual Studio\\Final Project\\Final Project\\Test Users.txt";
	cout << endl;

	inFile.open(filePath);
	if (inFile)
	{
		cout << "Reading employee data from file..." << endl;
		while (!inFile.eof())
		{
			inFile >> firstName >> lastName >> userName;
			inFile.ignore();
			getline(inFile, department);
			inFile >> id;
			newUser.setInfo(firstName, lastName, userName, department, id);
			currentUsers.appendNodeFront(newUser);
		}
		cout << "Employees successfully added." << endl;

	}
	else
	{
		cout << "Error while reading file. Please check the file path and try again." << endl;
		cout << "Returning to menu." << endl;
	} 
	inFile.close();
}

void updateExistingUser()
{
	user searchTarget;

	int id;

	if (currentUsers.getUserNum() != 0)
	{
		currentUsers.detailedPrint();
		cout << "Enter the ID of the user you'd wish to update." << endl;
		cout << "Your selection: ";
		cin >> id;
		cout << endl;
		currentUsers.searchToUpdate(searchTarget, id);
	}
	else
		cout << "There are no employees to search for." << endl;
}


void shutdownProtocol() 
{
	cout << "OK, I've got an idea, but it is bloody dangerous. OK, here we go..." << endl;
	cout << "AUGH!!!" << endl;
	cout << "Huh ? Oh for God's... They told me that if I ever turned on this flashlight, I would die!" << endl;
	cout << "They told me that about everything!" << endl;
	cout << "I mean, why do they even bother giving me this stuff if they didn't want me using it?! It's pointless! Mad!" << endl;
	system("shutdown -s -t 7");
}
void flowProtocol()
{
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Well come and well met, my brave little spark" << endl;
	cout << "How long you've wandered, burned bright as a star" << endl;
	cout << "Oh, I have awaited you patiently all this time" << endl;
	cout << "Past every fate" << endl;
	cout << "Now sing with me once more, share of your life" << endl;
	cout << "Far greater than memory, its loss and love words cannot hold" << endl;
	cout << "Boundless, the tale overflows" << endl;
	cout << "And carries your light out to sea" << endl;
	cout << "Remember the rain, near and far beloved" << endl;
	cout << "Each drop a blessing from heavens above" << endl;
	cout << "And how as time flowed on those waters became one" << endl;
	cout << "Streams, rivers and lakes" << endl;
	cout << "Reaching for the horizon and far beyond" << endl;
	cout << "They carry onward however changed with each brief reflection, by setting sun" << endl;
	cout << "By storm's wake" << endl;
	cout << "Til welcomed home to gentle sea" << endl;
	cout << "Sinking deeper and deeper in calm embrace" << endl;
	cout << "Loving tides sweep in and bear you down" << endl;
	cout << "Should you meet a soul rising surface - ways" << endl;
	cout << "With your unbeating heart, wish them well" << endl;
	cout << "Deep, dark, far away, I have heard your voice, weighed your every choice" << endl;
	cout << "Now our hands join round the meaning you sought" << endl;
	cout << "I'll catch your tears, quench your fears with joy til you near the shore" << endl;
	cout << "Where in time, all shall as hope be reborn, ah" << endl;
	cout << "Hush, love, close your eyes, and in sleep abide" << endl;
	cout << "As sun's distant light, echoes down to dreams below" << endl;
	cout << "Know you will wake, on winds rise again" << endl;	
	cout << "For this journey's end is but one step forward to tomorrow" << endl;

	cout << "-------------------------------------------    Flow | Final Fantasy XIV: Endwalker" << endl;
}

void leagueProtocol()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "Pressure's rising fast as lighting they can't stop it now" << endl;
	cout << "If you ain't talking realness then just change the topic now" << endl;
	cout << "They laughing at the top like they can't see the bottom" << endl;
	cout << "And they thought I needed help but I got here without them" << endl;
	cout << "I am sharper than a pack of hundred razor blades" << endl;
	cout << "When the smoke clears, outta here, bet they name gon' fade" << endl;
	cout << "I'ma be here doing it, doing it my way" << endl;
	cout << "They said I should I change it up" << endl;
	cout << "But what did I say?" << endl;
	cout << "----------------- Dynasties and Dystopias | Arcane (A League of Legends Story)" << endl;
}

void undefeatableProtocol()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "It's time to face your fear" << endl;
	cout << "'Cause when your time has come and gone" << endl;
	cout << "I'll be the one to carry on (carry on)" << endl;
	cout << "And you can throw me to the wolves (throw me to the wolves)" << endl;
	cout << "'Cause I am undefeatable!" << endl;
	cout << "I'm hanging on to the other side" << endl;
	cout << "I won't give up 'til the end of me" << endl;
	cout << "I'm what you get when the stars collide" << endl;
	cout << "Now face it, you're just an enemy!" << endl;
	cout << "----------------------------------- Undefeatable | Sonic Frontiers" << endl;
}