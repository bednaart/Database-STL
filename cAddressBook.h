#pragma once
#include <chrono>
#include <thread>
#include "cContactCard.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class cAddressBook
{
public:
	cAddressBook();
	~cAddressBook();
	int mcAddContact();
	int mcAddContact(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile);
	int mcRemoveContact();
	void mcSearchForContact();
	int mcShowMenu();
	void mcDisplayAllContacts();
	void mcSortEntriesInDatabase();
	int mcLoadDatabaseFromFile();
    friend bool mcCompareTwoObjects(cContactCard* pcFirstObjToCompare, cContactCard* pcSecondObjToCompare);

private:

    vector<cContactCard *> vDatabase;

};

