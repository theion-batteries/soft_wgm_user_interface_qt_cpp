#include "sinkingView.h"

sinkingView::sinkingView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(2, "Sinking");

/**************** signals and slots ********************/

    // connect cmd button connect axis
    connect(ui->sink_connect_distance_sensor, &QAbstractButton::pressed, [this]() {
        sinkControll.on_sink_connect_distance_sensor_clicked();
        });
    // connect cmd button connect sensor
    connect(ui->sink_connect_motion_axis, &QAbstractButton::pressed, [this]() {
        sinkControll.on_sink_connect_motion_axis_clicked();
        });
    // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->sink_time);
        sinkControll.on_run_sinking_process_clicked();
        sinkControll.passLcdNum(ui->sink_time);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.passLcdNum(ui->sink_time);
        sinkControll.on_stop_sinking_process_clicked();
        sinkControll.passLcdNum(ui->sink_time);
        });
    // connect enter to send cmd and to clear input
    connect(ui->sink_input_axis_cmd , &QLineEdit::returnPressed, [this]() {
        auto inputCmd = ui->sink_input_axis_cmd->text();
        ui->sink_cmd_given->setText(inputCmd);
        sinkControll.sendAxisCmd(inputCmd.toStdString());
        ui->sink_input_axis_cmd->clear();
    
        });

}

sinkingView::~sinkingView()
{
}

sinkingController* sinkingView::getController()
{
    return &sinkControll;
}