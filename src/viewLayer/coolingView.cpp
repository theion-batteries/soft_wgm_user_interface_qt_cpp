#include "coolingView.h"

coolingView::coolingView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(4, "Cooling");
    ui->ph_connected_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_trigger_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cooling_proc_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_trigger_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_response_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    /**************** signals and slots ********************/
    /************  connect methods           ***********/
    // connect cmd button connect x,y axis
    connect(ui->connect_ph_x_y_motion, &QAbstractButton::pressed, this, [this]() {
        auto connectAxisTask = QtConcurrent::run([this]() {
            coolControll.on_connect_ph_x_y_motion_clicked();});
        }, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::axisConnected, this, [this]() {
        coolControll.updateLabelAxis(ui->ph_motion_ready);
    auto lin = QtConcurrent::run(&coolingController::updateLcdAxisPosition, &coolControll, ui->ph_axis_linear_value);
    auto rot = QtConcurrent::run(&coolingController::updateLcdRotationPosition, &coolControll, ui->ph_axis_rotation_value);
        }, Qt::QueuedConnection);

    // connect cmd button connect trigger
    connect(ui->connect_ph_trigger, &QAbstractButton::pressed, this, [this]() {
        auto connectrotTask = QtConcurrent::run([this]() {
            coolControll.on_connect_ph_trigger_clicked();});}, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::rotationConnected, this, [this]() {
        coolControll.updateLabelTrigger(ui->ph_trigger_ready);
        }, Qt::QueuedConnection);

    // connect cmd button connect ph
    connect(ui->connect_ph_meteor, &QAbstractButton::pressed, this, [this]() {
        auto connectPhTask = QtConcurrent::run([this]() {
            coolControll.on_connect_ph_meteor_clicked();});}, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::phConnected, this, [this]() {
        coolControll.updateLabelPh(ui->ph_connected_status);
    std::cout << "main thread id: " << QThread::currentThreadId() << std::endl;
    auto func = QtConcurrent::run(&coolingController::updateLcdPhFrequency, &coolControll, ui->ph_ejet_frequency);
        }, Qt::QueuedConnection);

/*****************  manual commands section *******************/
    // connect enter to send manual cmd to motion axis
    connect(ui->ph_input_axis_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->ph_input_axis_cmd->text();
    ui->ph_axis_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelAxisResponse, &coolControll,ui->ph_axis_response, inputCmd);
        }, Qt::QueuedConnection);
    // connect axis reply to update text
    connect(&coolControll, &coolingController::axisReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->ph_input_axis_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_axis_cmd->setText(reply.c_str());
    ui->ph_input_axis_cmd->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to rotation
    connect(ui->ph_input_trigger_cmd, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->ph_input_trigger_cmd->text();
    ui->ph_trigger_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelTrigResponse, &coolControll,ui->ph_trigger_response, inputCmd);
        }, Qt::QueuedConnection);
   // connect dispenser reply to update text
    connect(&coolControll, &coolingController::rotaryReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->ph_input_trigger_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_trigger_cmd->setText(reply.c_str());
    ui->ph_input_trigger_cmd->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to ph
    connect(ui->ph_input_cmd_field, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->ph_input_cmd_field->text();
    ui->ph_given_cmd->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelPhResponse, &coolControll,ui->ph_response_status, inputCmd);
        }, Qt::QueuedConnection);
   // connect hv reply to update text
    connect(&coolControll, &coolingController::phReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->ph_input_cmd_field->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_cmd_field->setText(reply.c_str());
    ui->ph_input_cmd_field->clear();
        }, Qt::QueuedConnection);

    /***********       Process   *****/
    // connect cmd button run process sinking
    connect(ui->run_cooling_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {coolControll.on_run_cooling_process_clicked();});
    coolControll.updateLabelAxis(ui->ph_motion_ready);
    coolControll.updateLabelTrigger(ui->ph_trigger_ready);
    coolControll.updateLabelPh(ui->ph_connected_status);
    coolControll.updateLabelProcess(ui->cooling_proc_status);
    coolControll.updateLcdTime(ui->cool_time);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_cooling_process, &QAbstractButton::pressed, [this]() {
        if (coolControll.getProcessStatus())
        {
            std::cout << "process already finished" << std::endl;
            return;
        }
    auto func = QtConcurrent::run([this]() {coolControll.on_stop_cooling_process_clicked();});
        });

    // algorithms
    // move down to center
    connect(ui->ph_move_center, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_move_center_clicked, &coolControll);
        });
    // move home
    connect(ui->ph_motion_xy_move_home, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_motion_xy_move_home_clicked, &coolControll);
        });
    // trigger
    connect(ui->ph_trigger, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_trigger_clicked, &coolControll);
        });
    // rotate
    connect(ui->ph_rotate_center, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_rotate_center_clicked, &coolControll);
        });
    // print
    connect(ui->ph_rotate_print, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_rotate_print_clicked, &coolControll);
        });







}

coolingView::~coolingView()
{
}
coolingController* coolingView::getController()
{
    return &coolControll;
}