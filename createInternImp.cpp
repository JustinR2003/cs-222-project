#include <iostream>
#include <string>
#include "createIntern.h"

using namespace std;

void intern::setIsPaid(bool isP)
{
	isPaid = isP;
}

void intern::printInfo()
{
	user::printInfo();
	if (isPaid)
		cout << "Is Paid: True" << endl;
	else
		cout << "Is Paid: False" << endl;
}

void intern::setInfo()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
	isPaid = false;
}

void intern::setInfo(string nameF, string nameL, string nameU, string dep, int id, bool isP)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
	isPaid = isP;
}

bool intern::getIsPaid()
{
	return isPaid; 
}

intern::intern()
{
	firstName = "";
	lastName = "";
	uID = 0;
	department = "";
	userName = "";
	isPaid = false;
}

intern::intern(string nameF, string nameL, string nameU, string dep, int id, bool isP)
{
	firstName = nameF;
	lastName = nameL;
	uID = id;
	department = dep;
	userName = nameU;
	isPaid = isP;
}