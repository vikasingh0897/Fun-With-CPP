#include <filesystem> // Imp --> filesystem::path p(dbpath); --> p(Path Object)
#include <functional> // Imp --> function<void(int,int)> func; --> C++ Style
#include "sqlite3.h"
#include <iostream>
#include <string>

#ifndef DB_H
#define DB_H

using namespace std;

namespace fs = filesystem;

class DB
{
private:
    sqlite3 *db;
    string dbPath;

public:
    DB(const string &dbpath, string);

    void executeSQL(string, int (*callBack)(void *, int, char **, char **), void *);

    ~DB();
};

#endif