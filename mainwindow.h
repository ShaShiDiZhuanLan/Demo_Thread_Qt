#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "test_thread2.h"
#include "test_concurent.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onTest(const QString &s);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QThread* my_thread = Q_NULLPTR;
    Test_Thread2 *test_2 = Q_NULLPTR;
    Test_Concurent* test_concurent = Q_NULLPTR;
};

#endif // MAINWINDOW_H
