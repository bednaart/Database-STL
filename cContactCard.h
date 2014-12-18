#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class cContactCard
{
public:

	cContactCard();
	cContactCard(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile);
	~cContactCard();
    string mcGetName();
    string mcGetEmail();
    string mcGetPhone();
	void mcGetDataFromUser();
    friend bool operator<(cContactCard& pcFirstObj, cContactCard& pcSecondObj);

private:

	string sName;
	string sEmail;
	string sPhone;
};

