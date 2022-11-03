#include "menuDebugView.h"

menuDebugView::menuDebugView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
/**************** signals and slots ********************/
      // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
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
        freopen("CONOUT$", "wt", stdout);
        freopen("CONIN$", "rt", stdin);
        SetConsoleTitle(L"Debug Console");
        std::ios::sync_with_stdio(1);
    }   
}
