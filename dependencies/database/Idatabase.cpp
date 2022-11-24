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
        std::cout << zErrMsg << std::endl;

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
        std::cout << zErrMsg << std::endl;

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
        std::cout << zErrMsg << std::endl;
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
        std::cout << zErrMsg << std::endl;

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
        std::cout << zErrMsg << std::endl;

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
    LastID = argc;
    printf("\n");
    return 0;
}

table& Idatabase::getTableHandle()
{
    return *tableHandler;
}

int Idatabase::getLastInsertRowID()
{
    auto id = static_cast<int> (sqlite3_last_insert_rowid(dbHandler));
    std::cout << "last row id: " << id << std::endl;
    return id;
}

int Idatabase::getLastRowID()
{
    queryDBTable(this->tableHandler->Table_name);
    std::cout << "last row id: " << LastID << std::endl;
    return LastID;
}

bool Idatabase::searchDBRowValues(std::string table, std::string col1, std::string val1, std::string col2, std::string val2)
{
    std::string select_cmd = "SELECT ";
    std::string from = " FROM ";
    std::string comma = ",";
    std::string where = " WHERE ";
    std::string match = " MATCH ";
    std::string equal = " = ";
    std::string AND = " AND ";
    std::string semicol = " ;";
    auto query = select_cmd + col1 + comma + col2 + from + table + where + col1 + equal + "'" + val1 + "'" + AND + col2 + equal + "'" + val2 + "'" + semicol;
    std::cout << query << std::endl;
    Records records;
    int rc;
    char* zErrMsg = 0;
    rc = sqlite3_exec(dbHandler, (query).c_str(), select_callback, &records, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cout << zErrMsg << std::endl;

        std::cerr << "Error SELECT command" << std::endl;
        sqlite3_free(zErrMsg);
        return false;
    }
    else
    {
        if (records.size() == 0)
        {
            std::cout << "record not found" << std::endl;
            return false;
        }
        std::cout << "row with name " << val1 << " selected Successfully!" << std::endl;
        std::cout << records.size() << " records returned.\n";
        auto c = 0;
        for (auto& record : records) {
            std::cout << "record: " << record[c] << std::endl;
            c++;
        }
        return true;
    }
}



int Idatabase::select_callback(void* p_data, int num_fields, char** p_fields, char** p_col_names)
{
    Records* records = static_cast<Records*>(p_data);
    try {
        records->emplace_back(p_fields, p_fields + num_fields);
    }
    catch (...) {
        // abort select on failure, don't let exception propogate thru sqlite3 call-stack
        return 1;
    }
    return 0;
}







