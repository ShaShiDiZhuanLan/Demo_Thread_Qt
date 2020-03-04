#include "test_thread2.h"

Test_Thread2::Test_Thread2(QObject *parent) : QObject(parent)
{

}

void Test_Thread2::doWork(const QString &s)
{
    emit sigResultReady(s);
}
