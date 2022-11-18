
#include "extractingDB.h"

extractingDB::extractingDB(std::string tableName)
{
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ATTEMPT", "INT" }, true, true);
    tableHandler->addColumn({ "AXIS_POSITION", "REAL" }, true);
    tableHandler->addColumn({ "SENSOR_DISTANCE", "REAL" }, true);
    tableHandler->addColumn({ "PROCESS_TIME", "REAL" }, true);
    tableHandler->generateTable();

}
extractingDB::~extractingDB()
{
    delete tableHandler;
}