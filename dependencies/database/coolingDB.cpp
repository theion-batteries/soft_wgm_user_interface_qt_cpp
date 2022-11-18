
#include "coolingDB.h"

coolingDB::coolingDB(std::string tableName)
{
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ATTEMPT", "INT" }, true, true);
    tableHandler->addColumn({ "AXIS_ROTATION_ANGLE", "REAL" }, true);
    tableHandler->addColumn({ "AXIS_MOTION_POSITION", "REAL" }, true);
    tableHandler->addColumn({ "AXIS_ROTATION_VELOCITY", "REAL" }, true);
    tableHandler->addColumn({ "AXIS_MOTION_VELOCITY", "REAL" }, true);
    tableHandler->addColumn({ "PH_EJET_FREQUENCY", "REAL" }, true);
    tableHandler->addColumn({ "PH_DROPLET_VOLUME", "REAL" }, true);
    tableHandler->addColumn({ "PH_NUMBER_ACTIVE_NUZZLES", "REAL" }, true);
    tableHandler->addColumn({ "PH_LIQUID_TEMPERATURE", "REAL" }, true);
    tableHandler->addColumn({ "PROCESS_TIME", "REAL" }, true);
    tableHandler->generateTable();

}
coolingDB::~coolingDB()
{
    delete tableHandler;
}