#ifndef SERIAL_H
#define SERIAL_H
#include <QtSerialPort/QSerialPort>

class serial : public QObject
{
    Q_OBJECT
public:
    explicit serial(QObject *parent = nullptr);
    ~serial();
    void openConnection();
    void closeConnection();
    void write(const char* messageToWrite );
    bool isOpen();
    bool isWritable();
private slots:
    void newData();
signals:
    void gotNewData(QByteArray data);


private:
    QSerialPort _serial;

public slots:
};

#endif // SERIAL_H
