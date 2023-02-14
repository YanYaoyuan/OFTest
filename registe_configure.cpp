#include "registe_configure.h"
#include "ui_registe_configure.h"
#include <iostream>
#define DT_ERROR_OK		1


registe_configure::registe_configure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registe_configure)
{
    ui->setupUi(this);
}

registe_configure::~registe_configure()
{
    delete ui;
}

void registe_configure::on_pushButton_clicked()
{
    std::cout<<"config"<<std::endl;
}

void registe_configure::on_pushButton_i2c_write_clicked()
{
    QString text;
    bool bOk;

    //text = ui->comboBox_module->currentText();
    //unsigned int uModule = text.toInt(&bOk, 16);

    text = ui->lineEdit_master->text();
    //TITAN_INFO("%s:materaddr=%s\n", __FUNCTION__, text.toLatin1().data());
    unsigned int uMasterAddr = text.toUInt(&bOk, 16);

    text = ui->lineEdit_reg->text();
    unsigned int uRegAddr = text.toUInt(&bOk, 16);

    text = ui->lineEdit_value->text();
    unsigned int uRegValue = text.toUInt(&bOk, 16);

    text = ui->comboBox_iic_mode->currentText();
    unsigned int uMode = text.toUInt();

    int iRet = DT_ERROR_OK;

    //烧写接口
    //iRet = WriteSensorReg(uMasterAddr, uRegAddr, uRegValue, uMode, m_nDevID);

//    TITAN_INFO("%s:masteraddr=%x,regaddr=%x,value=%x,umode=%x\n", __FUNCTION__,
//               uMasterAddr, uRegAddr, uRegValue, uMode);
    if (iRet != DT_ERROR_OK)
    {
        //TITAN_INFO("%s:data write iic fail\n", __FUNCTION__);
    }
    else
    {

    }
}

void registe_configure::on_pushButton_i2c_read_clicked()
{
    QString text;
    bool bOk;

    //text = ui->comboBox_module->currentText();
    //unsigned int uModule = text.toInt(&bOk, 16);

    text = ui->lineEdit_master->text();
    unsigned int uMasterAddr = text.toInt(&bOk, 16);

    text = ui->lineEdit_reg->text();
    unsigned int uRegAddr = text.toInt(&bOk, 16);

    text = ui->lineEdit_value->text();
    unsigned int  uRegValue = text.toInt(&bOk, 16);

    text = ui->comboBox_iic_mode->currentText();
    unsigned int uMode = text.toInt(&bOk, 16);

    int iRet = DT_ERROR_OK;

    //读取接口
    //iRet = ReadSensorReg(uMasterAddr, uRegAddr, &uRegValue, uMode, m_nDevID);

//    TITAN_INFO("%s:masteraddr=%x,regaddr=%x,value=%x,umode=%x\n", __FUNCTION__,
//               uMasterAddr, uRegAddr, uRegValue, uMode);
    if (iRet != DT_ERROR_OK)
    {
        //TITAN_INFO("%s:data write iic fail\n", __FUNCTION__);
    }
    else
    {

    }

    text = QString("%1").arg(uRegValue, 4, 16, QChar('0'));
    ui->lineEdit_value->setText(text);
}

