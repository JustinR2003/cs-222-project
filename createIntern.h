#ifndef H_createIntern
#define H_createIntern

#include <iostream>
#include <string>
#include "createUser.h"

using namespace std;

class intern : public user
{

protected:

	bool isPaid;

public:

	void setIsPaid(bool isP);
	// Intializes isPaid variable

	void printInfo();
	// Prints information of a given intern

	void setInfo();
	// Intializes properties of an intern with default values

	void setInfo(string nameF, string nameL, string nameU, string dep, int id, bool isP);
	// Intializes properties of an intern with given parameters

	bool getIsPaid();
	// Returns isPaid value

	intern();
	// Constructor with default values

	intern(string nameF, string nameL, string nameU, string dep, int id, bool isP);
	// Constructor with parameters


};
#endif
