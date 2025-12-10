#include <iostream>
#include "sqlite3.h"
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
			sqlite3* db;

			int rc = sqlite3_open("baseballCard.db", &db);

			sqlite3_exec(db, "PRAGMA foreign_keys = ON;", NULL, NULL, NULL);
			

			string Players =
				//Players Table
				"CREATE TABLE IF NOT EXISTS Players("
				"PlayerID	INT PRIMARY KEY	NOT NULL,"
				"FirstName	TEXT	NOT NULL,"
				"LastName	TEXT	NOT NULL,"
				"Birthdate	TEXT	NOT NULL,"
				"Position	TEXT	NOT NULL,"
				"ThrowingArm	TEXT	NOT NULL,"
				"HittingSide	TEXT	NOT NULL,"
				"Height	TEXT	NOT NULL,"
				"Weight	TEXT	NOT NULL);";
			rc = sqlite3_exec(db, Players.c_str(), NULL, NULL, NULL);

			string Sets =
				//Sets Table
				"CREATE TABLE IF NOT EXISTS Sets("
				"SetID	INT PRIMARY KEY	NOT NULL,"
				"BrandName	TEXT	NOT NULL,"
				"SetYear	TEXT	NOT NULL,"
				"SetName	TEXT	NOT NULL);";
			rc = sqlite3_exec(db, Sets.c_str(), NULL, NULL, NULL);

			string Teams =
				//Teams Table
				"CREATE TABLE IF NOT EXISTS Teams("
				"TeamID	INT PRIMARY KEY	NOT NULL,"
				"TeamYear	INT	NOT NULL,"
				"TeamName	TEXT	NOT NULL,"
				"TeamDivision	TEXT	NOT NULL,"
				"TeamLeague	TEXT	NOT NULL,"
				"TeamCity	TEXT	NOT NULL,"
				"TeamState	TEXT	NOT NULL);";
			rc = sqlite3_exec(db, Teams.c_str(), NULL, NULL, NULL);

			string Cards =
				//Cards Table
				"CREATE TABLE IF NOT EXISTS Cards("
				"CardID	INT PRIMARY KEY	NOT NULL,"
				"PlayerID	INT,"
				"SetID	INT,"
				"TeamID	INT,"
				"CardNumber	INT	NOT NULL,"
				"Rookie	INT	NOT NULL,"
				"Autograph	INT	NOT NULL,"
				"Relic	INT	NOT NULL,"
				"'Insert'	INT	NOT NULL,"
				"Parallel	INT	NOT NULL,"
				"Reflective	INT	NOT NULL,"
				"Error	INT	NOT NULL,"
				"'Book/Hit'	INT	NOT NULL, "
				"'Pre-War'	INT	NOT NULL,"
				"FOREIGN KEY(PlayerID) REFERENCES Players(PlayerID),"
				"FOREIGN KEY(SetID) REFERENCES Sets(SetID),"
				"FOREIGN KEY(TeamID) REFERENCES Teams(TeamID));";

			rc = sqlite3_exec(db, Cards.c_str(), NULL, NULL, NULL);
			
			if (rc != SQLITE_OK)
			{
				cerr << "Error Create Database" << endl;

			}
			else
			{
				cout << "\nDatabase has been successfully Created.\n" << endl;
			}

			sqlite3_close(db);
		}

	} while (response != 6);
}

