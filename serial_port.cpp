#include "serial_port.h"
#include "ui_serial_port.h"
#include <QMessageBox>
#pragma execution_character_set("utf-8");
serial_port::serial_port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serial_port)
{
    ui->setupUi(this);

    open=false;
    serial = new QSerialPort;

    //查找可用的串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);     //设置串口
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());    //显示串口name
            serial.close();
        }
    }
    //设置波特率下拉菜单默认显示第0项
    ui->BaudBox->setCurrentIndex(0);
     //connect(serial, SIGNAL(readyRead()), this, SLOT(slotReadSerialMsg()));

    ui->SendButton->setEnabled(false);
}

serial_port::~serial_port()
{
    delete ui;
}

void serial_port::analysis(QString myStrTemp)
{/*
    ui->textEdit->insertPlainText(myStrTemp+"\n");//显示
    //解析数据
    if(myStrTemp.isEmpty())
    {
       serial->write("R\r\n");
        return;
    }

     QChar ch;
     ch = myStrTemp.at(0);
     if(ch == 'R'){
         if(myStrTemp.size()<2)
         {
             serial->write("R\r\n");
             return;
         }
         ch = myStrTemp.at(1);
         if(ch=='W')
         {

             ui->textEdit->insertPlainText("RW\n");
             serial->write("RP\r\n");
         }else if(ch=='K')
         {

             }
         else if(ch=='M')
         {
             ui->textEdit->insertPlainText("RP\n");

         }else if (ch=='C') {

}
     else{
         //未定义,请求重发
          serial->write("R\r\n");
     }
}
*/
}

 void serial_port::slotReadSerialMsg()
 {

      static int i=0;
      if(serial->bytesAvailable()>=0){
         i++;

         QByteArray temp=serial->readAll();
         QString myStrTemp=QString::fromLocal8Bit( temp);
         QString txt = "开始解析第"+QString::number(i)+"条信息\n";
         ui->textEdit->insertPlainText(txt);
        analysis(myStrTemp.trimmed());

        temp.clear();
      }
 }



 void serial_port::on_OpenSerialButton_clicked()
 {


     if(ui->OpenSerialButton->text() == tr("打开串口"))
     {
         serial = new QSerialPort;
         //设置串口名
         if(ui->PortBox->count()<1)
         {

             QMessageBox::information(this,"提示","未找到串口，请重新搜索");
             return;

         }

         serial->setPortName(ui->PortBox->currentText());
         //打开串口
         if(!serial->open(QIODevice::ReadWrite))//用ReadWrite 的模式尝试打开串口
         {
             qDebug()<<"打开失败!";
             QMessageBox::information(this,"info","串口打开失败");
             return;
         }


         serial->open(QIODevice::ReadWrite);
         switch (ui->BaudBox->currentIndex()) {
         case 9600:
             serial->setBaudRate(QSerialPort::Baud9600);
             break;
         case 19200:
             serial->setBaudRate(QSerialPort::Baud19200);
             break;
         case 38400:
             serial->setBaudRate(QSerialPort::Baud38400);
             break;
         case 57600:
             serial->setBaudRate(QSerialPort::Baud57600);
             break;
         case 115200:
             serial->setBaudRate(QSerialPort::Baud115200);
             break;
         default:
             break;

         }
         //设置波特率
         //serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200


         //设置数据位数
         switch (ui->BitBox->currentIndex())
         {
         case 0:
             serial->setDataBits(QSerialPort::Data8);//设置数据位8
             break;
         case 1:
             serial->setDataBits(QSerialPort::Data7);//设置数据位8
             break;
         default:
             break;
         }


         //设置校验位
         switch (ui->ParityBox->currentIndex())
         {
         case 0:
             serial->setParity(QSerialPort::NoParity);
             break;
         case 1:
             serial->setParity(QSerialPort::EvenParity);
             break;
         default:
             break;
         }



         //设置停止位
         switch (ui->BitBox->currentIndex())
         {
         case 0:
             serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
             break;
         case 1:
             serial->setStopBits(QSerialPort::TwoStop);
         default:
             break;
         }



         //设置流控制
         serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制

         serial->setReadBufferSize(1024);



             //关闭设置菜单使能
             ui->PortBox->setEnabled(false);
             ui->BaudBox->setEnabled(false);
             ui->BitBox->setEnabled(false);
             ui->ParityBox->setEnabled(false);
             ui->StopBox->setEnabled(false);
             ui->SendButton->setEnabled(true);
             ui->OpenSerialButton->setText(tr("关闭串口"));

             //连接信号槽
            // QObject::connect(serial,&SERIAL_MODEL::readyRead,this,slotReadSerialMsg);
             connect(serial, SIGNAL(readyRead()), this, SLOT(slotReadSerialMsg()));

             //simulation = false;
             //sendTimer.start();



     }
     else
     {
         //关闭串口
         serial->clear();
         serial->close();
         serial->deleteLater();

         //恢复设置使能
         ui->PortBox->setEnabled(true);
         ui->BaudBox->setEnabled(true);
         ui->BitBox->setEnabled(true);
         ui->ParityBox->setEnabled(true);
         ui->StopBox->setEnabled(true);
         ui->SendButton->setEnabled(true);
         ui->OpenSerialButton->setText(tr("打开串口"));


     }
 }

 //发送按钮槽函数
 void serial_port::on_SendButton_clicked()
 {

     serial->write(ui->textEdit_2->toPlainText().toLocal8Bit());
     serial->write("\r\n");
 }

 void serial_port::senddata(QByteArray b)
 {
     serial->write(b);
     serial->write("\r\n");
     qDebug()<<"senddata:"<<b;
 }


