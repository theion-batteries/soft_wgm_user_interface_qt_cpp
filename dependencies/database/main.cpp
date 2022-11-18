#include "Idatabase.h"

int main() {
    Idatabase db;
    table bbb;
    bbb.setTableName("afg");
    bbb.addColumn({ "ID", "INT" }, true, true);
    bbb.addColumn({ "NAME", "TEXT" }, true);
    bbb.addColumn({ "SURNAME", "TEXT" }, true);
    bbb.addColumn({ "AGE", "INT" }, true);
    bbb.addColumn({ "ADDRESS", "CHAR(50)" }, true);
    bbb.addColumn({ "SALARY", "REAL" }, true);
    bbb.generateTable();
    db.createDBfile("ccc");
    db.createDBTable(bbb);
    std::string values = "(0, 'STEVE', 'GATES', '30', 'PALO ALTO', '1000.0');";
    db.insertDBTableRow(bbb.Table_name, values);
     values = "(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);";
    db.insertDBTableRow(bbb.Table_name, values);
     values = "(2, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);";
    db.insertDBTableRow(bbb.Table_name, values);
    db.deleteDBTableRow(bbb.Table_name, "1");
    db.queryDBTable(bbb.Table_name);
    db.selectDBTableColumn(bbb.Table_name, "NAME");

}