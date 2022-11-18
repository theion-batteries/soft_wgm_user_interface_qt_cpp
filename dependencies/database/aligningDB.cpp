#include "aligningDB.h"

aligningDB::aligningDB(std::string tableName)
{
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ATTEMPT", "INT" }, true, true);
    tableHandler->addColumn({ "AXIS_POSITION", "REAL" }, true);
    tableHandler->addColumn({ "DISPENSER_FREQ", "REAL" }, true);
    tableHandler->addColumn({ "HV_INPUT_CURRENT", "REAL" }, true);
    tableHandler->addColumn({ "HV_INPUT_VOLTAGE", "REAL" }, true);
    tableHandler->addColumn({ "HV_OUTPUT_VOLTAGE", "REAL" }, true);
    tableHandler->addColumn({ "HV_OUTPUT_CURRENT", "REAL" }, true);
    tableHandler->addColumn({ "PROCESS_TIME", "REAL" }, true);
    tableHandler->generateTable();

}
aligningDB::~aligningDB()
{
    delete tableHandler;
}
