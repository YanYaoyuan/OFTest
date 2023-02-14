#ifndef FPGA_H
#define FPGA_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
namespace Ui {
class FPGA;
}

class FPGA : public QDialog
{
    Q_OBJECT

public:
    explicit FPGA(QWidget *parent = nullptr);
    ~FPGA();

    void setLED(QLabel* label, int color, int size);

private slots:
    //void on_FPGA_accepted();

    void on_pushButton_clicked();

private:
    Ui::FPGA *ui;
};

#endif // FPGA_H
