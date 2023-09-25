#include "createUser.h"
#include <iostream>
#include <string>

using namespace std;

// Initializes the first name variable
void user::setFirstName(string name)
{
	firstName = name;
}

// Initializes the last name variable
void user::setLastName(string name)
{
	lastName = name;
}

// Initializes the user name variable
void user::setUserName(string name)
{
	userName = name;
}

// Initializes the department variable
void user::setDepartment(string dep)
{
	department = dep;
}

// Initializes the user ID variable
void user::setID(int id)
{
	uID = id;
}

// Prints out the information of a given user
void user::printInfo()
{
	cout << "-= User Information =-" << endl;
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Username: " << userName << endl;
	cout << "Employee ID: " << uID << endl;
	cout << "Department: " << department << endl;
}

//Sets default info for a user, that being blank strings and an ID number of 0
void user::setInfo()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
}

//Sets info for a user, like a constructor
void user::setInfo(string nameF, string nameL, string nameU, string dep, int id)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
}

// Returns the first name of a user
string user::getFirstName()
{
	return firstName;
}

// Returns the last name of a user
string user::getLastName()
{
	return lastName;
}

// Returns the user name of a user
string user::getUserName()
{
	return userName;
}

// Returns the department of a user
string user::getDepartment()
{
	return department;
}

// Returns the ID of a user
int user::getID()
{
	return uID;
}

// Much like setInfo(), sets all strings to empty and the ID to 0
user::user()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
}

// Much like setInfo(string, string, string, string, int), sets the following fields with inputted information.
user::user(string nameF, string nameL, string nameU, string dep, int id)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
}