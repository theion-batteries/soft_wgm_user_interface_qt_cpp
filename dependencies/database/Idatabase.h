/**
 * @file Idatabase.h
 * @author sami dhiab
 * @brief  interface for sqlite3
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include "sqlite3.h"
#include <functional>
#include <iostream>
#include <memory>
#include <filesystem>
#include <map>
#include <vector>
struct table
{
    table();
    table(std::string name);
    std::string Table_name;
    void setTableName(std::string name);
    void addColumn(std::pair<std::string,std::string> element_type_pair,  bool isNotNull=false,bool isFirstKey=false);
    std::string createRow(std::string Val1, std::string Val2, ...);
    void generateTable();
    void printTable();
    std::string TableToSend;
    std::vector<std::string> Columns_Vector;
};
class Idatabase
{
protected:
    sqlite3* dbHandler;
    table* tableHandler;
public:
    Idatabase(/* args */);
     ~Idatabase();
    void createDBfile(std::string fileName);
    void openDBfile(std::string fileName);
    void closeDBhandle();
    void createDBTable(table& newtable);
    void queryDBTable(std::string table);
    void insertDBTableRow(std::string table, std::string row);
    void deleteDBTableRow(std::string table, std::string rowIndex,std::string key="ATTEMPT");
    void selectDBTableColumn(std::string table, std::string Column);
    static int queryDBCallback(void* data, int argc, char** argv, char** azColName);
    table& getTableHandle();
};


