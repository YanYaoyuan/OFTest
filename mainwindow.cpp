#include "mainwindow.h"
#include "ui_mainwindow.h"

#pragma execution_character_set("utf-8")
#include <QMenuBar>   //菜单栏头文件
#include <QMenu>      //菜单头文件
#include <QAction>    //动作头文件
#include <QDebug>     //打印头文件
#include <QToolBar>   //工具栏头文件
#include <QPushButton>//按钮头文件
#include <QStatusBar> //状态栏头文件
#include <QLabel>     //标签头文件
#include <QTextEdit>  //核心控件，文本编辑区头文件
#include <QDockWidget>//浮动窗口头文件
#include <QSettings>  //设置
#include <QMessageBox>//打印log
#include <QKeyEvent>  //键盘快捷键
#include <QListWidget>
#include <QGuiApplication>
#include <QApplication>
#include <QTextStream>
#include <iostream>
#include <QFileDialog>
#include <QColormap>
#include <QGridLayout>


#include <QSurfaceFormat>
#include <vtkCubeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSmartPointer.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <QDateTime>
#include <vtkCamera.h>
#include <QVTKOpenGLWidget.h>
#include <vtkAxesActor.h>
#include "vtkRenderWindow.h"
#include <vtkOutputWindow.h>
#include <vtkAutoInit.h>

vtkSmartPointer<vtkPoints> m_Points = vtkSmartPointer<vtkPoints>::New();
vtkSmartPointer<vtkCellArray> vertices = vtkSmartPointer<vtkCellArray>::New();	//_存放细胞顶点，用于渲染（显示点云所必须的）
vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
vtkSmartPointer<vtkPolyDataMapper> pointMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
vtkSmartPointer<vtkActor> pointActor = vtkSmartPointer<vtkActor>::New();
vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer< vtkRenderer>::New();
vtkSmartPointer<vtkRenderer> ren0 = vtkSmartPointer< vtkRenderer>::New();
vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
vtkSmartPointer<vtkInteractorStyleTrackballCamera> istyle = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
vtkSmartPointer<vtkCamera> myCamera = vtkSmartPointer<vtkCamera>::New(); //相机视角




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);//当关闭时删除该组件

    mBar=menuBar();
    createMenus();
    createActions();
    (void)statusBar();//增加状态栏

    setWindowFilePath(QString());


    QScreen *screen=QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    int screen_width = mm.width();
    int screen_height = mm.height();


    QColormap *caa;

    initial();


}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initial() {
    // 界面初始化
    //setWindowIcon(QIcon(tr(":/Resources/images/icon.png")));
    //setWindowTitle(tr("CloudViewer"));


    //实时显示时间
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

    // 点云初始化
    int total_points = 0;



    // 点云初始化
    mycloud.cloud.reset(new PointCloudT);
    mycloud.cloud->resize(1);

    //将Viewer初始化进VTKOpenGLNativeWidget
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    auto renderer = vtkSmartPointer<vtkRenderer>::New( );
    auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New( );
    renderWindow->AddRenderer(renderer);
    viewer.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "viewer", false));
    ui->openGLWidget->setRenderWindow(viewer->getRenderWindow( ));
    viewer->setupInteractor(ui->openGLWidget->interactor(), ui->openGLWidget->renderWindow());
    ui->openGLWidget->update();

    ui->propertyTable->setSelectionMode(QAbstractItemView::ExtendedSelection); // 禁止点击属性管理器的 item
    ui->consoleTable->setSelectionMode(QAbstractItemView::ExtendedSelection);  // 禁止点击输出窗口的 item  NoSelection
    ui->dataTree_2->setSelectionMode(QAbstractItemView::ExtendedSelection); // 允许 dataTree 进行多选
    // Item in dataTree is left-clicked (connect)
    connect(ui->dataTree_2, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemSelected(QTreeWidgetItem*, int)));
    // Item in dataTree is right-clicked
    connect(ui->dataTree_2, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenu(const QPoint&)));

    connect(ui->consoleTable, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(popMenuInConsole(const QPoint&)));
    // 设置默认主题
    //QString qss = darcula_qss;
    //qApp->setStyleSheet(qss);

    setPropertyTable();
    setConsoleTable();

    std::cout<<"Start arens function."<<std::endl;

	// 输出窗口
	consoleLog("Software start", "CloudViewer", "Welcome to use CloudViewer", "Nightn");



}


void MainWindow::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label->setText(str);
}

void MainWindow::onaction_new_file(){
    std::cout<<"2222222"<<std::endl;
}


void MainWindow::on_document_accepted(){
    std::cout<<"document"<<std::endl;
    document *doc =new document();
    //document *doc;
    doc->showNormal();

    //doc.show();
    //return a.exec();

}


void MainWindow::on_FPGA_accepted(){
    std::cout<<"FPGA"<<std::endl;
    FPGA *fpga =new FPGA();
    fpga->showNormal();

}

void MainWindow::on_serial_port_accepted(){
    std::cout<<"serial_port"<<std::endl;
    serial_port *serial =new serial_port();
    serial->showNormal();

}


void MainWindow::on_laser_accepted(){
    std::cout<<"Laser"<<std::endl;
    Laser *laser =new Laser();
    laser->showNormal();

}


void MainWindow::on_receiver_accepted(){
    std::cout<<"receiver"<<std::endl;

    receiver *receive =new receiver();
    //document *doc;
    receive->showNormal();

    //doc.show();
    //return a.exec();

}


void MainWindow::on_mems_accepted(){
    std::cout<<"mems"<<std::endl;

    mems *mems_ =new mems();
    //document *doc;
    mems_->showNormal();

    //doc.show();
    //return a.exec();

}


void MainWindow::on_ip_config_accepted(){
    std::cout<<"ip_config"<<std::endl;
    ip_config *ip_address =new ip_config();
    //document *doc;
    ip_address->showNormal();

    //doc.show();
    //return a.exec();

}


void MainWindow::on_mcu_accepted(){
    std::cout<<"registe_configure"<<std::endl;
    registe_configure *configure =new registe_configure();
    //document *doc;
    configure->showNormal();

    //doc.show();
    //return a.exec();

}

//adc实时监控
void MainWindow::on_adc_accepted() {
	std::cout << "adc" << std::endl;
	adc *adc_test = new adc();
	adc_test->showNormal();

	//doc.show();
	//return a.exec();

}

//温度实时监控
void MainWindow::on_Temperature_Accepted()
{
    std::cout << "on_Temperature_Accepted" << std::endl;
    //temperature *ss = new temperature;
    temperature_realshow *realdata = new temperature_realshow();
    realdata->showNormal();
}
//电压实时监控
void MainWindow::on_Voltage_Accepted()
{
    std::cout << "on_Voltage_Accepted" << std::endl;
    voltage_realshow *realdata = new voltage_realshow();
    realdata->showNormal();
}


//快捷键保存
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F12)
    {
        QString filePathName = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz")+".jpg";
        QPixmap p = this->grab(QRect(0, 0, this->width(),this->height()));
        p.save(filePathName,"PNG");
    }
}




void MainWindow::slot_uploadBtnClicked()
{

    std::cout<<"currentPath    "<< QDir::currentPath().toStdString()<<std::endl;
//    std::cout<<"applicationDirPath    "<< qApp->applicationDirPath( ).toStdString()<<std::endl;
//    QDir::setCurrent(qApp->applicationDirPath());//设置当前目录为程序的可执行文件所在目录
//    std::cout<<"currentPath    "<< QDir::currentPath().toStdString()<<std::endl;

    //QString filepath = QFileDialog::getOpenFileName(nullptr, QStringLiteral("选择图片"), ".", "*.png;*.jpg");


	if (isChecked)    //绘制圆环及网格
	{
		//画网格 
		for (int i = -100; i <= 100; i += 10) {
			viewer->addLine(pcl::PointXYZ(i, -100, 0), pcl::PointXYZ(i, 100, 0), QString("GridlineY%1").arg(i).toStdString(), 0);
			viewer->addLine(pcl::PointXYZ(-100, i, 0), pcl::PointXYZ(100, i, 0), QString("GridlineX%1").arg(i).toStdString(), 0);
			if (i > 0)
				viewer->addText3D(QString::number(i).append("m").toStdString(), pcl::PointXYZ(0, i, 0), 0.8, 0.5, 0.5, 0.5, QString("GridText%1").arg(i).toStdString(), 0);
			viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineY%1").arg(i).toStdString(), 0);
			viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineX%1").arg(i).toStdString(), 0);
		}

		//画圆环
		QVector<pcl::PointXYZ> points;
		for (int j = 1; j <= 10; j++) {
			int r = 10 * j;

			vtkSmartPointer<vtkRegularPolygonSource>   source = vtkSmartPointer<vtkRegularPolygonSource>::New();
			vtkSmartPointer<vtkPolyDataMapper>         mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
			vtkSmartPointer<vtkActor>                  actor = vtkSmartPointer<vtkActor>::New();

			source->SetNumberOfSides(70);    //多边形边数
			source->SetRadius(r);            //半径
			source->SetCenter(0, 0, 0);      //圆心     
			mapper->SetInputConnection(source->GetOutputPort());
			actor->SetMapper(mapper);
			actor->GetProperty()->SetColor(0.5, 0.5, 0.5);    //颜色
			actor->GetProperty()->SetOpacity(1);    //透明度
			actor->GetProperty()->SetRepresentationToWireframe();//图形不填充，只要边框

            //ui->qvtkWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
		}
	}
	else    //删除圆环及网格
	{
		//删除网格图形
		viewer->removeAllShapes();

		//删除圆环
        vtkActorCollection* actorCollection;// = ui->qvtkWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetActors();
		int num = actorCollection->GetNumberOfItems();
		actorCollection->InitTraversal();
		for (int i = 0; i < num; ++i)
		{
			vtkActor* actor = actorCollection->GetNextActor();
            //ui->qvtkWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->RemoveActor(actor);
		}
	}
    //ui->qvtkWidget->update();


}



//设置当前文件
void MainWindow::setCurrentFile(const QString& filePathList)
{
    curFile = filePathList;
    setWindowFilePath(curFile);//设置关联文件路径

    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(filePathList);//移除所有文件名
    files.prepend(filePathList);//在开头附加子串
    //如果尺寸超过最大尺寸，则删除最后一项
    while (files.size() > MaxRecentFiles)
        files.removeLast();
    std::cout<<"setCurrentFile1111"<<std::endl;
    settings.setValue("recentFileList", files);//设置键值对
    //settings.setValue()
    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
        if (mainWin)
        {
            std::cout<<"setCurrentFile33333"<<std::endl;

            mainWin->updateRecentFileActions();//更新最近文件
            std::cout<<"setCurrentFile4444"<<std::endl;
        }
    }

    std::cout<<"setCurrentFile2222"<<std::endl;

}



//更新最近文件操作
void MainWindow::updateRecentFileActions()
{
    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();//读取recentFileList的值

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);//计算两者的最小值

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));//序号 文件名
        recentFileActs[i]->setText(text);//设置文本
        recentFileActs[i]->setData(files[i]);//设置数据
        recentFileActs[i]->setVisible(true);//设置可见性
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);//其他数量设置为不可见

    separatorAct->setVisible(numRecentFiles > 0);//如果有最近未见则设置分隔符为可见
}


//获取文件名
QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();//返回文件名
}


// 通过颜色对话框改变点云颜色
void MainWindow::pointcolorChanged() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");

    if (color.isValid()) {
        // QAction* action = dynamic_cast<QAction*>(sender());
        // if (action != ui.pointcolorAction) // 改变颜色的信号来自于 dataTree
        QList<QTreeWidgetItem*> itemList = ui->dataTree_2->selectedItems();
        int selected_item_count = ui->dataTree_2->selectedItems().size();
        if (selected_item_count == 0) {
            for (int i = 0; i != mycloud_vec.size(); ++i) {
                mycloud_vec[i].setPointColor(color.red(), color.green(), color.blue());
            }
            // 输出窗口
            consoleLog("Change cloud color", "All point clouds",
                       QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
        }
        else {
            for (int i = 0; i != selected_item_count; i++) {
                int cloud_id = ui->dataTree_2->indexOfTopLevelItem(itemList[i]);
                mycloud_vec[cloud_id].setPointColor(color.red(), color.green(), color.blue());
            }
            // 输出窗口
            consoleLog("Change cloud color", "Point clouds selected",
                       QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()), "");
        }


        showPointcloud();
    }
}


// 显示点云，不重置相机角度
void MainWindow::showPointcloud() {

    for (int i = 0; i != mycloud_vec.size(); i++)
    {

        viewer->updatePointCloud(mycloud_vec[i].cloud, mycloud_vec[i].cloudId);
    }
    //注：viewer->spin()使viewer重新渲染，若不调用则无法自动执行显示
    viewer->spin();
    ui->openGLWidget->update();

}

// 添加点云到viewer,并显示点云
void MainWindow::showPointcloudAdd() {
    for(int i = 0; i < mycloud_vec.size(); i++)
    {
        mycloud_vec[i].elevationRendering();
        viewer->addPointCloud(mycloud_vec[i].cloud, mycloud_vec[i].cloudId);
    }

    showPointcloud();

}

// Add Point Cloud
void MainWindow::add() {
  QStringList filePathList = QFileDialog::getOpenFileNames(
    this,
    tr("Add point cloud file"),
    toQString(mycloud.fileDir),
    toQString(fileIO.getInputFormatsStr())
  );
  if (filePathList.isEmpty()) return;

  loadFile(filePathList);
}

// Clear all point clouds
void MainWindow::clear()
{
    mycloud_vec.clear();  // 从点云容器中移除所有点云
    viewer->removeAllPointClouds();  // 从viewer中移除所有点云
    viewer->removeAllShapes(); // 这个remove更彻底
    ui->dataTree_2->clear();  // 将dataTree清空

    ui->propertyTable->clear();  // 清空属性窗口propertyTable
    QStringList header;
    header << "Property" << "Value";
    ui->propertyTable->setHorizontalHeaderLabels(header);

    viewer->initCameraParameters();

    // 输出窗口
    consoleLog("Clear", "All point clouds", "", "");

    setWindowTitle("CloudViewer");  // 更新窗口标题
    viewer->spin();
    ui->openGLWidget->update();
}

//加载文件
void MainWindow::loadFile(const QStringList& filePathList)
{
    // Open point cloud file one by one
    for (int i = 0; i != filePathList.size(); i++) {
        timeStart(); // time start
        mycloud.cloud.reset(new PointCloudT); // Reset cloud
        QFileInfo fileInfo(filePathList[i]);
        std::string filePath = fromQString(fileInfo.filePath());
        std::string fileName = fromQString(fileInfo.fileName());

        // begin loading
        ui->statusbar->showMessage(
                    fileInfo.fileName() + ": " + QString::number(i) + "/" + QString::number(filePathList.size())
                    + " point cloud loading..."
                    );


        mycloud = fileIO.load(fileInfo);

        std::cout<<"test loadFile function.."<<std::endl;
        if (!mycloud.isValid) {
            // TODO: deal with the error, print error info in console?
            qDebug("invalid cloud.");
            continue;
        }
        mycloud.viewer = viewer;
        mycloud_vec.push_back(mycloud);//将点云加入点云容器

        timeCostSecond = timeOff(); // time off

        consoleLog(
                    "Open",
                    toQString(mycloud.fileName),
                    toQString(mycloud.filePath),
                    "Time cost: " + timeCostSecond + " s, Points: " + QString::number(mycloud.cloud->points.size())
                    );

        // update tree widget
        QTreeWidgetItem *cloudName = new QTreeWidgetItem(QStringList()
                                                         << toQString(mycloud.fileName));
        cloudName->setIcon(0, QIcon(":/Resources/images/icon.png"));
        ui->dataTree_2->addTopLevelItem(cloudName);

        total_points += mycloud.cloud->points.size();
    }
    ui->statusbar->showMessage("");
    showPointcloudAdd();
    setPropertyTable();

}



//打开最近文件
void MainWindow::pRecentOpen()
{
    QAction *action = qobject_cast<QAction *>(sender());
    //if (action)
        //loadFile(action->data().toString());
}



void MainWindow::onaction_Open_File()
{

    std::cout<<"Open File"<<std::endl;

    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径

    QStringList filePathList = QFileDialog::getOpenFileNames(
                this,
                tr("Open point cloud file"),
                curPath,
                "点云文件(*.ply *.obj *.pcd *.stl *.vtk);;所有文件(*.*)");

    if (filePathList.isEmpty())
        return;

    mycloud_vec.clear();
    total_points = 0;
    ui->dataTree_2->clear();
    viewer->removeAllPointClouds();
    loadFile(filePathList);

    consoleLog("Open File", "Point clouds selected", "", "");

}


void MainWindow::on_Index_accepted()
{
    datatable *table =new datatable(this);
    //document *doc;
    table->showNormal();

}

// 设置属性管理窗口
void MainWindow::setPropertyTable() {
  QStringList header;
  header << "Property" << "Value";
  ui->propertyTable->setHorizontalHeaderLabels(header);
  ui->propertyTable->setItem(0, 0, new QTableWidgetItem("Clouds"));
  ui->propertyTable->setItem(0, 1, new QTableWidgetItem(QString::number(0))); //cloud->points.size()

  ui->propertyTable->setItem(1, 0, new QTableWidgetItem("Points"));
  ui->propertyTable->setItem(1, 1, new QTableWidgetItem(""));

  ui->propertyTable->setItem(2, 0, new QTableWidgetItem("Faces"));
  ui->propertyTable->setItem(2, 1, new QTableWidgetItem(""));

  ui->propertyTable->setItem(3, 0, new QTableWidgetItem("Total points"));
  ui->propertyTable->setItem(3, 1, new QTableWidgetItem(QString::number(total_points)));

  ui->propertyTable->setItem(4, 0, new QTableWidgetItem("RGB"));
  ui->propertyTable->setItem(4, 1, new QTableWidgetItem(""));

}


void MainWindow::setConsoleTable() {
  // 设置输出窗口
    QStringList header2;
    header2 << "Time" << "Operation" << "Operation object" << "Details" << "Note";
    ui->consoleTable->setHorizontalHeaderLabels(header2);
    ui->consoleTable->setColumnWidth(0, 150);
    ui->consoleTable->setColumnWidth(1, 200);
    ui->consoleTable->setColumnWidth(2, 200);
    ui->consoleTable->setColumnWidth(3, 300);

    // ui.consoleTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置不可编辑
    ui->consoleTable->verticalHeader()->setDefaultSectionSize(22); // 设置行距

    ui->consoleTable->setContextMenuPolicy(Qt::CustomContextMenu);

}

void MainWindow::consoleLog(QString operation, QString subname, QString filename, QString note) {
    if (enable_console == false) {
        return;
    }
    int rows = ui->consoleTable->rowCount();
    ui->consoleTable->setRowCount(++rows);
    QDateTime time = QDateTime::currentDateTime();  // 获取系统现在的时间
    QString time_str = time.toString("MM-dd hh:mm:ss"); // 设置显示格式
    ui->consoleTable->setItem(rows - 1, 0, new QTableWidgetItem(time_str));
    ui->consoleTable->setItem(rows - 1, 1, new QTableWidgetItem(operation));
    ui->consoleTable->setItem(rows - 1, 2, new QTableWidgetItem(subname));
    ui->consoleTable->setItem(rows - 1, 3, new QTableWidgetItem(filename));
    ui->consoleTable->setItem(rows - 1, 4, new QTableWidgetItem(note));

    ui->consoleTable->scrollToBottom(); // 滑动自动滚到最底部
}


// consoleTable 右击响应事件
void MainWindow::popMenuInConsole(const QPoint&) {
    QAction clearConsoleAction("Clear console", this);
    QAction enableConsoleAction("Enable console", this);
    QAction disableConsoleAction("Disable console", this);

    connect(&clearConsoleAction, &QAction::triggered, this, &MainWindow::clearConsole);
    connect(&enableConsoleAction, &QAction::triggered, this, &MainWindow::enableConsole);
    connect(&disableConsoleAction, &QAction::triggered, this, &MainWindow::disableConsole);

    QPoint pos;
    QMenu menu(ui->dataTree_2);
    menu.addAction(&clearConsoleAction);
    menu.addAction(&enableConsoleAction);
    menu.addAction(&disableConsoleAction);

    if (enable_console == true){
        menu.actions()[1]->setVisible(false);
        menu.actions()[2]->setVisible(true);
    }
    else{
        menu.actions()[1]->setVisible(true);
        menu.actions()[2]->setVisible(false);
        }

    menu.exec(QCursor::pos()); // 在当前鼠标位置显示
}

// 清空 consoleTable
void MainWindow::clearConsole() {
    ui->consoleTable->clearContents();
    ui->consoleTable->setRowCount(0);
}

// 允许使用 consoleTable
void MainWindow::enableConsole() {
    enable_console = true;
}

// 禁用 consoleTable
void MainWindow::disableConsole() {
    clearConsole();
    enable_console = false;

}

// QTreeWidget的item的右击响应函数
void MainWindow::popMenu(const QPoint&) {
    QTreeWidgetItem* curItem = ui->dataTree_2->currentItem(); // 获取当前被点击的节点
    if (curItem == NULL)return;           // 这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
    QString name = curItem->text(0);
    int id = ui->dataTree_2->indexOfTopLevelItem(curItem);
    MyCloud& myCloud = mycloud_vec[id];

    QAction hideItemAction("Hide", this);
    QAction showItemAction("Show", this);
    QAction deleteItemAction("Delete", this);
    QAction changeColorAction("Change color", this);
    // show mode
    QAction pointModeAction("Set point mode", this);
    QAction meshModeAction("Set mesh mode", this);
    QAction pointMeshModeAction("Set point+mesh mode", this);
    //pointModeAction.setData(QVariant(CLOUDVIEWER_MODE_POINT));
    //meshModeAction.setData(QVariant(CLOUDVIEWER_MODE_MESH));
    //pointMeshModeAction.setData(QVariant(CLOUDVIEWER_MODE_POINT_MESH));

    pointModeAction.setCheckable(true);
    meshModeAction.setCheckable(true);
    pointMeshModeAction.setCheckable(true);

    if (myCloud.curMode == "point") {
        pointModeAction.setChecked(true);
    }
    else if (myCloud.curMode == "mesh") {
        meshModeAction.setChecked(true);
    }
    else if (myCloud.curMode == "point+mesh") {
        pointMeshModeAction.setChecked(true);
    }

    connect(&hideItemAction, &QAction::triggered, this, &MainWindow::hideItem);
    connect(&showItemAction, &QAction::triggered, this, &MainWindow::showItem);
    connect(&deleteItemAction, &QAction::triggered, this, &MainWindow::deleteItem);
    connect(&changeColorAction, &QAction::triggered, this, &MainWindow::pointcolorChanged);

    connect(&pointModeAction, SIGNAL(triggered()), this, SLOT(setRenderingMode()));
    connect(&meshModeAction, SIGNAL(triggered()), this, SLOT(setRenderingMode()));
    connect(&pointMeshModeAction, SIGNAL(triggered()), this, SLOT(setRenderingMode()));

    QPoint pos;
    QMenu menu(ui->dataTree_2);
    menu.addAction(&hideItemAction);
    menu.addAction(&showItemAction);
    menu.addAction(&deleteItemAction);
    menu.addAction(&changeColorAction);

    menu.addAction(&pointModeAction);
    menu.addAction(&meshModeAction);
    menu.addAction(&pointMeshModeAction);

    if (mycloud_vec[id].visible == true){
        menu.actions()[1]->setVisible(false);
        menu.actions()[0]->setVisible(true);
    }
    else{
        menu.actions()[1]->setVisible(true);
        menu.actions()[0]->setVisible(false);
    }

    const vector<string> modes = myCloud.supportedModes;
    if (std::find(modes.begin(), modes.end(), "point") == modes.end()) {
        menu.actions()[4]->setVisible(false);
    }
    if (std::find(modes.begin(), modes.end(), "mesh") == modes.end()) {
        menu.actions()[5]->setVisible(false);
    }
    if (std::find(modes.begin(), modes.end(), "point+mesh") == modes.end()) {
        menu.actions()[6]->setVisible(false);
    }

    menu.exec(QCursor::pos()); // 在当前鼠标位置显示
}

void MainWindow::hideItem() {
    QList<QTreeWidgetItem*> itemList = ui->dataTree_2->selectedItems();
    for (int i = 0; i != ui->dataTree_2->selectedItems().size(); i++){
        // TODO hide之后，item变成灰色，再次右击item时，“hideItem” 选项变成 “showItem”
        // QTreeWidgetItem* curItem = ui.dataTree->currentItem();
        QTreeWidgetItem* curItem = itemList[i];
        QString name = curItem->text(0);
        int id = ui->dataTree_2->indexOfTopLevelItem(curItem);
        mycloud_vec[id].hide();
        // QMessageBox::information(this, "cloud_id", QString::fromLocal8Bit(cloud_id.c_str()));

        QColor item_color = QColor(112, 122, 132, 255);
        //curItem->setTextColor(0, item_color);
        mycloud_vec[id].visible = false;
    }

    // 输出窗口
    consoleLog("Hide point clouds", "Point clouds selected", "", "");
    viewer->spin();
    ui->openGLWidget->update();

}

void MainWindow::showItem() {
  QList<QTreeWidgetItem*> itemList = ui->dataTree_2->selectedItems();
    for (int i = 0; i != ui->dataTree_2->selectedItems().size(); i++){
        // QTreeWidgetItem* curItem = ui.dataTree->currentItem();
        QTreeWidgetItem* curItem = itemList[i];
        QString name = curItem->text(0);
        int id = ui->dataTree_2->indexOfTopLevelItem(curItem);
        // 将cloud_id所对应的点云设置成透明
        mycloud_vec[id].show();
        QColor item_color;
        if (theme_id == 0){
            item_color = QColor(0, 0, 0, 255);
        }
        else{
            item_color = QColor(241, 241, 241, 255);
        }
        //curItem->setText(0, item_color);
        //curItem->setTextColor(0, item_color);
        mycloud_vec[id].visible = true;
    }

    // 输出窗口
    consoleLog("Show point clouds", "Point clouds selected", "", "");
    viewer->spin();
    ui->openGLWidget->update();

}


// 三视图
void MainWindow::mainview_action() {
    std::cout<<"show by main view"<<std::endl;
    viewer->setCameraPosition(100, -100, 100, 0, 0, 0, 0, 0, 1);
    ui->openGLWidget->update();

    ui->fpsNumber->display("12345");

}

void MainWindow::leftview_action() {
    std::cout<<"show by left view"<<std::endl;
    viewer->setCameraPosition(-200, 0, 0, 0, 0, 0, 0, 0, 1);
    ui->openGLWidget->update();
}

void MainWindow::topview_action() {
    std::cout<<"show by top view"<<std::endl;
    viewer->setCameraPosition(0, 0, 200, 0, 0, 0, 0, 1, 0);
    ui->openGLWidget->update();
}


void MainWindow::deleteItem() {
    //输出vector删除前的长度
    std::cout << "vector delete item before " << mycloud_vec.size() << std::endl;

    QList<QTreeWidgetItem*> itemList = ui->dataTree_2->selectedItems();
    // ui.dataTree->selectedItems().size() 随着迭代次数而改变，因此循环条件要设置为固定大小的 selected_item_count
    int selected_item_count = ui->dataTree_2->selectedItems().size();

    for (int i = 0; i != selected_item_count; i++){
    // QTreeWidgetItem* curItem = ui.dataTree->currentItem();
    // QMessageBox::information(this, "itemList's size", QString::number(ui.dataTree->selectedItems().size()));
    QTreeWidgetItem* curItem = itemList[i];
    QString name = curItem->text(0);
    int id = ui->dataTree_2->indexOfTopLevelItem(curItem);
    // QMessageBox::information(this, "information", "curItem: " + name + " " + QString::number(id));
    auto it = mycloud_vec.begin() + ui->dataTree_2->indexOfTopLevelItem(curItem);
    // 删除点云之前，将其点的数目保存
    int delete_points = (*it).cloud->points.size();
    it = mycloud_vec.erase(it);
    // QMessageBox::information(this, "information", QString::number(delete_points) + " " + QString::number(mycloud_vec.size()));

    total_points -= delete_points;
    setPropertyTable();
    ui->dataTree_2->takeTopLevelItem(ui->dataTree_2->indexOfTopLevelItem(curItem));

    //选择项数输出
    std::cout << "selected item number =  " << selected_item_count << std::endl;
    std::cout << "selected item id =  " << id << std::endl;
    std::cout << "vector delete item after " << mycloud_vec.size() << std::endl;
    }

   //移除之后再添加，避免 id 和资源管理树行号不一致的情况
    viewer->removeAllPointClouds();
    for (int i = 0; i != mycloud_vec.size(); i++)
    {
        viewer->addPointCloud(mycloud_vec[i].cloud, mycloud_vec[i].cloudId);
        viewer->updatePointCloud(mycloud_vec[i].cloud, mycloud_vec[i].cloudId);
    }

    //输出窗口
    consoleLog("Delete point clouds", "Point clouds selected", "", "");
    viewer->spin();
    ui->openGLWidget->update();


}

void MainWindow::createActions()
{



    pOpen=Files->addAction("打开");
    pOpen->setShortcuts(QKeySequence::Open);//设置快捷键
    pOpen->setStatusTip(tr("Open file"));//设置状态栏
    connect(pOpen,SIGNAL(triggered()),this,SLOT(onaction_Open_File())); //方式1,代码添加菜单栏，关联槽
    connect(ui->openAction,SIGNAL(triggered()),this,SLOT(onaction_Open_File())); //方式2,添加工具栏按钮关联槽

    QObject::connect(ui->addAction, &QAction::triggered, this, &MainWindow::add);
    QObject::connect(ui->clearAction, &QAction::triggered, this, &MainWindow::clear);





    ui->saveAction->setData(QVariant(false));       // isSaveBinary = false
    ui->saveBinaryAction->setData(QVariant(true));  // isSaveBinary = true
    connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->saveBinaryAction, SIGNAL(triggered()), this, SLOT(save()));

    pNew=Files->addAction("新建");
    pNew->setShortcuts(QKeySequence::New);//设置快捷键
    pNew->setStatusTip(tr("Create a new file"));//设置状态栏


    //5个Action(打开最近五个文件)
    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),this, SLOT(pRecentOpen()));
    }



    //设备
    Run=Device->addAction("启动");
    Stop =Device->addAction("停止");
    Close=Device->addAction("关闭");


    //录制
   OpenPcap=Record->addAction("打开文件");
   Start=Record->addAction("开始");
   Pause =Record->addAction("暂停");
   Return=Record->addAction("回放");
   Save=Record->addAction("保存");


    //工具
    Calibration=Tools->addAction("标定");
    Filter=Tools->addAction("滤波");


    //显示
    mainview=viewerMenu->addAction("主视图");
    leftview=viewerMenu->addAction("左视图");
    topview=viewerMenu->addAction("俯视图");
    QObject::connect(mainview,&QAction::triggered,this,&MainWindow::mainview_action);
    QObject::connect(leftview,&QAction::triggered,this,&MainWindow::leftview_action);
    QObject::connect(topview,&QAction::triggered,this,&MainWindow::topview_action);
    connect(ui->mainviewAction, &QAction::triggered, this, &MainWindow::mainview_action);
    connect(ui->leftviewAction, &QAction::triggered, this, &MainWindow::leftview_action);
    connect(ui->topviewAction, &QAction::triggered, this, &MainWindow::topview_action);

    Rotation=Show->addAction("旋转");
    Zoom=Show->addAction("缩放");
    Index=Show->addAction("查看数据");
    connect(Index,SIGNAL(triggered()),this,SLOT(on_Index_accepted()));


    Color=Show->addAction("颜色");

    //配置
    Mcu=Configs->addAction("寄存器");
    Mcu->setStatusTip(tr("寄存器配置"));//设置状态栏
    connect(Mcu,SIGNAL(triggered()),this,SLOT(on_mcu_accepted()));

    Ip_addres=Configs->addAction("IP地址");
    connect(Ip_addres,SIGNAL(triggered()),this,SLOT(on_ip_config_accepted()));



    Device_SN=Configs->addAction("设备序列号");
    Fps=Configs->addAction("帧率");


    Serial_Port=Configs->addAction("串口调试");
    connect(Serial_Port,SIGNAL(triggered()),this,SLOT(on_serial_port_accepted()));

    Firmware = Configs->addAction("固件烧录");
    Did = Configs->addAction("DID");

    //可靠性测试 信号与槽
    Fpga=Monitoring->addAction("FPGA");
    connect(Fpga,SIGNAL(triggered()),this,SLOT(on_FPGA_accepted()));
    Temperature=Monitoring->addAction("温度");
    connect(Temperature,SIGNAL(triggered()),this,SLOT(on_Temperature_Accepted()));
    Vbd=Monitoring->addAction("电压");
    connect(Vbd,SIGNAL(triggered()),this,SLOT(on_Voltage_Accepted()));

    //性能测试
    Accuracy_test=Verify->addAction("精度测试");





    //调试模块

    Laser_Module = Debug->addAction("激光器");
    connect(Laser_Module,SIGNAL(triggered()),this,SLOT(on_laser_accepted()));
    Receiver_Module = Debug->addAction("接收端");
    QObject::connect(Receiver_Module,SIGNAL(triggered()),this,SLOT(on_receiver_accepted()));
    Mems_Module = Debug->addAction("2D mems");
    connect(Mems_Module,SIGNAL(triggered()),this,SLOT(on_mems_accepted()));
	Adc_Module = Debug->addAction("ADC");
	connect(Adc_Module, SIGNAL(triggered()), this, SLOT(on_adc_accepted()));



}




//创建菜单栏
void MainWindow::createMenus()
{


    //在菜单栏上添加菜单
    Files=mBar->addMenu("文件");//在菜单栏上添加了一个文件的菜单

    SystemMenu = new QMenu(this);
    SystemMenu->setTitle(tr("帮助"));

    Files->addMenu(SystemMenu);
    soft=SystemMenu->addAction("关于本软件");
    soft->setShortcuts(QKeySequence::HelpContents);//设置快捷键
    soft->setStatusTip(tr("help document"));//设置状态栏
    connect(soft,SIGNAL(triggered()),this,SLOT(on_document_accepted()));

    //QCoreApplication::setOrganizationName("Recently");         //设置组织名称
    //QCoreApplication::setApplicationName("Recent Files");       //设置标题名称
    //QSettings settings;

    //Files->addSeparator();




    separatorAct = Files->addSeparator();//增加分隔符
    //for (int i = 0; i < MaxRecentFiles; ++i)
    //    Files->addAction(recentFileActs[i]);
    Files->addSeparator();               //增加分隔符
    //Files->addAction(exitAct);
    //updateRecentFileActions();



    //添加分割线
    Files->addSeparator();


    Device=mBar->addMenu("设备");//在菜单栏上添加了一个开始的菜单



    Record=mBar->addMenu("录制");



    Tools=mBar->addMenu("工具");




    Show=mBar->addMenu("显示");
    viewerMenu = new QMenu(this);
    viewerMenu->setTitle(tr("视图"));
    Show->addMenu(viewerMenu);
//    mainview=viewerMenu->addAction("主视图");
//    leftview=viewerMenu->addAction("左视图");
//    topview=viewerMenu->addAction("俯视图");

//    connect(ui->mainviewAction,SIGNAL(triggered()),this,SLOT(mainview_action()));
//    connect(ui->leftviewAction,SIGNAL(triggered()),this,SLOT(leftview_action()));
//    connect(ui->topviewAction,SIGNAL(triggered()),this,SLOT(topview_action()));

    Configs=mBar->addMenu("配置");


    Monitoring=mBar->addMenu("可靠性测试");

    Verify=mBar->addMenu("性能测试");


    Debug=mBar->addMenu("调试");


}


//工具栏颜色按钮
void MainWindow::on_pointcolorAction_triggered()
{
    std::cout<<"start pointClou color change" <<std::endl;
    QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");

    if (color.isValid()) {
        for(int i = 0; i < mycloud_vec.size(); i++){
        mycloud_vec[i].setPointColor(color.red(), color.green(), color.blue());
        }
    }
    showPointcloud();

}


//显示窗口背景颜色
void MainWindow::on_bgcolorAction_triggered()
{
    std::cout<<"start background color change" <<std::endl;
    QColor color = QColorDialog::getColor(Qt::white, this, "Select color for point cloud");

    if (color.isValid()) {
        viewer->setBackgroundColor(double(double(color.red()) / 255), double(double(color.green()) / 255), double(double(color.blue()) / 255));
        viewer->spin();
    }else{
        std::cout << "Please select Color !!!" << std::endl;
    }
}
//工具栏退出操作
void MainWindow::on_exitAction_triggered()
{
    QMainWindow::close();
}
//保存点云文件操作
void MainWindow::on_saveAction_triggered()
{
    std::cout << "Save single point cloud !" << std::endl;
    //保存到PCD文件

    \
    //待完成，弹窗选择保存文件类型
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,
            tr("Save PointCloud File As"), "",
            tr("PCD Files (*.pcd);; PLY File(*.ply);;OBJ File(*obj);; VTK File(*.vtk);; Text File(*.txt)"));
    std::cout << fileName.toStdString() << std::endl;
    if(fileName.contains(".pcd")){
        pcl::io::savePCDFile(fileName.toStdString(), *mycloud_vec[0].cloud);
    }else if(fileName.contains(".ply"))
    {
        pcl::io::savePLYFile(fileName.toStdString(), *mycloud_vec[0].cloud);
    }else if(fileName.contains(".obj"))
    {
        pcl::io::saveOBJFile(fileName.toStdString(), *mycloud_vec[0].mesh);
    }else if(fileName.contains(".ply"))
    {
        pcl::io::saveVTKFile(fileName.toStdString(), *mycloud_vec[0].mesh, 1);
    }

}





//工具栏圆环按钮
void MainWindow::on_addCricleshow_triggered(bool checked)
{
    if(checked)
    {
        //画网格
        for (int i = -100; i <= 100; i += 10) {
            viewer->addLine(pcl::PointXYZ(i, -100, 0), pcl::PointXYZ(i, 100, 0), QString("GridlineY%1").arg(i).toStdString(), 0);
            viewer->addLine(pcl::PointXYZ(-100, i, 0), pcl::PointXYZ(100, i, 0), QString("GridlineX%1").arg(i).toStdString(), 0);
            if (i > 0)
                viewer->addText3D(QString::number(i).append("m").toStdString(), pcl::PointXYZ(0, i, 0), 0.8, 0.5, 0.5, 0.5, QString("GridText%1").arg(i).toStdString(), 0);
            viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineY%1").arg(i).toStdString(), 0);
            viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineX%1").arg(i).toStdString(), 0);
        }
        //画圆环
        for (int j = 1; j <= 10; j++) {
            int r = 10 * j;

            vtkSmartPointer<vtkRegularPolygonSource>   source = vtkSmartPointer<vtkRegularPolygonSource>::New();
            vtkSmartPointer<vtkPolyDataMapper>         mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            vtkSmartPointer<vtkActor>                  actor = vtkSmartPointer<vtkActor>::New();

            source->SetNumberOfSides(70);    //多边形边数
            source->SetRadius(r);            //半径
            source->SetCenter(0, 0, 0);      //圆心
            mapper->SetInputConnection(source->GetOutputPort());
            actor->SetMapper(mapper);
            actor->GetProperty()->SetColor(0.5, 0.5, 0.5);    //颜色
            actor->GetProperty()->SetOpacity(1);    //透明度
            actor->GetProperty()->SetRepresentationToWireframe();//图形不填充，只要边框
            circle_v.push_back(actor);
        }
        for(int i = 0; i < circle_v.size(); i++)
        {
            ui->openGLWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(circle_v[i]);

        }
        viewer->spin();
        ui->openGLWidget->update();

    }else
    {
        //删除网格图形
        viewer->removeAllShapes();
        //删除圆环
        for(int i = 0; i < circle_v.size(); i++)
        {
            ui->openGLWidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->RemoveActor(circle_v[i]);
        }
        viewer->spin();
        ui->openGLWidget->update();
    }

}


void MainWindow::on_addCoordinate_triggered(bool checked)
{
    vtkSmartPointer<vtkAxesActor> axes_actor = vtkSmartPointer<vtkAxesActor>::New();
    vtkOrientationMarkerWidget * widget_new = vtkOrientationMarkerWidget::New();
    if(checked)
    {
        axes_actor->SetAxisLabels( 1 );
        axes_actor->SetPosition(0, 0, 0);
        axes_actor->SetTotalLength(2, 2, 2);
        axes_actor->SetShaftType(0);
        axes_actor->SetCylinderRadius(0.02);

        widget_new->SetOutlineColor(0.9300, 0.5700, 0.1300);
        widget_new->SetOrientationMarker(axes_actor);
        widget_new->SetInteractor(ui->openGLWidget->interactor());
        widget_new->SetEnabled(1);
        widget_new->InteractiveOff();
        //此段语句需要在setRenderer()之后  暂时在初始化中加入
        ui->openGLWidget->update();
    }else
    {
        widget_new->SetOutlineColor(0, 0, 0);
        std::cout<< "hide axes" << std::endl;
        //待完成
    }
}
