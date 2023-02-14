/********************************************************************************
** Form generated from reading UI file 'ip_config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IP_CONFIG_H
#define UI_IP_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ip_config
{
public:
    QLabel *label_4;
    QLabel *label_24;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox_ip;
    QComboBox *comboBox_netmask;

    void setupUi(QDialog *ip_config)
    {
        if (ip_config->objectName().isEmpty())
            ip_config->setObjectName(QString::fromUtf8("ip_config"));
        ip_config->resize(613, 462);
        label_4 = new QLabel(ip_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 80, 81, 16));
        label_24 = new QLabel(ip_config);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(50, 40, 211, 18));
        label_6 = new QLabel(ip_config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 110, 78, 16));
        label_7 = new QLabel(ip_config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 110, 78, 16));
        lineEdit = new QLineEdit(ip_config);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 140, 221, 271));
        lineEdit_2 = new QLineEdit(ip_config);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(300, 140, 221, 271));
        pushButton = new QPushButton(ip_config);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 30, 121, 61));
        QFont font;
        font.setPointSize(24);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(ip_config);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 10, 75, 24));
        comboBox_ip = new QComboBox(ip_config);
        comboBox_ip->setObjectName(QString::fromUtf8("comboBox_ip"));
        comboBox_ip->setGeometry(QRect(100, 40, 191, 22));
        comboBox_netmask = new QComboBox(ip_config);
        comboBox_netmask->setObjectName(QString::fromUtf8("comboBox_netmask"));
        comboBox_netmask->setGeometry(QRect(100, 80, 191, 22));
#if QT_CONFIG(shortcut)
        label_6->setBuddy(label_6);
        label_7->setBuddy(label_6);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ip_config);

        QMetaObject::connectSlotsByName(ip_config);
    } // setupUi

    void retranslateUi(QDialog *ip_config)
    {
        ip_config->setWindowTitle(QCoreApplication::translate("ip_config", "TCP/IP\347\275\221\347\273\234\351\200\232\344\277\241", nullptr));
        label_4->setText(QCoreApplication::translate("ip_config", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_24->setText(QCoreApplication::translate("ip_config", "ip\345\234\260\345\235\200", nullptr));
        label_6->setText(QCoreApplication::translate("ip_config", "\345\217\221\351\200\201\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("ip_config", "\346\216\245\346\224\266\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("ip_config", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ip_config", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ip_config: public Ui_ip_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IP_CONFIG_H
