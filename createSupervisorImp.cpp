#include <iostream>
#include <string>
#include "createSupervisor.h"

using namespace std;

void supervisor::setPhoneNumber(string phoneN)
{
	phoneNumber = phoneN;
}

void supervisor::printInfo()
{
	user::printInfo();
	cout << "Phone Number: " << phoneNumber << endl;
}

void supervisor::setInfo()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
	phoneNumber = "";
}

void supervisor::setInfo(string nameF, string nameL, string nameU, string dep, int id, string phoneN)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
	phoneNumber = phoneN;
}

string supervisor::getPhoneNumber()
{
	return phoneNumber;
}

supervisor::supervisor()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
	phoneNumber = "";
}

supervisor::supervisor(string nameF, string nameL, string nameU, string dep, int id, string phoneN)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
	phoneNumber = phoneN;
}
