#include "extractingModel.h"
extractingModel::extractingModel(wgm_processes::Isinking_process* sinProcPtr)

{
    std::cout << "extracting model constructed" << std::endl;
    extractingProcessHandler = new wgm_processes::extracting_process(sinProcPtr->get_sys_obj());
}

extractingModel::~extractingModel()
{
    delete extractingProcessHandler;
}