#include "coolingModel.h"

coolingModel::coolingModel()
{
    std::cout << "cooling Model constructed" << std::endl;
    coolingProcessHandler = new wgm_processes::cooling_process();
}

coolingModel::~coolingModel()
{
    delete coolingProcessHandler;
}