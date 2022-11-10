#include "sinkingView.h"

sinkingView::sinkingView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(2, "Sinking");
    ui->sink_sensor_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sink_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sinking_finished->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sink_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");

/**************** signals and slots ********************/

    // connect cmd button connect sensor
    connect(ui->sink_connect_distance_sensor, &QAbstractButton::pressed, [this]() {
        sinkControll.on_sink_connect_distance_sensor_clicked();
        ui->sink_sensor_ready->setText(sinkControll.get_sensor_status() );
        ui->sink_sensor_ready->setStyleSheet("QLabel { background-color : green; color : black; }");
        sinkControll.updateLcdDistance(ui->sink_distance_head1);

        });
    // connect cmd button connect axis
    connect(ui->sink_connect_motion_axis, &QAbstractButton::pressed, [this]() {
        sinkControll.on_sink_connect_motion_axis_clicked();
        ui->sink_motion_ready->setText(sinkControll.get_axis_status() );
        ui->sink_motion_ready->setStyleSheet("QLabel { background-color : green; color : black; }");
        sinkControll.updateLcdPosition(ui->sink_axis_pos);
        });
    // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.updateLcdTime(ui->sink_time);
        sinkControll.on_run_sinking_process_clicked();
        sinkControll.updateLcdTime(ui->sink_time);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        sinkControll.updateLcdTime(ui->sink_time);
        sinkControll.on_stop_sinking_process_clicked();
        sinkControll.updateLcdTime(ui->sink_time);
        });
    // connect enter to send cmd and to clear input
    connect(ui->sink_input_axis_cmd , &QLineEdit::returnPressed, [this]() {
        auto inputCmd = ui->sink_input_axis_cmd->text();
        ui->sink_cmd_given->setText(inputCmd);
        auto response = sinkControll.sendAxisCmd(inputCmd.toStdString());
        ui->sink_axis_response->setStyleSheet("QLabel { background-color : green; color : black; }");        
        ui->sink_axis_response->setText(response.c_str());
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