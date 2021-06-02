#include <QtTest\QtTest>
#include <QCoreApplication>
#include <QtGui>
#include "../code/mainwindow.h"
#include <QWidget>


class test_gui : public QObject
{
    Q_OBJECT

public:
    test_gui();
    ~test_gui();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
private:
    MainWindow w;

};

test_gui::test_gui()
{
}

test_gui::~test_gui()
{
}

void test_gui::initTestCase()
{
    w.show();
}

void test_gui::cleanupTestCase()
{
    w.close();
}

void test_gui::test_case1()
{
    QTest::mouseClick(w.ui->StartButton, Qt::LeftButton);
    QCOMPARE(w.ui->OutputW->toPlainText(), QString("Введите"));
}
void test_gui::test_case2()
{
    QTest::keyClicks(w.ui->Word, "aaaaammmmm33!");
    QCOMPARE(w.ui->Word->text(), QString("aaaaammmmm33!"));
    QVERIFY(w.ui->Word->isModified());
}
void test_gui::test_case3()
{
     w.ui->Word->clear();
     QTest::keyClicks(w.ui->Word, "1 2 3 4 5");
     QTest::mouseClick(w.ui->StartButton, Qt::LeftButton);
     QCOMPARE(w.ui->OutputW->toPlainText(), QString("2 1 4 3 5 "));
}
void test_gui::test_case4()
{
    w.ui->Word->clear();
    QTest::keyClicks(w.ui->Word, "1 2 3 4 1");
     QTest::mouseClick(w.ui->StartButton, Qt::LeftButton);
     QCOMPARE(w.ui->OutputW->toPlainText(), QString("Ошибка ввода"));
}
void test_gui::test_case5()
{
     w.ui->Word->clear();
     QTest::keyClicks(w.ui->Word, "1 * 3 4 5");
     QTest::mouseClick(w.ui->StartButton, Qt::LeftButton);
     QCOMPARE(w.ui->OutputW->toPlainText(), QString("Ошибка ввода"));
}
void test_gui::test_case6()
{
     QTest::mouseClick(w.ui->ClButton, Qt::LeftButton);
     QCOMPARE(w.ui->OutputW->toPlainText(), QString(""));
     QCOMPARE(w.ui->Word->text(), QString(""));
}
QTEST_MAIN(test_gui)

#include "tst_test_gui.moc"
