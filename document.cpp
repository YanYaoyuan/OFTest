#include "document.h"
#include "ui_document.h"
#include <iostream>
document::document(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::document)
{
    ui->setupUi(this);
}

document::~document()
{
    delete ui;
}

//void document::on_document_accepted()
//{
////    std::cout<<"333333"<<std::endl;
////   // buttonBox = new document();

////    document *doc;
////    doc->show();
//}



void document::on_pushButton_clicked()
{
    std::cout<<"aaaaaa"<<std::endl;
}


void document::on_pushButton_2_clicked()
{

}


void document::on_textEdit_copyAvailable(bool b)
{

}

