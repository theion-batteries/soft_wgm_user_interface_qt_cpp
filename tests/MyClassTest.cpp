#include <QtTest/QtTest>

#include "MyClass.h"

class MyClassTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructor()
    {
        MyClass obj;
        QVERIFY(obj.isValid());
    }

    void testAdd()
    {
        MyClass obj;
        QCOMPARE(obj.add(2, 3), 5);
    }
};

QTEST_MAIN(MyClassTest)
#include "MyClassTest.moc"
