#pragma once
#ifdef _MSC_VER
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include "lib/sqlite3.h"

#define EXIT_EVENT "$EXIT$"

using namespace std;

struct TableNames {
	const char* full_title;
	char short_title;
};

struct Domains {
	int id;
	string domain;
};

struct Users {
	int id;
	string login;
	string password;
};

struct PrivatePage {
	int id;
	int access_level;
	string domain;
	string page;
};

class TablesLib {

protected:
	list<TableNames> table_names;
	list<Domains> domains;
	list<Users> users;
	
public:
	TablesLib();
	~TablesLib();
	list<Domains> GetDomains();
	list<Users> GetUsers();
	char GetShortCommand(const char*);
	string MD5(string);
};

