#include "sinkingDB.h"

sinkingDB::sinkingDB(std::string tableName)
{
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ATTEMPT", "INT" }, true, true);
    tableHandler->addColumn({ "AXIS_POSITION", "REAL" }, true);
    tableHandler->addColumn({ "SENSOR_DISTANCE", "REAL" }, true);
    tableHandler->addColumn({ "PROCESS_TIME", "REAL" }, true);
    tableHandler->generateTable();

}
sinkingDB::~sinkingDB()
{
    delete tableHandler;
}