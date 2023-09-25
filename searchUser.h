#ifndef H_searchUser
#define H_searchUser

#include <iostream>
#include <string>
#include "createUser.h"

using namespace std;

class searchUser : public user
{
public:
	void searchByLastName(string);
	void searchByUID(int);
};

#endif
