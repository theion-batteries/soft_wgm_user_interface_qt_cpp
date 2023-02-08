/**
 * @file sinkingDB.h
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

class sinkingDB: public Idatabase
{
    public:
    sinkingDB(std::string tableName="sinkingTable");
    ~sinkingDB();

};