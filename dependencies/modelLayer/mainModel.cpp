#include "mainModel.h"

mainModel::mainModel()
{
    std::cout << "main model constructed" << "\n";
    processManager = new wgm_processes::process_manager();
}

mainModel::~mainModel()
{

    delete processManager;

}