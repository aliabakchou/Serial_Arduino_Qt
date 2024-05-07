#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serial.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void updateGUI(QByteArray data);

private slots:
    void on_p_ledOn_clicked();

    void on_p_ledOff_clicked();

private:
    Ui::MainWindow *ui;
    serial *arduino;
};

#endif // MAINWINDOW_H
