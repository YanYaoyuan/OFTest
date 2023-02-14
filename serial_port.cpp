#include "serial_port.h"
#include "ui_serial_port.h"
#include <iostream>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
int serial_port::sendBytes = 0;
int serial_port::receBytes = 0;


serial_port::serial_port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serial_port)
{
    ui->setupUi(this);
    recByteLen=0;

    init_all_combox();

    updateComTimer.start(1000);

    connect(&mySerial,&QSerialPort::readyRead,this,&serial_port::serial_read_data);
    connect(&updateComTimer,&QTimer::timeout,this,&serial_port::init_port_combobox);
    connect(&sendTime,&QTimer::timeout,this,&serial_port::serial_send_data);
}

serial_port::~serial_port()
{
    delete ui;
}



void serial_port::serial_read_data()
{
    QByteArray bytes = mySerial.readAll();
    QString dataString;

    recByteLen+=bytes.length();

    if(ui->timeStampCheckBox->isChecked())
    {
         dataString.append("<font color=\"#FF0000\">");
         dataString.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"));
         dataString.append("</font>");

    }
    dataString.append(ui->hexShowCheckBox->isChecked()?bytes.toHex(' '):QString::fromLocal8Bit(bytes));
    //保存到文件选项，将数据保存到文件
    QString fileName = ui->saveFileNameEdit->text();
    if(ui->saveFileCheckBox->isChecked())
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);
        file.write(dataString.toUtf8()+"\n");
        file.close();
    }




    // 读取数据后，将数据输出至ui
    ui->recTextShowTextBrowser->append(dataString);

    QString s = QString(" 接收区：已接收%1字节").arg(recByteLen);
    ui->recGroupBox->setTitle(s);
}

void serial_port::on_serialSwitchBtn_clicked()
{
    if(mySerial.isOpen())
    {
        //串口已经打开
        mySerial.clear();
        mySerial.close();
        ui->serialSwitchBtn->setText("打开串口");
        ui_enable(true);

        //发送区控件状态处理
        ui->timingSendCheckBox->setChecked(false);
        sendTime.stop();
        ui->sendTimeEdit->setEnabled(true);
        return;
    }


    mySerial.setPortName(ui->serialPortComBox->currentText());
    mySerial.setBaudRate(static_cast<QSerialPort::Parity>(ui->serialBandrateComBox->currentData().toInt()));
    mySerial.setParity(static_cast<QSerialPort::Parity>(ui->serialVerifyBitComBox->currentData().toInt()));
    mySerial.setDataBits(static_cast<QSerialPort::DataBits>(ui->serialDataBitComBox->currentData().toInt()));
    mySerial.setStopBits(static_cast<QSerialPort::StopBits>(ui->serialStopBitComBox->currentData().toInt()));

    if(ui->flowCheckBox->isChecked())
    {
        if(ui->flowModeCheckBox->isChecked())
            mySerial.setFlowControl(QSerialPort::HardwareControl);
        else
            mySerial.setFlowControl(QSerialPort::SoftwareControl);
    }
    else
        mySerial.setFlowControl(QSerialPort::NoFlowControl);

    if(mySerial.open(QSerialPort::ReadWrite))
    {
        ui->serialSwitchBtn->setText("关闭串口");
        ui_enable(false);
    }
    else
    {
        QMessageBox::warning(this,"错误",mySerial.errorString());
    }

}


void serial_port::on_saveWidgetBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                "open","../","TXT(*.txt)");
    if(path.isEmpty()==false)
    {
        //创建文件对象
        QFile file(path);

        bool isOk = file.open(QIODevice::WriteOnly| QIODevice::Text);
        if(isOk==true)
        {
            QString context = ui->recTextShowTextBrowser->document()->toPlainText();
            file.write(context.toUtf8());
        }
        file.close();
    }
}


void serial_port::on_clearRecBtn_clicked()
{
    recByteLen=0;
    ui->recTextShowTextBrowser->clear();
    ui->recGroupBox->setTitle(" 接收区：已接收0字节");
}


void serial_port::on_sendBtn_clicked()
{
    if(!mySerial.isOpen())
    {
        QMessageBox::warning(this,"错误","串口没有连接!");
        return;
    }
    serial_send_data();
}


void serial_port::on_clearSendAreaBtn_clicked()
{
    ui->sendTextTextEdit->clear();
}
void serial_port::on_saveFileCheckBox_clicked(bool checked)
{

    if(checked==false)
    {
        ui->saveFileNameEdit->setEnabled(true);
        return;
    }
    QString fileName = ui->saveFileNameEdit->text();
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"错误","文件名不能为空！");
        ui->saveFileCheckBox->setCheckState(Qt::Unchecked);
        ui->saveFileNameEdit->setEnabled(true);
        return;
    }
    ui->saveFileNameEdit->setEnabled(false);
}

void serial_port::on_timingSendCheckBox_clicked(bool checked)
{
    if(checked)
    {
        int time = ui->sendTimeEdit->text().toInt();
        if(time<=0)
        {
            ui->timingSendCheckBox->setChecked(false);
            QMessageBox::warning(this,"错误","请在下方框中输入定时发送时间！");
            return;
        }
        if(!mySerial.isOpen())
        {
            ui->timingSendCheckBox->setChecked(false);
            QMessageBox::warning(this,"错误","串口未连接！");
            return;
        }
        ui->sendBtn->setEnabled(false);
        ui->sendTimeEdit->setEnabled(false);

        sendTime.start(time);
    }
    else
    {
        ui->sendBtn->setEnabled(true);
        ui->sendTimeEdit->setEnabled(true);
        sendTime.stop();
    }
}
void serial_port::serial_send_data()
{
    QString val = ui->sendTextTextEdit->toPlainText();

    if(val.length()<=0)
        return;
    if(ui->hexSendCheckBox->isChecked())
    {
        val = val.trimmed();

        QByteArray inputData;
        QStringList stringList = val.split(" ");
        for (auto var : stringList)
        {
            if (var.length()){
                quint8 byte = var.toInt(Q_NULLPTR, 16);
                inputData.append(byte);
            }
        }
        if(ui->sendNewLineCheckBox->isChecked())
            inputData.append(0x0D).append(0x0A);
        mySerial.write(inputData);

    }

    else
    {
        if(ui->sendNewLineCheckBox->isChecked())
            val.append("\r\n");
        mySerial.write(val.toLocal8Bit());
    }
}

void serial_port::ui_enable(bool isEnable)
{
    ui->serialPortComBox->setEnabled(isEnable);
    ui->serialBandrateComBox->setEnabled(isEnable);
    ui->serialDataBitComBox->setEnabled(isEnable);
    ui->serialVerifyBitComBox->setEnabled(isEnable);
    ui->serialStopBitComBox->setEnabled(isEnable);
    ui->flowCheckBox->setEnabled(isEnable);
    ui->flowModeCheckBox->setEnabled(isEnable);
}

void serial_port::init_all_combox()
{
    init_port_combobox();
    init_port_combobox();
    init_bandrate_combobox();
    init_databit_combobox();
    init_paritybit_combobox();
    init_stopbit_combobox();
    init_ui_context();
}

void serial_port::init_port_combobox()
{
    // 获取本机所有串口设备信息
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    static  int infoListLen;

    if(infoList.length()==infoListLen)
        return;
    infoListLen = infoList.length();
    // 为了在下拉选项中显示更多信息，采用模型形式添加设备列表
    QStandardItemModel *model = new QStandardItemModel(ui->serialPortComBox);
    for (auto var : infoList){
        QStandardItem *item = new QStandardItem(var.portName());
        item->setToolTip(var.portName() + " " + var.description());
        model->appendRow(item);
    }

    // 将设备信息添加至设备选择框中，添加前清除原有信息
    ui->serialPortComBox->clear();
    ui->serialPortComBox->setModel(model);
}
void serial_port::init_bandrate_combobox()
{
    ui->serialBandrateComBox->clear();
    QList<qint32> bdList = QSerialPortInfo::standardBaudRates();
    for (auto var : bdList){
        ui->serialBandrateComBox->addItem(QString::number(var), QVariant::fromValue(var));
    }
    ui->serialBandrateComBox->setCurrentText("9600");
}
void serial_port::init_databit_combobox()
{
    ui->serialDataBitComBox->clear();

    ui->serialDataBitComBox->addItem(QString::number(QSerialPort::Data5,10),QVariant::fromValue(QSerialPort::Data5));
    ui->serialDataBitComBox->addItem(QString::number(QSerialPort::Data6,10),QVariant::fromValue(QSerialPort::Data6));
    ui->serialDataBitComBox->addItem(QString::number(QSerialPort::Data7,10),QVariant::fromValue(QSerialPort::Data7));
    ui->serialDataBitComBox->addItem(QString::number(QSerialPort::Data8,10),QVariant::fromValue(QSerialPort::Data8));
    ui->serialDataBitComBox->setCurrentText(QString::number(QSerialPort::Data8,10));
}
void serial_port::init_paritybit_combobox()
{


    ui->serialVerifyBitComBox->clear();
    ui->serialVerifyBitComBox->addItem("None",QVariant::fromValue(QSerialPort::NoParity));
    ui->serialVerifyBitComBox->addItem("Even",QVariant::fromValue(QSerialPort::EvenParity));
    ui->serialVerifyBitComBox->addItem("Odd",QVariant::fromValue(QSerialPort::OddParity));
    ui->serialVerifyBitComBox->addItem("Space",QVariant::fromValue(QSerialPort::SpaceParity));
    ui->serialVerifyBitComBox->addItem("Mark",QVariant::fromValue(QSerialPort::MarkParity));
    ui->serialVerifyBitComBox->setCurrentText("None");
}
void serial_port::init_stopbit_combobox()
{
    ui->serialStopBitComBox->clear();
    ui->serialStopBitComBox->addItem("1",QVariant::fromValue(QSerialPort::OneStop));
    ui->serialStopBitComBox->addItem("1.5",QVariant::fromValue(QSerialPort::OneAndHalfStop));
    ui->serialStopBitComBox->addItem("2",QVariant::fromValue(QSerialPort::TwoStop));

}
void serial_port::init_ui_context()
{
    ui->saveFileNameEdit->setText("save.txt");
    ui->sendTimeEdit->setText("1000");
}



void serial_port::on_updataBtn_clicked()
{
    /*清除comboxBox的内容，防止显示重复的串口*/
    ui->serialPortComBox->clear();

    const auto infos = QSerialPortInfo::availablePorts();

    /*下面这个循环语句用来查找可以用的串口端口*/
    /*不确定有多少串口可用，也就不知道循环多少次，所以用foreach（不知道用的就百度）*/
    for(const QSerialPortInfo &info : infos)
    {
        QSerialPort serial_aaa;     //在循环语句内部实例化类，因为可用串口不一定只就一个
        serial_aaa.setPort(info);    //设置能够用的串口端口
        if(serial_aaa.open(QIODevice::ReadWrite))       //用ReadWrite可读写的方式打开串口
        {
            /*记录可用的uart名字serial.portName()，前面的ui->PortBox->addItem不用管，这个是界面里面的。*/
            ui->serialPortComBox->addItem(info.portName());

            /*然后关闭串口，因为这段代码打开串口只是为了查找串口可以用不可用而已。*/
            serial_aaa.close();
        }
    }

}
