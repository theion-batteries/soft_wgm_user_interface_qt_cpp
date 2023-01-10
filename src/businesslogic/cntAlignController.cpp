#include "cntAlignController.h"

/***************** cntAlign controller *******************/

cntAlignController::cntAlignController()
{
    std::cout << "cntAlign controller constructed" << std::endl;
}

cntAlignController::~cntAlignController()
{
    std::cout << "cntAlign controller desctructed" << std::endl;
}

void cntAlignController::on_cnt_connect_motion_axis_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->connect_motion_axis();
        emit axisConnected();
}

void cntAlignController::on_cnt_connect_dispenser_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->connect_dispenser();
    emit dispenserConnected();
}

void cntAlignController::on_cnt_connect_hv_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->connect_hv();
        emit hvConnected();

}
void cntAlignController::on_run_cnt_aligning_process_clicked()
{
    cntModel.aligningProcessHandler->start_process();
    time_elapsed = cntModel.aligningProcessHandler->get_elapsed_time();
}

void cntAlignController::on_stop_cnt_proc_clicked()
{
    cntModel.aligningProcessHandler->stop_process();
    time_elapsed = cntModel.aligningProcessHandler->get_elapsed_time();
}
void cntAlignController::on_move_down_to_center_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().cnt_motion_move_to_center();
}
void cntAlignController::on_move_back_home_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().cnt_motion_move_home();
}
void cntAlignController::on_dispenser_vibrate_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().cnt_dispenser_vibrate();          
}
void cntAlignController::on_high_voltage_pulse_clicked()
{
    cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()->  pulse();
}

// update lcd

// loop
void cntAlignController::updateLcdDispenserFreq(QLCDNumber* Lcd)
{
    if (get_dispenser_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd dispensr freq" << std::endl;
        Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_dispenser_frequency());
        std::cout << "lcd Dispenser thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(1);
    }

}
void cntAlignController::updateLcdPosition(QLCDNumber* Lcd)
{

    while (get_axis_status()) // while connected, launch thread display
    {
        std::cout << "updating lcd position " << std::endl;
        Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_axis_position());
        std::cout << "lcd position thread id: " << QThread::currentThreadId() << std::endl;
        QThread::currentThread()->sleep(1);
    }
}
// once
void cntAlignController::updateLcdTime(QLCDNumber* Lcd)
{
    Lcd->display(time_elapsed);
    time_elapsed = 0;
}
void cntAlignController::updateLcdInputCurrent(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_input_current());
}

void cntAlignController::updateLcdOutputCurrent(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_output_current());
}
void cntAlignController::updateLcdInputVoltage(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_input_voltage());
}
void cntAlignController::updateLcdOutputVoltage(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_output_voltage());
}
void cntAlignController::updateLcdInputFrequency(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_input_frequency());
}
void cntAlignController::updateLcdOutputFrequency(QLCDNumber* Lcd)
{
    Lcd->display(cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().get_hv_ptr()-> get_output_frequency());
}
// get status
bool cntAlignController::get_axis_status()
{

    return cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysStatus("axis_motion");

}

bool cntAlignController::get_dispenser_status()
{

    return cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysStatus("dispenser");

}

bool cntAlignController::get_hv_status()
{

    return cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysStatus("hv");

}

bool cntAlignController::getProcessStatus()
{
    std::cout << "getting process status" << std::endl;
    return cntModel.aligningProcessHandler->is_proc_success();
}

// label update
void cntAlignController::updateLabelAxis(QLabel* label)
{
    if (get_axis_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
    }

}
void cntAlignController::updateLabelDispenser(QLabel* label)
{
    if (get_dispenser_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
    }

}
void cntAlignController::updateLabelHV(QLabel* label)
{
    if (get_hv_status())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }

}
void cntAlignController::updateLabelProcess(QLabel* label)
{
    if (getProcessStatus())
    {
        label->setText("true");
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        return;
    }

}
void cntAlignController::updateLabelAxisResponse(QLabel* label, QString cmd)
{
    auto response = sendAxisCmd(cmd.toStdString());
    if (response == "ok")
    {
        label->setStyleSheet("QLabel { background-color : green; color : black; }");
        label->setText(response.c_str());
        return;
    }
    label->setText(response.c_str());

}

std::string cntAlignController::sendAxisCmd(std::string Cmd)
{
    return cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().sendDirectCmdAxis(Cmd);
}

void cntAlignController::reload_cnt_config_file()
{
    std::cout << "file closed succefuly, updating parameters" << std::endl;
    cntModel.aligningProcessHandler->get_sys_ptr()->getSubSysController().reload_config_file();
}
