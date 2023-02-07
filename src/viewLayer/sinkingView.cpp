#include "sinkingView.h"

sinkingView::sinkingView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(2, "Sinking");
    ui->sink_sensor_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sink_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sinking_finished->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->sink_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    /**************** signals and slots ********************/
    /************  connect methods           ***********/

    // connect cmd button connect axis
    connect(ui->sink_connect_motion_axis, &QAbstractButton::pressed, this, [this]() {
        auto connectAxisTask = QtConcurrent::run([this]() {
            sinkControll.on_sink_connect_motion_axis_clicked();});
        }, Qt::QueuedConnection);
    connect(&sinkControll, &sinkingController::axisConnected, this, [this]() {
        sinkControll.updateLabelAxis(ui->sink_motion_ready);
    auto func = QtConcurrent::run(&sinkingController::updateLcdPosition, &sinkControll, ui->sink_axis_pos);
        }, Qt::QueuedConnection);

    // connect cmd button connect sensor
    connect(ui->sink_connect_distance_sensor, &QAbstractButton::pressed, this, [this]() {
        auto connectSensorTask = QtConcurrent::run([this]()
            {sinkControll.on_sink_connect_distance_sensor_clicked();});}, Qt::QueuedConnection);
    connect(&sinkControll, &sinkingController::sensorConnected, this, [this]() {
        sinkControll.updateLabelSensor(ui->sink_sensor_ready);
    auto func = QtConcurrent::run(&sinkingController::updateLcdDistance, &sinkControll, ui->sink_distance_head1);
        }, Qt::QueuedConnection);
/*****************  manual commands section *******************/

    // connect enter to send cmd manually
    connect(ui->sink_input_axis_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->sink_input_axis_cmd->text();
    ui->sink_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run(&sinkingController::updateLabelAxisResponse, &sinkControll, ui->sink_axis_response, inputCmd);
        }, Qt::QueuedConnection);
        
    // connect axis reply to update text
    connect(&sinkControll, &sinkingController::axisReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->sink_axis_response->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->sink_axis_response->setText(reply.c_str());
    ui->sink_input_axis_cmd->clear();
        }, Qt::QueuedConnection);

    /**********   Process   **********/
 // connect cmd button run process sinking
    connect(ui->run_sinking_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {sinkControll.on_run_sinking_process_clicked();});
    sinkControll.updateLabelAxis(ui->sink_motion_ready);
    sinkControll.updateLabelSensor(ui->sink_sensor_ready);
    sinkControll.updateLabelProcess(ui->sinking_finished);
    sinkControll.updateLcdTime(ui->sink_time);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_sinking_process, &QAbstractButton::pressed, [this]() {
        if (sinkControll.getProcessStatus())
        {
            std::cout << "process already finished" << std::endl;
            return;
        }
    auto func = QtConcurrent::run([this]() {sinkControll.on_stop_sinking_process_clicked();});
        });

    // algorithms
    // move down until data valid
    connect(ui->move_down_until_sensor_data_valid, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&sinkingController::on_move_down_until_sensor_data_valid_clicked, &sinkControll);
        });
    // move down to surface
    connect(ui->move_down_to_surface_contact, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&sinkingController::on_move_down_to_surface_contact_clicked, &sinkControll);
        });
    // deep wafer desired thicknesss
    connect(ui->deep_wafer_holder_desired_thickness, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&sinkingController::on_deep_wafer_holder_desired_thickness_clicked, &sinkControll);
        });
    // calibrate
    connect(ui->monitor_and_calibrate, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&sinkingController::on_monitor_and_calibrate_clicked, &sinkControll);
        });

}

sinkingController* sinkingView::getController()
{
    return &sinkControll;
}

sinkingView::~sinkingView()
{
}

