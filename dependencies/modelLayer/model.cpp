#include "model.h"

model::model()
{
    std::cout << "model constructed" << "\n";
    processManager = new wgm_processes::process_manager();
}

model::~model()
{

    delete processManager;

}