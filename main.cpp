#include "mainwindow.h"
#include <Windows.h>
#include <QApplication>
#include <QThread>
#include <blocksleepclass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.hide(); // 干脆直接隐藏
    BlockSleepClass *bsleep = new BlockSleepClass();
    bsleep->start();
    return a.exec();
}
