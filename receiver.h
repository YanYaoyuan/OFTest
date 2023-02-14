#ifndef RECEIVER_H
#define RECEIVER_H

#include <QtWidgets/QWidget>

namespace Ui {
class receiver;
}

class receiver : public QWidget
{
    Q_OBJECT

public:
    explicit receiver(QWidget *parent = nullptr);
    ~receiver();

private:
    Ui::receiver *ui;
};

#endif // RECEIVER_H
