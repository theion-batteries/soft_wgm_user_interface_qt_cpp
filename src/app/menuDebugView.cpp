#include "menuDebugView.h"

menuDebugView::menuDebugView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
/**************** signals and slots ********************/
      // open whs config
    connect(ui->actionopen_debug_console, &QAction::triggered, [this]() {
        on_actionopen_debug_console_triggered();
        });
}

menuDebugView::~menuDebugView()
{
}

void menuDebugView::on_actionopen_debug_console_triggered()
{

      if (AllocConsole())
    {
    std::cout<< "opening debug console"<<std::endl;
    //QProcess::startDetached("C:\\Windows\\system32\\notepad.exe", {WHS_CONFIG});
        freopen("CONOUT$", "wt", stdout);
        freopen("CONIN$", "rt", stdin);
        SetConsoleTitle(L"Debug Console");
        std::ios::sync_with_stdio(1);
    }   
}
