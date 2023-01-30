#include "model.h"

model::model()
{
    std::cout << "model constructed" << std::endl;
    processManager = new wgm_processes::process_manager();
}

model::~model()
{

    delete processManager;

}