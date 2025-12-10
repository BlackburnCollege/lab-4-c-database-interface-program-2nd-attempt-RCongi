#pragma once
#include <iostream>
#include "sqlite3.h"
#include "CreateDB.h"
using namespace std;

void createDatabase();
void importData();
void simple();
void complex();
void UserDefined();