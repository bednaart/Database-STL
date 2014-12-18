#include "cContactCard.h"


cContactCard::cContactCard()
{
}

cContactCard::cContactCard(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile)
{
	sName = sNameFromFile;
	sEmail = sEmailFromFile;
	sPhone = sPhoneFromFile;
}
cContactCard::~cContactCard()
{
}

string cContactCard::mcGetName()
{
	return sName;
}

string cContactCard::mcGetEmail()
{
	return sEmail;
}

string cContactCard::mcGetPhone()
{
	return sPhone;
}

void cContactCard::mcGetDataFromUser()
{

	cout << "Adding new contact:" << endl;
	cout << "Name: ";
	cin >> sName;
	cout << "Email: ";
	cin >> sEmail;
	cout << "Phone: ";
	cin >> sPhone;

}

bool operator<(cContactCard& pcFirstObj, cContactCard& pcSecondObj)
{
    if(pcFirstObj.sName <= pcSecondObj.sName)
        return true;
    else
        return false;
}


