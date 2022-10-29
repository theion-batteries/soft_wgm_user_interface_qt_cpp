#include "model.h"

modelSinking::modelSinking()
{
    std::cout << "model sinking constructed" << std::endl;
    sinkingProcessHandler = new wgm_processes::sinking_process();
}

modelSinking::~modelSinking()
{

    delete sinkingProcessHandler;

}