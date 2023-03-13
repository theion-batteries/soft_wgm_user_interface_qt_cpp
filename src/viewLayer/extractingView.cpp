#include "extractingView.h"

extractingView::extractingView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(5, "Extracting");

/**************** signals and slots ********************/
  ui->extract_sensor_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->extract_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->extract_proc_finished->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->extract_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    /**************** signals and slots ********************/
    /************  connect methods           ***********/
    // connect cmd button connect axis
    connect(ui->extract_connect_motion_axis, &QAbstractButton::pressed, this, [this]() {
        auto connectAxisTask = QtConcurrent::run([this]() {
            extractControll.on_extract_connect_motion_axis_clicked();});
        }, Qt::QueuedConnection);
    connect(&extractControll, &extractingController::axisConnected, this, [this]() {
        extractControll.updateLabelAxis(ui->extract_motion_ready);
    auto func = QtConcurrent::run(&extractingController::updateLcdPosition, &extractControll, ui->extract_axis_pos_display);
        }, Qt::QueuedConnection);

    // connect cmd button connect sensor
    connect(ui->extract_connect_distance_sensor, &QAbstractButton::pressed, this, [this]() {
        auto connectSensorTask = QtConcurrent::run([this]()
            {extractControll.on_extract_connect_distance_sensor_clicked();});}, Qt::QueuedConnection);
    connect(&extractControll, &extractingController::sensorConnected, this, [this]() {
        extractControll.updateLabelSensor(ui->extract_sensor_ready);
    auto func = QtConcurrent::run(&extractingController::updateLcdDistance, &extractControll, ui->extract_distance_head1_view);
        }, Qt::QueuedConnection);
/*****************  manual commands section *******************/

    // connect enter to send cmd manually
    connect(ui->extract__input_axis_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->extract__input_axis_cmd->text();
    ui->extract_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run(&extractingController::updateLabelAxisResponse, &extractControll, ui->extract_axis_response, inputCmd);
        }, Qt::QueuedConnection);
        
    // connect axis reply to update text
    connect(&extractControll, &extractingController::axisReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << "\n";
    ui->extract_axis_response->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->extract_axis_response->setText(reply.c_str());
    ui->extract__input_axis_cmd->clear();
        }, Qt::QueuedConnection);

    /**********   Process   **********/
 // connect cmd button run process extracting
    connect(ui->run_extracting_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {extractControll.on_run_extracting_process_clicked();});
    extractControll.updateLabelAxis(ui->extract_motion_ready);
    extractControll.updateLabelSensor(ui->extract_sensor_ready);
    extractControll.updateLabelProcess(ui->extract_proc_finished);
    extractControll.updateLcdTime(ui->extract_time_proc);
        });
    // connect cmd button stop process extracting
    connect(ui->stop_extracting_process, &QAbstractButton::pressed, [this]() {
        if (extractControll.getProcessStatus())
        {
            std::cout << "process already finished" << "\n";
            return;
        }
    auto func = QtConcurrent::run([this]() {extractControll.on_stop_extracting_process_clicked();});
        });

    // algorithms
    // move home
    connect(ui->extract_move_home, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&extractingController::on_extract_move_home_clicked, &extractControll);
        });


}

extractingView::~extractingView()
{
}

extractingController* extractingView::getController()
{
    return &extractControll;
}