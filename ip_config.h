#ifndef IP_CONFIG_H
#define IP_CONFIG_H

#include <QtWidgets/QDialog>

namespace Ui {
class ip_config;
}

class ip_config : public QDialog
{
    Q_OBJECT

public:
    explicit ip_config(QWidget *parent = nullptr);
    ~ip_config();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void on_lineEdit_master_selectionChanged();

private:
    Ui::ip_config *ui;
};

#endif // IP_CONFIG_H
