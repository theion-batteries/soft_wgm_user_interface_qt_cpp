#include "menuDebugView.h"
#include <ios>
#include <cstdio>
#include <io.h>
#include <fcntl.h>

menuDebugView::menuDebugView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
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
        SetConsoleTitle(L"Debug Console");

        // use static for scope
        static std::ofstream conout("CONOUT$", std::ios::out);
        // Set std::cout stream buffer to conout's buffer (aka redirect/fdreopen)
        std::cout.rdbuf(conout.rdbuf());
        std::cerr.rdbuf(conout.rdbuf());


    }


}
