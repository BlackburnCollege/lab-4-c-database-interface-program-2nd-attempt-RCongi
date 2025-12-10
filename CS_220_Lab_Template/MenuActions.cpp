#include "MenuActions.h"

void createDatabase()
{
	sqlite3* db;

	CreateDB Database;

	int rc = sqlite3_open("baseballCard.db", &db);

	sqlite3_exec(db, "PRAGMA foreign_keys = ON;", NULL, NULL, NULL);

	string Players = Database.Players();
	rc = sqlite3_exec(db, Players.c_str(), NULL, NULL, NULL);

	string Sets = Database.Sets();
	rc = sqlite3_exec(db, Sets.c_str(), NULL, NULL, NULL);

	string Teams = Database.Teams();
	rc = sqlite3_exec(db, Teams.c_str(), NULL, NULL, NULL);

	string Cards = Database.Cards();
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

void importData()
{

}
void simple()
{

}
void complex()
{

}

void UserDefined()
{

}