#include "heatingView.h"

heatingView::heatingView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(1, "Heating");
    ui->heating_ready_bool->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->heat_cmd_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->heating_process_status->setStyleSheet("QLabel { background-color : red; color : black; }");

    /**************** signals and slots ********************/
    /************  connect methods           ***********/

          // connect cmd button connect heater
    connect(ui->connect_heating_dev, &QAbstractButton::pressed, this, [this]() {
        auto connectTask = QtConcurrent::run([this]() {
            heatControll.on_connect_heating_dev_clicked();});
        }, Qt::QueuedConnection);
    connect(&heatControll, &heatingController::heaterConnected, this, [this]() {
        heatControll.updateLabelHeater(ui->heating_ready_bool);});
/*****************  manual commands section *******************/

    // connect enter to send manual cmd to heater
    connect(ui->heat_input_cmd, &QLineEdit::returnPressed, this, [this]() {
        auto inputCmd = ui->heat_input_cmd->text();
    ui->heat_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run(&heatingController::updateLabelHeater, &heatControll, ui->heat_cmd_response);
        }, Qt::QueuedConnection);
    // connect heater reply to update text
    connect(&heatControll, &heatingController::heaterReplied, this, [this](std::string reply) {
        std::cout << " full response: " << reply << std::endl;
    ui->heat_input_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->heat_input_cmd->setText(reply.c_str());
    ui->heat_input_cmd->clear();
        }, Qt::QueuedConnection);

    /***********       Process   *****/
    // connect cmd button run process heating
    connect(ui->run_heating_process, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run([this]() {heatControll.on_run_heating_process_clicked();});
    heatControll.updateLabelHeater(ui->heating_ready_label);
    heatControll.updateLabelProcess(ui->heating_process_status);
    heatControll.updateLcdTime(ui->lcd_proc_heating_time);
        });
    // connect cmd button stop process heating
    connect(ui->stop_heating_proc, &QAbstractButton::pressed, [this]() {
        if (heatControll.getProcessStatus())
        {
            std::cout << "process already finished" << std::endl;
            return;
        }
    auto func = QtConcurrent::run([this]() {heatControll.on_stop_heating_proc_clicked();});
        });

    // algorithms
    // on
    connect(ui->start_heating, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&heatingController::on_start_heating_clicked, &heatControll);
        });
    // off
    connect(ui->stop_heating, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&heatingController::on_stop_heating_clicked, &heatControll);
        });


}

heatingView::~heatingView()
{
}

heatingController* heatingView::getController()
{
    return &heatControll;
}
