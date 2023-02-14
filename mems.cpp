#include "mems.h"
#include "ui_mems.h"
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QCategoryAxis>
#include <QColorDialog>
#include <iostream>
#include <fstream>
#include <QString>


using namespace std;

#pragma execution_character_set("utf-8")
mems::mems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mems)
{
    ui->setupUi(this);

    init();
}

mems::~mems()
{
    delete ui;
}


void mems::init()
{

    ui->chartViewQSpline->setRenderHint(QPainter::Antialiasing);
    ui->chartViewQSpline->chart()->setTitle(QStringLiteral("MEMS Fast Signal"));
    ui->chartViewQSpline->chart()->setTheme(QChart::ChartThemeLight);
    QSplineSeries *spLineSeries = new QSplineSeries;
    spLineSeries->setName(QStringLiteral("Fast Signal"));
    ui->chartViewQSpline->chart()->addSeries(spLineSeries);
    //创建坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Time"); //设置X轴的标题
    axisX->setRange(0, 30);
    axisX->setTickCount(10);
    axisX->setLabelsVisible(true);//x轴坐标显示
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Voltage"); //设置X轴的标题
    axisY->setRange(-20, 20);
    ui->chartViewQSpline->chart()->setAxisX(axisX, spLineSeries);
    ui->chartViewQSpline->chart()->setAxisY(axisY, spLineSeries);

    //图例
    ui->chartViewQSpline->chart()->legend()->setAlignment(Qt::AlignBottom);


	//connect(ui->mems_serial_test, SIGNAL(triggered()), this, SLOT(on_mems_serial_test()));
	connect(ui->mems_serial_test, &QPushButton::clicked, this, &mems::on_mems_serial_test);

}

void mems::createQSplineSeries()
{
    ui->chartViewQSpline->chart()->removeAllSeries();
    ui->chartViewQSpline->chart()->series().clear();
    //std::cout<<(ui->chartViewQSpline->chart()->series().)<<std::endl;
    QSplineSeries *spLineSeries = new QSplineSeries;
//    //ui->chartViewQSpline = new
//    ui->chartViewQSpline->setRenderHint(QPainter::Antialiasing);
//    ui->chartViewQSpline->chart()->setTitle(QStringLiteral("MEMS快轴信号"));
//    ui->chartViewQSpline->chart()->setTheme(QChart::ChartThemeLight);
//    //创建光滑曲线序列，并添加数据

    spLineSeries->setName(QStringLiteral("Fast Signal"));
    int m_period = 15; //周期
    int m_grain = 1;    //粒度
    int m_radius = 10; // 振幅
    for (int x = 0; x < 30;  x+=m_grain)
    {
        //spLineSeries->append(i, ui->tableWidget->item(i, 2)->text().toInt());

        double angle = (double) x / m_period * 2 * 3.1415926;
        double y = m_radius * sin(angle);
        spLineSeries->append(x,y);

    }
    ui->chartViewQSpline->chart()->addSeries(spLineSeries);
//    //创建坐标轴
//    QValueAxis *axisX = new QValueAxis;
//    axisX->setRange(0, 30);
//    axisX->setTickCount(10);
//    axisX->setLabelsVisible(true);//x轴坐标显示
//    QValueAxis *axisY = new QValueAxis;
//    axisY->setRange(-20, 20);
//    ui->chartViewQSpline->chart()->setAxisX(axisX, spLineSeries);
//    ui->chartViewQSpline->chart()->setAxisY(axisY, spLineSeries);

    //显示曲线的数据点
    spLineSeries->setPointsVisible(true);
    //图例
    ui->chartViewQSpline->chart()->legend()->setAlignment(Qt::AlignBottom);
}


void mems::on_btnSplinePointColor_clicked()
{//设置光滑曲线：数据点颜色

    QSplineSeries *splineSeries = (QSplineSeries *)ui->chartViewQSpline->chart()->series().at(0);
    QColor color = splineSeries->pen().color();
    color = QColorDialog::getColor(color);
    QPen pen = splineSeries->pen();
    pen.setColor(color);
    splineSeries->setPen(pen);
}

void mems::on_chkDataPoint_stateChanged(int arg1)
{//设置光滑曲线：数据点显示

    QSplineSeries *splineSeries = (QSplineSeries *)ui->chartViewQSpline->chart()->series().at(0);
    if (Qt::Checked == arg1)
    {

        splineSeries->setPointsVisible(true);
    }
    else
    {
        splineSeries->setPointsVisible(false);
    }
}

void mems::on_chkDataPointLabelVisible_stateChanged(int arg1)
{//设置光滑曲线：数据点标签显示

    QSplineSeries *splineSeries = (QSplineSeries *)ui->chartViewQSpline->chart()->series().at(0);
    if (Qt::Checked == arg1)
    {
        splineSeries->setPointLabelsVisible(true);
    }
    else
    {
        splineSeries->setPointLabelsVisible(false);
    }
}


void mems::on_mems_showdata_clicked()
{
    std::cout<<"show loacl data"<<std::endl;
    //createQSplineSeries();
    //ui->mems_showdata->setEnabled(false);

    loadLocaldata("FS_data1.txt");
}


bool BruteForce(std::string t, std::string p)
{
	int lenT = t.size();
	int lenP = p.size();

	if (t == p.substr(0, lenT))
	{
		return true;
	}

	return false;
}

void mems::on_mems_serial_test()
{
	std::cout << "mems_serial_test" << std::endl;
	std::string mems_serial = "MEMS_";
	const auto infos = QSerialPortInfo::availablePorts();
	ui->mems_serial_test->setEnabled(false);
	//ui->statusbar->showMessage("");
	/*下面这个循环语句用来查找可以用的串口端口*/
	/*不确定有多少串口可用，也就不知道循环多少次，所以用foreach（不知道用的就百度）*/
	for (const QSerialPortInfo &info : infos)
	{
		QSerialPort serial_aaa;     //在循环语句内部实例化类，因为可用串口不一定只就一个
		serial_aaa.setPort(info);    //设置能够用的串口端口
		if (serial_aaa.open(QIODevice::ReadWrite))       //用ReadWrite可读写的方式打开串口
		{
			/*记录可用的uart名字serial.portName()，前面的ui->PortBox->addItem不用管，这个是界面里面的。*/
			//ui->serialPortComBox->addItem(info.portName());

			serial_aaa.write("version");

			bytes = serial_aaa.readAll();

            std::string serial_version = bytes.toStdString();
			if (BruteForce(mems_serial, serial_version))
			{
				//std::cout << "11111111111" << std::endl;
				//imu_com = COM_list[i];
				ui->mems_serial_test->setEnabled(false);
			}

			/*然后关闭串口，因为这段代码打开串口只是为了查找串口可以用不可用而已。*/
			//serial_aaa.close();
		}
	}

}


void mems::on_mems_refresh_clicked()
{
    ui->chartViewQSpline->chart()->removeAllSeries();
    //createQSplineSeries();
    QSplineSeries *spLineSeries = new QSplineSeries;
    spLineSeries->setName(QStringLiteral("快轴信号"));
    //spLineSeries->clear();

    for (int x = 0; x < 30;  x+=2)
    {
        //spLineSeries->append(i, ui->tableWidget->item(i, 2)->text().toInt());

        double angle = (double) x / 10 * 2 * 3.1415926;
        double y = 10 * sin(angle);
        spLineSeries->append(x,y);

    }
    spLineSeries->setPointsVisible(true);
    ui->chartViewQSpline->chart()->addSeries(spLineSeries);

}

//加载本地txt文本中数据
void mems::loadLocaldata(string str_data)
{

    ifstream infile;
    infile.open("FS_data1.txt");
    if (!infile)  //打开失败
        cout << "Error opening TXT file." << endl;
    string s;
    string data1;
    int i = 0;
    int PointData[1200];

    while (infile >> s)
    {
        cout << " Read from file from data start: " << s << endl;
        //string to int function
        i = atoi(s.c_str());
        //infile >> PointData[i];
        //cout << "data = " << i << endl;
        if(s == "2us)") //此处判断是否已经读到数据处
            break;
    }
    int j = 0;
    while(infile >> data1)
    {
        //cout << " start data output: " << data1 << endl;
        PointData[j] = atoi(data1.c_str());
        cout << "PointData["<<j <<"] = " << PointData[j] << endl;
        j++;
    }
    showVoltageCurve(PointData);
    infile.close();
}

//显示电压曲线 输入：电压数组
void mems::showVoltageCurve(int voltageData[])
{
    ui->chartViewQSpline->chart()->removeAllSeries();
    ui->chartViewQSpline->chart()->series().clear();

    QSplineSeries *spLineSeries = new QSplineSeries;

    spLineSeries->setName(QStringLiteral("Fast Signal"));
    double x = 0;
    for(int i = 0; i < 1200; i++)
    {
        double y = (double)voltageData[i] * 3 / 65536;
        x = i * 2;

        spLineSeries->append(x,y);
        cout<<"The " << i <<".st coordinate :(x, y) = (" << x <<", " << y <<")." << endl;
    }


    //将坐标轴与数据对应
    //创建坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Time++"); //设置X轴的标题
    ui->chartViewQSpline->chart()->setAxisX(axisX, spLineSeries);

    ui->chartViewQSpline->chart()->addSeries(spLineSeries);

    //显示曲线的数据点
    spLineSeries->setPointsVisible(true);
    //图例
    ui->chartViewQSpline->chart()->legend()->setAlignment(Qt::AlignBottom);
    //缩放
    ui->chartViewQSpline->setRubberBand(ui->chartViewQSpline->RectangleRubberBand);




}



