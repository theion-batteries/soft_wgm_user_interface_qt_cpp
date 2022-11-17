/**
 * @file Idatabase.h
 * @author sami dhiab
 * @brief easy to use interface for sqlite3
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sqlite3.h"
class Idatabase 
{
private:
    /* data */
public:
    Idatabase(/* args */);
    ~Idatabase();
     void createDBFile();
     void createTable();
     void insertElement();
     void deleteElement();
     void select();
};


