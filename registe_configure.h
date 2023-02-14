#ifndef REGISTE_CONFIGURE_H
#define REGISTE_CONFIGURE_H

#include <QtWidgets/QDialog>



namespace Ui {
class registe_configure;
}

class registe_configure : public QDialog
{
    Q_OBJECT

public:
    explicit registe_configure(QWidget *parent = nullptr);
    ~registe_configure();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_i2c_write_clicked();

    void on_pushButton_i2c_read_clicked();

private:
    Ui::registe_configure *ui;
    int m_nDevID = 0;
};

#endif // REGISTE_CONFIGURE_H
