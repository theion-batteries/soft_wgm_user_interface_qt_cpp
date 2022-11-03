#include "sinkingModel.h"

sinkingModel::sinkingModel()
{
    std::cout << "model sinking constructed" << std::endl;
   
    sinkingProcessHandler = new wgm_processes::sinking_process();
}

sinkingModel::~sinkingModel()
{

    delete sinkingProcessHandler;

}