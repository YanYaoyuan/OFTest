#include "laser.h"
#include "ui_laser.h"

Laser::Laser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Laser)
{
    ui->setupUi(this);
}

Laser::~Laser()
{
    delete ui;
}



