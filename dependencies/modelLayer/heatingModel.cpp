#include "heatingModel.h"

heatingModel::heatingModel()
{
    std::cout << "heating model constructed" << "\n";
    heatingProcessHandler = new wgm_processes::heating_process();
}

heatingModel::~heatingModel()
{

    delete heatingProcessHandler;

}