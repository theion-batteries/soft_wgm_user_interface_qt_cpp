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
#include <QtWidgets/QLineEdit>
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
    QAction *actiondocumentation;
    QAction *actiongrbl;
    QAction *actionopen_debug_console;
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
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QCommandLinkButton *sink_connect_motion_axis;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *sink_motion_ready;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *sink_input_axis_cmd;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *cmd_given_1;
    QSpacerItem *horizontalSpacer_11;
    QLabel *sink_cmd_given;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_9;
    QLabel *sink_axis_response;
    QHBoxLayout *horizontalLayout_4;
    QCommandLinkButton *sink_connect_distance_sensor;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QLabel *sink_sensor_ready;
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
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *sink_distance_head1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLCDNumber *sink_time;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QLCDNumber *sink_axis_pos;
    QWidget *Cnt_Alignment;
    QHBoxLayout *horizontalLayout_32;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_14;
    QCommandLinkButton *connect_motion_axis_2;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_13;
    QLabel *cnt_motion_ready;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *cnt_input_axis_cmd;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *cmd_given_2;
    QSpacerItem *horizontalSpacer_16;
    QLabel *cnt_axis_cmd_given;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_17;
    QLabel *cnt_axis_response;
    QHBoxLayout *horizontalLayout_18;
    QCommandLinkButton *connect_distance_sensor_2;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_19;
    QLabel *cnt_dispenser_ready;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_29;
    QLineEdit *cnt_input_axis_cmd_3;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *horizontalLayout_26;
    QHBoxLayout *horizontalLayout_27;
    QLabel *cmd_given_4;
    QSpacerItem *horizontalSpacer_31;
    QLabel *cnt_axis_cmd_given_3;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_32;
    QLabel *cnt_axis_response_3;
    QHBoxLayout *horizontalLayout_24;
    QCommandLinkButton *connect_distance_sensor_3;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_28;
    QLabel *cnt_dispenser_ready_2;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_23;
    QLineEdit *cnt_input_axis_cmd_2;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_23;
    QLabel *cmd_given_3;
    QSpacerItem *horizontalSpacer_25;
    QLabel *cnt_axis_cmd_given_2;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_26;
    QLabel *cnt_axis_response_2;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_13;
    QCommandLinkButton *run_sinking_process_2;
    QSpacerItem *verticalSpacer_2;
    QCommandLinkButton *stop_sinking_process_2;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_21;
    QLabel *cnt_proc_finished;
    QSpacerItem *horizontalSpacer_22;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_17;
    QLCDNumber *cnt_view_frequency;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_19;
    QLCDNumber *cnt_axis_pos;
    QHBoxLayout *horizontalLayout_28;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_26;
    QLCDNumber *cnt_view_frequency_3;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_27;
    QLCDNumber *cnt_view_frequency_4;
    QHBoxLayout *horizontalLayout_29;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_28;
    QLCDNumber *cnt_view_frequency_5;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_29;
    QLCDNumber *cnt_view_frequency_6;
    QHBoxLayout *horizontalLayout_30;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_30;
    QLCDNumber *cnt_view_frequency_7;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_31;
    QLCDNumber *cnt_view_frequency_8;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_18;
    QLCDNumber *sink_time_2;
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
        MainWindow->resize(1362, 780);
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
        actiondocumentation = new QAction(MainWindow);
        actiondocumentation->setObjectName("actiondocumentation");
        actiongrbl = new QAction(MainWindow);
        actiongrbl->setObjectName("actiongrbl");
        actionopen_debug_console = new QAction(MainWindow);
        actionopen_debug_console->setObjectName("actionopen_debug_console");
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
        processList->setMouseTracking(false);
        processList->setFocusPolicy(Qt::NoFocus);
        processList->setAutoFillBackground(true);
        processList->setAutoScroll(true);
        processList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        processList->setSelectionMode(QAbstractItemView::SingleSelection);
        processList->setSelectionBehavior(QAbstractItemView::SelectItems);
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
        horizontalLayout_7 = new QHBoxLayout(Sinking);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        sink_connect_motion_axis = new QCommandLinkButton(Sinking);
        sink_connect_motion_axis->setObjectName("sink_connect_motion_axis");
        sizePolicy.setHeightForWidth(sink_connect_motion_axis->sizePolicy().hasHeightForWidth());
        sink_connect_motion_axis->setSizePolicy(sizePolicy);
        sink_connect_motion_axis->setMinimumSize(QSize(100, 10));

        horizontalLayout_3->addWidget(sink_connect_motion_axis);


        verticalLayout_9->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        label_7 = new QLabel(Sinking);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        sink_motion_ready = new QLabel(Sinking);
        sink_motion_ready->setObjectName("sink_motion_ready");
        sizePolicy.setHeightForWidth(sink_motion_ready->sizePolicy().hasHeightForWidth());
        sink_motion_ready->setSizePolicy(sizePolicy);
        sink_motion_ready->setAutoFillBackground(true);

        horizontalLayout_8->addWidget(sink_motion_ready);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_10 = new QLabel(Sinking);
        label_10->setObjectName("label_10");

        horizontalLayout_9->addWidget(label_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        sink_input_axis_cmd = new QLineEdit(Sinking);
        sink_input_axis_cmd->setObjectName("sink_input_axis_cmd");
        sink_input_axis_cmd->setContextMenuPolicy(Qt::NoContextMenu);
        sink_input_axis_cmd->setClearButtonEnabled(true);

        horizontalLayout_9->addWidget(sink_input_axis_cmd);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        cmd_given_1 = new QLabel(Sinking);
        cmd_given_1->setObjectName("cmd_given_1");

        horizontalLayout_10->addWidget(cmd_given_1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        sink_cmd_given = new QLabel(Sinking);
        sink_cmd_given->setObjectName("sink_cmd_given");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sink_cmd_given->sizePolicy().hasHeightForWidth());
        sink_cmd_given->setSizePolicy(sizePolicy2);
        sink_cmd_given->setMinimumSize(QSize(100, 50));
        sink_cmd_given->setAutoFillBackground(true);

        horizontalLayout_10->addWidget(sink_cmd_given);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        horizontalLayout_9->addLayout(horizontalLayout_11);

        label_11 = new QLabel(Sinking);
        label_11->setObjectName("label_11");

        horizontalLayout_9->addWidget(label_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        sink_axis_response = new QLabel(Sinking);
        sink_axis_response->setObjectName("sink_axis_response");
        sizePolicy2.setHeightForWidth(sink_axis_response->sizePolicy().hasHeightForWidth());
        sink_axis_response->setSizePolicy(sizePolicy2);
        sink_axis_response->setMinimumSize(QSize(30, 50));
        sink_axis_response->setAutoFillBackground(true);

        horizontalLayout_9->addWidget(sink_axis_response);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sink_connect_distance_sensor = new QCommandLinkButton(Sinking);
        sink_connect_distance_sensor->setObjectName("sink_connect_distance_sensor");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(100);
        sizePolicy3.setHeightForWidth(sink_connect_distance_sensor->sizePolicy().hasHeightForWidth());
        sink_connect_distance_sensor->setSizePolicy(sizePolicy3);
        sink_connect_distance_sensor->setMinimumSize(QSize(100, 10));

        horizontalLayout_4->addWidget(sink_connect_distance_sensor);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_8 = new QLabel(Sinking);
        label_8->setObjectName("label_8");

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        sink_sensor_ready = new QLabel(Sinking);
        sink_sensor_ready->setObjectName("sink_sensor_ready");
        sizePolicy.setHeightForWidth(sink_sensor_ready->sizePolicy().hasHeightForWidth());
        sink_sensor_ready->setSizePolicy(sizePolicy);
        sink_sensor_ready->setAutoFillBackground(true);

        horizontalLayout_4->addWidget(sink_sensor_ready);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        run_sinking_process = new QCommandLinkButton(Sinking);
        run_sinking_process->setObjectName("run_sinking_process");
        sizePolicy.setHeightForWidth(run_sinking_process->sizePolicy().hasHeightForWidth());
        run_sinking_process->setSizePolicy(sizePolicy);
        run_sinking_process->setMinimumSize(QSize(100, 10));

        verticalLayout_8->addWidget(run_sinking_process);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer);

        stop_sinking_process = new QCommandLinkButton(Sinking);
        stop_sinking_process->setObjectName("stop_sinking_process");
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stop_sinking_process->sizePolicy().hasHeightForWidth());
        stop_sinking_process->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(stop_sinking_process);


        horizontalLayout_6->addLayout(verticalLayout_8);

        horizontalSpacer_6 = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_9 = new QLabel(Sinking);
        label_9->setObjectName("label_9");

        horizontalLayout_5->addWidget(label_9);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sinking_finished = new QLabel(Sinking);
        sinking_finished->setObjectName("sinking_finished");
        sizePolicy.setHeightForWidth(sinking_finished->sizePolicy().hasHeightForWidth());
        sinking_finished->setSizePolicy(sizePolicy);
        sinking_finished->setAutoFillBackground(true);

        horizontalLayout_5->addWidget(sinking_finished);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(Sinking);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(500, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        sink_distance_head1 = new QLCDNumber(Sinking);
        sink_distance_head1->setObjectName("sink_distance_head1");
        sizePolicy.setHeightForWidth(sink_distance_head1->sizePolicy().hasHeightForWidth());
        sink_distance_head1->setSizePolicy(sizePolicy);
        sink_distance_head1->setMinimumSize(QSize(200, 100));
        sink_distance_head1->setMaximumSize(QSize(450, 450));
        sink_distance_head1->setAcceptDrops(false);
        sink_distance_head1->setAutoFillBackground(true);

        verticalLayout_2->addWidget(sink_distance_head1);


        verticalLayout_11->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(Sinking);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(500, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        sink_time = new QLCDNumber(Sinking);
        sink_time->setObjectName("sink_time");
        sizePolicy.setHeightForWidth(sink_time->sizePolicy().hasHeightForWidth());
        sink_time->setSizePolicy(sizePolicy);
        sink_time->setMinimumSize(QSize(100, 100));
        sink_time->setMaximumSize(QSize(450, 450));
        sink_time->setAcceptDrops(false);
        sink_time->setAutoFillBackground(true);

        verticalLayout_3->addWidget(sink_time);


        verticalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(Sinking);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(500, 16777215));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        sink_axis_pos = new QLCDNumber(Sinking);
        sink_axis_pos->setObjectName("sink_axis_pos");
        sizePolicy.setHeightForWidth(sink_axis_pos->sizePolicy().hasHeightForWidth());
        sink_axis_pos->setSizePolicy(sizePolicy);
        sink_axis_pos->setMinimumSize(QSize(100, 100));
        sink_axis_pos->setMaximumSize(QSize(450, 450));
        sink_axis_pos->setAcceptDrops(false);
        sink_axis_pos->setAutoFillBackground(true);

        verticalLayout_7->addWidget(sink_axis_pos);


        verticalLayout_11->addLayout(verticalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_11);


        horizontalLayout_7->addLayout(horizontalLayout_2);

        tabWidget->addTab(Sinking, QString());
        Cnt_Alignment = new QWidget();
        Cnt_Alignment->setObjectName("Cnt_Alignment");
        horizontalLayout_32 = new QHBoxLayout(Cnt_Alignment);
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        connect_motion_axis_2 = new QCommandLinkButton(Cnt_Alignment);
        connect_motion_axis_2->setObjectName("connect_motion_axis_2");
        sizePolicy.setHeightForWidth(connect_motion_axis_2->sizePolicy().hasHeightForWidth());
        connect_motion_axis_2->setSizePolicy(sizePolicy);
        connect_motion_axis_2->setMinimumSize(QSize(100, 10));

        horizontalLayout_14->addWidget(connect_motion_axis_2);


        verticalLayout_12->addLayout(horizontalLayout_14);


        horizontalLayout_13->addLayout(verticalLayout_12);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);

        label_12 = new QLabel(Cnt_Alignment);
        label_12->setObjectName("label_12");

        horizontalLayout_13->addWidget(label_12);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);

        cnt_motion_ready = new QLabel(Cnt_Alignment);
        cnt_motion_ready->setObjectName("cnt_motion_ready");
        sizePolicy.setHeightForWidth(cnt_motion_ready->sizePolicy().hasHeightForWidth());
        cnt_motion_ready->setSizePolicy(sizePolicy);
        cnt_motion_ready->setAutoFillBackground(true);

        horizontalLayout_13->addWidget(cnt_motion_ready);


        verticalLayout_10->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_13 = new QLabel(Cnt_Alignment);
        label_13->setObjectName("label_13");

        horizontalLayout_15->addWidget(label_13);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);

        cnt_input_axis_cmd = new QLineEdit(Cnt_Alignment);
        cnt_input_axis_cmd->setObjectName("cnt_input_axis_cmd");
        cnt_input_axis_cmd->setContextMenuPolicy(Qt::NoContextMenu);
        cnt_input_axis_cmd->setClearButtonEnabled(true);

        horizontalLayout_15->addWidget(cnt_input_axis_cmd);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        cmd_given_2 = new QLabel(Cnt_Alignment);
        cmd_given_2->setObjectName("cmd_given_2");

        horizontalLayout_17->addWidget(cmd_given_2);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_16);

        cnt_axis_cmd_given = new QLabel(Cnt_Alignment);
        cnt_axis_cmd_given->setObjectName("cnt_axis_cmd_given");
        sizePolicy2.setHeightForWidth(cnt_axis_cmd_given->sizePolicy().hasHeightForWidth());
        cnt_axis_cmd_given->setSizePolicy(sizePolicy2);
        cnt_axis_cmd_given->setMinimumSize(QSize(100, 50));
        cnt_axis_cmd_given->setAutoFillBackground(true);

        horizontalLayout_17->addWidget(cnt_axis_cmd_given);


        horizontalLayout_16->addLayout(horizontalLayout_17);


        horizontalLayout_15->addLayout(horizontalLayout_16);

        label_14 = new QLabel(Cnt_Alignment);
        label_14->setObjectName("label_14");

        horizontalLayout_15->addWidget(label_14);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_17);

        cnt_axis_response = new QLabel(Cnt_Alignment);
        cnt_axis_response->setObjectName("cnt_axis_response");
        sizePolicy2.setHeightForWidth(cnt_axis_response->sizePolicy().hasHeightForWidth());
        cnt_axis_response->setSizePolicy(sizePolicy2);
        cnt_axis_response->setMinimumSize(QSize(30, 50));
        cnt_axis_response->setAutoFillBackground(true);

        horizontalLayout_15->addWidget(cnt_axis_response);


        verticalLayout_10->addLayout(horizontalLayout_15);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        connect_distance_sensor_2 = new QCommandLinkButton(Cnt_Alignment);
        connect_distance_sensor_2->setObjectName("connect_distance_sensor_2");
        sizePolicy3.setHeightForWidth(connect_distance_sensor_2->sizePolicy().hasHeightForWidth());
        connect_distance_sensor_2->setSizePolicy(sizePolicy3);
        connect_distance_sensor_2->setMinimumSize(QSize(100, 10));

        horizontalLayout_18->addWidget(connect_distance_sensor_2);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_18);

        label_15 = new QLabel(Cnt_Alignment);
        label_15->setObjectName("label_15");

        horizontalLayout_18->addWidget(label_15);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_19);

        cnt_dispenser_ready = new QLabel(Cnt_Alignment);
        cnt_dispenser_ready->setObjectName("cnt_dispenser_ready");
        sizePolicy.setHeightForWidth(cnt_dispenser_ready->sizePolicy().hasHeightForWidth());
        cnt_dispenser_ready->setSizePolicy(sizePolicy);
        cnt_dispenser_ready->setAutoFillBackground(true);

        horizontalLayout_18->addWidget(cnt_dispenser_ready);


        verticalLayout_10->addLayout(horizontalLayout_18);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        label_23 = new QLabel(Cnt_Alignment);
        label_23->setObjectName("label_23");

        horizontalLayout_25->addWidget(label_23);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_29);

        cnt_input_axis_cmd_3 = new QLineEdit(Cnt_Alignment);
        cnt_input_axis_cmd_3->setObjectName("cnt_input_axis_cmd_3");
        cnt_input_axis_cmd_3->setContextMenuPolicy(Qt::NoContextMenu);
        cnt_input_axis_cmd_3->setClearButtonEnabled(true);

        horizontalLayout_25->addWidget(cnt_input_axis_cmd_3);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_30);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        cmd_given_4 = new QLabel(Cnt_Alignment);
        cmd_given_4->setObjectName("cmd_given_4");

        horizontalLayout_27->addWidget(cmd_given_4);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_31);

        cnt_axis_cmd_given_3 = new QLabel(Cnt_Alignment);
        cnt_axis_cmd_given_3->setObjectName("cnt_axis_cmd_given_3");
        sizePolicy2.setHeightForWidth(cnt_axis_cmd_given_3->sizePolicy().hasHeightForWidth());
        cnt_axis_cmd_given_3->setSizePolicy(sizePolicy2);
        cnt_axis_cmd_given_3->setMinimumSize(QSize(100, 50));
        cnt_axis_cmd_given_3->setAutoFillBackground(true);

        horizontalLayout_27->addWidget(cnt_axis_cmd_given_3);


        horizontalLayout_26->addLayout(horizontalLayout_27);


        horizontalLayout_25->addLayout(horizontalLayout_26);

        label_24 = new QLabel(Cnt_Alignment);
        label_24->setObjectName("label_24");

        horizontalLayout_25->addWidget(label_24);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_32);

        cnt_axis_response_3 = new QLabel(Cnt_Alignment);
        cnt_axis_response_3->setObjectName("cnt_axis_response_3");
        sizePolicy2.setHeightForWidth(cnt_axis_response_3->sizePolicy().hasHeightForWidth());
        cnt_axis_response_3->setSizePolicy(sizePolicy2);
        cnt_axis_response_3->setMinimumSize(QSize(30, 50));
        cnt_axis_response_3->setAutoFillBackground(true);

        horizontalLayout_25->addWidget(cnt_axis_response_3);


        verticalLayout_10->addLayout(horizontalLayout_25);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        connect_distance_sensor_3 = new QCommandLinkButton(Cnt_Alignment);
        connect_distance_sensor_3->setObjectName("connect_distance_sensor_3");
        sizePolicy3.setHeightForWidth(connect_distance_sensor_3->sizePolicy().hasHeightForWidth());
        connect_distance_sensor_3->setSizePolicy(sizePolicy3);
        connect_distance_sensor_3->setMinimumSize(QSize(100, 10));

        horizontalLayout_24->addWidget(connect_distance_sensor_3);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_27);

        label_22 = new QLabel(Cnt_Alignment);
        label_22->setObjectName("label_22");

        horizontalLayout_24->addWidget(label_22);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_28);

        cnt_dispenser_ready_2 = new QLabel(Cnt_Alignment);
        cnt_dispenser_ready_2->setObjectName("cnt_dispenser_ready_2");
        sizePolicy.setHeightForWidth(cnt_dispenser_ready_2->sizePolicy().hasHeightForWidth());
        cnt_dispenser_ready_2->setSizePolicy(sizePolicy);
        cnt_dispenser_ready_2->setAutoFillBackground(true);

        horizontalLayout_24->addWidget(cnt_dispenser_ready_2);


        verticalLayout_10->addLayout(horizontalLayout_24);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_20 = new QLabel(Cnt_Alignment);
        label_20->setObjectName("label_20");

        horizontalLayout_21->addWidget(label_20);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_23);

        cnt_input_axis_cmd_2 = new QLineEdit(Cnt_Alignment);
        cnt_input_axis_cmd_2->setObjectName("cnt_input_axis_cmd_2");
        cnt_input_axis_cmd_2->setContextMenuPolicy(Qt::NoContextMenu);
        cnt_input_axis_cmd_2->setClearButtonEnabled(true);

        horizontalLayout_21->addWidget(cnt_input_axis_cmd_2);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_24);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        cmd_given_3 = new QLabel(Cnt_Alignment);
        cmd_given_3->setObjectName("cmd_given_3");

        horizontalLayout_23->addWidget(cmd_given_3);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_25);

        cnt_axis_cmd_given_2 = new QLabel(Cnt_Alignment);
        cnt_axis_cmd_given_2->setObjectName("cnt_axis_cmd_given_2");
        sizePolicy2.setHeightForWidth(cnt_axis_cmd_given_2->sizePolicy().hasHeightForWidth());
        cnt_axis_cmd_given_2->setSizePolicy(sizePolicy2);
        cnt_axis_cmd_given_2->setMinimumSize(QSize(100, 50));
        cnt_axis_cmd_given_2->setAutoFillBackground(true);

        horizontalLayout_23->addWidget(cnt_axis_cmd_given_2);


        horizontalLayout_22->addLayout(horizontalLayout_23);


        horizontalLayout_21->addLayout(horizontalLayout_22);

        label_21 = new QLabel(Cnt_Alignment);
        label_21->setObjectName("label_21");

        horizontalLayout_21->addWidget(label_21);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_26);

        cnt_axis_response_2 = new QLabel(Cnt_Alignment);
        cnt_axis_response_2->setObjectName("cnt_axis_response_2");
        sizePolicy2.setHeightForWidth(cnt_axis_response_2->sizePolicy().hasHeightForWidth());
        cnt_axis_response_2->setSizePolicy(sizePolicy2);
        cnt_axis_response_2->setMinimumSize(QSize(30, 50));
        cnt_axis_response_2->setAutoFillBackground(true);

        horizontalLayout_21->addWidget(cnt_axis_response_2);


        verticalLayout_10->addLayout(horizontalLayout_21);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        run_sinking_process_2 = new QCommandLinkButton(Cnt_Alignment);
        run_sinking_process_2->setObjectName("run_sinking_process_2");
        sizePolicy.setHeightForWidth(run_sinking_process_2->sizePolicy().hasHeightForWidth());
        run_sinking_process_2->setSizePolicy(sizePolicy);
        run_sinking_process_2->setMinimumSize(QSize(100, 10));

        verticalLayout_13->addWidget(run_sinking_process_2);

        verticalSpacer_2 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_2);

        stop_sinking_process_2 = new QCommandLinkButton(Cnt_Alignment);
        stop_sinking_process_2->setObjectName("stop_sinking_process_2");
        sizePolicy4.setHeightForWidth(stop_sinking_process_2->sizePolicy().hasHeightForWidth());
        stop_sinking_process_2->setSizePolicy(sizePolicy4);

        verticalLayout_13->addWidget(stop_sinking_process_2);


        horizontalLayout_19->addLayout(verticalLayout_13);

        horizontalSpacer_20 = new QSpacerItem(200, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_20);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        label_16 = new QLabel(Cnt_Alignment);
        label_16->setObjectName("label_16");

        horizontalLayout_20->addWidget(label_16);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_21);

        cnt_proc_finished = new QLabel(Cnt_Alignment);
        cnt_proc_finished->setObjectName("cnt_proc_finished");
        sizePolicy.setHeightForWidth(cnt_proc_finished->sizePolicy().hasHeightForWidth());
        cnt_proc_finished->setSizePolicy(sizePolicy);
        cnt_proc_finished->setAutoFillBackground(true);

        horizontalLayout_20->addWidget(cnt_proc_finished);


        horizontalLayout_19->addLayout(horizontalLayout_20);


        verticalLayout_10->addLayout(horizontalLayout_19);


        horizontalLayout_31->addLayout(verticalLayout_10);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_22);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        label_17 = new QLabel(Cnt_Alignment);
        label_17->setObjectName("label_17");
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMaximumSize(QSize(500, 16777215));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_17);

        cnt_view_frequency = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency->setObjectName("cnt_view_frequency");
        sizePolicy.setHeightForWidth(cnt_view_frequency->sizePolicy().hasHeightForWidth());
        cnt_view_frequency->setSizePolicy(sizePolicy);
        cnt_view_frequency->setMinimumSize(QSize(100, 100));
        cnt_view_frequency->setMaximumSize(QSize(450, 450));
        cnt_view_frequency->setAcceptDrops(false);
        cnt_view_frequency->setAutoFillBackground(true);

        verticalLayout_15->addWidget(cnt_view_frequency);


        horizontalLayout_12->addLayout(verticalLayout_15);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_19 = new QLabel(Cnt_Alignment);
        label_19->setObjectName("label_19");
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMaximumSize(QSize(500, 16777215));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_19);

        cnt_axis_pos = new QLCDNumber(Cnt_Alignment);
        cnt_axis_pos->setObjectName("cnt_axis_pos");
        sizePolicy.setHeightForWidth(cnt_axis_pos->sizePolicy().hasHeightForWidth());
        cnt_axis_pos->setSizePolicy(sizePolicy);
        cnt_axis_pos->setMinimumSize(QSize(100, 100));
        cnt_axis_pos->setMaximumSize(QSize(450, 450));
        cnt_axis_pos->setAcceptDrops(false);
        cnt_axis_pos->setAutoFillBackground(true);

        verticalLayout_17->addWidget(cnt_axis_pos);


        horizontalLayout_12->addLayout(verticalLayout_17);


        verticalLayout_14->addLayout(horizontalLayout_12);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_26 = new QLabel(Cnt_Alignment);
        label_26->setObjectName("label_26");
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setMaximumSize(QSize(500, 16777215));
        label_26->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_26);

        cnt_view_frequency_3 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_3->setObjectName("cnt_view_frequency_3");
        sizePolicy.setHeightForWidth(cnt_view_frequency_3->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_3->setSizePolicy(sizePolicy);
        cnt_view_frequency_3->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_3->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_3->setAcceptDrops(false);
        cnt_view_frequency_3->setAutoFillBackground(true);

        verticalLayout_19->addWidget(cnt_view_frequency_3);


        horizontalLayout_28->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_27 = new QLabel(Cnt_Alignment);
        label_27->setObjectName("label_27");
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMaximumSize(QSize(500, 16777215));
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(label_27);

        cnt_view_frequency_4 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_4->setObjectName("cnt_view_frequency_4");
        sizePolicy.setHeightForWidth(cnt_view_frequency_4->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_4->setSizePolicy(sizePolicy);
        cnt_view_frequency_4->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_4->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_4->setAcceptDrops(false);
        cnt_view_frequency_4->setAutoFillBackground(true);

        verticalLayout_20->addWidget(cnt_view_frequency_4);


        horizontalLayout_28->addLayout(verticalLayout_20);


        verticalLayout_14->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        label_28 = new QLabel(Cnt_Alignment);
        label_28->setObjectName("label_28");
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);
        label_28->setMaximumSize(QSize(500, 16777215));
        label_28->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_28);

        cnt_view_frequency_5 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_5->setObjectName("cnt_view_frequency_5");
        sizePolicy.setHeightForWidth(cnt_view_frequency_5->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_5->setSizePolicy(sizePolicy);
        cnt_view_frequency_5->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_5->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_5->setAcceptDrops(false);
        cnt_view_frequency_5->setAutoFillBackground(true);

        verticalLayout_21->addWidget(cnt_view_frequency_5);


        horizontalLayout_29->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName("verticalLayout_22");
        label_29 = new QLabel(Cnt_Alignment);
        label_29->setObjectName("label_29");
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMaximumSize(QSize(500, 16777215));
        label_29->setAlignment(Qt::AlignCenter);

        verticalLayout_22->addWidget(label_29);

        cnt_view_frequency_6 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_6->setObjectName("cnt_view_frequency_6");
        sizePolicy.setHeightForWidth(cnt_view_frequency_6->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_6->setSizePolicy(sizePolicy);
        cnt_view_frequency_6->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_6->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_6->setAcceptDrops(false);
        cnt_view_frequency_6->setAutoFillBackground(true);

        verticalLayout_22->addWidget(cnt_view_frequency_6);


        horizontalLayout_29->addLayout(verticalLayout_22);


        verticalLayout_14->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName("verticalLayout_23");
        label_30 = new QLabel(Cnt_Alignment);
        label_30->setObjectName("label_30");
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);
        label_30->setMaximumSize(QSize(500, 16777215));
        label_30->setAlignment(Qt::AlignCenter);

        verticalLayout_23->addWidget(label_30);

        cnt_view_frequency_7 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_7->setObjectName("cnt_view_frequency_7");
        sizePolicy.setHeightForWidth(cnt_view_frequency_7->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_7->setSizePolicy(sizePolicy);
        cnt_view_frequency_7->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_7->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_7->setAcceptDrops(false);
        cnt_view_frequency_7->setAutoFillBackground(true);

        verticalLayout_23->addWidget(cnt_view_frequency_7);


        horizontalLayout_30->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName("verticalLayout_24");
        label_31 = new QLabel(Cnt_Alignment);
        label_31->setObjectName("label_31");
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);
        label_31->setMaximumSize(QSize(500, 16777215));
        label_31->setAlignment(Qt::AlignCenter);

        verticalLayout_24->addWidget(label_31);

        cnt_view_frequency_8 = new QLCDNumber(Cnt_Alignment);
        cnt_view_frequency_8->setObjectName("cnt_view_frequency_8");
        sizePolicy.setHeightForWidth(cnt_view_frequency_8->sizePolicy().hasHeightForWidth());
        cnt_view_frequency_8->setSizePolicy(sizePolicy);
        cnt_view_frequency_8->setMinimumSize(QSize(200, 100));
        cnt_view_frequency_8->setMaximumSize(QSize(450, 450));
        cnt_view_frequency_8->setAcceptDrops(false);
        cnt_view_frequency_8->setAutoFillBackground(true);

        verticalLayout_24->addWidget(cnt_view_frequency_8);


        horizontalLayout_30->addLayout(verticalLayout_24);


        verticalLayout_14->addLayout(horizontalLayout_30);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        label_18 = new QLabel(Cnt_Alignment);
        label_18->setObjectName("label_18");
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMaximumSize(QSize(500, 16777215));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_18);

        sink_time_2 = new QLCDNumber(Cnt_Alignment);
        sink_time_2->setObjectName("sink_time_2");
        sizePolicy.setHeightForWidth(sink_time_2->sizePolicy().hasHeightForWidth());
        sink_time_2->setSizePolicy(sizePolicy);
        sink_time_2->setMinimumSize(QSize(100, 100));
        sink_time_2->setMaximumSize(QSize(450, 450));
        sink_time_2->setAcceptDrops(false);
        sink_time_2->setAutoFillBackground(true);

        verticalLayout_16->addWidget(sink_time_2);


        verticalLayout_14->addLayout(verticalLayout_16);


        horizontalLayout_31->addLayout(verticalLayout_14);


        horizontalLayout_32->addLayout(horizontalLayout_31);

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
        menubar->setGeometry(QRect(0, 0, 1362, 22));
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
        menuDebug->addAction(actionopen_debug_console);
        menuHelp->addAction(actiondocumentation);
        menuHelp->addAction(actiongrbl);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        actionwhs_config->setText(QCoreApplication::translate("MainWindow", "whs_config.yaml", nullptr));
        actiondocumentation->setText(QCoreApplication::translate("MainWindow", "documentation", nullptr));
        actiongrbl->setText(QCoreApplication::translate("MainWindow", "grbl", nullptr));
        actionopen_debug_console->setText(QCoreApplication::translate("MainWindow", "open debug console", nullptr));
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
        sink_connect_motion_axis->setText(QCoreApplication::translate("MainWindow", "connect motion axis", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "axis_ready", nullptr));
        sink_motion_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "axis_input_command", nullptr));
        cmd_given_1->setText(QCoreApplication::translate("MainWindow", "cmd_given: ", nullptr));
        sink_cmd_given->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "axis_response", nullptr));
        sink_axis_response->setText(QCoreApplication::translate("MainWindow", "idle", nullptr));
        sink_connect_distance_sensor->setText(QCoreApplication::translate("MainWindow", "connect distance sensor", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "distance_ready", nullptr));
        sink_sensor_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        run_sinking_process->setText(QCoreApplication::translate("MainWindow", "run sinking process", nullptr));
        stop_sinking_process->setText(QCoreApplication::translate("MainWindow", "stop sinking process", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "process_finished", nullptr));
        sinking_finished->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "sensor mesured distance(mm)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "process time elapsed (sec)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "axis current position (mm)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Sinking), QCoreApplication::translate("MainWindow", "Sinking", nullptr));
        connect_motion_axis_2->setText(QCoreApplication::translate("MainWindow", "connect motion axis", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "axis_ready", nullptr));
        cnt_motion_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "axis_input_command", nullptr));
        cmd_given_2->setText(QCoreApplication::translate("MainWindow", "cmd_given: ", nullptr));
        cnt_axis_cmd_given->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "axis_response", nullptr));
        cnt_axis_response->setText(QCoreApplication::translate("MainWindow", "idle", nullptr));
        connect_distance_sensor_2->setText(QCoreApplication::translate("MainWindow", "connect cnt dispenser", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "cnt_dispenser_ready", nullptr));
        cnt_dispenser_ready->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "dispenser_input_command", nullptr));
        cmd_given_4->setText(QCoreApplication::translate("MainWindow", "cmd_given: ", nullptr));
        cnt_axis_cmd_given_3->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "dispenser_response", nullptr));
        cnt_axis_response_3->setText(QCoreApplication::translate("MainWindow", "idle", nullptr));
        connect_distance_sensor_3->setText(QCoreApplication::translate("MainWindow", "connect high_voltage", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "hv_ready", nullptr));
        cnt_dispenser_ready_2->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "hv_input_command", nullptr));
        cmd_given_3->setText(QCoreApplication::translate("MainWindow", "cmd_given: ", nullptr));
        cnt_axis_cmd_given_2->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "hv_response", nullptr));
        cnt_axis_response_2->setText(QCoreApplication::translate("MainWindow", "idle", nullptr));
        run_sinking_process_2->setText(QCoreApplication::translate("MainWindow", "run aligning process", nullptr));
        stop_sinking_process_2->setText(QCoreApplication::translate("MainWindow", "stop aligning process", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "process_finished", nullptr));
        cnt_proc_finished->setText(QCoreApplication::translate("MainWindow", "false", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "dispenser mesured frequency(mm)", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "axis current position (mm)", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "high voltage input current(mA)", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "high voltage output current(mA)", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "high voltage input voltage(V)", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "high voltage output voltage(V)", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "high voltage input frequency(Hz)", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "high voltage output frequency(Hz)", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "process time elapsed (sec)", nullptr));
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
