#include "userDB.h"
int main() {
    // sinking DB
    Idatabase* userA = new userDB(); 
    std::string values = "(10, 'sami', 'dhiab');";
    userA->getLastRowID();
    //userA->insertDBTableRow(userA->getTableHandle().Table_name, values);
    userA->searchDBRowValues(userA->getTableHandle().Table_name,"name",  "sami","password", "dhiab");

    delete userA;
}