
/**
 * @file extractingDB.h
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

class extractingDB: public Idatabase
{
    public:
    extractingDB(std::string tableName="extractingTable");
    ~extractingDB();

};