#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "mainwindow.h"
#include <QThread>

class myThread : public QThread
{
public:
    MainWindow * w;
    myThread();
    myThread(MainWindow * window );
    void run();
};

#endif // MYTHREAD_H
