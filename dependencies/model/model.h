#pragma once

#include <iostream>
#include "process_manager.h"
class model
{
    public:
    model()
    {
        std::cout<< "model constructed"<< std::endl;
      // processManager = new wgm_processes::process_management();
    sinkingProcessHandler = new wgm_processes::sinking_process();
    }
    private:
    //wgm_processes::Iprocesses_managment* processManager;
    //wgm_processes::Iprocesses_managment* heatingProcessHandler;
    wgm_processes::Iprocesses_managment* sinkingProcessHandler;
};