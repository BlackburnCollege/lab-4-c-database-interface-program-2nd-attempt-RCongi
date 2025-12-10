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
		cerr << "Error Creating Database" << endl;

	}
	else
	{
		cout << "\nDatabase has been successfully Created.\n" << endl;
	}

	sqlite3_close(db);
}

void importData()
{
	sqlite3* db;
	char* errMsg = nullptr;

	if (sqlite3_open("baseballCard.db", &db)) 
	{
		cerr << "Error opening DB: " << sqlite3_errmsg(db) << endl;
	}

//Player File
	ifstream playersFile("Players.csv");
	if (!playersFile.is_open()) 
	{
		cerr << "Could not open CSV file." << endl;
	}

	string line;
	while (getline(playersFile, line)) 
	{
		stringstream ss(line);
		string PlayerID, FirstName, LastName, Birthdate, Position, ThrowingArm, HittingSide, Height, Weight;

		getline(ss, PlayerID, '	');
		getline(ss, FirstName, '	');
		getline(ss, LastName, '	');
		getline(ss, Birthdate, '	');
		getline(ss, Position, '	');
		getline(ss, ThrowingArm, '	');
		getline(ss, HittingSide, '	');
		getline(ss, Height, '	');
		getline(ss, Weight, '	');

		string sql = "INSERT INTO Players (PlayerID, FirstName, LastName, Birthdate, Position, ThrowingArm, HittingSide, Height, Weight) VALUES (" +
			PlayerID + ", '" + FirstName + "', '" + LastName + "', '" + Birthdate + "', '" + Position + "', '" +
			ThrowingArm + "', '" + HittingSide + "', '" + Height + "', '" + Weight + "');";

		int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK) 
		{
			cerr << "SQL error: " << errMsg << endl;
			sqlite3_free(errMsg);
		}
	}
	playersFile.close();

//Set File
	ifstream setsFile("Sets.csv");
	if (!setsFile.is_open())
	{
		cerr << "Could not open CSV file." << endl;
	}

	while (getline(setsFile, line))
	{
		stringstream ss(line);
		string SetID, BrandName, SetYear, SetName;

		getline(ss, SetID, '	');
		getline(ss, BrandName, '	');
		getline(ss, SetYear, '	');
		getline(ss, SetName, '	');

		string sql = "INSERT INTO Sets (SetID, BrandName, SetYear, SetName) VALUES (" +
			SetID + ", '" + BrandName + "', '" + SetYear + "', '" + SetName + "');";

		int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "SQL error: " << errMsg << endl;
			sqlite3_free(errMsg);
		}
	}
	setsFile.close();

//Teams File
	ifstream teamsFile("Teams.csv");
	if (!teamsFile.is_open())
	{
		cerr << "Could not open CSV file." << endl;
	}

	while (getline(teamsFile, line))
	{
		stringstream ss(line);
		string TeamID, TeamName, TeamDiv, TeamLeague, TeamCity, TeamState;

		getline(ss, TeamID, '	');
		getline(ss, TeamName, '	');
		getline(ss, TeamDiv, '	');
		getline(ss, TeamLeague, '	');
		getline(ss, TeamCity, '	');
		getline(ss, TeamState, '	');

		string sql = "INSERT INTO Teams (TeamID, TeamName, TeamDivision, TeamLeague, TeamCity, TeamState) VALUES (" +
			TeamID + ", '" + TeamName + "', '" + TeamDiv + "', '" + TeamLeague + "', '" + TeamCity + "', '" + TeamState + "');";

		int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "SQL error: " << errMsg << endl;
			sqlite3_free(errMsg);
		}
	}
	teamsFile.close();

//Cards File
	ifstream cardsFile("Cards.csv");
	if (!cardsFile.is_open())
	{
		cerr << "Could not open CSV file." << endl;
	}

	while (getline(cardsFile, line))
	{
		stringstream ss(line);
		string CardID, PlayerID, SetID, TeamID, CardNumber, Rookie, Autograph, Relic, Reflective;

		getline(ss, CardID, '	');
		getline(ss, PlayerID, '	');
		getline(ss, SetID, '	');
		getline(ss, TeamID, '	');
		getline(ss, CardNumber, '	');
		getline(ss, Rookie, '	');
		getline(ss, Autograph, '	');
		getline(ss, Relic, '	');
		getline(ss, Reflective, '	');

		string sql = "INSERT INTO Cards (CardID, PlayerID, SetID, TeamID, CardNumber, Rookie, Autograph, Relic, Reflective) VALUES (" +
			CardID + ", '" + PlayerID + "', '" + SetID + "', '" + TeamID + "', '" + CardNumber + "', '" + Rookie + "', '" + Autograph + "', '" + Relic + "', '" + Reflective + "');";

		int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK)
		{
			cerr << "SQL error: " << errMsg << endl;
			sqlite3_free(errMsg);
		}
	}
	cardsFile.close();
	
	sqlite3_close(db);
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