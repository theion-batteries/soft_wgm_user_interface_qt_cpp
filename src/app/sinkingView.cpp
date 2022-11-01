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
    // connect cmd button connect axis
    connect(ui->connect_distance_sensor, &QAbstractButton::pressed, [this]() {
        sinkControll.on_connect_distance_sensor_clicked();
        });
    // connect cmd button connect sensor
    connect(ui->connect_motion_axis, &QAbstractButton::pressed, [this]() {
        sinkControll.on_connect_motion_axis_clicked();
        });
    // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_run_sinking_process_clicked();
        sinkControll.passLcdNum(ui->time_sinking);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->time_sinking);
        sinkControll.on_stop_sinking_process_clicked();
        sinkControll.passLcdNum(ui->time_sinking);
        });
    // connect enter to clear input
    connect(ui->input_axis_cmd , &QLineEdit::returnPressed, [this]() {
        auto inputCmd = ui->input_axis_cmd->text();
        ui->cmd_given->setText(inputCmd);
        ui->input_axis_cmd->clear();
    
        });

}

sinkingView::~sinkingView()
{
}