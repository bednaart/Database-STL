#include "cAddressBook.h"
#include "tinyxml2-master\tinyxml2.cpp"

using namespace tinyxml2;

cAddressBook::cAddressBook()
{
}

cAddressBook::~cAddressBook()
{
    vector<cContactCard *>::iterator it;
    for(it = vDatabase.begin(); it != vDatabase.end(); it++)
    {
        delete *it;
        *it=nullptr;
    }

    vDatabase.clear();

}

int cAddressBook::mcAddContact()
{
	cContactCard* mcNewContact = new cContactCard;

	mcNewContact->mcGetDataFromUser();

    vDatabase.push_back(mcNewContact);
    cout << endl << " New contact added!";
    return 0;
}

int cAddressBook::mcAddContact(string sNameFromFile, string sEmailFromFile, string sPhoneFromFile)
{
	cContactCard* mcNewContact = new cContactCard(sNameFromFile, sEmailFromFile, sPhoneFromFile);

    vDatabase.push_back(mcNewContact);

    return 0;
}

int cAddressBook::mcRemoveContact()
{
	mcDisplayAllContacts();
	string sContactToRemove;
	int iIsAnythingFound = 0;

    if (!vDatabase.empty())
	{
		cout << "Type contact name to remove: ";
		cin >> sContactToRemove;

        vector<cContactCard *>::iterator it = vDatabase.begin();
        for(it = vDatabase.begin(); it != vDatabase.end(); it++)
        {
            if ((*it)->mcGetName() == sContactToRemove)
            {
                delete *it;
                *it = nullptr;
                vDatabase.erase(it);

                cout << endl << "\tContact " << sContactToRemove << " removed!" << endl;
                iIsAnythingFound++;
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }

        }

        if (0 == iIsAnythingFound && it == vDatabase.end())
        {
            cout << "No matches found! Contact not removed!";
            this_thread::sleep_for(chrono::seconds(1));
        }

        return 0;
	}
    else
    {
        cout << "Database is empty!";
        this_thread::sleep_for(chrono::seconds(1));
        return 1;
    }

}



int cAddressBook::mcShowMenu()
{
	int iChoosenOption;
	string sChoosenOption;
	system("CLS");
	cout << "Address Book Menu:" << endl;
	cout << "1. Add new contact" << endl;
	cout << "2. Search for contact" << endl;
	cout << "3. Display all contacts" << endl;
	cout << "4. Remove contact" << endl;
	cout << "5. Load contacts from file database.xml" << endl;
	cout << "0. Exit" << endl << endl;

	cout << "Choosen option: ";
	cin >> sChoosenOption;


	if (1 == sChoosenOption.length() && isdigit(sChoosenOption[0]))
	{
		iChoosenOption = atoi(sChoosenOption.c_str());
	}
	else
	{
		iChoosenOption = -1;
	}

	return iChoosenOption;

}


void cAddressBook::mcDisplayAllContacts()
{

    if (vDatabase.empty())
	{
		cout << endl << "\tDatabase is empty!";
		this_thread::sleep_for(chrono::seconds(1));
	}
	else
	{
        int iNumberOfContact = 1;
        vector<cContactCard *>::iterator it;

        for(it = vDatabase.begin(); it != vDatabase.end(); it++, iNumberOfContact++)
        {
			cout << endl << "\t" << iNumberOfContact << ".";
            cout << endl << "\tName: " << (*it)->mcGetName();
            cout << endl << "\tEmail: " << (*it)->mcGetEmail();
            cout << endl << "\tPhone: " << (*it)->mcGetPhone();
			cout << endl << endl;
		}
		system("PAUSE");
	}

}

void cAddressBook::mcSearchForContact()
{
	string sTextToFind;
	int iNumberOfContact = 1, iIsAnythingFound = 0;

	cout << endl << "Type part of name, email or phone to find." << endl << "Find: ";
	cin >> sTextToFind;

    if (vDatabase.empty())
	{
		cout << endl << "Database is empty!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	else
	{
        vector<cContactCard *>::iterator it;

        for(it = vDatabase.begin(); it != vDatabase.end(); it++, iNumberOfContact++)
        {
            if ((string::npos != ((*it)->mcGetName()).find(sTextToFind)) || (string::npos != ((*it)->mcGetEmail()).find(sTextToFind)) || (string::npos != ((*it)->mcGetPhone()).find(sTextToFind)) )
			{	
				cout << endl << "\t" << iNumberOfContact << ".";
                cout << endl << "\tName: " << (*it)->mcGetName();
                cout << endl << "\tEmail: " << (*it)->mcGetEmail();
                cout << endl << "\tPhone: " << (*it)->mcGetPhone();
				cout << endl;
				iIsAnythingFound++;
			}
		}

		if (0 == iIsAnythingFound)
		{
			cout << "No matches found!";
		}

		cout << endl;
		system("PAUSE");
	}



}

bool mcCompareTwoObjects(cContactCard* pcFirstObjToCompare, cContactCard* pcSecondObjToCompare)
{
    return (*pcFirstObjToCompare < *pcSecondObjToCompare);
}


void cAddressBook::mcSortEntriesInDatabase()
{
    sort((vDatabase.begin()), (vDatabase.end()), mcCompareTwoObjects);
}


int cAddressBook::mcLoadDatabaseFromFile()
{
    XMLDocument* xmlDatabase = new XMLDocument;

    const char * sFileLocation = "d:/_SelfStudy/Database/database.xml";

    if (!xmlDatabase->LoadFile(sFileLocation))
	{
		XMLElement* xmlContactsIterator, *xmlContactsDataIterator;
		vector<string>* vNewContactFromFile = new vector<string>;

		xmlContactsIterator = xmlDatabase->FirstChildElement("AddressBook")->FirstChildElement("Contact");

		for (xmlContactsIterator; xmlContactsIterator != NULL; xmlContactsIterator = xmlContactsIterator->NextSiblingElement())
		{
			for (xmlContactsDataIterator = xmlContactsIterator->FirstChildElement(); xmlContactsDataIterator != NULL; xmlContactsDataIterator = xmlContactsDataIterator->NextSiblingElement())
			{
				vNewContactFromFile->push_back(xmlContactsDataIterator->GetText());
			}
			mcAddContact(vNewContactFromFile->at(0), vNewContactFromFile->at(1), vNewContactFromFile->at(2));
			vNewContactFromFile->clear();
		}

		xmlDatabase->Clear();
	}

	
	return 0;
}
