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
#include "process_manager.h"
class model
{
public:
  model();
  ~model();
private:
  wgm_processes::Iprocess_manager* processManager;
};
