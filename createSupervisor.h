#ifndef H_createSupervisor
#define H_createSupervisor

#include <iostream>
#include <string>
#include "createUser.h"

using namespace std;

class supervisor : public user
{
protected: 

	string phoneNumber;

public: 

	void setPhoneNumber(string phoneN);
	// Initializes phone number variable

	void printInfo();
	//Prints information of a given supervisor

	void setInfo();
	// Intializes properties of a supervisor with default values

	void setInfo(string nameF, string nameL, string nameU, string dep, int id, string phoneN);
	// Intializes properties of a supervisor with parameters

	string getPhoneNumber();
	// Returns phone number variable

	supervisor();
	// Constructors with default values

	supervisor(string nameF, string nameL, string nameU, string dep, int id, string phoneN);
	// Constructor with parameters

};




#endif
