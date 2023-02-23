#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QQueue>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtGui/QWindow>
#include <QtWidgets/QMenuBar>
#include <QtCore/QStringList>
#include <QtWidgets/QColorDialog>
#include <QTimer>
#include <QMutex>

#include <thread>
#include "datatable.h"
#include "document.h"
#include "registe_configure.h"
#include "ip_config.h"
#include "serial_port.h"
#include "laser.h"
#include "receiver.h"
#include "mems.h"
#include "fpga.h"
#include "MyCloud.h"
#include "FileIO.h"
#include "pointcloud.h"
#include "datatable.h"
#include "temperature_realshow.h"
#include "voltage_realshow.h"
//#include "spreadsheet/spreadsheet.h"
#include "adc.h"
//#include "pcap_analysis.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <vtkSmartPointer.h>
#include <vtkCameraActor.h>
#include <vtkNamedColors.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkCamera.h>
#include <vtkPlanes.h>
#include <vtkMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRegularPolygonSource.h>
#include "vtkAutoInit.h" 
#include <vtkWindowToImageFilter.h>
//#include <vtkAVIWriter.h>   //VTK9.1中未找到
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)

VTK_MODULE_INIT(vtkRenderingFreeType)
//VTK_MODULE_INIT(vtkRenderingCore);
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


//友元
friend class datatable;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QQueue<QString> cloudFileDic;
    QTreeWidgetItem *CameraTree = new QTreeWidgetItem;



protected:

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_mcu_accepted();
	void on_adc_accepted();
    void on_ip_config_accepted();
    void on_serial_port_accepted();
    void on_laser_accepted();
    void on_receiver_accepted();
    void on_mems_accepted();
    void on_document_accepted();
    void on_FPGA_accepted();
    void onaction_Open_File();
    void onaction_new_file();
    void on_Index_accepted();
    void on_Temperature_Accepted();
    void on_Voltage_Accepted();
    //增加PCD文件流播放
    void onPcap();
    void onPlayer();
    void onPause();


    void loadFile(const QStringList& filePathList);
    void add();
    void clear();
    void pRecentOpen();
    void slot_uploadBtnClicked();


    void popMenu(const QPoint&);
    void hideItem();
    void showItem();
    void deleteItem();

    void popMenuInConsole(const QPoint&);
    void clearConsole();
    void enableConsole();
    void disableConsole();
    void timerUpdate(); //显示时间函数






    void on_pointcolorAction_triggered();


    void on_bgcolorAction_triggered();

    void on_exitAction_triggered();

    void on_saveAction_triggered();




    void on_addCricleshow_triggered(bool checked);

    void on_addCoordinate_triggered(bool checked);

    void on_nextFrame_clicked();

    void on_pointSizeChange_sliderMoved(int position);

    void on_actionRecord_triggered();

private:

	Ui::MainWindow *ui;

    void initial();
    void createActions();
    void createMenus();

    void pointcolorChanged();
    void showPointcloud();
    void showPointcloudAdd();  //添加给viewer，显示点云
    void showPointcloudSequence();
    void mainview_action();
    void leftview_action();
    void topview_action();

	bool isChecked = true;


    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);

    void setConsoleTable();
    void setPropertyTable();
    bool enable_console = true; // console 的可用状态
    void consoleLog(QString operation, QString subname, QString filename, QString note);
    int total_points = 0;
    int theme_id = 1;
    QString timeCostSecond = "0";  // 记录某个动作执行的时间
    
    MyCloud mycloud;
    std::vector<MyCloud> mycloud_vec;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_rgb;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    FileIO fileIO;
    //多圆环点云容器 Yan
    std::vector<vtkSmartPointer<vtkActor>> circle_v;






    QTextEdit *textEdit;
    QMenuBar *mBar;
    QMenu *Files;
    QMenu *SystemMenu;
    QMenu *Device;
    QMenu *Record;
    QMenu *Tools;


    QMenu *Show;
    QMenu *viewerMenu;
    QAction *mainview;
    QAction *leftview;
    QAction *topview;

    QMenu *Configs;
    QMenu *Monitoring;
    QMenu *Verify;
    QAction *exitAct;
    QMenu *Debug;




    QMenu *fileMenu;
    QMenu *recentFilesMenu;
    QString curFile;
    QAction *separatorAct;
    QAction *soft;
    QAction *pOpen;

    QAction *pNew;
    //设备
    QAction *Run;
    QAction *Stop;
    QAction *Close;
    //录制
    QAction *OpenPcap;
    QAction *Start;
    QAction *Pause;
    QAction *Return;
    QAction *Save;
    //工具
    QAction *Calibration;
    QAction *Filter;
    //显示
    QAction *Viewer;
    QAction *Rotation;
    QAction *Zoom;
    QAction *Index;
    QAction *Color;
    //配置
    QAction *Mcu;
    QAction *Ip_addres;
    QAction *Device_SN;
    QAction *Fps;
    QAction *Serial_Port;
    QAction *Firmware;
    QAction *Did;
    //可靠性测试
    QAction *Fpga;
    QAction *Temperature;
    QAction *Vbd;
    //性能测试
    QAction *Accuracy_test;

    //调试
    QAction *Laser_Module;
    QAction *Receiver_Module;
    QAction *Mems_Module;
	QAction *Adc_Module;
    //工具栏
    QToolBar *toolBar;

    //设置最大最近文件为5个
    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];


    //QLabel *m_picLable;
    bool m_bSavePcdFileStatus = false;

    //设置计时器，读取点云流
    QTimer *myTimer;
    QMutex g_mutex_1;
    int currentFrame = 0;

};
#endif // MAINWINDOW_H
