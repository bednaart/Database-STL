//#pragma once
#include "main.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	int iMenuOption = -1;
	cAddressBook* pcAddressBookInstance = new cAddressBook;
	int iReturnValue;

	while (0 != iMenuOption)
	{

		iMenuOption = pcAddressBookInstance->mcShowMenu();

		switch (iMenuOption)
		{
		case 1:
			iReturnValue = pcAddressBookInstance->mcAddContact();
			pcAddressBookInstance->mcSortEntriesInDatabase();
			
			break;

		case 2:
			pcAddressBookInstance->mcSearchForContact();

			break;

		case 3:
			pcAddressBookInstance->mcDisplayAllContacts();

			break;

		case 4:
			iReturnValue = pcAddressBookInstance->mcRemoveContact();

			break;

		case 5:
			iReturnValue = pcAddressBookInstance->mcLoadDatabaseFromFile();
			pcAddressBookInstance->mcSortEntriesInDatabase();
			
			break;

		case 0:
			cout << endl << "Shuting down..." << endl;

			break;

		default:
			cout << endl << "Wrong option! Choose correct option" << endl;
			this_thread::sleep_for(chrono::seconds(1));

			break;

		}

	}

	delete pcAddressBookInstance;
}
