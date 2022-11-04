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
    std::cout<< "opening debug console"<<std::endl;
       std::ifstream file;

    file.open("cout.txt", std::ios::out);
    std::string line;
 
    // Backup streambuffers of  cout
    std::streambuf* stream_buffer_cout = std::cout.rdbuf();
    std::streambuf* stream_buffer_cin = std::cin.rdbuf();
 
    // Get the streambuffer of the file
    std::streambuf* stream_buffer_file = file.rdbuf();
 
    // Redirect cout to file
    std::cout.rdbuf(stream_buffer_file);
 
    std::cout << "This line written to file" << std::endl;
 
    // Redirect cout back to screen
    std::cout.rdbuf(stream_buffer_cout);
    std::cout << "This line is written to screen" << std::endl;
 
    file.close();
   // QProcess::startDetached("C:\\Windows\\system32\\notepad.exe", {});
         /*  if (AllocConsole())
         {
             freopen_s(stream,"stdout.out", "wt", stdout);
             freopen_s( stream, "stderr.out", "wt", stderr );
             freopen_s(stream,"stdin.out", "rt", stdin);
             SetConsoleTitle(L"Debug Console");
             std::ios::sync_with_stdio(1);
         }*/
}
