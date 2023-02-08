/**
 * @file model.h
 * @author sami dhiab
 * @brief template for model layer mvc
 * @version 0.1
 * @date 2022-10-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include "cooling_process.h"


class coolingModel 
{
public:
  coolingModel();
  ~coolingModel();
  wgm_processes::Icooling_process* coolingProcessHandler;
};