
/**
 * @file coolingDB.h
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

class coolingDB: public Idatabase
{
    public:
    coolingDB(std::string tableName="coolingTable");
    ~coolingDB();

};