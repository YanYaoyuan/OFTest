/********************************************************************************
** Form generated from reading UI file 'mems.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMS_H
#define UI_MEMS_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mems
{
public:
    QChartView *chartViewQSpline;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *chkDataPoint;
    QCheckBox *chkDataPointLabelVisible;
    QPushButton *btnSplinePointColor;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_26;
    QLabel *label_6;
    QLineEdit *lineEdit_master_6;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_25;
    QLabel *label_2;
    QLineEdit *lineEdit_master_2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_31;
    QLabel *label_3;
    QLineEdit *lineEdit_master_3;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_29;
    QLabel *label_4;
    QLineEdit *lineEdit_master_4;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_32;
    QLabel *label_5;
    QLineEdit *lineEdit_master_5;
    QPushButton *pushButton_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mems_serial_test;
    QPushButton *mems_showdata;
    QPushButton *mems_refresh;

    void setupUi(QWidget *mems)
    {
        if (mems->objectName().isEmpty())
            mems->setObjectName(QString::fromUtf8("mems"));
        mems->resize(975, 553);
        chartViewQSpline = new QChartView(mems);
        chartViewQSpline->setObjectName(QString::fromUtf8("chartViewQSpline"));
        chartViewQSpline->setGeometry(QRect(420, 10, 521, 431));
        chartViewQSpline->setMinimumSize(QSize(400, 300));
        groupBox = new QGroupBox(mems);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 290, 261, 191));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chkDataPoint = new QCheckBox(groupBox);
        chkDataPoint->setObjectName(QString::fromUtf8("chkDataPoint"));

        gridLayout->addWidget(chkDataPoint, 1, 1, 1, 1);

        chkDataPointLabelVisible = new QCheckBox(groupBox);
        chkDataPointLabelVisible->setObjectName(QString::fromUtf8("chkDataPointLabelVisible"));

        gridLayout->addWidget(chkDataPointLabelVisible, 2, 1, 1, 1);

        btnSplinePointColor = new QPushButton(groupBox);
        btnSplinePointColor->setObjectName(QString::fromUtf8("btnSplinePointColor"));
        btnSplinePointColor->setMinimumSize(QSize(121, 41));

        gridLayout->addWidget(btnSplinePointColor, 0, 1, 1, 1);

        layoutWidget = new QWidget(mems);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 341, 191));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_26);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(60, 0));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_master_6 = new QLineEdit(layoutWidget);
        lineEdit_master_6->setObjectName(QString::fromUtf8("lineEdit_master_6"));

        horizontalLayout_7->addWidget(lineEdit_master_6);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_7->addWidget(pushButton_6);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_25);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_master_2 = new QLineEdit(layoutWidget);
        lineEdit_master_2->setObjectName(QString::fromUtf8("lineEdit_master_2"));

        horizontalLayout_2->addWidget(lineEdit_master_2);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_31 = new QLabel(layoutWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setMinimumSize(QSize(84, 0));
        label_31->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_31);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(60, 0));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_master_3 = new QLineEdit(layoutWidget);
        lineEdit_master_3->setObjectName(QString::fromUtf8("lineEdit_master_3"));

        horizontalLayout_3->addWidget(lineEdit_master_3);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(84, 0));
        label_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_29);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_master_4 = new QLineEdit(layoutWidget);
        lineEdit_master_4->setObjectName(QString::fromUtf8("lineEdit_master_4"));

        horizontalLayout_4->addWidget(lineEdit_master_4);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_32 = new QLabel(layoutWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setMinimumSize(QSize(84, 0));
        label_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_32);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(60, 0));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_master_5 = new QLineEdit(layoutWidget);
        lineEdit_master_5->setObjectName(QString::fromUtf8("lineEdit_master_5"));

        horizontalLayout_6->addWidget(lineEdit_master_5);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_6->addWidget(pushButton_5);


        gridLayout_2->addLayout(horizontalLayout_6, 4, 0, 1, 1);

        widget = new QWidget(mems);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 291, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mems_serial_test = new QPushButton(widget);
        mems_serial_test->setObjectName(QString::fromUtf8("mems_serial_test"));

        horizontalLayout->addWidget(mems_serial_test);

        mems_showdata = new QPushButton(widget);
        mems_showdata->setObjectName(QString::fromUtf8("mems_showdata"));

        horizontalLayout->addWidget(mems_showdata);

        mems_refresh = new QPushButton(widget);
        mems_refresh->setObjectName(QString::fromUtf8("mems_refresh"));

        horizontalLayout->addWidget(mems_refresh);


        retranslateUi(mems);

        QMetaObject::connectSlotsByName(mems);
    } // setupUi

    void retranslateUi(QWidget *mems)
    {
        mems->setWindowTitle(QCoreApplication::translate("mems", "2D mems", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mems", "\345\212\237\350\203\275", nullptr));
        chkDataPoint->setText(QCoreApplication::translate("mems", "\346\230\276\347\244\272\346\225\260\346\215\256\347\202\271", nullptr));
        chkDataPointLabelVisible->setText(QCoreApplication::translate("mems", "\346\230\276\347\244\272\346\225\260\346\215\256\347\202\271\346\240\207\347\255\276", nullptr));
        btnSplinePointColor->setText(QCoreApplication::translate("mems", "\345\205\211\346\273\221\346\233\262\347\272\277\351\242\234\350\211\262", nullptr));
        label_26->setText(QCoreApplication::translate("mems", "\345\277\253\350\275\264\351\242\221\347\216\207(HZ)\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("mems", "TextLabel", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mems", "\350\256\276\345\256\232", nullptr));
        label_25->setText(QCoreApplication::translate("mems", "\346\205\242\350\275\264\351\242\221\347\216\207(HZ)\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("mems", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mems", "\350\256\276\345\256\232", nullptr));
        label_31->setText(QCoreApplication::translate("mems", "\345\277\253\350\275\264\346\211\253\347\216\207()\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("mems", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mems", "\350\256\276\345\256\232", nullptr));
        label_29->setText(QCoreApplication::translate("mems", "\347\224\265\345\216\213(V)\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("mems", "TextLabel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mems", "\350\256\276\345\256\232", nullptr));
        label_32->setText(QCoreApplication::translate("mems", "\347\224\265\345\216\213\345\271\205\345\200\274(V)\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("mems", "TextLabel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mems", "\350\256\276\345\256\232", nullptr));
        mems_serial_test->setText(QCoreApplication::translate("mems", "\346\265\213\350\257\225\344\270\262\345\217\243", nullptr));
        mems_showdata->setText(QCoreApplication::translate("mems", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        mems_refresh->setText(QCoreApplication::translate("mems", "\345\210\267\346\226\260\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mems: public Ui_mems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMS_H
