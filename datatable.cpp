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
    //先清空字符串容器
    point_x.clear();
    point_y.clear();
    point_z.clear();

    getData(myWindow);
    showTable();




}

void datatable::getData(MainWindow *myWindow)
{
    myWindow->consoleLog("get point data", "dataTable", "show", "");

    //获取当前点云集总帧数
    total_Frame = myWindow->mycloud_vec.size();
    col_table = myWindow->mycloud_vec[current_Frame].cloud->points.size() - 1;
    for(int i = 0; i < myWindow->mycloud_vec[current_Frame].cloud->points.size(); i++)
    {
        point_x.push_back(std::to_string(myWindow->mycloud_vec[current_Frame].cloud->points[i].x));
        point_y.push_back(std::to_string(myWindow->mycloud_vec[current_Frame].cloud->points[i].y));
        point_z.push_back(std::to_string(myWindow->mycloud_vec[current_Frame].cloud->points[i].z));
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
    //表格上方帧数信息显示
    ui->label_current->setText(QString::number(current_Frame + 1));
    ui->label_single->setText(QString::number(col_table));
    ui->label_total->setText(QString::number(total_Frame));
}




void datatable::on_saveCurrent_Frame_clicked()
{
    //保存当前帧
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,
            tr("Save Current Frame Data"), "",
            tr("PCD Files (*.pcd);; PLY File(*.ply);;OBJ File(*obj);; VTK File(*.vtk);; Text File(*.txt)"));
    std::cout << "Current frame is " << current_Frame + 1 << "'s" << std::endl;
}
//显示最开始的数据表
void datatable::on_frist_Frame_clicked()
{
    //将当前帧数设为0，每一次重新显示时候将数据容器清空
    current_Frame = 0;
    point_x.clear();
    point_y.clear();
    point_z.clear();

    getData(myWindow);
    showTable();
}
//显示上一帧数据表
void datatable::on_last_Frame_clicked()
{
    if(current_Frame > 0)
    {
        current_Frame -= 1;
        point_x.clear();
        point_y.clear();
        point_z.clear();
        getData(myWindow);
        showTable();

    }else
    {
        std::cout << "Already First Frame!!!" << std::endl;
    }
}
//显示下一帧数据表
void datatable::on_next_Frame_clicked()
{

    current_Frame += 1;
    point_x.clear();
    point_y.clear();
    point_z.clear();
    if(current_Frame < total_Frame)
    {
        getData(myWindow);
        showTable();
    }else{
        std::cout << "End of Frame!!!" << std::endl;
    }

}
//跳转到指定帧数页面
void datatable::on_skip_to_clicked()
{
    point_x.clear();
    point_y.clear();
    point_z.clear();
    QString s = ui->num_Frame->text();
    current_Frame = s.toInt();
    if(current_Frame < (total_Frame-1) && current_Frame >=0)
    {
        getData(myWindow);
        showTable();
    }else
    {
        std::cout << "Invaild number!!!" << std::endl;
    }
}
