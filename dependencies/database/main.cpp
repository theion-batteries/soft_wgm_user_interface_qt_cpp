#include "sinkingDB.h"

int main() {
    Idatabase* sinkDB = new sinkingDB("sinkingTable1"); 
    sinkDB->createDBfile("tgb");
    sinkDB->createDBTable(sinkDB->getTableHandle());
    std::string values = "(1, 300.0, '300.0', '0.0');";
    sinkDB->insertDBTableRow(sinkDB->getTableHandle().Table_name, values);
    values = "(2, 250.0, '280.0', '1.0');";
    sinkDB->insertDBTableRow(sinkDB->getTableHandle().Table_name, values);
    sinkDB->deleteDBTableRow(sinkDB->getTableHandle().Table_name, "0");
    sinkDB->queryDBTable(sinkDB->getTableHandle().Table_name);
    sinkDB->selectDBTableColumn(sinkDB->getTableHandle().Table_name, "AXIS_POSITION");
    Idatabase* sink1DB = new sinkingDB("sinkingTable2"); 
    sink1DB->openDBfile("tgb");
    sink1DB->createDBTable(sink1DB->getTableHandle());
    values = "(0, 200.0, '200.0', '0.0');";
    sink1DB->insertDBTableRow(sink1DB->getTableHandle().Table_name, values);
    values = "(1, 300.0, '300.0', '0.0');";
    sink1DB->insertDBTableRow(sink1DB->getTableHandle().Table_name, values);
    values = "(2, 250.0, '280.0', '1.0');";
    sink1DB->insertDBTableRow(sink1DB->getTableHandle().Table_name, values);
    sink1DB->deleteDBTableRow(sink1DB->getTableHandle().Table_name, "0");
    sink1DB->queryDBTable(sink1DB->getTableHandle().Table_name);
    sink1DB->selectDBTableColumn(sink1DB->getTableHandle().Table_name, "AXIS_POSITION");
    delete sinkDB;
    delete sink1DB;
}