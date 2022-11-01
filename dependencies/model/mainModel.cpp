#include "mainModel.h"

mainModel::mainModel()
{
    std::cout << "main model constructed" << std::endl;
    processManager = new wgm_processes::process_management();
}

mainModel::~mainModel()
{

    delete processManager;

}