#pragma once
#include <iostream>
#include <fstream>
#include "sqlite3.h"
#include "CreateDB.h"
#include "ImportDB.h"
#include <string>
#include <sstream>
using namespace std;

void createDatabase();
void importData();
void simple();
void complex();
void UserDefined();