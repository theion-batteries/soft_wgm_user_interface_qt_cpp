#include <QTest>
#include "cntViewTest/cntViewTest.h"

int main(int argc, char *argv[]) {
    CntViewTest cntViewTest;
    QTest::qExec(&cntViewTest);
}

