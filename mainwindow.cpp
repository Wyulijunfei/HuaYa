#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialization();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialization(){
    Serialport=new serial_port(ui->SerialportWidget);
    Serialport->show();
}
