#ifndef ADC_H
#define ADC_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QSplineSeries>
#include <QtCharts>
#include <QTableView>
#include <QStandardItemModel>
#include <QScatterSeries>
namespace Ui {
class adc;
}

class adc : public QWidget
{
    Q_OBJECT

public:
    explicit adc(QWidget *parent = nullptr);
    ~adc();

    void showdata();
    void getPeakpoint();

private slots:
    void on_pushButton_clicked();
    void on_adc_refresh_clicked();
    //void findPeaks(int distance);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_loadLocaldata_clicked();

private:
    Ui::adc *ui;
    void init();
    int peak_num;
    std::vector<float> adc_data;//采集数据
    std::vector<float> peak_data; //峰值数据
    std::vector<size_t> ans;//峰值数据索引
    QStandardItemModel* m_model;

    void showADCdata(int adcData[]);

    void slotTimeout();

    /* 用于模拟生成实时数据的定时器 */
    QTimer* m_timer;
    /* 图表对象 */
    QChart* m_chart;
    /* 横纵坐标轴对象 */
    QValueAxis *m_axisX, *m_axisY;
    /* 曲线图对象 */
    QLineSeries* m_lineSeries;
    /* 横纵坐标最大显示范围 */
    const int AXIS_MAX_X = 5000, AXIS_MAX_Y = 5000;
    /* 用来记录数据点数 */
    int pointCount = 0;



};

#endif // ADC_H
