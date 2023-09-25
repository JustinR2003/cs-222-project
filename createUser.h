#ifndef H_createUser
#define H_createUser

#include <iostream>
#include <string>

using namespace std;

class user
{
protected:
	string firstName;
	string lastName;
	string userName;
	string department;
	int uID;

public:
	void setFirstName(string name);
	void setLastName(string name);
	void setUserName(string name);
	void setDepartment(string dep);
	void setID(int id);

	void printInfo();
	void setInfo();
	void setInfo(string nameF, string nameL, string nameU, string dep, int id);
	
	string getFirstName();
	string getLastName();
	string getUserName();
	string getDepartment();
	int getID();

	user();
	user(string nameF, string nameL, string nameU, string dep, int id);
};


#endif