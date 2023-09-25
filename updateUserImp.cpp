#include "updateUser.h"
#include "createUser.h"
#include <iostream>
#include <string>

using namespace std;

void updateUser::changeFirstName(string name)
{
	firstName = name;
}
void updateUser::changeLastName(string name)
{
	lastName = name;
}
void updateUser::changeUserName(string name)
{
	userName = name;
}
void updateUser::changeDepartment(string dep)
{
	department = dep;
}
void updateUser::changeUID(int id)
{
	uID = id;
}

void updateUser::changeInfo(string fName, string lName, string dep, string uName, int id)
{
	firstName = fName;
	lastName = lName;
	department = dep;
	userName = uName;
	uID = id;
}