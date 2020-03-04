#-------------------------------------------------
#
# Project created by Shazhenyu 2020-03-03T09:22:50
#
#-------------------------------------------------

QT       += core gui
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo_Thread_Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    test_thread.cpp \
    test_thread2.cpp \
    test_concurent.cpp

HEADERS  += mainwindow.h \
    test_thread.h \
    test_thread2.h \
    test_concurent.h

FORMS    += mainwindow.ui \
    test_concurent.ui
