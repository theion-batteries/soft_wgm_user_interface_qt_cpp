/**
 * @file heatingDB.h
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

class heatingDB: public Idatabase
{
    public:
    heatingDB(std::string tableName="heatingTable");
    ~heatingDB();

};