/**
 * @file Idatabase.h
 * @author sami dhiab
 * @brief easy to use interface for sqlite3
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sqlite3.h"
#include <functional>
#include <iostream>
#include <memory>
#include <filesystem>
#include <map>
#include <vector>
struct table
{
    std::string Table_name;
    void setTableName(std::string name);
    void addColumn(std::pair<std::string,std::string> element_type_pair,  bool isNotNull=false,bool isFirstKey=false);
    void generateTable();
    void printTable();
    std::string TableToSend;
    std::vector<std::string> Columns_Vector;
};
class Idatabase
{
private:
    sqlite3* dbHandler;
public:
    Idatabase(/* args */);
    ~Idatabase();
    void createDBfile(std::string fileName);
    void openDBfile(std::string fileName);
    void closeDBhandle();
    void createDBTable(table& newtable);
    void queryDBTable(std::string table);
    void insertDBTableRow(std::string table, std::string row);
    void deleteDBTableRow(std::string table, std::string rowIndex);
    void selectDBTableColumn(std::string table, std::string Column);
    static int queryDBCallback(void* data, int argc, char** argv, char** azColName);

};


