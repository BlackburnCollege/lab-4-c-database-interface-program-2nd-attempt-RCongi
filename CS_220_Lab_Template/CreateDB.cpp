#include "CreateDB.h"

string CreateDB::Players()
{
	return
		"CREATE TABLE IF NOT EXISTS Players("
		"PlayerID	TEXT PRIMARY KEY	NOT NULL,"
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
		"SetID	TEXT PRIMARY KEY	NOT NULL,"
		"BrandName	TEXT	NOT NULL,"
		"SetYear	TEXT	NOT NULL,"
		"SetName	TEXT	NOT NULL);";
}

string CreateDB::Teams()
{
	return
		"CREATE TABLE IF NOT EXISTS Teams("
		"TeamID	TEXT PRIMARY KEY	NOT NULL,"
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
		"CardID	TEXT PRIMARY KEY	NOT NULL,"
		"PlayerID	TEXT,"
		"SetID	TEXT,"
		"TeamID	TEXT,"
		"CardNumber	TEXT	NOT NULL,"
		"Rookie	TEXT	NOT NULL,"
		"Autograph	TEXT	NOT NULL,"
		"Relic	TEXT	NOT NULL,"
		"Reflective	TEXT	NOT NULL,"
		"FOREIGN KEY(PlayerID) REFERENCES Players(PlayerID),"
		"FOREIGN KEY(SetID) REFERENCES Sets(SetID),"
		"FOREIGN KEY(TeamID) REFERENCES Teams(TeamID));";
}

