#include "test_concurent.h"
#include "ui_test_concurent.h"

#include<QDebug>
#include<QtConcurrent>//要记得添加该头文件

/*****************************************
 *
 * QtConcurrent 多线程 - run
 *
 ****************************************/

Test_Concurent::Test_Concurent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test_Concurent)
{
    ui->setupUi(this);
}

void Test_Concurent::star()
{
    QtConcurrent::run(this, &Test_Concurent::xunhuan);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}

void Test_Concurent::xunhuan()
{
    int i = 0;
    int curL = numList.length();
    while(myEnable) {
        if (i == 0)
            numList.append(i);
        i++;
        numList[curL] = i;
        qDebug() << curL << i;
    }
}

Test_Concurent::~Test_Concurent()
{
    delete ui;
}

void Test_Concurent::on_pushButton_clicked()
{
    myEnable = 1;
    ui->textEdit->setText(ui->textEdit->toPlainText()+"\nStart.");
    xunhuan(); //非多线程执行死循环
}

void Test_Concurent::on_pushButton_2_clicked()
{
    myEnable=0;//标志位置零，退出死循环
    for (int i = 0; i < numList.length(); i++){
        ui->textEdit->setText(ui->textEdit->toPlainText()+"\nThread" + QString::number(i) + ": " +QString::number(numList[i]));
    }
    ui->textEdit->setText(ui->textEdit->toPlainText()+"\nStop.");
    qDebug()<<"退出死循环!";
}

void Test_Concurent::on_pushButton_3_clicked()
{
    myEnable = 1;
    ui->textEdit->setText(ui->textEdit->toPlainText()+"\nQtConcurrent run.");
    star();//多线程启动死循环
}
