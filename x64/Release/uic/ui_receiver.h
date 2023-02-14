/********************************************************************************
** Form generated from reading UI file 'receiver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVER_H
#define UI_RECEIVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receiver
{
public:
    QLabel *label_26;
    QLabel *label_24;
    QLineEdit *lineEdit_master;
    QLabel *label_27;
    QLabel *label_25;
    QLineEdit *lineEdit_master_2;
    QLineEdit *lineEdit_master_3;
    QLabel *label_28;
    QLabel *label_29;

    void setupUi(QWidget *receiver)
    {
        if (receiver->objectName().isEmpty())
            receiver->setObjectName(QString::fromUtf8("receiver"));
        receiver->resize(380, 300);
        label_26 = new QLabel(receiver);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(242, 60, 13, 21));
        label_24 = new QLabel(receiver);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(40, 60, 51, 21));
        lineEdit_master = new QLineEdit(receiver);
        lineEdit_master->setObjectName(QString::fromUtf8("lineEdit_master"));
        lineEdit_master->setGeometry(QRect(100, 60, 136, 21));
        label_27 = new QLabel(receiver);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(240, 160, 13, 21));
        label_25 = new QLabel(receiver);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(38, 160, 51, 21));
        lineEdit_master_2 = new QLineEdit(receiver);
        lineEdit_master_2->setObjectName(QString::fromUtf8("lineEdit_master_2"));
        lineEdit_master_2->setGeometry(QRect(100, 160, 136, 21));
        lineEdit_master_3 = new QLineEdit(receiver);
        lineEdit_master_3->setObjectName(QString::fromUtf8("lineEdit_master_3"));
        lineEdit_master_3->setGeometry(QRect(100, 110, 136, 21));
        label_28 = new QLabel(receiver);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(242, 110, 13, 21));
        label_29 = new QLabel(receiver);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(40, 110, 51, 21));

        retranslateUi(receiver);

        QMetaObject::connectSlotsByName(receiver);
    } // setupUi

    void retranslateUi(QWidget *receiver)
    {
        receiver->setWindowTitle(QCoreApplication::translate("receiver", "Sipm", nullptr));
        label_26->setText(QCoreApplication::translate("receiver", "V", nullptr));
        label_24->setText(QCoreApplication::translate("receiver", "V_bias\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("receiver", "\302\260", nullptr));
        label_25->setText(QCoreApplication::translate("receiver", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_28->setText(QCoreApplication::translate("receiver", "V", nullptr));
        label_29->setText(QCoreApplication::translate("receiver", "V_bd\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receiver: public Ui_receiver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVER_H
