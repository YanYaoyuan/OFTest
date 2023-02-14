/********************************************************************************
** Form generated from reading UI file 'document.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENT_H
#define UI_DOCUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_document
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *document)
    {
        if (document->objectName().isEmpty())
            document->setObjectName(QString::fromUtf8("document"));
        document->resize(640, 480);
        buttonBox = new QDialogButtonBox(document);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(550, 10, 81, 461));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(document);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 170, 75, 24));
        pushButton_2 = new QPushButton(document);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 90, 75, 24));
        textEdit = new QTextEdit(document);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(430, 190, 104, 71));

        retranslateUi(document);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, document, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, document, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(document);
    } // setupUi

    void retranslateUi(QDialog *document)
    {
        document->setWindowTitle(QCoreApplication::translate("document", "\350\275\257\344\273\266\350\257\264\346\230\216", nullptr));
        pushButton->setText(QCoreApplication::translate("document", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("document", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class document: public Ui_document {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENT_H
