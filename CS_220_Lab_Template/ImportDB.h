#pragma once
#include <iostream>
#include "sqlite3.h"
using namespace std;

class ImportDB
{
public:
	string Players();
	string Sets();
	string Teams();
	string Cards();
};

