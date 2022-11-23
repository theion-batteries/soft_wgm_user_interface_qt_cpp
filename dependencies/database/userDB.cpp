
#include "userDB.h"

userDB::userDB(std::string tableName)
{
    
    tableHandler=new table(tableName);
    tableHandler->addColumn({ "ID", "INT" }, true, true);
    tableHandler->addColumn({ "NAME", "TEXT" }, true);
    tableHandler->addColumn({ "PASSWORD", "TEXT" }, true);
    //tableHandler->addColumn({ "DEPARTMENT", "TEXT" }, true);
    //tableHandler->addColumn({ "ROLE", "TEXT" }, true);
    tableHandler->generateTable();
    // create db file and table in it
    this->createDBfile("UsersDataBase");
    this->createDBTable(this->getTableHandle());

}
userDB::~userDB()
{
    delete tableHandler;
}