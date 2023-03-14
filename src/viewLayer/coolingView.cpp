#include "coolingView.h"

coolingView::coolingView(Ui::MainWindow *uiPtr)
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
    connect(
        ui->connect_ph_x_y_motion, &QAbstractButton::pressed, this, [this]()
        { auto connectAxisTask = QtConcurrent::run([this]()
                                                   { coolControll.on_connect_ph_x_y_motion_clicked(); }); },
        Qt::QueuedConnection);
    connect(
        &coolControll, &coolingController::axisConnected, this, [this]()
        {
            coolControll.updateLabelAxis(ui->ph_motion_ready);
            // auto pos = QtConcurrent::run(&coolingController::updateLcdXYPosition, &coolControll, ui->ph_axis_linear_value, ui->ph_axis_rotation_value);
            // auto vel = QtConcurrent::run(&coolingController::updateLcdXYVelocity, &coolControll, ui->ph_axis_velocity_value, ui->ph_axis_rotation_velocity_value);
            auto all = QtConcurrent::run(&coolingController::updateLcdXY, &coolControll, ui->ph_axis_linear_value, ui->ph_axis_rotation_value, ui->ph_axis_velocity_value, ui->ph_axis_rotation_velocity_value);
        },
        Qt::QueuedConnection);

    // connect cmd button connect trigger
    connect(
        ui->connect_ph_trigger, &QAbstractButton::pressed, this, [this]()
        { auto connectrotTask = QtConcurrent::run([this]()
                                                  { coolControll.on_connect_ph_trigger_clicked(); }); },
        Qt::QueuedConnection);
    connect(
        &coolControll, &coolingController::rotationConnected, this, [this]()
        { coolControll.updateLabelTrigger(ui->ph_trigger_ready); },
        Qt::QueuedConnection);

    // connect cmd button connect ph
    connect(
        ui->connect_ph_meteor, &QAbstractButton::pressed, this, [this]()
        { auto connectPhTask = QtConcurrent::run([this]()
                                                 { coolControll.on_connect_ph_meteor_clicked(); }); },
        Qt::QueuedConnection);
    connect(
        &coolControll, &coolingController::phConnected, this, [this]()
        {
        coolControll.updateLabelPh(ui->ph_connected_status);
    std::cout << "main thread id: " << QThread::currentThreadId() << "\n";
    auto func1 = QtConcurrent::run(&coolingController::updateLcdPhFrequency, &coolControll, ui->ph_ejet_frequency);
    auto func2 = QtConcurrent::run(&coolingController::updateLcdPhDropletVolume, &coolControll, ui->ph_droplet_volume);
    auto func3 = QtConcurrent::run(&coolingController::updateLcdPhLiquidTemperature, &coolControll, ui->ph_liquid_temperature);
    auto func4 = QtConcurrent::run(&coolingController::updateLcdPhNumberActiveNuzzles, &coolControll, ui->ph_number_active_nuzzles); },
        Qt::QueuedConnection);

    /*****************  manual commands section *******************/
    // connect enter to send manual cmd to motion axis
    connect(
        ui->ph_input_axis_cmd, &QLineEdit::returnPressed, this, [this]()
        {
        auto inputCmd = ui->ph_input_axis_cmd->text();
    ui->ph_axis_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelAxisResponse, &coolControll,ui->ph_axis_response, inputCmd); },
        Qt::QueuedConnection);
    // connect axis reply to update text
    connect(
        &coolControll, &coolingController::axisReplied, this, [this](std::string reply)
        {
        std::cout << "axis full response: " << reply << "\n";
    ui->ph_input_axis_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_axis_cmd->setText(reply.c_str());
    ui->ph_input_axis_cmd->clear(); },
        Qt::QueuedConnection);

    // connect enter to send manual cmd to rotation
    connect(
        ui->ph_input_trigger_cmd, &QLineEdit::returnPressed, this, [this]()
        {
        auto inputCmd = ui->ph_input_trigger_cmd->text();
    ui->ph_trigger_cmd_given->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelTrigResponse, &coolControll,ui->ph_trigger_response, inputCmd); },
        Qt::QueuedConnection);
    // connect dispenser reply to update text
    connect(
        &coolControll, &coolingController::rotaryReplied, this, [this](std::string reply)
        {
        std::cout << "axis full response: " << reply << "\n";
    ui->ph_input_trigger_cmd->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_trigger_cmd->setText(reply.c_str());
    ui->ph_input_trigger_cmd->clear(); },
        Qt::QueuedConnection);

    // connect enter to send manual cmd to ph
    connect(
        ui->ph_input_cmd_field, &QLineEdit::returnPressed, this, [this]()
        {
        auto inputCmd = ui->ph_input_cmd_field->text();
    ui->ph_given_cmd->setText(inputCmd);
    auto func = QtConcurrent::run( &coolingController::updateLabelPhResponse, &coolControll,ui->ph_response_status, inputCmd); },
        Qt::QueuedConnection);
    // connect hv reply to update text
    connect(
        &coolControll, &coolingController::phReplied, this, [this](std::string reply)
        {
        std::cout << "axis full response: " << reply << "\n";
    ui->ph_input_cmd_field->setStyleSheet("QLabel { background-color : green; color : black; }");
    ui->ph_input_cmd_field->setText(reply.c_str());
    ui->ph_input_cmd_field->clear(); },
        Qt::QueuedConnection);

    /***********       Process   *****/
    // connect cmd button run process sinking
    connect(ui->run_cooling_process, &QAbstractButton::pressed, [this]()
            {
        auto func = QtConcurrent::run([this]() {coolControll.on_run_cooling_process_clicked();});
    coolControll.updateLabelAxis(ui->ph_motion_ready);
    coolControll.updateLabelTrigger(ui->ph_trigger_ready);
    coolControll.updateLabelPh(ui->ph_connected_status);
    coolControll.updateLabelProcess(ui->cooling_proc_status);
    coolControll.updateLcdTime(ui->cool_time); });
    // connect cmd button stop process sinking
    connect(ui->stop_cooling_process, &QAbstractButton::pressed, [this]()
            {
        if (coolControll.getProcessStatus())
        {
            std::cout << "process already finished" << "\n";
            return;
        }
    auto func = QtConcurrent::run([this]() {coolControll.on_stop_cooling_process_clicked();}); });

    // algorithms
    // move down to center
    connect(ui->ph_motion_move_offset50, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_move_offset_clicked, &coolControll, 50); });

    // rotate to 90 degree
    connect(ui->ph_motion_rotate_90, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_rotate_clicked, &coolControll, 180); });

    // move home
    connect(ui->ph_motion_xy_move_home, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_motion_xy_move_home_clicked, &coolControll); });
   
       // move offset to 135 clicked
    connect(ui->ph_motion_move_offset135, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_move_offset_clicked, &coolControll, 135); });

       // move offset to 2 clicked
    connect(ui->ph_motion_move_offset2, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_move_offset_clicked, &coolControll, 2); });

    // print
    connect(ui->ph_motion_rotate_print, &QAbstractButton::pressed, [this]()
            { auto func = QtConcurrent::run(&coolingController::on_ph_rotate_print_clicked, &coolControll); });


}

coolingView::~coolingView()
{
}
coolingController *coolingView::getController()
{
    return &coolControll;
}