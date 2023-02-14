#ifndef LASER_H
#define LASER_H

#include <QtWidgets/QDialog>

namespace Ui {
class Laser;
}

class Laser : public QDialog
{
    Q_OBJECT

public:
    explicit Laser(QWidget *parent = nullptr);
    ~Laser();

private slots:
    //void on_Laser_accepted();

private:
    Ui::Laser *ui;
};

#endif // LASER_H
