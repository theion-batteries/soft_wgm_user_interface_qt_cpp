#include "menuDebugView.h"

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
QProcess debug_console;
debug_console.execute("cmd.exe",{});

     /*
       FILE *stream;
           if (AllocConsole())
         {
         std::cout<< "opening debug console"<<std::endl;
             freopen_s(&stream,"stdout.out", "wt", stdout);
             freopen_s( &stream, "stderr.out", "wt", stderr );
             freopen_s(&stream,"stdin.out", "rt", stdin);
             SetConsoleTitle(L"Debug Console");
             std::ios::sync_with_stdio(1);
         }
         */
}
