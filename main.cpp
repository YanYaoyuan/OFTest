#include "mainwindow.h"
//#include "spreadsheet/spreadsheet.h"
#include "pointcloud.h"
#include "pcap_analysis.h"
#include <QtWidgets/QLayout>
#include <QtWidgets/QApplication>
#include <QtGui/QScreen>
#include <QtCore/QLocale>
#include <QtCore/QTranslator>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Recently");         //设置组织名称
    a.setApplicationName("Recent Files");       //设置标题名称

    MainWindow w;

    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    //int screen_width = mm.width();
    //int screen_height = mm.height();
    w.move((mm.width() - w.width())/ 2, (mm.height() - w.height()) /2);
    w.show();

//    int num=100;
//    SpreadSheet sheet(num, 6);
//    sheet.setWindowIcon(QPixmap(":/images/interview.png"));
//    sheet.show();
//    sheet.layout()->setSizeConstraint(QLayout::SetNoConstraint);


//    pcap_analysis *pcap;
//    pcap->test();

//    pointcloud *point = new pointcloud;
//    point->show();

    return a.exec();
}
