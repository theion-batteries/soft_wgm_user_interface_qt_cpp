#include "sinkingModel.h"
// Cpp program to redirect cout to a file
#include <fstream>
#include <iostream>
#include <string>
sinkingModel::sinkingModel()
{
    std::cout << "model sinking constructed" << std::endl;
    sinkingProcessHandler = new wgm_processes::sinking_process();
}

sinkingModel::~sinkingModel()
{

    delete sinkingProcessHandler;

}