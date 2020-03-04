#include "mainwindow.h"
#include <QApplication>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>

/*****************************************
 *
 * QtConcurrent blockingMapped 并发处理QList或者QMap
 *
 ****************************************/


// 字符串反转
QString stringInversion(QString str)
{
    QString tmp;
    for(auto ch: str)
        tmp.prepend(ch);
    return tmp;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<QString> strList;
    for (int i = 0; i < 20; i++)
        strList.append(QString::number(i + 1) + " ok");
    qDebug() << strList;

    QList<QString> strNew = QtConcurrent::blockingMapped(strList, stringInversion);
    qDebug() << strNew;

    return a.exec();
}
