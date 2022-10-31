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
#include <QtWidgets/QSpacerItem>
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
    QListWidget *processList;
    QCommandLinkButton *execute_process;
    QCommandLinkButton *execute_all_processes;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLCDNumber *time_processes;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QProgressBar *progressBar;
    QLabel *label_5;
    QWidget *Heating;
    QCommandLinkButton *run_heating_process;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *temperature;
    QWidget *Sinking;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *distance_head1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLCDNumber *time_sinking;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QLCDNumber *delta_pos;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLCDNumber *distance_head2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_11;
    QLCDNumber *distance_head3;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QCommandLinkButton *run_sinking_process;
    QSpacerItem *verticalSpacer;
    QCommandLinkButton *stop_sinking_process;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *sinking_finished;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_4;
    QCommandLinkButton *connect_keyence_sensor;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QLabel *keyence_ready;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QCommandLinkButton *execute_delta_subprocess;
    QHBoxLayout *horizontalLayout_3;
    QCommandLinkButton *connect_delta_server;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *delta_ready;
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
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("applications-utilities");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionwhs_config->setIcon(icon);
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
        layoutWidget = new QWidget(Main);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(800, 70, 241, 191));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
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

        time_processes = new QLCDNumber(layoutWidget);
        time_processes->setObjectName("time_processes");
        time_processes->setAutoFillBackground(true);

        verticalLayout_4->addWidget(time_processes);

        layoutWidget1 = new QWidget(Main);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(170, 470, 741, 91));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximumSize(QSize(1000, 50));
        progressBar->setAutoFillBackground(true);
        progressBar->setValue(0);

        verticalLayout_5->addWidget(progressBar);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(600, 20));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        tabWidget->addTab(Main, QString());
        Heating = new QWidget();
        Heating->setObjectName("Heating");
        run_heating_process = new QCommandLinkButton(Heating);
        run_heating_process->setObjectName("run_heating_process");
        run_heating_process->setGeometry(QRect(40, 60, 187, 41));
        layoutWidget2 = new QWidget(Heating);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(730, 80, 311, 141));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(200);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(500, 16777215));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        temperature = new QLCDNumber(layoutWidget2);
        temperature->setObjectName("temperature");
        temperature->setAutoFillBackground(true);

        verticalLayout->addWidget(temperature);

        tabWidget->addTab(Heating, QString());
        Sinking = new QWidget();
        Sinking->setObjectName("Sinking");
        layoutWidget3 = new QWidget(Sinking);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(510, 10, 258, 403));
        verticalLayout_11 = new QVBoxLayout(layoutWidget3);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(500, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        distance_head1 = new QLCDNumber(layoutWidget3);
        distance_head1->setObjectName("distance_head1");
        sizePolicy.setHeightForWidth(distance_head1->sizePolicy().hasHeightForWidth());
        distance_head1->setSizePolicy(sizePolicy);
        distance_head1->setMinimumSize(QSize(200, 100));
        distance_head1->setMaximumSize(QSize(450, 450));
        distance_head1->setAcceptDrops(false);
        distance_head1->setAutoFillBackground(true);

        verticalLayout_2->addWidget(distance_head1);


        verticalLayout_11->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(500, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        time_sinking = new QLCDNumber(layoutWidget3);
        time_sinking->setObjectName("time_sinking");
        sizePolicy.setHeightForWidth(time_sinking->sizePolicy().hasHeightForWidth());
        time_sinking->setSizePolicy(sizePolicy);
        time_sinking->setMinimumSize(QSize(100, 100));
        time_sinking->setMaximumSize(QSize(450, 450));
        time_sinking->setAcceptDrops(false);
        time_sinking->setAutoFillBackground(true);

        verticalLayout_3->addWidget(time_sinking);


        verticalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(500, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        delta_pos = new QLCDNumber(layoutWidget3);
        delta_pos->setObjectName("delta_pos");
        sizePolicy.setHeightForWidth(delta_pos->sizePolicy().hasHeightForWidth());
        delta_pos->setSizePolicy(sizePolicy);
        delta_pos->setMinimumSize(QSize(100, 100));
        delta_pos->setMaximumSize(QSize(450, 450));
        delta_pos->setAcceptDrops(false);
        delta_pos->setAutoFillBackground(true);

        verticalLayout_7->addWidget(delta_pos);


        verticalLayout_11->addLayout(verticalLayout_7);

        layoutWidget4 = new QWidget(Sinking);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(799, 11, 258, 267));
        verticalLayout_13 = new QVBoxLayout(layoutWidget4);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName("label_10");
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(500, 16777215));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_10);

        distance_head2 = new QLCDNumber(layoutWidget4);
        distance_head2->setObjectName("distance_head2");
        sizePolicy.setHeightForWidth(distance_head2->sizePolicy().hasHeightForWidth());
        distance_head2->setSizePolicy(sizePolicy);
        distance_head2->setMinimumSize(QSize(200, 100));
        distance_head2->setMaximumSize(QSize(450, 450));
        distance_head2->setAcceptDrops(false);
        distance_head2->setAutoFillBackground(true);

        verticalLayout_6->addWidget(distance_head2);


        verticalLayout_13->addLayout(verticalLayout_6);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName("label_11");
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMaximumSize(QSize(500, 16777215));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_11);

        distance_head3 = new QLCDNumber(layoutWidget4);
        distance_head3->setObjectName("distance_head3");
        sizePolicy.setHeightForWidth(distance_head3->sizePolicy().hasHeightForWidth());
        distance_head3->setSizePolicy(sizePolicy);
        distance_head3->setMinimumSize(QSize(200, 100));
        distance_head3->setMaximumSize(QSize(450, 450));
        distance_head3->setAcceptDrops(false);
        distance_head3->setAutoFillBackground(true);

        verticalLayout_12->addWidget(distance_head3);


        verticalLayout_13->addLayout(verticalLayout_12);

        layoutWidget5 = new QWidget(Sinking);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(20, 290, 432, 110));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        run_sinking_process = new QCommandLinkButton(layoutWidget5);
        run_sinking_process->setObjectName("run_sinking_process");
        sizePolicy.setHeightForWidth(run_sinking_process->sizePolicy().hasHeightForWidth());
        run_sinking_process->setSizePolicy(sizePolicy);
        run_sinking_process->setMinimumSize(QSize(100, 10));

        verticalLayout_8->addWidget(run_sinking_process);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer);

        stop_sinking_process = new QCommandLinkButton(layoutWidget5);
        stop_sinking_process->setObjectName("stop_sinking_process");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stop_sinking_process->sizePolicy().hasHeightForWidth());
        stop_sinking_process->setSizePolicy(sizePolicy2);

        verticalLayout_8->addWidget(stop_sinking_process);


        horizontalLayout_6->addLayout(verticalLayout_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName("label_9");

        horizontalLayout_5->addWidget(label_9);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sinking_finished = new QLabel(layoutWidget5);
        sinking_finished->setObjectName("sinking_finished");
        sizePolicy.setHeightForWidth(sinking_finished->sizePolicy().hasHeightForWidth());
        sinking_finished->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(sinking_finished);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        layoutWidget6 = new QWidget(Sinking);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(20, 170, 441, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        connect_keyence_sensor = new QCommandLinkButton(layoutWidget6);
        connect_keyence_sensor->setObjectName("connect_keyence_sensor");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(100);
        sizePolicy3.setHeightForWidth(connect_keyence_sensor->sizePolicy().hasHeightForWidth());
        connect_keyence_sensor->setSizePolicy(sizePolicy3);
        connect_keyence_sensor->setMinimumSize(QSize(100, 10));

        horizontalLayout_4->addWidget(connect_keyence_sensor);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_8 = new QLabel(layoutWidget6);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        keyence_ready = new QLabel(layoutWidget6);
        keyence_ready->setObjectName("keyence_ready");
        sizePolicy.setHeightForWidth(keyence_ready->sizePolicy().hasHeightForWidth());
        keyence_ready->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(keyence_ready);

        layoutWidget7 = new QWidget(Sinking);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(20, 50, 441, 91));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        execute_delta_subprocess = new QCommandLinkButton(layoutWidget7);
        execute_delta_subprocess->setObjectName("execute_delta_subprocess");
        sizePolicy.setHeightForWidth(execute_delta_subprocess->sizePolicy().hasHeightForWidth());
        execute_delta_subprocess->setSizePolicy(sizePolicy);
        execute_delta_subprocess->setMinimumSize(QSize(100, 10));

        horizontalLayout_2->addWidget(execute_delta_subprocess);


        verticalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        connect_delta_server = new QCommandLinkButton(layoutWidget7);
        connect_delta_server->setObjectName("connect_delta_server");
        sizePolicy.setHeightForWidth(connect_delta_server->sizePolicy().hasHeightForWidth());
        connect_delta_server->setSizePolicy(sizePolicy);
        connect_delta_server->setMinimumSize(QSize(100, 10));

        horizontalLayout_3->addWidget(connect_delta_server);


        verticalLayout_9->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget7);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        delta_ready = new QLabel(layoutWidget7);
        delta_ready->setObjectName("delta_ready");
        sizePolicy.setHeightForWidth(delta_ready->sizePolicy().hasHeightForWidth());
        delta_ready->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(delta_ready);


        horizontalLayout_8->addLayout(horizontalLayout_7);

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
        actionwhs_config->setText(QCoreApplication::translate("MainWindow", "whs_config.yaml", nullptr));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "time elapsed (sec)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "overall progress", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Main), QCoreApplication::translate("MainWindow", "Main", nullptr));
        run_heating_process->setText(QCoreApplication::translate("MainWindow", "run heating process", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "temperature (\302\260C)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Heating), QCoreApplication::translate("MainWindow", "Heating", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "keyence mesured distance head1(mm)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "process time elapsed (sec)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "delta current position (mm)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "keyence mesured distance head2(mm)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "keyence mesured distance head2(mm)", nullptr));
        run_sinking_process->setText(QCoreApplication::translate("MainWindow", "run sinking process", nullptr));
        stop_sinking_process->setText(QCoreApplication::translate("MainWindow", "stop sinking process", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "process_finished", nullptr));
        sinking_finished->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        connect_keyence_sensor->setText(QCoreApplication::translate("MainWindow", "connect keyence Sensor", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "keyence_ready", nullptr));
        keyence_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        execute_delta_subprocess->setText(QCoreApplication::translate("MainWindow", "execute delta subprocess", nullptr));
        connect_delta_server->setText(QCoreApplication::translate("MainWindow", "connect delta server", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "delta_ready", nullptr));
        delta_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Sinking), QCoreApplication::translate("MainWindow", "Sinking", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cnt_Alignment), QCoreApplication::translate("MainWindow", "Cnt_Alignment", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cooling), QCoreApplication::translate("MainWindow", "Cooling", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Extracting), QCoreApplication::translate("MainWindow", "Extracting", nullptr));
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
