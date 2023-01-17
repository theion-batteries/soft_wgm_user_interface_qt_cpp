#include "coolingView.h"

coolingView::coolingView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(4, "Cooling");
    ui->ph_connected_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_rotation_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cooling_proc_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_rotation_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_response_status->setStyleSheet("QLabel { background-color : red; color : black; }");
/**************** signals and slots ********************/
  






}

coolingView::~coolingView()
{
}