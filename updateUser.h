#ifndef H_updateUser
#define H_updateUser

#include "createUser.h"
#include <iostream>
#include <string>

using namespace std;

class updateUser : public user
{
private:
	int oldUID;
	int newUID;

public:
	void changeFirstName(string name);
	void changeLastName(string name);
	void changeUserName(string name);
	void changeDepartment(string dep);
	void changeUID(int id);

	void changeInfo(string fName, string lName, string dep, string uName, int id); 
};

#endif