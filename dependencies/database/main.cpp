#include "userDB.h"
int main() {
    // sinking DB
    Idatabase* userA = new userDB(); 
    userA->createDBfile("userTable");
    userA->createDBTable(userA->getTableHandle());
    std::string values = "(0, 'aaa', 'bbb');";
    //for (int i =0; i<10;i++)
    //{
    //auto x =std::to_string(i);
    //std::cout<<values.at(1)<<std::endl;
    //values.at(1)=*x.c_str();
    //userA->insertDBTableRow(userA->getTableHandle().Table_name, values);
//
    //}
    //userA->deleteDBTableRow(userA->getTableHandle().Table_name, "1");
    userA->queryDBTable(userA->getTableHandle().Table_name);
    //userA->selectDBTableColumn(userA->getTableHandle().Table_name, "AXIS_POSITION");

    delete userA;
}