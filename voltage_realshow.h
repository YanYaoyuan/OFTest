#ifndef VOLTAGE_REALSHOW_H
#define VOLTAGE_REALSHOW_H

#include <QWidget>

namespace Ui {
class voltage_realshow;
}

class voltage_realshow : public QWidget
{
    Q_OBJECT

public:
    explicit voltage_realshow(QWidget *parent = nullptr);
    ~voltage_realshow();

private:
    Ui::voltage_realshow *ui;
};

#endif // VOLTAGE_REALSHOW_H
