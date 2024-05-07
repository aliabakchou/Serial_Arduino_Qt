#include "serial.h"
#include <QDebug>
serial::serial(QObject *parent)
    :QObject{parent}
{
    _serial.setPortName("/dev/ttyUSB1");
    _serial.setBaudRate(QSerialPort::Baud9600);
    _serial.setDataBits(QSerialPort::Data8);
    _serial.setParity(QSerialPort::NoParity);
    _serial.setStopBits(QSerialPort::OneStop);
    _serial.setFlowControl(QSerialPort::NoFlowControl);
    connect(&_serial, &QSerialPort::readyRead, this, &serial::newData);

}
serial::~serial(){
    closeConnection();
}

void serial::closeConnection(){
    _serial.close();
}
void serial::write(const char* messageToWrite){
    _serial.write(messageToWrite);
}
void serial::openConnection(){
    if(!_serial.open(QIODevice::ReadWrite)){
        qDebug() <<"no connection";
    }
    else {
        qDebug() <<"connected with arduino";
    }
}

bool serial::isOpen(){
   return _serial.isOpen();
}
bool serial::isWritable(){
   return  _serial.isWritable();
}
void serial::newData(){
    emit gotNewData(_serial.readAll());
}
