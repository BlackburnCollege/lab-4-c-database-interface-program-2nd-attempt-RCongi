#include <iostream>
#include "sqlite3.h"
#include "CreateDB.h"
#include "MenuActions.h"
using namespace std;

int main()
{
	int response;

	do
	{
		cout << "Program Menu: \n\n1) Create Database. \n2) Import Data. \n3) Perform Simple. \n4) Perform Complex. \n5) Perform User-defined.\
				\n6) Exit. \n\nEnter Response: ";
		cin >> response;
		
		while (response < 1 || response > 6)
		{
			cout << "\nPlease enter a value 1-6: ";
			cin >> response;
		}

		if (response == 1)
		{
			createDatabase();
		}

	} while (response != 6);
}

