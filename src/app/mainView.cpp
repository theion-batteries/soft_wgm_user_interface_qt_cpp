#include "mainView.h"

mainView::mainView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(0, "Main");

/**************** signals and slots ********************/
 
}

mainView::~mainView()
{
}