/********************************************************************************
** Form generated from reading UI file 'serial_port.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_PORT_H
#define UI_SERIAL_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial_port
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *PortBox;
    QComboBox *BaudBox;
    QComboBox *BitBox;
    QComboBox *ParityBox;
    QComboBox *StopBox;
    QPushButton *OpenSerialButton;
    QTextEdit *textEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_2;
    QPushButton *SendButton;

    void setupUi(QWidget *serial_port)
    {
        if (serial_port->objectName().isEmpty())
            serial_port->setObjectName(QString::fromUtf8("serial_port"));
        serial_port->resize(394, 385);
        widget = new QWidget(serial_port);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 341, 301));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        PortBox = new QComboBox(widget);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));

        verticalLayout->addWidget(PortBox);

        BaudBox = new QComboBox(widget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QString::fromUtf8("BaudBox"));

        verticalLayout->addWidget(BaudBox);

        BitBox = new QComboBox(widget);
        BitBox->addItem(QString());
        BitBox->setObjectName(QString::fromUtf8("BitBox"));

        verticalLayout->addWidget(BitBox);

        ParityBox = new QComboBox(widget);
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));

        verticalLayout->addWidget(ParityBox);

        StopBox = new QComboBox(widget);
        StopBox->addItem(QString());
        StopBox->setObjectName(QString::fromUtf8("StopBox"));

        verticalLayout->addWidget(StopBox);

        OpenSerialButton = new QPushButton(widget);
        OpenSerialButton->setObjectName(QString::fromUtf8("OpenSerialButton"));

        verticalLayout->addWidget(OpenSerialButton);


        horizontalLayout_2->addLayout(verticalLayout);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_2->addWidget(textEdit);

        widget1 = new QWidget(serial_port);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 340, 358, 31));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_2 = new QTextEdit(widget1);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout->addWidget(textEdit_2);

        SendButton = new QPushButton(widget1);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));

        horizontalLayout->addWidget(SendButton);


        retranslateUi(serial_port);

        BaudBox->setCurrentIndex(0);
        BitBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(serial_port);
    } // setupUi

    void retranslateUi(QWidget *serial_port)
    {
        serial_port->setWindowTitle(QApplication::translate("serial_port", "Form", nullptr));
        BaudBox->setItemText(0, QApplication::translate("serial_port", "9600", nullptr));
        BaudBox->setItemText(1, QApplication::translate("serial_port", "19200", nullptr));
        BaudBox->setItemText(2, QApplication::translate("serial_port", "38400", nullptr));
        BaudBox->setItemText(3, QApplication::translate("serial_port", "57600", nullptr));
        BaudBox->setItemText(4, QApplication::translate("serial_port", "115200", nullptr));

        BitBox->setItemText(0, QApplication::translate("serial_port", "8", nullptr));

        ParityBox->setItemText(0, QApplication::translate("serial_port", "0", nullptr));

        StopBox->setItemText(0, QApplication::translate("serial_port", "1", nullptr));

        OpenSerialButton->setText(QApplication::translate("serial_port", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        SendButton->setText(QApplication::translate("serial_port", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial_port: public Ui_serial_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_PORT_H
