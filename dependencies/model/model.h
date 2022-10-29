#pragma once

#include <iostream>
#include "process_manager.h"
class model
{
public:
  model()
  {
    std::cout << "model constructed" << std::endl;
    processManager = new wgm_processes::process_management();
  }
private:
  wgm_processes::Iprocesses_managment* processManager;
  wgm_processes::Iprocesses_managment* heatingProcessHandler;
};

class modelSinking 
{
public:
  modelSinking();
  ~modelSinking();
  wgm_processes::Isinking_process* sinkingProcessHandler;
};