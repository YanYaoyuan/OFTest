#include "voltage_realshow.h"
#include "ui_voltage_realshow.h"

voltage_realshow::voltage_realshow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::voltage_realshow)
{
    ui->setupUi(this);
}

voltage_realshow::~voltage_realshow()
{
    delete ui;
}
