/********************************************************************************
** Form generated from reading UI file 'registe_configure.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTE_CONFIGURE_H
#define UI_REGISTE_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registe_configure
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_24;
    QLabel *label_24;
    QGridLayout *gridLayout_23;
    QLabel *label;
    QLineEdit *lineEdit_master;
    QGridLayout *gridLayout_20;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_reg;
    QGridLayout *gridLayout_21;
    QLabel *label_5;
    QGridLayout *gridLayout_19;
    QLabel *label_3;
    QLineEdit *lineEdit_value;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QComboBox *comboBox_iic_mode;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_i2c_write;
    QPushButton *pushButton_i2c_read;

    void setupUi(QDialog *registe_configure)
    {
        if (registe_configure->objectName().isEmpty())
            registe_configure->setObjectName(QString::fromUtf8("registe_configure"));
        registe_configure->resize(789, 300);
        buttonBox = new QDialogButtonBox(registe_configure);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 230, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(registe_configure);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 60, 741, 161));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(29, 40, 671, 85));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        horizontalLayout->addLayout(gridLayout_5);

        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_24->addWidget(label_24, 0, 0, 1, 1);

        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_23->addWidget(label, 0, 0, 1, 1);

        lineEdit_master = new QLineEdit(layoutWidget);
        lineEdit_master->setObjectName(QString::fromUtf8("lineEdit_master"));

        gridLayout_23->addWidget(lineEdit_master, 0, 1, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_24);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_20->addWidget(label_4, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_reg = new QLineEdit(layoutWidget);
        lineEdit_reg->setObjectName(QString::fromUtf8("lineEdit_reg"));

        gridLayout->addWidget(lineEdit_reg, 0, 1, 1, 1);


        gridLayout_20->addLayout(gridLayout, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_20);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_21->addWidget(label_5, 0, 0, 1, 1);

        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_19->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_value = new QLineEdit(layoutWidget);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));

        gridLayout_19->addWidget(lineEdit_value, 0, 1, 1, 1);


        gridLayout_21->addLayout(gridLayout_19, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_21);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        comboBox_iic_mode = new QComboBox(layoutWidget);
        comboBox_iic_mode->setObjectName(QString::fromUtf8("comboBox_iic_mode"));

        gridLayout_3->addWidget(comboBox_iic_mode, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 3);

        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_i2c_write = new QPushButton(layoutWidget);
        pushButton_i2c_write->setObjectName(QString::fromUtf8("pushButton_i2c_write"));

        gridLayout_2->addWidget(pushButton_i2c_write, 0, 0, 1, 1);

        pushButton_i2c_read = new QPushButton(layoutWidget);
        pushButton_i2c_read->setObjectName(QString::fromUtf8("pushButton_i2c_read"));

        gridLayout_2->addWidget(pushButton_i2c_read, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        retranslateUi(registe_configure);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, registe_configure, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, registe_configure, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(registe_configure);
    } // setupUi

    void retranslateUi(QDialog *registe_configure)
    {
        registe_configure->setWindowTitle(QCoreApplication::translate("registe_configure", "\345\257\204\345\255\230\345\231\250\351\205\215\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registe_configure", "I2C Debug", nullptr));
        label_24->setText(QCoreApplication::translate("registe_configure", "SlaveID", nullptr));
        label->setText(QCoreApplication::translate("registe_configure", "0x", nullptr));
        label_4->setText(QCoreApplication::translate("registe_configure", "Reg address", nullptr));
        label_2->setText(QCoreApplication::translate("registe_configure", "0x", nullptr));
        label_5->setText(QCoreApplication::translate("registe_configure", "Value", nullptr));
        label_3->setText(QCoreApplication::translate("registe_configure", "0x", nullptr));
        label_6->setText(QCoreApplication::translate("registe_configure", "Mode:", nullptr));
        pushButton_i2c_write->setText(QCoreApplication::translate("registe_configure", "Write", nullptr));
        pushButton_i2c_read->setText(QCoreApplication::translate("registe_configure", "Read", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registe_configure: public Ui_registe_configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTE_CONFIGURE_H
