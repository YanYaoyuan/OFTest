#ifndef DATATABLE_H
#define DATATABLE_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableView>
#include <QtGui/QStandardItemModel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

class MainWindow;

namespace Ui {
class datatable;
}

class datatable : public QDialog
{
    Q_OBJECT



public:
    explicit datatable(QWidget *parent = nullptr);

    ~datatable();

    void createtable();





private slots:
    void on_freshData_clicked();

    void getData(MainWindow *myWindow);

private:
    Ui::datatable *ui;
    datatable *table;

    MainWindow *myWindow;

    int col_table = 100;
    int row_table = 6;
    std::vector<std::string> point_x;
    std::vector<std::string> point_y;
    std::vector<std::string> point_z;

    void showTable();

};

#endif // DATATABLE_H
