#include "model.h"

model::model()
{
    std::cout << "model sinking constructed" << std::endl;
    processManager = new wgm_processes::sinking_process();
}

model::~model()
{

    delete processManager;

}