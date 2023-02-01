#include "mainView.h"

mainView::mainView(Ui::MainWindow* uiPtr)
{
    ui = uiPtr;
    ui->tabWidget->setTabText(0, "Main");


    /**************** signals and slots ********************/
      // connect select item
    connect(ui->processList, &QListWidget::itemSelectionChanged, this, [this]() {
        std::cout << "process: " << ui->processList->currentItem()->text().toStdString() << " with id: " << ui->processList->currentRow() << " selected " << std::endl;
        }, Qt::QueuedConnection);
    // connect double clik item
    connect(ui->processList, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem* item) {
        std::cout << "process: " << ui->processList->currentItem()->text().toStdString() << " with id: " << ui->processList->currentRow() << " is double clicked and will be executed next.." << std::endl;
    auto func = QtConcurrent::run([this]() {mainControll.execute_process(ui->processList->currentRow());});
        }, Qt::QueuedConnection); // needed for multithreading
    // connect finsihed to update time and bar
    connect(&mainControll, &mainController::finishedProc, this, [this]() {
        mainControll.updateLcdTime(ui->time_processes);
    mainControll.updateProgressBar(ui->progressBar);
        }, Qt::QueuedConnection);

    /**************** On press button exec ***************/
    // connect execute single proc
    connect(ui->execute_process, &QAbstractButton::pressed, this, [this]() {
        if (ui->processList->currentItem() == nullptr) 
        {
         std::cout << "no process selected " << std::endl;
        return;
        }
        if (ui->processList->currentItem()->isSelected()) // if item selected, execute it
        {
            std::cout << "process: " << ui->processList->currentItem()->text().toStdString() << " with id: " << ui->processList->currentRow() << " will be executed" << std::endl;
            auto func = QtConcurrent::run([this]() {mainControll.execute_process(ui->processList->currentRow());});
        }
        }, Qt::QueuedConnection);
    // connect execute all proc
    connect(ui->execute_all_processes, &QAbstractButton::pressed, this, [this]() {
        auto func = QtConcurrent::run([this]() {mainControll.on_execute_all_clicked();});
        }, Qt::QueuedConnection);

    // connect finsihed to update time and bar
    connect(&mainControll, &mainController::finishedAll, this, [this]() {
        mainControll.updateLcdTime(ui->time_processes);
    mainControll.updateProgressBar(ui->progressBar);
        }, Qt::QueuedConnection);


}

mainView::~mainView()
{
}