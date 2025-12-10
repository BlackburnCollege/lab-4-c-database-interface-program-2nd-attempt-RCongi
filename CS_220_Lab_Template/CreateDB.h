#pragma once
#include <iostream>
#include "sqlite3.h"
using namespace std;

class CreateDB
{
public:
	string Players();
	string Sets();
	string Teams();
	string Cards();
};

