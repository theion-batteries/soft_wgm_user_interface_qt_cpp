#include "sinkingView.h"

sinkingView::sinkingView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(2, "Sinking");

/**************** signals and slots ********************/
    // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
        sinkControll.on_actionwhs_config_triggered();
        });
    // connect cmd button execute delta subproc
    connect(ui->execute_delta_subprocess, &QAbstractButton::pressed, [this]() {
        sinkControll.on_execute_delta_subprocess_clicked();
        });
    // connect cmd button connect delta
    connect(ui->connect_delta_server, &QAbstractButton::pressed, [this]() {
        sinkControll.on_connect_delta_clicked();
        });
    // connect cmd button execute keyence
    connect(ui->connect_keyence_sensor, &QAbstractButton::pressed, [this]() {
        sinkControll.on_connect_keyence_sensor_clicked();
        });
    // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_run_sinking_process_clicked();
        ui->delta_ready->setText(sinkControll.get_delta_status());
        sinkControll.passLcdNum(ui->time_sinking);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_stop_sinking_process_clicked();
        sinkControll.passLcdNum(ui->time_sinking);
        });


}

sinkingView::~sinkingView()
{
}