#include "model.h"

model::model()
{
    std::cout << "model constructed" << std::endl;
    processManager = new wgm_processes::process_management();
}

model::~model()
{

    delete processManager;

}