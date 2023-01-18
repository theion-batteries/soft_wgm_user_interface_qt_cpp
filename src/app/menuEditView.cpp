#include "menuEditView.h"

menuEditView::menuEditView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    /**************** signals and slots ********************/
         // open whs config
    connect(ui->actionwhs_config, &QAction::triggered, [this]() {
        on_actionwhs_config_triggered();
        });         
        // open cnt config
   connect(ui->actioncnt_config, &QAction::triggered, [this]() {
       on_actioncnt_config_triggered();
       });
        // open ph config
connect(ui->actionph_config_yaml, &QAction::triggered, [this]() {
       on_actionph_config_yaml_triggered();
       });
}

menuEditView::~menuEditView()
{
}

void  menuEditView::on_actionwhs_config_triggered()
{
#ifdef WHS_CONFIG

    std::cout << "opening whs config yaml file in notepad: " << WHS_CONFIG<<std::endl;
    whs_config_editor.start("C:\\Windows\\system32\\notepad.exe", { WHS_CONFIG });


#endif
}

void  menuEditView::on_actioncnt_config_triggered()
{
#ifdef CNT_CONFIG

    std::cout << "opening CNT config yaml file in notepad: " << CNT_CONFIG<<std::endl;
    cnt_config_editor.start("C:\\Windows\\system32\\notepad.exe", { CNT_CONFIG });


#endif
}

void  menuEditView::on_actionph_config_yaml_triggered()
{
#ifdef PH_CONFIG

    std::cout << "opening PH config yaml file in notepad: " << PH_CONFIG<<std::endl;
    ph_config_editor.start("C:\\Windows\\system32\\notepad.exe", { PH_CONFIG });


#endif
}
QProcess* menuEditView::getWhsConfigProc()
{
    return &whs_config_editor;
}

QProcess* menuEditView::getCntConfigProc()
{
    return &cnt_config_editor;
}
QProcess* menuEditView::getPhConfigProc()
{
    return &ph_config_editor;
}