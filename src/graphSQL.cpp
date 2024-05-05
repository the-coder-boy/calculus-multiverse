#include <iostream>
#include <sqlite3.h>
#include "headers/GraphSQL.h"

// loading sqlite db
void GraphSQL::LoadDB(char * dbName)
{
    db_instance=sqlite3_open(dbName, &db);

    if (db_instance)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
}


// call back function for each record in the select
static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

// get function to get the data from table in db
void GraphSQL::GetData(char * tableName)
{
    const char *data = "Callback function called";
    char *zErrMsg = 0;
    char command[] = "SELECT * from expenses"+tableName;
    db_instance = sqlite3_exec(db, command, callback, (void*)data, &zErrMsg);

    if (db_instance!=SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }
}

void GraphSQL::SQLClose()
{
    sqlite3_close(db);
}