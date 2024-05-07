#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serial.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino = new serial;
    arduino->openConnection();
    connect(arduino, &serial::gotNewData, this, &MainWindow::updateGUI);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateGUI(QByteArray data) {
    ui->lcd_byte_received->display(ui->lcd_byte_received->value() + data.size());
}

void MainWindow::on_p_ledOn_clicked()
{
    if(arduino->isWritable()) arduino->write("A");
    else qDebug() << "not connected pls check the connection";
}

void MainWindow::on_p_ledOff_clicked()
{
    if(arduino->isWritable()){

        arduino->write("B");
    }
    else {
       qDebug() << "not connected pls check the connection";
    }
}
