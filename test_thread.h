#ifndef TEST_THREAD_H
#define TEST_THREAD_H

#include <QThread>

class Test_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Test_Thread(QObject *parent = 0);
signals:
    void sigResultReady(const QString &s);
protected:
    void run();
};

#endif // TEST_THREAD_H
