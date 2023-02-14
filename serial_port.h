#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QtWidgets/QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtGui/QStandardItemModel>
#include <String>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDateTime>
#include <QtCore/QTime>
#include <QtCore/QTimer>
#include <QtCore/QFile>
#include <iostream>

namespace Ui {
class serial_port;
}

class serial_port : public QWidget
{
    Q_OBJECT

public:
    explicit serial_port(QWidget *parent = nullptr);
    ~serial_port();

private:

    QSerialPort mySerial;
    QTimer updateComTimer,sendTime;
    uint32_t recByteLen;

    void init_all_combox();
    void init_port_combobox();
    void init_bandrate_combobox();
    void init_databit_combobox();
    void init_paritybit_combobox();
    void init_stopbit_combobox();
    void init_ui_context();

    void ui_enable(bool isEnable);

    void serial_read_data();
    void serial_send_data();

private slots:
    void on_serialSwitchBtn_clicked();

    void on_saveWidgetBtn_clicked();

    void on_clearRecBtn_clicked();

    void on_sendBtn_clicked();

    void on_clearSendAreaBtn_clicked();

    void on_saveFileCheckBox_clicked(bool checked);

    void on_timingSendCheckBox_clicked(bool checked);

    void on_updataBtn_clicked();

private:
    Ui::serial_port *ui;
    static   int sendBytes;
    static   int receBytes;
};

#endif // SERIAL_PORT_H
