#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "mythread.h"
#include <QPainter>
#include <iostream>
#include <vector>
#include <cstring>
#include <QTime>
using namespace std;

void sleep(unsigned int msec)
{
    //
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime()<reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Graph = graph(N,M);

}
void MainWindow::paintEvent(QPaintEvent *){

    QPainter painter(this);
    vector<vector<int> > g = Graph.g;


    QPen pen; //画笔
    pen.setColor(QColor(0, 251, 251));
    painter.setPen(pen); //添加画笔
    QBrush brush(QColor(0, 251, 251)); //画刷
    painter.setBrush(brush); //添加画刷

    QList<QRect> gridList;
    QList<QRect> wallList;
    QList<QRect> unblockWall;
    for (int i = 0;i<(2*N + 1);++i){
        for (int j = 0;j<(2*M+1);++j){
            if (i % 2 == 0){
                //偶数行 只有墙壁 而且一定是横墙
                if (j % 2 == 0){
                    //正方形格子 不会被消去
                    wallList.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,wallWidth,wallWidth));
                }else{
                    //横墙
                    if (g[i][j] == 1){
                        wallList.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,gridWidth,wallWidth));
                    }else{
                        unblockWall.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,gridWidth,wallWidth));
                    }
                }
            }else{
                //奇数行 有格子和墙壁
                if (j % 2 == 0){
                    //竖墙
                    if (g[i][j] == 1){
                        wallList.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,wallWidth,gridWidth));
                    }else{
                        unblockWall.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,wallWidth,gridWidth));
                    }
                }else{
                    //格子
                    gridList.push_back(QRect(startX + (j+1)/2 * wallWidth + (j/2) * gridWidth , startY + (i+1)/2 * wallWidth + (i/2) * gridHeight,gridWidth,gridHeight));
                }
            }
        }
    }
    painter.drawRects(gridList);
    painter.drawRects(unblockWall);
    brush.setColor(QColor(0,0,255));
    painter.setBrush(brush);
    painter.drawRects(wallList);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    myThread *thread1 = new myThread(this);
    thread1->start();
}

