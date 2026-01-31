#include "../include/DB.h"

// ------------------------------------------------
// ------------ Constructor Function
DB::DB(const string &dbpath, string sql)
{
    fs::path p(dbpath); // Turn into a path object
    fs::path dir = p.parent_path();

    if (!dir.empty() && !fs::exists(dir))
    {
        if (fs::create_directories(dir))
        {
            cout << "Created directory: " << dir << std::endl;
        }
    }

    int connection = sqlite3_open(dbpath.c_str(), &db);

    if (connection != SQLITE_OK)
    {
        cerr << "Error Opening DB :" << sqlite3_errmsg(db) << "\n";
    }

    else
    {
        executeSQL(sql, [](void *, int argc, char **argv, char **azColName) -> int {
            // Imp --> Done to avoid miss match
            // Beacuse lamda  
            return 0;
        }, NULL);
    }
}

// ------------------------------------------------
// ------------ Execute SQL Command Function
void DB::executeSQL(string sql, int (*callBack)(void *, int, char **, char **), void* data)
{
    char *messageError;

    int success = sqlite3_exec(db, sql.c_str(), callBack, data, &messageError);

    if (success != SQLITE_OK)
    {
        cerr << "SQL Error: " << messageError << std::endl;

        sqlite3_free(messageError);
    }
}

// ------------------------------------------------
// ------------ Destructor Function
DB::~DB()
{
    sqlite3_close(db);
}