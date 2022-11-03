#include "sinkingModel.h"

sinkingModel::sinkingModel()
{
    std::cout << "model sinking constructed" << std::endl;
      if (AllocConsole())
    {
    std::cout<< "opening debug console"<<std::endl;
        freopen("CONOUT$", "wt", stdout);
        freopen("CONIN$", "rt", stdin);
        SetConsoleTitle(L"Debug Console");
        std::ios::sync_with_stdio(1);
    }   
    sinkingProcessHandler = new wgm_processes::sinking_process();
 
}

sinkingModel::~sinkingModel()
{

    delete sinkingProcessHandler;

}