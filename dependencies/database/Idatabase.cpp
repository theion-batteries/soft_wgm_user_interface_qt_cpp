#include "Idatabase.h"

table::table()
{

}
table::table(std::string name)
{
    Table_name = name;
}
// struct table
void table::setTableName(std::string name)
{
    Table_name = name;
}

void table::addColumn(std::pair<std::string, std::string> element_type_pair, bool isNotNull, bool isFirstKey)
{
    std::string column;
    std::string NL = "";
    std::string  FK = "";
    if (isFirstKey) FK = " PRIMARY KEY ";
    if (isNotNull)  NL = " NOT NULL";
    // table struct
    TableToSend = Table_name + "(";
    element_type_pair.second.append(FK + NL);
    // parse rows 
    column = element_type_pair.first + " " + element_type_pair.second + ",";
    Columns_Vector.push_back(column);
}

void table::generateTable()
{
    Columns_Vector.back().pop_back();
    for (auto v : Columns_Vector)
    {
        TableToSend.append(v);
    }
    TableToSend += ");";
}
void table::printTable()
{
    std::cout << "table: " << TableToSend << std::endl;
}

std::string table::createRow(std::string Val1, std::string Val2, ...)
{
    return "";
}

// interface database methods

Idatabase::Idatabase(/* args */)
{
    std::cout << "creating database interface" << std::endl;
}

Idatabase::~Idatabase()
{
    std::cout << "deleting database interface" << std::endl;
    closeDBhandle();
}
void Idatabase::createDBfile(std::string fileName)
{
    auto cwd = std::filesystem::current_path().generic_string();
    std::string extension = ".db";
    int rc;
    rc = sqlite3_open((fileName + extension).c_str(), &dbHandler);

    if (rc) {
        std::cout << "Can't create database: " << sqlite3_errmsg(dbHandler) << std::endl;
    }
    else {
        std::cout << "created database successfully. the databse will be stored here:" << std::endl;
        std::cout << cwd << "/" << fileName << extension << std::endl;
    }
}

void Idatabase::openDBfile(std::string fileName)
{
    std::string extension = ".db";
    int rc;
    rc = sqlite3_open((fileName + extension).c_str(), &dbHandler);

    if (rc) {
        std::cout << "Can't open database: " << sqlite3_errmsg(dbHandler) << std::endl;
    }
    else {
        std::cout << "opened database successfully" << std::endl;
    }
}
void Idatabase::createDBTable(table& newtable)
{
    std::string create_cmd = "CREATE TABLE ";
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (create_cmd + newtable.TableToSend).c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        std::cout << "SQL error: %s\n" << zErrMsg << std::endl;

        sqlite3_free(zErrMsg);
    }
    else {
        std::cout << "Table: " << newtable.TableToSend << " created successfully" << std::endl;
    }


}
void Idatabase::closeDBhandle()
{
    sqlite3_close(dbHandler);
}
void Idatabase::queryDBTable(std::string table)
{
    std::string query_cmd = "SELECT * FROM ";
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (query_cmd + table + ";").c_str(), queryDBCallback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        std::cout << "SQL error: %s\n" << zErrMsg << std::endl;

        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "query operation success\n");
    }
}

void Idatabase::insertDBTableRow(std::string table, std::string row)
{
    std::string insert_cmd = "INSERT INTO ";
    std::string values = " VALUES";
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (insert_cmd + table + values + row).c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        std::cout << "SQL error: %s\n" << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }
    else {

        std::cout << "row: " << row << " inserted successfully" << std::endl;

    }

}
void Idatabase::deleteDBTableRow(std::string table, std::string rowIndex, std::string key)
{
    std::string delete_cmd = "DELETE FROM ";
    std::string where = " WHERE ";
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (delete_cmd + table + where + key + " =" + rowIndex + ";").c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cout << "SQL error: %s\n" << zErrMsg << std::endl;

        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "row " << rowIndex << " deleted Successfully!" << std::endl;
    }

}
void Idatabase::selectDBTableColumn(std::string table, std::string Column)
{
    std::string select_cmd = "SELECT ";
    std::string from = " FROM ";
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (select_cmd + Column + from + table).c_str(), queryDBCallback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error SELECT" << std::endl;
        std::cout << "SQL error: %s\n" << zErrMsg << std::endl;

        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "column " << Column << " selected Successfully!" << std::endl;
    }
}

int Idatabase::queryDBCallback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

table& Idatabase::getTableHandle()
{
    return *tableHandler;
}