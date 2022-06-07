#include "mainwindow.h"
#include "mythread.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <QThread>
#include <synchapi.h>
using namespace std;

const int Width = 1000;
const int Height = 800;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(Width,Height);
    w.show();





    a.exec();

    return 0;
}
