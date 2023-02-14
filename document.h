#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QtWidgets/QDialog>

namespace Ui {
class document;
}

class document : public QDialog
{
    Q_OBJECT

public:
    explicit document(QWidget *parent = nullptr);
    ~document();

private slots:
    //void closeEvent(QCloseEvent *e) override;
    //void on_document_accepted();


    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_textEdit_copyAvailable(bool b);

private:
    Ui::document *ui;
};

#endif // DOCUMENT_H
