/********************************************************************************
** Form generated from reading UI file 'fpga.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPGA_H
#define UI_FPGA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FPGA
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_led1;
    QLabel *label_led2;
    QPushButton *pushButton;

    void setupUi(QDialog *FPGA)
    {
        if (FPGA->objectName().isEmpty())
            FPGA->setObjectName(QString::fromUtf8("FPGA"));
        FPGA->resize(320, 240);
        label = new QLabel(FPGA);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 53, 16));
        label_2 = new QLabel(FPGA);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 53, 16));
        label_led1 = new QLabel(FPGA);
        label_led1->setObjectName(QString::fromUtf8("label_led1"));
        label_led1->setGeometry(QRect(130, 50, 53, 16));
        label_led2 = new QLabel(FPGA);
        label_led2->setObjectName(QString::fromUtf8("label_led2"));
        label_led2->setGeometry(QRect(130, 90, 53, 16));
        pushButton = new QPushButton(FPGA);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 75, 24));

        retranslateUi(FPGA);

        QMetaObject::connectSlotsByName(FPGA);
    } // setupUi

    void retranslateUi(QDialog *FPGA)
    {
        FPGA->setWindowTitle(QCoreApplication::translate("FPGA", "FPGA", nullptr));
        label->setText(QCoreApplication::translate("FPGA", "FPGA\347\212\266\346\200\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FPGA", "\350\256\276\345\244\207\347\212\266\346\200\201", nullptr));
        label_led1->setText(QCoreApplication::translate("FPGA", "TextLabel", nullptr));
        label_led2->setText(QCoreApplication::translate("FPGA", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("FPGA", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FPGA: public Ui_FPGA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPGA_H
