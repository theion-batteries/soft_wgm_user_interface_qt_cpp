#include "controller.h"

controller::controller(/* args */)
{
    std::cout << "controller constructed" << std::endl;
}


controller::~controller()
{
}

void controller::generateValues()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 100);
    while (true)
    {
        qInfo() << "running controller infinit loop monitor on thread: " << QThread::currentThread();

        auto new_val = distribution(generator);
        m_value = new_val;
        emit valueChanged(new_val);
        QThread::sleep(2);
        if (exit_flag == true) break;
    }

}

int controller::getValue()
{
    return m_value;
}

sinkingController::sinkingController()
{
    std::cout << "sinking controller constructed" << std::endl;
}

sinkingController::~sinkingController()
{
    std::cout << "sinking controller desctructed" << std::endl;
}

void sinkingController::on_execute_delta_subprocess_clicked()
{

    proc_sinking_model.sinkingProcessHandler->get_sys_obj()->execute_delta_sub();
}

void sinkingController::on_run_sinking_process_clicked()
{
    LcdTime->display(time_elapsed);
    proc_sinking_model.sinkingProcessHandler->start_process();
    time_elapsed = proc_sinking_model.sinkingProcessHandler->get_elapsed_time();
}

void sinkingController::on_stop_sinking_process_clicked()
{
    LcdTime->display(time_elapsed);
    proc_sinking_model.sinkingProcessHandler->stop_process();
    time_elapsed = proc_sinking_model.sinkingProcessHandler->get_elapsed_time();
}
void sinkingController::passLcdNum(QLCDNumber* Lcd)
{
    LcdTime = Lcd;
    LcdTime->display(time_elapsed);
    time_elapsed = 0;
}

void  sinkingController::on_actionwhs_config_triggered()
{
#ifdef WHS_CONFIG
    qInfo() << "opening whs config yaml file in notepad";
    QProcess::startDetached("C:\\Windows\\system32\\notepad.exe", {WHS_CONFIG});
#endif

}
