/**
 * @file view.h
 * @author sami dhiab
 * @brief template for view layer mvc
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
// qt

// mvc
#include "controller.h"

class view : public QObject
{
private:
    /* data */
public:
    view(/* args */);
    ~view();
};

view::view(/* args */)
{
}

view::~view()
{
}
