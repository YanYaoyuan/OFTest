#include "adc.h"
#include "ui_adc.h"
#include <iostream>

#include <fstream>
#include <QString>
#include <sstream>

#include <stdio.h>
using namespace std;

adc::adc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adc)
{
    ui->setupUi(this);
    init();
}

adc::~adc()
{
    delete ui;
}






void adc::showdata()
{

    //ui->peak_index->clear();

    //std::cout <<"adc_data.size() ===  "<< adc_data.size() << std::endl;
    //std::cout <<"ans.size() ===  "<< ans.size() << std::endl;


    //m_model->removeRows(0,model->rowCount());
    m_model = new QStandardItemModel(ans.size(),2);
    std::cout << "111111111111111" << std::endl;
    QStringList labels = QString("Index,PEAK").simplified().split(",");
    m_model->setHorizontalHeaderLabels(labels);
    std::cout << "2222222222222222222" << std::endl;
    ui->peak_index->setModel(m_model);
    ui->peak_index->horizontalHeader()->setStyleSheet("QHeaderView::section {"
		"color: black;}");
    
	std::cout << "333333333333333" << std::endl;

    QStandardItem* item = 0;
    for(int i = 0;i < ans.size(); i++)
    {

        /*std::cout <<"ans[i] ===  "<< ans[i] << std::endl;
        std::cout <<"adc_data[ans[i]] ===  "<< peak_data[i] << std::endl;*/



        item = new QStandardItem(QString("%1").arg(ans[i]));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        m_model->setItem(i,0,item);

        item = new QStandardItem(QString("%1").arg(peak_data[i]));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        m_model->setItem(i,1,item);
    }

    //ui->peak_index->verticalHeader()->hide();
    for(int i = 0; i < ui->peak_index->horizontalHeader()->count(); i++)
    {
        ui->peak_index->setColumnWidth(i,80);
    }

    ui->peak_index->showNormal();

}

void adc::getPeakpoint()
{
    std::cout<<"getPeakpoint"<<std::endl;
    QScatterSeries* series = new QScatterSeries();              // 创建一个散点数据集对象
    series->setName("圆点样式");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);  // 设置绘制的散点的样式为圆
    series->setColor(QColor(0,0,255));
    series->setMarkerSize(2);                                  // 设置绘制的点的大小

    for(int i = 0; i < peak_data.size(); i++)    // 添加10个任意点
    {
        std::cout<<ans[i]<<"  "<<peak_data[i]<<std::endl;
        series->append(ans[i], peak_data[i]);
    }

    ui->adc_QSpline->chart()->addSeries(series);       // 将创建的series添加经chart中
    //ui->adc_QSpline->chart()->createDefaultAxes();     // 新添加series后，调用这个函数根据添加的series自动生成对于类型的XY轴，会删除已有的轴再生成（推荐使用这种方法，尽量不要自己添加轴）
    std::cout<<"getPeakpoint  2"<<std::endl;
    //ui->adc_QSpline->update();
}


//寻峰2
void adc::on_pushButton_3_clicked()
{
     std::cout << "11111111111" << std::endl;

    ans.clear();
    peak_data.clear();
   //void findPeaks(double *src, double src_lenth, double distance, int *indMax, int *indMax_len, int *indMin, int *indMin_len)


    int distance = ui->min_distance->currentText().toInt();
    std::cout <<"distance  =====  "<< distance<< std::endl;
    int src_lenth = 30;
    int *sign = (int*)malloc(src_lenth * sizeof(int));
    int indMax[30] = { 0 };
    int indMin[30] = { 0 };

    int max_index = 0,
        min_index = 0;
//    int indMax_len = 0;
//    int indMin_len = 0;


    for (int i = 1; i < adc_data.size(); i++)
    {
        double diff = adc_data[i] - adc_data[i - 1];
        if (diff > 0)          sign[i - 1] = 1;
        else if (diff < 0) sign[i - 1] = -1;
        else                sign[i - 1] = 0;
    }
    for (int j = 1; j < adc_data.size() - 1; j++)
    {
        double diff = sign[j] - sign[j - 1];
        if (diff < 0)      indMax[max_index++] = j;
        else if (diff > 0)indMin[min_index++] = j;
    }


    std::cout << "2222222222222" << std::endl;
    int *flag_max_index = (int *)malloc(sizeof(int)*(max_index > min_index ? max_index : min_index));
    int *idelete = (int *)malloc(sizeof(int)*(max_index > min_index ? max_index : min_index));
    int *temp_max_index = (int *)malloc(sizeof(int)*(max_index > min_index ? max_index : min_index));
    int bigger = 0;
    double tempvalue = 0;
    int i, j, k;

     std::cout << "max_index ===== "<<max_index << std::endl;
     std::cout << "min_index ===== "<<min_index << std::endl;

    //波峰
    for (int i = 0; i < max_index; i++)
    {
        flag_max_index[i] = 0;
        idelete[i] = 0;
    }
    for (i = 0; i < max_index; i++)
    {
        tempvalue = -1;
        for (j = 0; j < max_index; j++)
        {
            if (!flag_max_index[j])
            {
                if (adc_data[indMax[j]] > tempvalue)
                {
                    bigger = j;
                    tempvalue = adc_data[indMax[j]];
                }
            }
        }
        flag_max_index[bigger] = 1;
        if (!idelete[bigger])
        {
            for (k = 0; k < max_index; k++)
            {
                idelete[k] |= (indMax[k] - distance <= indMax[bigger] & indMax[bigger] <= indMax[k] + distance);
            }
            idelete[bigger] = 0;
        }
    }
    for (i = 0, j = 0; i < max_index; i++)
    {
        if (!idelete[i])
            temp_max_index[j++] = indMax[i];
    }
    for (i = 0; i < max_index; i++)
    {
        if (i < j)
            indMax[i] = temp_max_index[i];
        else
            indMax[i] = 0;
    }
    max_index = j;

    //波谷
    for (int i = 0; i < min_index; i++)
    {
        flag_max_index[i] = 0;
        idelete[i] = 0;
    }
    for (i = 0; i < min_index; i++)
    {
        tempvalue = 1;
        for (j = 0; j < min_index; j++)
        {
            if (!flag_max_index[j])
            {
                if (adc_data[indMin[j]] < tempvalue)
                {
                    bigger = j;
                    tempvalue = adc_data[indMin[j]];
                }
            }
        }
        flag_max_index[bigger] = 1;
        if (!idelete[bigger])
        {
            for (k = 0; k < min_index; k++)
            {
                idelete[k] |= (indMin[k] - distance <= indMin[bigger] & indMin[bigger] <= indMin[k] + distance);
            }
            idelete[bigger] = 0;
        }
    }
    for (i = 0, j = 0; i < min_index; i++)
    {
        if (!idelete[i])
            temp_max_index[j++] = indMin[i];
    }
    for (i = 0; i < min_index; i++)
    {
        if (i < j)
            indMin[i] = temp_max_index[i];
        else
            indMin[i] = 0;
    }
    min_index = j;


    std::cout << "333333333333333" << std::endl;


    int num = ui->peak_num->currentText().toInt();
    std::cout << "num  ===  "<<num << std::endl;
    for (int i = 0; i < max_index; i++)
    {
        //std::cout << "444444444444" << std::endl;
        std::cout << indMax[i] << std::endl;
        ans.push_back(indMax[i]);
        peak_data.push_back(adc_data[indMax[i]]);
    }
    std::cout << "5555555555" << std::endl;
    for (int i = 0; i < min_index; i++)
            std::cout << indMin[i] << std::endl;

    std::cout << "ans.size() ====  "<<ans.size() << std::endl;


    //adc_data.clear();
    //showdata();

    //getPeakpoint();

}


//寻峰1
void adc::on_pushButton_clicked()
{
    //std::cout<<adc_data[1]<<std::endl;;
    ans.clear();
    peak_data.clear();
    int length = adc_data.size();
    //if (length <= 1) return std::vector<size_t>();
    //we dont need peaks at start and end points
    std::vector<int> sign(length, -1);
    std::vector<int> difference(length, 0);
    std::vector<size_t> temp_out;
    //first-order difference (sign)
    adjacent_difference(adc_data.begin(), adc_data.end(), difference.begin());
    difference.erase(difference.begin());
    difference.pop_back();
    for (int i = 0; i < difference.size(); ++i) {
        if (difference[i] >= 0) sign[i] = 1;
    }
    //second-order difference
    for (int j = 1; j < length - 1; ++j)
    {
        int  diff = sign[j] - sign[j - 1];
        if (diff < 0) {
            temp_out.push_back(j);
        }
    }

    int distance= ui->peak_num->currentText().toInt();
    std::cout<<distance<<std::endl;
    //if (temp_out.size() == 0 || distance == 0) return temp_out;
    //sort peaks from large to small by src value at peaks
    std::sort(temp_out.begin(), temp_out.end());




    //Initialize the answer and the collection to be excluded
    //ans.push_back(temp_out[0]);
    std::unordered_map<size_t, int> except;
    ////    int left=temp_out[0]-distance>0? temp_out[0]-distance:0;
    ////    int right=temp_out[0]+distance>length-1? length-1:temp_out[0]+distance;
    //    int left=temp_out[0]-distance;
    //    int right=temp_out[0]+distance;
    //    for (int i = left;i<=right; ++i) {
    //        except.insert(i);
    //    }
    for (auto it : temp_out) {
        if (!except.count(it))//如果不在排除范围内
        {
            ans.push_back(it);
            peak_data.push_back(adc_data[it]);
            //更新
            int left = it - distance > 0 ? it - distance : 0;
            int right = it + distance > length - 1 ? length - 1 : it + distance;
            for (int i = left; i <= right; ++i)
                ++except[i];
        }
    }
    //sort the ans from small to large by index value
    std::sort(ans.begin(), ans.end());
    //return ans;

    for(std::vector<size_t>::iterator itor = ans.begin();itor!=ans.end();++itor)
    {
        std::cout<<"ans =====  "<< *itor <<std::endl;
    }


    showdata();
}

void adc::init()
{

    ui->adc_QSpline->setRenderHint(QPainter::Antialiasing);
    ui->adc_QSpline->chart()->setTitle(QStringLiteral("ADC Data"));
    ui->adc_QSpline->chart()->setTheme(QChart::ChartThemeLight);
    QSplineSeries *spLineSeries = new QSplineSeries;
    spLineSeries->setName(QStringLiteral("10bit"));
    spLineSeries->hide();
    ui->adc_QSpline->chart()->addSeries(spLineSeries);
    //创建坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("range"); //设置X轴的标题
    axisX->setRange(0, 5000);
    axisX->setTickCount(10);
    axisX->setLabelsVisible(true);//x轴坐标显示
    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Voltage"); //设置X轴的标题
    axisY->setRange(-70, 5000);
    ui->adc_QSpline->chart()->setAxisX(axisX, spLineSeries);
    ui->adc_QSpline->chart()->setAxisY(axisY, spLineSeries);

    //图例
    ui->adc_QSpline->chart()->legend()->setAlignment(Qt::AlignBottom);

}



void adc::on_adc_refresh_clicked()
{
    adc_data.clear();

    ui->adc_QSpline->chart()->removeAllSeries();
    //createQSplineSeries();
    QSplineSeries *spLineSeries = new QSplineSeries;
    //spLineSeries->setName(QStringLiteral("data"));
    //spLineSeries->hide();
    //spLineSeries->clear();

    double y = 0.0;
    for (int x = 0; x < 1024;  x++)
    {
        //spLineSeries->append(i, ui->tableWidget->item(i, 2)->text().toInt());
        if(x<300)
        {
            double angle = (double) x /300  * 2 * 3.1415926;
            y = 60 * sin(angle);
        }

        if(x>300 &&x<600)
        {
            double angle = (double) x /400 * 2 * 3.1415926;
            y = 80 * sin(angle)+79;
        }

        if(x>600)
        {
            double angle = (double) x/1000 * 2 * 3.1415926;
            y = 50 * sin(angle)+120.9;
        }
        //std::cout<<x<<" "<<y<<std::endl;
        spLineSeries->append(x,y);
        //adc_data.append(y);

        adc_data.push_back(y);
        //adc_data.data().size();
    }

    std::cout<<"max(adc_data) ===== "<<*max_element(adc_data.begin(),adc_data.end())<<std::endl;
    std::cout<<"min(adc_data) ===== "<<*min_element(adc_data.begin(),adc_data.end())<<std::endl;

    spLineSeries->setPointsVisible(true);
    ui->adc_QSpline->chart()->addSeries(spLineSeries);

}

void adc::on_pushButton_2_clicked()
{
    std::cout << "on_pushButton_2_clicked" << std::endl;
}





void adc::on_loadLocaldata_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open ADC Data file"), ".",
        tr("Open CSV files(*.csv);;All file(*.*)"));
    std::ifstream infile;
    infile.open(fileName.toStdString());
    if (!infile){  //打开失败
        std::cout << "Error opening TXT file." << std::endl;
    }else
        std::cout << "Opening TXT file." << std::endl;

    string s;
    //将每行的数据以string类型存入vector
    vector<string> adcData[256];
    int i = 0;
    while(infile>>s)
    {

        adcData[i].push_back(s);
        //cout << i <<" adcData = " << adcData[i].front() << endl;
        //cout << i <<" adcData = " << adcData[i].front().size() << endl;
        i++;
    }

    vector<string> adcData_split[256][16];
    vector<int> adcData_int[256][16];//保存十进制adc数据, 未进行数据拼接

    string temp;
    string res;
    stringstream ss;
    for(int i = 0; i < 256; i++)
    {
        for(int j = 1; j <= 16; j++)
        {
            adcData_split[i][j-1].push_back(adcData[i].front().substr(60 - 4*(j - 1 ), 4));
            cout << "[" << i << ", " << j-1 << "] = "  << adcData_split[i][j-1].front() <<endl;
            adcData_split[i][j-1].front().append(adcData_split[i][j-1].front().substr(0, 2));

            temp = adcData_split[i][j-1].front().substr(2, 4);
            temp.erase(3,1);//删除第三位一个数据（此时已调转高低位），对应最低位
            //在此处判断最高位是否大于8
            res = temp[0];
            cout << "the top bit change befor : " << temp[0] << endl;
            if(stoi(res,0,16) < 8)
            {
                cout << "the top bit is < 8 : " << res << endl;
                cout << "change to DEC IS " << stoi(res,0,16) << endl;
                string result = (QString::number( stoi(res,0,16) + 8, 16 )).toStdString();
                ss << result;
                ss >> temp[0];

            }else{
                cout << "the top bit is > 8 : " << res << endl;
                cout << "change to DEC IS " << stoi(res,0,16) << endl;
                string result = (QString::number( stoi(res,0,16) - 8, 16 )).toStdString();
                ss << result;
                ss >> temp[0];
            }
            cout << "the top bit change after : " << temp[0] << endl;

            adcData_int[i][j-1].assign(1, stoi(temp,0,16));
            //un_adcData_int[i][j-1] = adcData_int[i][j-1];

            cout << "HEX string = " << temp <<endl;
            cout << "DEC int    = " << adcData_int[i][j-1].front() <<endl;

        }
    }

    vector<int> adcData_com[256][16];//创建新的adc数据，并进行拼接
    for(int i = 0; i < 256; i++)
    {
        int k = 7;
        for(int j = 0; j < 16; j++)
        {
            if (j % 2 == 0)
            {
                std::cout << "here is oushu  = " << j << std:: endl;
                std::cout << "from " << j << " -> " << j / 2  << std:: endl;
                adcData_com[i][j / 2] = adcData_int[i][j];
            }else {
                    std::cout << "here is jishu  = " << j << std:: endl;
                    std::cout << "from " << j << " -> " << j+k << std:: endl;
                    adcData_com[i][j+k] = adcData_int[i][j];
                    k--;
            }
        }
    }

    cout << "创建新的adc数据，并进行拼接 ";

    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            cout << "After resort ADC Data: (" << i << ", " << j <<") = " << adcData_com[i][j].front() <<endl;
        }
    }



    //创建一个存放绘图数据
    int adcData_plot[4096];
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            adcData_plot[ i * 16 + j] = adcData_com[i][j].front();

        }
    }

    showADCdata(adcData_plot);

    ofstream outfile ("D://res.txt",ios::in|ios::out|ios::binary);
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 16; j++)
        {
            outfile << adcData_int[i][j].front() << " ";
        }
        outfile << "\r\n";
    }

    ofstream outfile1 ("D://ress.txt",ios::in|ios::out|ios::binary);
    for(int i = 0; i < 256; i++) {
        for(int j = 0; j < 16; j++)
        {
            outfile1 << adcData_com[i][j].front() << " ";
        }
        outfile1 << "\r\n";
    }


}


void adc::showADCdata(int adcData[])
{
    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleText("X-label");
    m_axisY->setTitleText("Y-label");
    m_axisX->setMin(0);
    m_axisY->setMin(0);
    m_axisX->setMax(AXIS_MAX_X);
    m_axisY->setMax(AXIS_MAX_Y);

    m_lineSeries = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries->setName("ADC Data Plot");                            // 图例名称
    m_lineSeries->setPen(QPen(Qt::blue));
    for(int i=0; i< 4096; i++)
    {
        m_lineSeries->append(i, adcData[i]);
    }

    m_chart = new QChart();                                        // 创建图表对象
    m_chart->addAxis(m_axisX, Qt::AlignBottom);                      // 将X轴添加到图表上
    m_chart->addAxis(m_axisY, Qt::AlignLeft);                    // 将Y轴添加到图表上
    m_chart->addSeries(m_lineSeries);                              // 将曲线对象添加到图表上
    m_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->adc_QSpline->setChart(m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->adc_QSpline->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    ui->adc_QSpline->setRubberBand(ui->adc_QSpline->RectangleRubberBand);// 缩放

}

void adc::slotTimeout()
{
    static int count = 0;
    if(count > AXIS_MAX_X)
    {
        m_lineSeries->remove(0);
        m_chart->axisX()->setMin(count - AXIS_MAX_X);
        m_chart->axisX()->setMax(count);                    // 更新X轴范围
    }
    m_lineSeries->append(QPointF(count, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
    count++;
}

