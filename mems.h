#ifndef MEMS_H
#define MEMS_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QtCharts>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
//QT_CHARTS_USE_NAMESPACE
namespace Ui {
class mems;
}

class mems : public QWidget
{
    Q_OBJECT

public:
    explicit mems(QWidget *parent = nullptr);
    ~mems();
private slots:

    void on_btnSplinePointColor_clicked();

    void on_chkDataPoint_stateChanged(int arg1);

    void on_chkDataPointLabelVisible_stateChanged(int arg1);


    void on_mems_refresh_clicked();

    void on_mems_showdata_clicked();


	void on_mems_serial_test();

private:
    //创建光滑曲线序列
    void createQSplineSeries();
    void init();

    //读取本地文本数据
    const char* nameIS;
    void loadLocaldata(std::string str_data);

    //显示快轴慢轴电压曲线
    void showVoltageCurve(int voltageData[]);

private:

	QByteArray bytes;
    int i = 0;
    QList<QString *> m_charts;
    QSplineSeries *spLineSeries;

    Ui::mems *ui;
};

#endif // MEMS_H
