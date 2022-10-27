#pragma once

#include <iostream>
#include "process_manager.h"
class model
{
    public:
    model()
    {
        std::cout<< "model constructed"<< std::endl;
        whs_sinking_proc = new wgm_processes::sinking_process();


    }
    private:
    wgm_processes::Isinking_process* whs_sinking_proc;
};