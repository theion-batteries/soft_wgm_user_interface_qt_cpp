#include "cntAlignView.h"

cntAlignView::cntAlignView(Ui::MainWindow* uiPtr)
{
    ui=uiPtr;
    ui->tabWidget->setTabText(3, "Cnt_Alignment");
    ui->cnt_motion_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_dispenser_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_hv_ready->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_axis_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_dispenser_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_hv_response->setStyleSheet("QLabel { background-color : red; color : black; }");
    ui->cnt_proc_finished->setStyleSheet("QLabel { background-color : red; color : black; }");

/**************** signals and slots ********************/
        // connect cmd button connect dispenser
    connect(ui->cnt_connect_dispenser, &QAbstractButton::pressed, [this]() {
        cntControll.on_cnt_connect_dispenser_clicked();
        cntControll.updateLabelDispenser(ui->cnt_dispenser_ready);
        auto func = QtConcurrent::run(&cntAlignController::updateLcdDispenserFreq, &cntControll, ui->cnt_lcd_dispenser_frequency);
        });
    // connect cmd button connect axis
    connect(ui->cnt_connect_motion_axis, &QAbstractButton::pressed, [this]() {
        cntControll.on_cnt_connect_motion_axis_clicked();
        cntControll.updateLabelAxis(ui->cnt_motion_ready);
        std::cout<<"main thread id: "<<QThread::currentThreadId()<< std::endl;
        auto func = QtConcurrent::run(&cntAlignController::updateLcdPosition, &cntControll,ui->cnt_axis_pos);
        });
    // connect cmd button connect hv
    connect(ui->cnt_connect_hv, &QAbstractButton::pressed, [this]() {
        cntControll.on_cnt_connect_hv_clicked();
        cntControll.updateLabelAxis(ui->cnt_hv_ready);
        std::cout<<"main thread id: "<<QThread::currentThreadId()<< std::endl;
        auto func = QtConcurrent::run(&cntAlignController::updateLcdOutputVoltage, &cntControll,ui->cnt_lcd_hv_voltage_out);
        // TOOD
        // add all displays for hv
        });



    // connect cmd button run process sinking
    connect(ui->run_cnt_aligning_process, &QAbstractButton::pressed, [this]() {
        cntControll.on_run_cnt_aligning_process_clicked();
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
            std::cout << "process already finished" <<std::endl;
            return;
        }
        cntControll.on_stop_cnt_proc_clicked();
        });
    // connect enter to send cmd and to clear input
    connect(ui->cnt_input_axis_cmd, &QLineEdit::returnPressed, [this]() {
        auto inputCmd = ui->cnt_input_axis_cmd->text();
        ui->cnt_cmd_given->setText(inputCmd);
        ui->cnt_input_axis_cmd->clear();
        cntControll.updateLabelAxisResponse(ui->cnt_axis_response, inputCmd );
        });
    // algorithms
    // move down to center
    connect(ui->move_down_to_center, &QAbstractButton::pressed, [this]() {
        auto func = QtConcurrent::run(&cntAlignController::on_move_down_to_center_clicked, &cntControll);
        });
    // move home
    connect(ui->move_back_home, &QAbstractButton::pressed, [this]() {
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
 


cntAlignView::~cntAlignView()
{
}