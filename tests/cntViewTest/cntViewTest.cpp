#include "cntViewTest.h"
#include <QTest>
#include <QDebug>
#include <ui_mainwindow.h>
CntViewTest::CntViewTest(QObject *parent) : QObject(parent)
{
}

void CntViewTest::first()
{
    QVERIFY(true);
    qInfo() << "Verify first test case";
}

void CntViewTest::on_cnt_connect_motion_axis_clicked(){
    
}