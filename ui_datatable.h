/********************************************************************************
** Form generated from reading UI file 'datatable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATABLE_H
#define UI_DATATABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_datatable
{
public:
    QTableView *tableView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *freshData;
    QPushButton *frist_Frame;
    QPushButton *last_Frame;
    QPushButton *next_Frame;
    QPushButton *skip_to;
    QLineEdit *num_Frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_6;
    QLabel *label_total;
    QPushButton *current_Frame;
    QLabel *label_current;
    QPushButton *pushButton_7;
    QLabel *label_single;
    QPushButton *saveCurrent_Frame;
    QLineEdit *savecurptahEdit;

    void setupUi(QDialog *datatable)
    {
        if (datatable->objectName().isEmpty())
            datatable->setObjectName(QString::fromUtf8("datatable"));
        datatable->resize(719, 699);
        tableView = new QTableView(datatable);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 100, 611, 571));
        layoutWidget = new QWidget(datatable);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(51, 21, 547, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        freshData = new QPushButton(layoutWidget);
        freshData->setObjectName(QString::fromUtf8("freshData"));

        horizontalLayout->addWidget(freshData);

        frist_Frame = new QPushButton(layoutWidget);
        frist_Frame->setObjectName(QString::fromUtf8("frist_Frame"));

        horizontalLayout->addWidget(frist_Frame);

        last_Frame = new QPushButton(layoutWidget);
        last_Frame->setObjectName(QString::fromUtf8("last_Frame"));

        horizontalLayout->addWidget(last_Frame);

        next_Frame = new QPushButton(layoutWidget);
        next_Frame->setObjectName(QString::fromUtf8("next_Frame"));

        horizontalLayout->addWidget(next_Frame);

        skip_to = new QPushButton(layoutWidget);
        skip_to->setObjectName(QString::fromUtf8("skip_to"));

        horizontalLayout->addWidget(skip_to);

        num_Frame = new QLineEdit(layoutWidget);
        num_Frame->setObjectName(QString::fromUtf8("num_Frame"));

        horizontalLayout->addWidget(num_Frame);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        label_total = new QLabel(layoutWidget);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        horizontalLayout_2->addWidget(label_total);

        current_Frame = new QPushButton(layoutWidget);
        current_Frame->setObjectName(QString::fromUtf8("current_Frame"));

        horizontalLayout_2->addWidget(current_Frame);

        label_current = new QLabel(layoutWidget);
        label_current->setObjectName(QString::fromUtf8("label_current"));

        horizontalLayout_2->addWidget(label_current);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        label_single = new QLabel(layoutWidget);
        label_single->setObjectName(QString::fromUtf8("label_single"));

        horizontalLayout_2->addWidget(label_single);

        saveCurrent_Frame = new QPushButton(layoutWidget);
        saveCurrent_Frame->setObjectName(QString::fromUtf8("saveCurrent_Frame"));

        horizontalLayout_2->addWidget(saveCurrent_Frame);

        savecurptahEdit = new QLineEdit(layoutWidget);
        savecurptahEdit->setObjectName(QString::fromUtf8("savecurptahEdit"));

        horizontalLayout_2->addWidget(savecurptahEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(datatable);

        QMetaObject::connectSlotsByName(datatable);
    } // setupUi

    void retranslateUi(QDialog *datatable)
    {
        datatable->setWindowTitle(QCoreApplication::translate("datatable", "\347\202\271\344\272\221\346\225\260\346\215\256\350\241\250", nullptr));
        freshData->setText(QCoreApplication::translate("datatable", "\345\210\267\346\226\260\346\225\260\346\215\256", nullptr));
        frist_Frame->setText(QCoreApplication::translate("datatable", "\350\265\267\345\247\213\345\270\247", nullptr));
        last_Frame->setText(QCoreApplication::translate("datatable", "\344\270\212\344\270\200\345\270\247", nullptr));
        next_Frame->setText(QCoreApplication::translate("datatable", "\344\270\213\344\270\200\345\270\247", nullptr));
        skip_to->setText(QCoreApplication::translate("datatable", "\350\267\263\350\275\254", nullptr));
        pushButton_6->setText(QCoreApplication::translate("datatable", "\346\200\273\345\270\247\346\225\260\357\274\232", nullptr));
        label_total->setText(QCoreApplication::translate("datatable", "TextLabel", nullptr));
        current_Frame->setText(QCoreApplication::translate("datatable", "\345\275\223\345\211\215\345\270\247\357\274\232", nullptr));
        label_current->setText(QCoreApplication::translate("datatable", "TextLabel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("datatable", "\345\215\225\345\270\247\347\202\271\346\225\260\357\274\232", nullptr));
        label_single->setText(QCoreApplication::translate("datatable", "TextLabel", nullptr));
        saveCurrent_Frame->setText(QCoreApplication::translate("datatable", "\345\255\230\345\202\250\345\275\223\345\211\215\345\270\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class datatable: public Ui_datatable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATABLE_H
