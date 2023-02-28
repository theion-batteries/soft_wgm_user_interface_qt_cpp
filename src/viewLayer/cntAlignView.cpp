#include "cntAlignView.h"

cntAlignView::cntAlignView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(3, "Cnt_Alignment");
    ui->cnt_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_dispenser_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_hv_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_dispenser_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_hv_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_proc_finished->setStyleSheet("QLabel { background-color : red; color : black; }");

    /**************** signals and slots ********************/
    /************  connect methods           ***********/
    // connect cmd button connect axis
    connect(ui->cnt_connect_motion_axis, &QAbstractButton::pressed, this, [this]() {
        auto connectAxisTask = QtConcurrent::run([this]() {
            cntControll.on_cnt_connect_motion_axis_clicked();});
        }, Qt::QueuedConnection);
    connect(&cntControll, &cntAlignController::axisConnected, this, [this]() {
        cntControll.updateLabelAxis(ui->cnt_motion_ready);
    auto func = QtConcurrent::run(&cntAlignController::updateLcdPosition, &cntControll, ui->cnt_axis_pos);
        }, Qt::QueuedConnection);

    // connect cmd button connect dispenser
    connect(ui->cnt_connect_dispenser, &QAbstractButton::pressed, this, [this]() {
        auto connectDispenserTask = QtConcurrent::run([this]() {
            cntControll.on_cnt_connect_dispenser_clicked();});}, Qt::QueuedConnection);
    connect(&cntControll, &cntAlignController::dispenserConnected, this, [this]() {
        cntControll.updateLabelDispenser(ui->cnt_dispenser_ready);
    auto func = QtConcurrent::run(&cntAlignController::updateLcdDispenserFreq, &cntControll, ui->cnt_lcd_dispenser_frequency);
        }, Qt::QueuedConnection);

    // connect cmd button connect hv
    connect(ui->cnt_connect_hv, &QAbstractButton::pressed, this, [this]() {
        auto connectHvTask = QtConcurrent::run([this]() {
            cntControll.on_cnt_connect_hv_clicked();});}, Qt::QueuedConnection);
    connect(&cntControll, &cntAlignController::hvConnected, this, [this]() {
        cntControll.updateLabelAxis(ui->cnt_hv_ready);
    std::cout << "main thread id: " << QThread::currentThreadId() << std::endl;
    auto func = QtConcurrent::run(&cntAlignController::updateLcdOutputVoltage, &cntControll, ui->cnt_lcd_hv_voltage_out);
        }, Qt::QueuedConnection);

/*****************  manual commands section *******************/

    // connect enter to send manual cmd to motion axis
    connect(ui->cnt_input_axis_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->cnt_input_axis_cmd->text();
    ui->cnt_axis_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &cntAlignController::updateLabelAxisResponse, &cntControll,ui->cnt_axis_response, inputCmd);
        }, Qt::QueuedConnection);
    // connect axis reply to update text
    connect(&cntControll, &cntAlignController::axisReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_axis_response->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_axis_response->setText(reply.c_str());
    ui->cnt_input_axis_cmd->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to dispenser
    connect(ui->cnt_input_dispenser, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->cnt_input_dispenser->text();
    ui->cnt_dispenser_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &cntAlignController::updateLabelDispenserResponse, &cntControll,ui->cnt_dispenser_response, inputCmd);
        }, Qt::QueuedConnection);
   // connect dispenser reply to update text
    connect(&cntControll, &cntAlignController::dispenserReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_input_dispenser->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_input_dispenser->setText(reply.c_str());
    ui->cnt_input_dispenser->clear();
        }, Qt::QueuedConnection);

    // connect enter to send manual cmd to hv
    connect(ui->cnt_input_hv_cmd, &QLineEdit::returnPressed,this, [this]() {
        auto inputCmd = ui->cnt_input_hv_cmd->text();
    ui->cnt_hv_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &cntAlignController::updateLabelHvResponse, &cntControll,ui->cnt_hv_response, inputCmd);
        }, Qt::QueuedConnection);
   // connect hv reply to update text
    connect(&cntControll, &cntAlignController::hvReplied, this, [this](std::string reply) {
        std::cout << "axis full response: " << reply << std::endl;
    ui->cnt_input_hv_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->cnt_input_hv_cmd->setText(reply.c_str());
    ui->cnt_input_hv_cmd->clear();
        }, Qt::QueuedConnection);

    /***********       Process   *****/
    // connect cmd button run process sinking
    connect(ui->run_cnt_aligning_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {cntControll.on_run_cnt_aligning_process_clicked();});
    cntControll.updateLabelAxis(ui->cnt_motion_ready);
    cntControll.updateLabelDispenser(ui->cnt_dispenser_ready);
    cntControll.updateLabelHV(ui->cnt_hv_ready);
    cntControll.updateLabelProcess(ui->cnt_proc_finished);
    cntControll.updateLcdTime(ui->cnt_proc_tim_lcd);
        });
    // connect cmd button stop process sinking
    connect(ui->stop_cnt_proc, &QAbstractButton::pressed, [this]() {
        if (cntControll.getProcessStatus())
        {
            std::cout << "process already finished" << std::endl;
            return;
        }
    auto func = QtConcurrent::run([this]() {cntControll.on_stop_cnt_proc_clicked();});
        });

    // algorithms
    // move down to center
    connect(ui->cnt_move_down_center, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&cntAlignController::on_move_down_to_center_clicked, &cntControll);
        });
    // move home
    connect(ui->cnt_move_home, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&cntAlignController::on_move_back_home_clicked, &cntControll);
        });
    // dispenser vibrate
    connect(ui->dispenser_vibrate, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&cntAlignController::on_dispenser_vibrate_clicked, &cntControll);
        });
    // pulse
    connect(ui->high_voltage_pulse, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&cntAlignController::on_high_voltage_pulse_clicked, &cntControll);
        });

}


cntAlignController* cntAlignView::getController()
{
    return &cntControll;
}

cntAlignView::~cntAlignView()
{
}