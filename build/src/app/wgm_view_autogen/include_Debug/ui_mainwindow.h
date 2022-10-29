/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexit;
    QAction *actionwhs_config;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Main;
    QProgressBar *progressBar;
    QListWidget *processList;
    QCommandLinkButton *execute_process;
    QCommandLinkButton *execute_all_processes;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLCDNumber *time_processes;
    QWidget *Heating;
    QCommandLinkButton *run_heating_process;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *temperature;
    QWidget *Sinking;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *distance;
    QCommandLinkButton *execute_delta_subprocess;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLCDNumber *time_sinking;
    QCommandLinkButton *run_sinking_process;
    QWidget *Cnt_Alignment;
    QWidget *Cooling;
    QWidget *Extracting;
    QMenuBar *menubar;
    QMenu *menuMain;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuBuild;
    QMenu *menuDebug;
    QMenu *menuAnalyze;
    QMenu *menuTools;
    QMenu *menuWindow;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1096, 646);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName("actionexit");
        actionwhs_config = new QAction(MainWindow);
        actionwhs_config->setObjectName("actionwhs_config");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMaximumSize(QSize(1900, 1900));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        Main = new QWidget();
        Main->setObjectName("Main");
        progressBar = new QProgressBar(Main);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(190, 440, 701, 71));
        progressBar->setAutoFillBackground(true);
        progressBar->setValue(0);
        processList = new QListWidget(Main);
        new QListWidgetItem(processList);
        new QListWidgetItem(processList);
        new QListWidgetItem(processList);
        new QListWidgetItem(processList);
        new QListWidgetItem(processList);
        processList->setObjectName("processList");
        processList->setGeometry(QRect(200, 40, 251, 131));
        processList->setAutoFillBackground(true);
        execute_process = new QCommandLinkButton(Main);
        execute_process->setObjectName("execute_process");
        execute_process->setGeometry(QRect(10, 30, 187, 41));
        execute_all_processes = new QCommandLinkButton(Main);
        execute_all_processes->setObjectName("execute_all_processes");
        execute_all_processes->setGeometry(QRect(500, 30, 187, 41));
        widget = new QWidget(Main);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(800, 70, 241, 191));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMaximumSize(QSize(500, 16777215));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        time_processes = new QLCDNumber(widget);
        time_processes->setObjectName("time_processes");
        time_processes->setAutoFillBackground(true);

        verticalLayout_4->addWidget(time_processes);

        tabWidget->addTab(Main, QString());
        Heating = new QWidget();
        Heating->setObjectName("Heating");
        run_heating_process = new QCommandLinkButton(Heating);
        run_heating_process->setObjectName("run_heating_process");
        run_heating_process->setGeometry(QRect(40, 60, 187, 41));
        widget1 = new QWidget(Heating);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(730, 80, 311, 141));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(500, 16777215));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        temperature = new QLCDNumber(widget1);
        temperature->setObjectName("temperature");
        temperature->setAutoFillBackground(true);

        verticalLayout->addWidget(temperature);

        tabWidget->addTab(Heating, QString());
        Sinking = new QWidget();
        Sinking->setObjectName("Sinking");
        layoutWidget = new QWidget(Sinking);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(760, 30, 291, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(500, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        distance = new QLCDNumber(layoutWidget);
        distance->setObjectName("distance");
        distance->setMaximumSize(QSize(450, 450));
        distance->setAcceptDrops(false);
        distance->setAutoFillBackground(true);

        verticalLayout_2->addWidget(distance);

        execute_delta_subprocess = new QCommandLinkButton(Sinking);
        execute_delta_subprocess->setObjectName("execute_delta_subprocess");
        execute_delta_subprocess->setGeometry(QRect(20, 40, 221, 51));
        layoutWidget_2 = new QWidget(Sinking);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(770, 200, 291, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(500, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        time_sinking = new QLCDNumber(layoutWidget_2);
        time_sinking->setObjectName("time_sinking");
        time_sinking->setMaximumSize(QSize(450, 450));
        time_sinking->setAcceptDrops(false);
        time_sinking->setAutoFillBackground(true);

        verticalLayout_3->addWidget(time_sinking);

        run_sinking_process = new QCommandLinkButton(Sinking);
        run_sinking_process->setObjectName("run_sinking_process");
        run_sinking_process->setGeometry(QRect(20, 100, 221, 51));
        tabWidget->addTab(Sinking, QString());
        Cnt_Alignment = new QWidget();
        Cnt_Alignment->setObjectName("Cnt_Alignment");
        tabWidget->addTab(Cnt_Alignment, QString());
        Cooling = new QWidget();
        Cooling->setObjectName("Cooling");
        tabWidget->addTab(Cooling, QString());
        Extracting = new QWidget();
        Extracting->setObjectName("Extracting");
        tabWidget->addTab(Extracting, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1096, 26));
        menuMain = new QMenu(menubar);
        menuMain->setObjectName("menuMain");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuBuild = new QMenu(menubar);
        menuBuild->setObjectName("menuBuild");
        menuDebug = new QMenu(menubar);
        menuDebug->setObjectName("menuDebug");
        menuAnalyze = new QMenu(menubar);
        menuAnalyze->setObjectName("menuAnalyze");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName("menuWindow");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMain->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuBuild->menuAction());
        menubar->addAction(menuDebug->menuAction());
        menubar->addAction(menuAnalyze->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuMain->addAction(actionexit);
        menuEdit->addAction(actionwhs_config);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        actionwhs_config->setText(QCoreApplication::translate("MainWindow", "whs_config", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Main</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Main</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)

        const bool __sortingEnabled = processList->isSortingEnabled();
        processList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = processList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Heating", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = processList->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Sinking", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = processList->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Cnt_Alignment", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = processList->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Cooling", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = processList->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Extracting", nullptr));
        processList->setSortingEnabled(__sortingEnabled);

        execute_process->setText(QCoreApplication::translate("MainWindow", "execute process:", nullptr));
        execute_all_processes->setText(QCoreApplication::translate("MainWindow", "execute all", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "time elapsed", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Main), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        run_heating_process->setText(QCoreApplication::translate("MainWindow", "run heating process", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "temperature", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Heating), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "distance", nullptr));
        execute_delta_subprocess->setText(QCoreApplication::translate("MainWindow", "execute delta subprocess", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "time", nullptr));
        run_sinking_process->setText(QCoreApplication::translate("MainWindow", "run sinking process", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Sinking), QCoreApplication::translate("MainWindow", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cnt_Alignment), QCoreApplication::translate("MainWindow", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cooling), QCoreApplication::translate("MainWindow", "Page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Extracting), QCoreApplication::translate("MainWindow", "Page", nullptr));
        menuMain->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuBuild->setTitle(QCoreApplication::translate("MainWindow", "Build", nullptr));
        menuDebug->setTitle(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        menuAnalyze->setTitle(QCoreApplication::translate("MainWindow", "Analyze", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("MainWindow", "Window", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
