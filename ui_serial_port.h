/********************************************************************************
** Form generated from reading UI file 'serial_port.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_PORT_H
#define UI_SERIAL_PORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial_port
{
public:
    QPushButton *sendBtn;
    QPushButton *updataBtn;
    QPushButton *serialSwitchBtn;
    QLabel *label_27;
    QComboBox *serialVerifyBitComBox;
    QLabel *label_28;
    QComboBox *serialStopBitComBox;
    QLabel *label_26;
    QComboBox *serialDataBitComBox;
    QLabel *label_25;
    QComboBox *serialBandrateComBox;
    QLabel *label_24;
    QComboBox *serialPortComBox;
    QTextEdit *sendTextTextEdit;
    QGroupBox *recGroupBox;
    QTextBrowser *recTextShowTextBrowser;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *hexShowCheckBox;
    QCheckBox *timeStampCheckBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *timingSendCheckBox;
    QCheckBox *flowCheckBox;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *sendTimeEdit;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_4;
    QPushButton *clearRecBtn;
    QCheckBox *flowModeCheckBox;
    QPushButton *clearSendAreaBtn;
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *saveFileCheckBox;
    QLineEdit *saveFileNameEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *hexSendCheckBox;
    QCheckBox *sendNewLineCheckBox;

    void setupUi(QWidget *serial_port)
    {
        if (serial_port->objectName().isEmpty())
            serial_port->setObjectName(QString::fromUtf8("serial_port"));
        serial_port->resize(758, 533);
        sendBtn = new QPushButton(serial_port);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(230, 140, 151, 41));
        updataBtn = new QPushButton(serial_port);
        updataBtn->setObjectName(QString::fromUtf8("updataBtn"));
        updataBtn->setGeometry(QRect(10, 30, 75, 24));
        serialSwitchBtn = new QPushButton(serial_port);
        serialSwitchBtn->setObjectName(QString::fromUtf8("serialSwitchBtn"));
        serialSwitchBtn->setGeometry(QRect(110, 30, 75, 24));
        label_27 = new QLabel(serial_port);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(32, 226, 48, 16));
        serialVerifyBitComBox = new QComboBox(serial_port);
        serialVerifyBitComBox->addItem(QString());
        serialVerifyBitComBox->setObjectName(QString::fromUtf8("serialVerifyBitComBox"));
        serialVerifyBitComBox->setGeometry(QRect(90, 226, 80, 22));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(28);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(serialVerifyBitComBox->sizePolicy().hasHeightForWidth());
        serialVerifyBitComBox->setSizePolicy(sizePolicy);
        serialVerifyBitComBox->setMinimumSize(QSize(10, 12));
        serialVerifyBitComBox->setSizeIncrement(QSize(20, 0));
        label_28 = new QLabel(serial_port);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(32, 276, 48, 16));
        serialStopBitComBox = new QComboBox(serial_port);
        serialStopBitComBox->addItem(QString());
        serialStopBitComBox->addItem(QString());
        serialStopBitComBox->addItem(QString());
        serialStopBitComBox->setObjectName(QString::fromUtf8("serialStopBitComBox"));
        serialStopBitComBox->setEnabled(true);
        serialStopBitComBox->setGeometry(QRect(90, 276, 80, 22));
        sizePolicy.setHeightForWidth(serialStopBitComBox->sizePolicy().hasHeightForWidth());
        serialStopBitComBox->setSizePolicy(sizePolicy);
        serialStopBitComBox->setMinimumSize(QSize(10, 10));
        serialStopBitComBox->setSizeIncrement(QSize(38, 0));
        label_26 = new QLabel(serial_port);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(32, 178, 48, 16));
        serialDataBitComBox = new QComboBox(serial_port);
        serialDataBitComBox->addItem(QString());
        serialDataBitComBox->setObjectName(QString::fromUtf8("serialDataBitComBox"));
        serialDataBitComBox->setGeometry(QRect(90, 178, 80, 22));
        sizePolicy.setHeightForWidth(serialDataBitComBox->sizePolicy().hasHeightForWidth());
        serialDataBitComBox->setSizePolicy(sizePolicy);
        serialDataBitComBox->setMinimumSize(QSize(10, 12));
        serialDataBitComBox->setSizeIncrement(QSize(20, 0));
        label_25 = new QLabel(serial_port);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(32, 130, 48, 16));
        serialBandrateComBox = new QComboBox(serial_port);
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->addItem(QString());
        serialBandrateComBox->setObjectName(QString::fromUtf8("serialBandrateComBox"));
        serialBandrateComBox->setGeometry(QRect(90, 130, 80, 22));
        sizePolicy.setHeightForWidth(serialBandrateComBox->sizePolicy().hasHeightForWidth());
        serialBandrateComBox->setSizePolicy(sizePolicy);
        serialBandrateComBox->setMinimumSize(QSize(10, 12));
        serialBandrateComBox->setSizeIncrement(QSize(20, 0));
        label_24 = new QLabel(serial_port);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(32, 82, 48, 16));
        serialPortComBox = new QComboBox(serial_port);
        serialPortComBox->setObjectName(QString::fromUtf8("serialPortComBox"));
        serialPortComBox->setGeometry(QRect(90, 82, 80, 22));
        sizePolicy.setHeightForWidth(serialPortComBox->sizePolicy().hasHeightForWidth());
        serialPortComBox->setSizePolicy(sizePolicy);
        serialPortComBox->setMinimumSize(QSize(10, 12));
        serialPortComBox->setSizeIncrement(QSize(20, 0));
        sendTextTextEdit = new QTextEdit(serial_port);
        sendTextTextEdit->setObjectName(QString::fromUtf8("sendTextTextEdit"));
        sendTextTextEdit->setGeometry(QRect(410, 70, 290, 192));
        recGroupBox = new QGroupBox(serial_port);
        recGroupBox->setObjectName(QString::fromUtf8("recGroupBox"));
        recGroupBox->setGeometry(QRect(200, 270, 531, 241));
        QFont font;
        font.setFamilies({QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R")});
        font.setPointSize(11);
        recGroupBox->setFont(font);
        recTextShowTextBrowser = new QTextBrowser(recGroupBox);
        recTextShowTextBrowser->setObjectName(QString::fromUtf8("recTextShowTextBrowser"));
        recTextShowTextBrowser->setGeometry(QRect(210, 30, 290, 192));
        widget = new QWidget(recGroupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 21, 181, 215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hexShowCheckBox = new QCheckBox(widget);
        hexShowCheckBox->setObjectName(QString::fromUtf8("hexShowCheckBox"));
        hexShowCheckBox->setEnabled(true);
        hexShowCheckBox->setMinimumSize(QSize(50, 30));

        horizontalLayout->addWidget(hexShowCheckBox);

        timeStampCheckBox = new QCheckBox(widget);
        timeStampCheckBox->setObjectName(QString::fromUtf8("timeStampCheckBox"));

        horizontalLayout->addWidget(timeStampCheckBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        timingSendCheckBox = new QCheckBox(widget);
        timingSendCheckBox->setObjectName(QString::fromUtf8("timingSendCheckBox"));

        horizontalLayout_4->addWidget(timingSendCheckBox);

        flowCheckBox = new QCheckBox(widget);
        flowCheckBox->setObjectName(QString::fromUtf8("flowCheckBox"));

        horizontalLayout_4->addWidget(flowCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sendTimeEdit = new QLineEdit(widget);
        sendTimeEdit->setObjectName(QString::fromUtf8("sendTimeEdit"));

        horizontalLayout_5->addWidget(sendTimeEdit);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        clearRecBtn = new QPushButton(widget);
        clearRecBtn->setObjectName(QString::fromUtf8("clearRecBtn"));

        verticalLayout->addWidget(clearRecBtn);

        flowModeCheckBox = new QCheckBox(serial_port);
        flowModeCheckBox->setObjectName(QString::fromUtf8("flowModeCheckBox"));
        flowModeCheckBox->setGeometry(QRect(70, 350, 105, 24));
        clearSendAreaBtn = new QPushButton(serial_port);
        clearSendAreaBtn->setObjectName(QString::fromUtf8("clearSendAreaBtn"));
        clearSendAreaBtn->setGeometry(QRect(230, 200, 151, 41));
        label_6 = new QLabel(serial_port);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 33, 273, 31));
        layoutWidget = new QWidget(serial_port);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 20, 224, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        saveFileCheckBox = new QCheckBox(layoutWidget);
        saveFileCheckBox->setObjectName(QString::fromUtf8("saveFileCheckBox"));

        horizontalLayout_2->addWidget(saveFileCheckBox);

        saveFileNameEdit = new QLineEdit(layoutWidget);
        saveFileNameEdit->setObjectName(QString::fromUtf8("saveFileNameEdit"));

        horizontalLayout_2->addWidget(saveFileNameEdit);

        layoutWidget1 = new QWidget(serial_port);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(serial_port);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(serial_port);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(220, 80, 164, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        hexSendCheckBox = new QCheckBox(layoutWidget3);
        hexSendCheckBox->setObjectName(QString::fromUtf8("hexSendCheckBox"));

        horizontalLayout_6->addWidget(hexSendCheckBox);

        sendNewLineCheckBox = new QCheckBox(layoutWidget3);
        sendNewLineCheckBox->setObjectName(QString::fromUtf8("sendNewLineCheckBox"));

        horizontalLayout_6->addWidget(sendNewLineCheckBox);

#if QT_CONFIG(shortcut)
        label_6->setBuddy(label_6);
#endif // QT_CONFIG(shortcut)

        retranslateUi(serial_port);

        QMetaObject::connectSlotsByName(serial_port);
    } // setupUi

    void retranslateUi(QWidget *serial_port)
    {
        serial_port->setWindowTitle(QCoreApplication::translate("serial_port", "\344\270\262\345\217\243\350\260\203\350\257\225", nullptr));
        sendBtn->setText(QCoreApplication::translate("serial_port", "\345\217\221\351\200\201\346\265\213\350\257\225", nullptr));
        updataBtn->setText(QCoreApplication::translate("serial_port", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        serialSwitchBtn->setText(QCoreApplication::translate("serial_port", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_27->setText(QCoreApplication::translate("serial_port", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        serialVerifyBitComBox->setItemText(0, QCoreApplication::translate("serial_port", "None", nullptr));

        label_28->setText(QCoreApplication::translate("serial_port", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        serialStopBitComBox->setItemText(0, QCoreApplication::translate("serial_port", "1", nullptr));
        serialStopBitComBox->setItemText(1, QCoreApplication::translate("serial_port", "2", nullptr));
        serialStopBitComBox->setItemText(2, QCoreApplication::translate("serial_port", "3", nullptr));

        label_26->setText(QCoreApplication::translate("serial_port", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        serialDataBitComBox->setItemText(0, QCoreApplication::translate("serial_port", "8", nullptr));

        label_25->setText(QCoreApplication::translate("serial_port", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        serialBandrateComBox->setItemText(0, QCoreApplication::translate("serial_port", "600", nullptr));
        serialBandrateComBox->setItemText(1, QCoreApplication::translate("serial_port", "1200", nullptr));
        serialBandrateComBox->setItemText(2, QCoreApplication::translate("serial_port", "2400", nullptr));
        serialBandrateComBox->setItemText(3, QCoreApplication::translate("serial_port", "4800", nullptr));
        serialBandrateComBox->setItemText(4, QCoreApplication::translate("serial_port", "9600", nullptr));
        serialBandrateComBox->setItemText(5, QCoreApplication::translate("serial_port", "19200", nullptr));
        serialBandrateComBox->setItemText(6, QCoreApplication::translate("serial_port", "38400", nullptr));
        serialBandrateComBox->setItemText(7, QCoreApplication::translate("serial_port", "115200", nullptr));

        label_24->setText(QCoreApplication::translate("serial_port", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        recGroupBox->setTitle(QCoreApplication::translate("serial_port", " \346\216\245\346\224\266\345\214\272\357\274\232\345\267\262\346\216\245\346\224\2660\345\255\227\350\212\202", nullptr));
        hexShowCheckBox->setText(QCoreApplication::translate("serial_port", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        timeStampCheckBox->setText(QCoreApplication::translate("serial_port", "\346\227\266\351\227\264\346\210\263", nullptr));
        timingSendCheckBox->setText(QCoreApplication::translate("serial_port", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        flowCheckBox->setText(QCoreApplication::translate("serial_port", "\346\265\201\346\216\247\351\200\211\346\213\251", nullptr));
        label_7->setText(QCoreApplication::translate("serial_port", "\346\257\253\347\247\222(ms)", nullptr));
        clearRecBtn->setText(QCoreApplication::translate("serial_port", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        flowModeCheckBox->setText(QCoreApplication::translate("serial_port", "\347\241\254\344\273\266\346\265\201\346\216\247", nullptr));
        clearSendAreaBtn->setText(QCoreApplication::translate("serial_port", "\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", nullptr));
        label_6->setText(QCoreApplication::translate("serial_port", "\345\217\221\351\200\201", nullptr));
        saveFileCheckBox->setText(QCoreApplication::translate("serial_port", "\344\277\235\345\255\230\345\210\260\346\226\207\344\273\266", nullptr));
        hexSendCheckBox->setText(QCoreApplication::translate("serial_port", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        sendNewLineCheckBox->setText(QCoreApplication::translate("serial_port", "\345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial_port: public Ui_serial_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_PORT_H
