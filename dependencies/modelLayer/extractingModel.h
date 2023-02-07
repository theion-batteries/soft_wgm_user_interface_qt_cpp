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
#include "sinking_process.h"
#include "extracting_process.h"


class extractingModel 
{
public:
  extractingModel(wgm_processes::Isinking_process* sinProcPtr);
  ~extractingModel();
  wgm_processes::Iextracting_process* extractingProcessHandler;
};