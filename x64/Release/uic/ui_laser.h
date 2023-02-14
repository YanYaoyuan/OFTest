/********************************************************************************
** Form generated from reading UI file 'laser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASER_H
#define UI_LASER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Laser
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_24;
    QLineEdit *lineEdit_master;
    QLabel *label_26;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_25;
    QLineEdit *lineEdit_master_2;
    QLabel *label_27;

    void setupUi(QDialog *Laser)
    {
        if (Laser->objectName().isEmpty())
            Laser->setObjectName(QString::fromUtf8("Laser"));
        Laser->resize(320, 240);
        widget = new QWidget(Laser);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 51, 201, 100));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_2->addWidget(label_24);

        lineEdit_master = new QLineEdit(widget);
        lineEdit_master->setObjectName(QString::fromUtf8("lineEdit_master"));

        horizontalLayout_2->addWidget(lineEdit_master);

        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_2->addWidget(label_26);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout->addWidget(label_25);

        lineEdit_master_2 = new QLineEdit(widget);
        lineEdit_master_2->setObjectName(QString::fromUtf8("lineEdit_master_2"));

        horizontalLayout->addWidget(lineEdit_master_2);

        label_27 = new QLabel(widget);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout->addWidget(label_27);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Laser);

        QMetaObject::connectSlotsByName(Laser);
    } // setupUi

    void retranslateUi(QDialog *Laser)
    {
        Laser->setWindowTitle(QCoreApplication::translate("Laser", "\346\277\200\345\205\211\345\231\250", nullptr));
        label_24->setText(QCoreApplication::translate("Laser", "\350\204\211\345\256\275\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("Laser", "ns", nullptr));
        label_25->setText(QCoreApplication::translate("Laser", "\351\242\221\347\216\207\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("Laser", "HZ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laser: public Ui_Laser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASER_H
