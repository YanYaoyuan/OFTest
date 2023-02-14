#include "temperature_realshow.h"
#include "ui_temperature_realshow.h"

temperature_realshow::temperature_realshow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temperature_realshow)
{
    ui->setupUi(this);
}

temperature_realshow::~temperature_realshow()
{
    delete ui;
}
