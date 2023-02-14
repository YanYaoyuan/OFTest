#include "receiver.h"
#include "ui_receiver.h"

receiver::receiver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::receiver)
{
    ui->setupUi(this);
}

receiver::~receiver()
{
    delete ui;
}
