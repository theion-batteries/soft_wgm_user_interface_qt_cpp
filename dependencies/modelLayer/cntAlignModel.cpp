#include "cntAlignModel.h"

cntAlignModel::cntAlignModel()
{
    std::cout << "aligning model constructed" << "\n";
    aligningProcessHandler = new wgm_processes::aligning_process();
}

cntAlignModel::~cntAlignModel()
{
    delete aligningProcessHandler;
}