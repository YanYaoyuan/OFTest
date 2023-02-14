#ifndef TEMPERATURE_REALSHOW_H
#define TEMPERATURE_REALSHOW_H

#include <QWidget>

namespace Ui {
class temperature_realshow;
}

class temperature_realshow : public QWidget
{
    Q_OBJECT

public:
    explicit temperature_realshow(QWidget *parent = nullptr);
    ~temperature_realshow();

private:
    Ui::temperature_realshow *ui;
};

#endif // TEMPERATURE_REALSHOW_H
