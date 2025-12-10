#include "CreateDB.h"
string CreateDB::Players()
{
	return
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
}

string CreateDB::Sets()
{
	return
		"CREATE TABLE IF NOT EXISTS Sets("
		"SetID	INT PRIMARY KEY	NOT NULL,"
		"BrandName	TEXT	NOT NULL,"
		"SetYear	TEXT	NOT NULL,"
		"SetName	TEXT	NOT NULL);";
}

string CreateDB::Teams()
{
	return
		"CREATE TABLE IF NOT EXISTS Teams("
		"TeamID	INT PRIMARY KEY	NOT NULL,"
		"TeamYear	INT	NOT NULL,"
		"TeamName	TEXT	NOT NULL,"
		"TeamDivision	TEXT	NOT NULL,"
		"TeamLeague	TEXT	NOT NULL,"
		"TeamCity	TEXT	NOT NULL,"
		"TeamState	TEXT	NOT NULL);";
}

string CreateDB::Cards()
{
	return
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
}

