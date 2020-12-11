#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QWidget>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSerialPort>
#include <QKeyEvent>
#include <QTimer>
namespace Ui {
class serial_port;
}

class serial_port : public QWidget
{
    Q_OBJECT

public:
    explicit serial_port(QWidget *parent = nullptr);
    ~serial_port();
    QSerialPort *serial;

    void senddata(QByteArray);
    bool open;
    void analysis(QString myStrTemp);

signals:
    void return_b();

private slots:
    void on_OpenSerialButton_clicked();     //打开串口按键

 //   void ReadData();                        //读数据

    void on_SendButton_clicked();           //发送按钮

    void slotReadSerialMsg();


private:
    Ui::serial_port *ui;
};

#endif // SERIAL_PORT_H
