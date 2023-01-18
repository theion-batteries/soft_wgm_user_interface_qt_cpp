#include "coolingView.h"

coolingView::coolingView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(4, "Cooling");
    ui->ph_connected_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_rotation_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cooling_proc_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_rotation_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->ph_response_status->setStyleSheet("QLabel { background-color : red; color : black; }");
    /**************** signals and slots ********************/

    // connect cmd button connect axis
    connect(ui->connect_motion_axis_ph, &QAbstractButton::pressed, this, [this]() {
        auto connectAxisTask = QtConcurrent::run([this]() {
            coolControll.on_connect_motion_axis_ph_clicked();});
        }, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::axisConnected, this, [this]() {
        coolControll.updateLabelAxis(ui->ph_motion_ready);
    auto func = QtConcurrent::run(&coolingController::updateLcdAxisPosition, &coolControll, ui->ph_axis_linear_value);
        }, Qt::QueuedConnection);

    // connect cmd button connect rotation
    connect(ui->connect_rotation_axis_ph, &QAbstractButton::pressed, this, [this]() {
        auto connectrotTask = QtConcurrent::run([this]() {
            coolControll.on_connect_rotation_axis_ph_clicked();});}, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::rotationConnected, this, [this]() {
        coolControll.updateLabelRotation(ui->ph_rotation_ready);
    auto func = QtConcurrent::run(&coolingController::updateLcdRotationPosition, &coolControll, ui->ph_axis_rotation_value);
        }, Qt::QueuedConnection);

    // connect cmd button connect ph
    connect(ui->connect_ph, &QAbstractButton::pressed, this, [this]() {
        auto connectPhTask = QtConcurrent::run([this]() {
            coolControll.on_connect_ph_clicked();});}, Qt::QueuedConnection);
    connect(&coolControll, &coolingController::phConnected, this, [this]() {
        coolControll.updateLabelPh(ui->cnt_hv_ready);
    std::cout << "main thread id: " << QThread::currentThreadId() << std::endl;
    auto func = QtConcurrent::run(&coolingController::updateLcdPhFrequency, &coolControll, ui->ph_ejet_frequency);
        }, Qt::QueuedConnection);


    // connect enter to send manual cmd to motion axis
    connect(ui->cnt_input_axis_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->cnt_input_axis_cmd->text();
    ui->cnt_axis_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelAxisResponse, &coolControll,ui->cnt_axis_response, inputCmd);
        }, Qt::QueuedConnection);
    // connect axis reply to update text
    connect(&coolControll, &coolingController::axisReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_input_axis_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_input_axis_cmd->setText(reply.c_str());
    ui->cnt_input_axis_cmd->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to rotation
    connect(ui->cnt_input_dispenser, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->cnt_input_dispenser->text();
    ui->cnt_dispenser_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelRotResponse, &coolControll,ui->cnt_dispenser_response, inputCmd);
        }, Qt::QueuedConnection);
   // connect dispenser reply to update text
    connect(&coolControll, &coolingController::rotaryReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_input_dispenser->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_input_dispenser->setText(reply.c_str());
    ui->cnt_input_dispenser->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to ph
    connect(ui->cnt_input_hv_cmd, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->cnt_input_hv_cmd->text();
    ui->cnt_hv_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelPhResponse, &coolControll,ui->cnt_hv_response, inputCmd);
        }, Qt::QueuedConnection);
   // connect hv reply to update text
    connect(&coolControll, &coolingController::phReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_input_hv_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_input_hv_cmd->setText(reply.c_str());
    ui->cnt_input_hv_cmd->clear();
        }, Qt::QueuedConnection);

    /***********       Process   *****/
    // connect cmd button run process sinking
    connect(ui->run_cnt_aligning_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {coolControll.on_run_cooling_process_clicked();});
    coolControll.updateLabelAxis(ui->cnt_motion_ready);
    coolControll.updateLabelRotation(ui->cnt_dispenser_ready);
    coolControll.updateLabelPh(ui->cnt_hv_ready);
    coolControll.updateLabelProcess(ui->cnt_proc_finished);
    coolControll.updateLcdTime(ui->cnt_proc_tim_lcd);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_cnt_proc, &QAbstractButton::pressed, [this]() {
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
    connect(ui->linear_move_home, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_linear_move_home_clicked, &coolControll);
        });
    // dispenser vibrate
    connect(ui->rotation_move_home, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_rotation_move_home_clicked, &coolControll);
        });
    // pulse
    connect(ui->ph_print, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&coolingController::on_ph_print_clicked, &coolControll);
        });







}

coolingView::~coolingView()
{
}
coolingController* coolingView::getController()
{
    return &coolControll;
}