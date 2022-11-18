
/**
 * @file aligningDB.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Idatabase.h"

class aligningDB: public Idatabase
{
    public:
    aligningDB(std::string tableName="aligningTable");
    ~aligningDB();

};
