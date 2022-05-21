#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test_thread.h"
#include <QDebug>
/*****************************************
 *
 * Test_Thread 多线程 - run start
 * Test_Thread2 多线程 - moveToThread
 *
 ****************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    test_2 = new Test_Thread2();//should not (this) , QObject::moveToThread: Cannot move objects with a parent
    my_thread = new QThread(this);
    test_2->moveToThread(my_thread);
    connect(my_thread, &QThread::finished, test_2, &Test_Thread2::deleteLater);
    connect(test_2, &Test_Thread2::sigResultReady, this, &MainWindow::onTest);
    test_concurent = new Test_Concurent();
    test_concurent->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (test_concurent){
        delete test_concurent;
        test_concurent = Q_NULLPTR;
    }
}


void MainWindow::onTest(const QString &s)
{
    qDebug() << s << s << s;
}

void MainWindow::on_pushButton_clicked()
{
    Test_Thread* ts_th = new Test_Thread(this);
    connect(ts_th, &Test_Thread::sigResultReady, this, &MainWindow::onTest);
    connect(ts_th, &Test_Thread::finished, ts_th, &Test_Thread::deleteLater);
    ts_th->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    test_2->doWork("test2");
}

void MainWindow::on_pushButton_3_clicked()
{
    test_concurent->show();
}
