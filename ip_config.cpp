#include "ip_config.h"
#include "ui_ip_config.h"
#include <iostream>
#include <QHostAddress>
/*外网ip*/
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QNetworkInterface>
ip_config::ip_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ip_config)
{
    ui->setupUi(this);
}

ip_config::~ip_config()
{
    delete ui;
}

void ip_config::on_pushButton_clicked()
{
    std::cout<<"11111"<<std::endl;
}


void ip_config::on_pushButton_2_clicked()
{

    ui->comboBox_ip->clear();
    ui->comboBox_netmask->clear();
//    //计算机名字
//    QString localHostName = QHostInfo::localHostName();
//    //qDebug() <<"localHostName: "<<localHostName;

//    //IPv6 地址
//    QHostInfo info = QHostInfo::fromName(localHostName);
//    qDebug() <<"IP Address: "<<info.addresses();

//    //IPV4 地址
//    QHostAddress address;
//    info.addresses();
//    if(address.protocol() == QAbstractSocket::IPv4Protocol)
//       qDebug() << address.toString();

//    if(address.protocol() == QAbstractSocket::IPv6Protocol)
//       qDebug() << address.toString();



    //获取公网IP
//    QString qstr=returnOutIP();
//    qDebug() << qstr;

    //获取本地IP片地址,
    QList<QHostAddress> addList = QNetworkInterface::allAddresses();

    foreach(QHostAddress address,addList)
    {
        //排除IPV6，排除回环地址
        if(address.protocol() == QAbstractSocket::IPv4Protocol
                && address != QHostAddress(QHostAddress::LocalHost))
        {
            //输出，转换为字符串格式
            qDebug() << address.toString();
        }
    }
    qDebug() << "----------------------------------";

    //获取本地所有的网络接口
    QList<QNetworkInterface> interface = QNetworkInterface::allInterfaces();

    foreach(QNetworkInterface inter,interface)
    {
        QList<QNetworkAddressEntry> entrList = inter.addressEntries();

        foreach(QNetworkAddressEntry entr,entrList)
        {
            QHostAddress hostIp = entr.ip();
            if(hostIp.protocol() == QAbstractSocket::IPv4Protocol &&
                    hostIp != QHostAddress(QHostAddress::LocalHost))
            {
                //获取输出名称
                qDebug()<<QString("名称：%1").arg(inter.humanReadableName());
                //获取输出ip地址
                qDebug() << QString("HostIp:%1").arg(hostIp.toString());
                ui->comboBox_ip->addItem(hostIp.toString());

                //获取输出子网掩码
                qDebug() << QString("NetMask:%1").arg(entr.netmask().toString());
                ui->comboBox_netmask->addItem(entr.netmask().toString());
                //获取并输出mac地址
                qDebug() << QString("HardAddress:%1").arg(inter.hardwareAddress());
                qDebug() << "----------------------------------";
            }
        }

    }



    //ui->comboBox_ip->addItem();


}


//void ip_config::on_lineEdit_master_selectionChanged()
//{

//    QString strIpAddress;
//    QList<QHostAddress> ipAddressesList = QNativeInterface::allAddresses();
//    // 获取第一个本主机的IPv4地址
//    int nListSize = ipAddressesList.size();
//    std::cout<<nListSize<<std::endl;


//    for (int i = 0; i < nListSize; ++i)
//    {
//        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
//                ipAddressesList.at(i).toIPv4Address()) {
//            strIpAddress = ipAddressesList.at(i).toString();
//            break;
//        }
//    }
//    // 如果没有找到，则以本地IP地址为IP
//    if (strIpAddress.isEmpty())
//        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
//    return strIpAddress;

//}



