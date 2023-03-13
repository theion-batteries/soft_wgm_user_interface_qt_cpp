#include "extractingModel.h"
extractingModel::extractingModel(wgm_processes::Isinking_process* sinProcPtr)

{
    std::cout << "extracting model constructed" << "\n";
    extractingProcessHandler = new wgm_processes::extracting_process(sinProcPtr->get_sys_ptr());
}

extractingModel::~extractingModel()
{
    delete extractingProcessHandler;
}