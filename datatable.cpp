#include "datatable.h"
#include "ui_datatable.h"
#include <iostream>



datatable::datatable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::datatable),
    myWindow(static_cast<MainWindow*>(parent))
{
    ui->setupUi(this);
}

datatable::~datatable()
{
    delete ui;
}


void datatable::createtable()
{


    //表格设置
    QStandardItemModel* m_model;
    m_model = new QStandardItemModel(10,2);
    QStringList labels = QString("Index,X,Y,Z,PEAK,NONE").simplified().split(",");
    m_model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                 "color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");
    //定义item
    QStandardItem* item = 0;
    for(int i = 16;i <= 25; i++){
        item = new QStandardItem(QString("%1").arg(i));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        m_model->setItem(i-16,0,item);
    }


    ui->tableView->verticalHeader()->hide();
    for(int i = 0; i < ui->tableView->horizontalHeader()->count(); i++)
    {
        ui->tableView->setColumnWidth(i,200);
    }

    ui->tableView->showNormal();
}



void datatable::on_freshData_clicked()
{


    //ui->tableView->update();
   // std::cout << MainWindow::mycloud_vec[0].cloud->points.size() << std::endl;
    getData(myWindow);
    showTable();


}

void datatable::getData(MainWindow *myWindow)
{
    std::cout <<"111" << std::endl;
    myWindow->consoleLog("get point data", "dataTable", "show", "");
    std::cout <<myWindow->mycloud_vec.size() << std::endl;
    col_table = myWindow->mycloud_vec[0].cloud->points.size() - 1;
    for(int i = 0; i < myWindow->mycloud_vec[0].cloud->points.size(); i++)
    {
        point_x.push_back(std::to_string(myWindow->mycloud_vec[0].cloud->points[i].x));
        point_y.push_back(std::to_string(myWindow->mycloud_vec[0].cloud->points[i].y));
        point_z.push_back(std::to_string(myWindow->mycloud_vec[0].cloud->points[i].z));
    }




}

void datatable::showTable()
{
    //表格设置
    QStandardItemModel* m_model;
    m_model = new QStandardItemModel(col_table,row_table);
    QStringList labels = QString("Index,X,Y,Z,PEAK,NA").simplified().split(",");
    m_model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                 "color: black;padding-left: 1px;border: 1px solid #6c6c6c;}");
    //定义item
    QStandardItem* item = 0;
    for(int i = 0;i <= col_table; i++){
        item = new QStandardItem(QString("%1").arg(i));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        m_model->setItem(i,0,item);
    }


    ui->tableView->verticalHeader()->hide();
    //std::cout<<ui->tableView->horizontalHeader()->count()<<std::endl;
    for(int i = 0; i < ui->tableView->horizontalHeader()->count(); i++)
    {
        ui->tableView->setColumnWidth(i,90);
    }
    for(int i = 0; i <= col_table; i++)
    {
        m_model->setItem(i, 1, new QStandardItem(QString::fromStdString(point_x[i])));
        m_model->setItem(i, 2, new QStandardItem(QString::fromStdString(point_y[i])));
        m_model->setItem(i, 3, new QStandardItem(QString::fromStdString(point_z[i])));
    }




}

