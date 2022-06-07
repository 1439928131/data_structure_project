#include "mythread.h"
#include "mainwindow.h"
#include <QDebug>
#include <synchapi.h>
myThread::myThread()
{

}
myThread::myThread(MainWindow * window)
{
    w = window;
}

void myThread::run(){
    //随机生成
    for (int i = 0;i<2*N+1;++i){
        //qDebug() << i << " ";
        if (i % 2 == 1){
            w->Graph.g[0][i] = 2;
            w->repaint();
        }
        Sleep(200);
    }

    //第一种随机算法  --> 每个墙壁随机打通
    for (int i = 1;i<2*N;++i){
        for (int j = 1;j<2*M;++j){
            if (i % 2 == 0){

            }else{

            }
            //Sleep(100);
        }

    }
}

