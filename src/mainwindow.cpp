#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>



void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        trayIcon->showMessage("title","你单击了"); //后面两个默认参数
        break;
    case QSystemTrayIcon::DoubleClick:
        trayIcon->showMessage("title","你双击了");
        break;
    case QSystemTrayIcon::MiddleClick:
        trayIcon->showMessage("title","你中键了");
        break;
    default:
        break;
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 增加托盘
    QIcon icon = QIcon(":/logo.ico");
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("阻止电脑睡眠");
    QString title = "tip title";
    QString text = "this is a tray tip";

    trayIcon->showMessage(title, text, QSystemTrayIcon::Information, 5000);
    trayIcon->show();

    //创建菜单项动作(以下动作只对windows有效)
    quitAction = new QAction("退出~", this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit())); //关闭应用，qApp对应的是程序全局唯一指针

    trayIconMenu = new QMenu(this);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

