QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += testlib
QT += gui
QT += testlib core gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_gui.cpp \
    ../code/list.cpp \
    ../code/mainwindow.cpp
FORMS += \
    ../code/mainwindow.ui


HEADERS += \
    ../code/list.h \
    ../code/mainwindow.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
