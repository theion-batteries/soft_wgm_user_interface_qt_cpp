
#include "heatingDB.h"

heatingDB::heatingDB(std::string tableName)
{
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ATTEMPT", "INT" }, true, true);
    tableHandler->addColumn({ "TEMPERATURE", "REAL" }, true);
    tableHandler->addColumn({ "PROCESS_TIME", "REAL" }, true);
    tableHandler->generateTable();

}
heatingDB::~heatingDB()
{
    delete tableHandler;
}