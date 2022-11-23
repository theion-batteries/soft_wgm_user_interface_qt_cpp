/**
 * @file userDB.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Idatabase.h"
class userDB: public Idatabase
{
    public:
    userDB(std::string tableName="userTable");
    ~userDB();

};