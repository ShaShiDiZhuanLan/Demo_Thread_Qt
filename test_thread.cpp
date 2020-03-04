#include "test_thread.h"
#include <QDebug>

Test_Thread::Test_Thread(QObject *parent) : QThread(parent)
{

}

void Test_Thread::run()
{
    QString result = "result";
    emit sigResultReady(result);
}
