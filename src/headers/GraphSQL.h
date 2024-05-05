#pragma once
#include <iostream>
#include <sqlite3.h>

class GraphSQL{

private:
    sqlite3 *db;
    int db_instance;
public:
    void LoadDB(char * dbName);
    void GetData(char tableName[]);
    void SQLClose();
};