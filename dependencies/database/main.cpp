#include "sinkingDB.h"
#include "aligningDB.h"
int main() {
    // sinking DB
    Idatabase* sinkDB = new sinkingDB(); 
    sinkDB->createDBfile("testExperiment");
    sinkDB->createDBTable(sinkDB->getTableHandle());
    std::string values = "(1, 300.0, '300.0', '0.0');";
    for (int i =0; i<10;i++)
    {
    auto x =std::to_string(i);
    std::cout<<values.at(1)<<std::endl;
    values.at(1)=*x.c_str();
    sinkDB->insertDBTableRow(sinkDB->getTableHandle().Table_name, values);

    }
    sinkDB->deleteDBTableRow(sinkDB->getTableHandle().Table_name, "1");
    sinkDB->queryDBTable(sinkDB->getTableHandle().Table_name);
    sinkDB->selectDBTableColumn(sinkDB->getTableHandle().Table_name, "AXIS_POSITION");


    Idatabase* alignDB = new aligningDB(); 
    alignDB->openDBfile("testExperiment");
    alignDB->createDBTable(alignDB->getTableHandle());

    values = "(1, 300.0, 300.0, 0.0, 200, 150,100, 50 );";
    for (int i =0; i<10;i++)
    {
    auto x =std::to_string(i);
    values.at(1)=*x.c_str();
    sinkDB->insertDBTableRow(alignDB->getTableHandle().Table_name, values);

    }
    alignDB->deleteDBTableRow(alignDB->getTableHandle().Table_name, "0");
    alignDB->queryDBTable(alignDB->getTableHandle().Table_name);
    alignDB->selectDBTableColumn(alignDB->getTableHandle().Table_name, "AXIS_POSITION");
    delete sinkDB;
    delete alignDB;
}