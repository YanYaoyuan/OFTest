/********************************************************************************
** Form generated from reading UI file 'adc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADC_H
#define UI_ADC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_adc
{
public:
    QPushButton *adc_refresh;
    QChartView *adc_QSpline;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QTableView *peak_index;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_27;
    QComboBox *min_distance;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_26;
    QComboBox *peak_num;

    void setupUi(QWidget *adc)
    {
        if (adc->objectName().isEmpty())
            adc->setObjectName(QString::fromUtf8("adc"));
        adc->resize(973, 606);
        adc_refresh = new QPushButton(adc);
        adc_refresh->setObjectName(QString::fromUtf8("adc_refresh"));
        adc_refresh->setGeometry(QRect(30, 50, 75, 24));
        adc_QSpline = new QChartView(adc);
        adc_QSpline->setObjectName(QString::fromUtf8("adc_QSpline"));
        adc_QSpline->setGeometry(QRect(210, 20, 741, 551));
        adc_QSpline->setMinimumSize(QSize(400, 300));
        checkBox = new QCheckBox(adc);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 80, 101, 41));
        pushButton = new QPushButton(adc);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 130, 75, 24));
        peak_index = new QTableView(adc);
        peak_index->setObjectName(QString::fromUtf8("peak_index"));
        peak_index->setGeometry(QRect(10, 260, 161, 201));
        pushButton_2 = new QPushButton(adc);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 470, 101, 31));
        pushButton_3 = new QPushButton(adc);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 130, 75, 24));
        layoutWidget = new QWidget(adc);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 210, 151, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_27);

        min_distance = new QComboBox(layoutWidget);
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->addItem(QString());
        min_distance->setObjectName(QString::fromUtf8("min_distance"));

        horizontalLayout_2->addWidget(min_distance);

        layoutWidget1 = new QWidget(adc);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 170, 151, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_26);

        peak_num = new QComboBox(layoutWidget1);
        peak_num->addItem(QString());
        peak_num->addItem(QString());
        peak_num->addItem(QString());
        peak_num->addItem(QString());
        peak_num->addItem(QString());
        peak_num->addItem(QString());
        peak_num->setObjectName(QString::fromUtf8("peak_num"));

        horizontalLayout->addWidget(peak_num);


        retranslateUi(adc);

        QMetaObject::connectSlotsByName(adc);
    } // setupUi

    void retranslateUi(QWidget *adc)
    {
        adc->setWindowTitle(QCoreApplication::translate("adc", "Form", nullptr));
        adc_refresh->setText(QCoreApplication::translate("adc", "\345\210\267\346\226\260\346\225\260\346\215\256", nullptr));
        checkBox->setText(QCoreApplication::translate("adc", "\346\230\276\347\244\272\347\244\272\344\276\213\347\272\277", nullptr));
        pushButton->setText(QCoreApplication::translate("adc", "\345\257\273\345\263\2601", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adc", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("adc", "\345\257\273\345\263\2602", nullptr));
        label_27->setText(QCoreApplication::translate("adc", "\346\234\200\345\260\217\350\267\235\347\246\273\357\274\232", nullptr));
        min_distance->setItemText(0, QCoreApplication::translate("adc", "5", nullptr));
        min_distance->setItemText(1, QCoreApplication::translate("adc", "10", nullptr));
        min_distance->setItemText(2, QCoreApplication::translate("adc", "20", nullptr));
        min_distance->setItemText(3, QCoreApplication::translate("adc", "30", nullptr));
        min_distance->setItemText(4, QCoreApplication::translate("adc", "50", nullptr));
        min_distance->setItemText(5, QCoreApplication::translate("adc", "100", nullptr));
        min_distance->setItemText(6, QCoreApplication::translate("adc", "200", nullptr));

        label_26->setText(QCoreApplication::translate("adc", "\345\263\260\345\200\274\344\270\252\346\225\260\357\274\232", nullptr));
        peak_num->setItemText(0, QCoreApplication::translate("adc", "1", nullptr));
        peak_num->setItemText(1, QCoreApplication::translate("adc", "2", nullptr));
        peak_num->setItemText(2, QCoreApplication::translate("adc", "3", nullptr));
        peak_num->setItemText(3, QCoreApplication::translate("adc", "4", nullptr));
        peak_num->setItemText(4, QCoreApplication::translate("adc", "5", nullptr));
        peak_num->setItemText(5, QCoreApplication::translate("adc", "6", nullptr));

    } // retranslateUi

};

namespace Ui {
    class adc: public Ui_adc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADC_H
