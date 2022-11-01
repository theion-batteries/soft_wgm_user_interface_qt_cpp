#include "heatingModel.h"

heatingModel::heatingModel()
{
    std::cout << "heating model constructed" << std::endl;
    heatingProcessHandler = new wgm_processes::heating_process();
}

heatingModel::~heatingModel()
{

    delete heatingProcessHandler;

}