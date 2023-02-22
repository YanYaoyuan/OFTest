/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLNativeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *saveAction;
    QAction *saveasAction;
    QAction *cubeAction;
    QAction *helpAction;
    QAction *aboutAction;
    QAction *exitAction;
    QAction *pointcolorAction;
    QAction *bgcolorAction;
    QAction *mainviewAction;
    QAction *leftviewAction;
    QAction *topviewAction;
    QAction *clearAction;
    QAction *addAction;
    QAction *sphereAction;
    QAction *cylinderAction;
    QAction *meshsurfaceAction;
    QAction *wireframeAction;
    QAction *windowsThemeAction;
    QAction *darculaThemeAction;
    QAction *saveBinaryAction;
    QAction *addCricleshow;
    QAction *addCoordinate;
    QWidget *centralwidget;
    QDockWidget *consoleDock;
    QWidget *dockWidgetContents_7;
    QTableWidget *consoleTable;
    QDockWidget *dataDock;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout;
    QTreeWidget *dataTree_2;
    QDockWidget *propertyDock_2;
    QWidget *dockWidgetContents_9;
    QTableWidget *propertyTable;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLCDNumber *fpsNumber;
    QLabel *label;
    QVTKOpenGLNativeWidget *openGLWidget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *fristFrame;
    QPushButton *lastFrame;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *nextFrame;
    QPushButton *endFrame;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 813);
        MainWindow->setMinimumSize(QSize(1200, 800));
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon1);
        saveasAction = new QAction(MainWindow);
        saveasAction->setObjectName(QString::fromUtf8("saveasAction"));
        saveasAction->setIcon(icon1);
        cubeAction = new QAction(MainWindow);
        cubeAction->setObjectName(QString::fromUtf8("cubeAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        cubeAction->setIcon(icon2);
        helpAction = new QAction(MainWindow);
        helpAction->setObjectName(QString::fromUtf8("helpAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpAction->setIcon(icon3);
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutAction->setIcon(icon4);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAction->setIcon(icon5);
        pointcolorAction = new QAction(MainWindow);
        pointcolorAction->setObjectName(QString::fromUtf8("pointcolorAction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/pointcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointcolorAction->setIcon(icon6);
        bgcolorAction = new QAction(MainWindow);
        bgcolorAction->setObjectName(QString::fromUtf8("bgcolorAction"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/bgcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        bgcolorAction->setIcon(icon7);
        mainviewAction = new QAction(MainWindow);
        mainviewAction->setObjectName(QString::fromUtf8("mainviewAction"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/zhengshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainviewAction->setIcon(icon8);
        leftviewAction = new QAction(MainWindow);
        leftviewAction->setObjectName(QString::fromUtf8("leftviewAction"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/zuoshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftviewAction->setIcon(icon9);
        topviewAction = new QAction(MainWindow);
        topviewAction->setObjectName(QString::fromUtf8("topviewAction"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/fushi.png"), QSize(), QIcon::Normal, QIcon::Off);
        topviewAction->setIcon(icon10);
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QString::fromUtf8("clearAction"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearAction->setIcon(icon11);
        addAction = new QAction(MainWindow);
        addAction->setObjectName(QString::fromUtf8("addAction"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addAction->setIcon(icon12);
        sphereAction = new QAction(MainWindow);
        sphereAction->setObjectName(QString::fromUtf8("sphereAction"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        sphereAction->setIcon(icon13);
        cylinderAction = new QAction(MainWindow);
        cylinderAction->setObjectName(QString::fromUtf8("cylinderAction"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/cylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        cylinderAction->setIcon(icon14);
        meshsurfaceAction = new QAction(MainWindow);
        meshsurfaceAction->setObjectName(QString::fromUtf8("meshsurfaceAction"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/mesh.png"), QSize(), QIcon::Normal, QIcon::Off);
        meshsurfaceAction->setIcon(icon15);
        wireframeAction = new QAction(MainWindow);
        wireframeAction->setObjectName(QString::fromUtf8("wireframeAction"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        wireframeAction->setIcon(icon16);
        windowsThemeAction = new QAction(MainWindow);
        windowsThemeAction->setObjectName(QString::fromUtf8("windowsThemeAction"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/theme.png"), QSize(), QIcon::Normal, QIcon::Off);
        windowsThemeAction->setIcon(icon17);
        darculaThemeAction = new QAction(MainWindow);
        darculaThemeAction->setObjectName(QString::fromUtf8("darculaThemeAction"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/interview.png"), QSize(), QIcon::Normal, QIcon::Off);
        darculaThemeAction->setIcon(icon18);
        saveBinaryAction = new QAction(MainWindow);
        saveBinaryAction->setObjectName(QString::fromUtf8("saveBinaryAction"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/saveBinary.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveBinaryAction->setIcon(icon19);
        addCricleshow = new QAction(MainWindow);
        addCricleshow->setObjectName(QString::fromUtf8("addCricleshow"));
        addCricleshow->setCheckable(true);
        addCricleshow->setChecked(false);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/circle1.png"), QSize(), QIcon::Normal, QIcon::Off);
        addCricleshow->setIcon(icon20);
        addCoordinate = new QAction(MainWindow);
        addCoordinate->setObjectName(QString::fromUtf8("addCoordinate"));
        addCoordinate->setCheckable(true);
        addCoordinate->setChecked(false);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/AXES.png"), QSize(), QIcon::Normal, QIcon::Off);
        addCoordinate->setIcon(icon21);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        consoleDock = new QDockWidget(centralwidget);
        consoleDock->setObjectName(QString::fromUtf8("consoleDock"));
        consoleDock->setEnabled(true);
        consoleDock->setGeometry(QRect(10, 540, 1131, 211));
        consoleDock->setMinimumSize(QSize(800, 140));
        consoleDock->setMaximumSize(QSize(1500, 220));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        consoleTable = new QTableWidget(dockWidgetContents_7);
        if (consoleTable->columnCount() < 5)
            consoleTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        consoleTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        consoleTable->setObjectName(QString::fromUtf8("consoleTable"));
        consoleTable->setGeometry(QRect(0, 10, 1131, 161));
        consoleTable->setShowGrid(false);
        consoleTable->setGridStyle(Qt::SolidLine);
        consoleTable->setRowCount(0);
        consoleTable->setColumnCount(5);
        consoleTable->horizontalHeader()->setVisible(false);
        consoleTable->horizontalHeader()->setDefaultSectionSize(200);
        consoleTable->horizontalHeader()->setStretchLastSection(true);
        consoleTable->verticalHeader()->setVisible(false);
        consoleDock->setWidget(dockWidgetContents_7);
        dataDock = new QDockWidget(centralwidget);
        dataDock->setObjectName(QString::fromUtf8("dataDock"));
        dataDock->setEnabled(true);
        dataDock->setGeometry(QRect(12, 16, 300, 233));
        dataDock->setMinimumSize(QSize(250, 233));
        dataDock->setMaximumSize(QSize(300, 524287));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        dataDock->setFont(font);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QString::fromUtf8("dockWidgetContents_8"));
        gridLayout = new QGridLayout(dockWidgetContents_8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dataTree_2 = new QTreeWidget(dockWidgetContents_8);
        dataTree_2->setObjectName(QString::fromUtf8("dataTree_2"));
        dataTree_2->setMinimumSize(QSize(230, 180));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        dataTree_2->setFont(font1);
        dataTree_2->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout->addWidget(dataTree_2, 0, 0, 1, 1);

        dataDock->setWidget(dockWidgetContents_8);
        propertyDock_2 = new QDockWidget(centralwidget);
        propertyDock_2->setObjectName(QString::fromUtf8("propertyDock_2"));
        propertyDock_2->setGeometry(QRect(12, 252, 291, 261));
        propertyDock_2->setMinimumSize(QSize(250, 233));
        propertyDock_2->setFont(font);
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        propertyTable = new QTableWidget(dockWidgetContents_9);
        if (propertyTable->columnCount() < 2)
            propertyTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        propertyTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        propertyTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        if (propertyTable->rowCount() < 4)
            propertyTable->setRowCount(4);
        propertyTable->setObjectName(QString::fromUtf8("propertyTable"));
        propertyTable->setGeometry(QRect(9, 9, 271, 221));
        propertyTable->setMinimumSize(QSize(230, 180));
        propertyTable->setFont(font1);
        propertyTable->setFrameShadow(QFrame::Sunken);
        propertyTable->setMidLineWidth(0);
        propertyTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        propertyTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        propertyTable->setAutoScroll(true);
        propertyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        propertyTable->setTabKeyNavigation(true);
        propertyTable->setProperty("showDropIndicator", QVariant(true));
        propertyTable->setDragDropOverwriteMode(true);
        propertyTable->setAlternatingRowColors(false);
        propertyTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        propertyTable->setTextElideMode(Qt::ElideLeft);
        propertyTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        propertyTable->setShowGrid(false);
        propertyTable->setWordWrap(true);
        propertyTable->setCornerButtonEnabled(true);
        propertyTable->setRowCount(4);
        propertyTable->setColumnCount(2);
        propertyTable->horizontalHeader()->setCascadingSectionResizes(false);
        propertyTable->horizontalHeader()->setMinimumSectionSize(25);
        propertyTable->horizontalHeader()->setDefaultSectionSize(100);
        propertyTable->horizontalHeader()->setHighlightSections(true);
        propertyTable->horizontalHeader()->setStretchLastSection(true);
        propertyTable->verticalHeader()->setVisible(false);
        propertyTable->verticalHeader()->setCascadingSectionResizes(false);
        propertyDock_2->setWidget(dockWidgetContents_9);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(900, 490, 241, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(20);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        fpsNumber = new QLCDNumber(layoutWidget);
        fpsNumber->setObjectName(QString::fromUtf8("fpsNumber"));

        horizontalLayout->addWidget(fpsNumber);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 490, 200, 21));
        label->setMinimumSize(QSize(200, 0));
        openGLWidget = new QVTKOpenGLNativeWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(340, 30, 801, 451));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(620, 490, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fristFrame = new QPushButton(layoutWidget1);
        fristFrame->setObjectName(QString::fromUtf8("fristFrame"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/frist.png"), QSize(), QIcon::Normal, QIcon::Off);
        fristFrame->setIcon(icon22);
        fristFrame->setIconSize(QSize(40, 40));
        fristFrame->setFlat(true);

        horizontalLayout_2->addWidget(fristFrame);

        lastFrame = new QPushButton(layoutWidget1);
        lastFrame->setObjectName(QString::fromUtf8("lastFrame"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/last_frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        lastFrame->setIcon(icon23);
        lastFrame->setIconSize(QSize(40, 40));
        lastFrame->setFlat(true);

        horizontalLayout_2->addWidget(lastFrame);

        play = new QPushButton(layoutWidget1);
        play->setObjectName(QString::fromUtf8("play"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon24);
        play->setIconSize(QSize(40, 40));
        play->setFlat(true);

        horizontalLayout_2->addWidget(play);

        stop = new QPushButton(layoutWidget1);
        stop->setObjectName(QString::fromUtf8("stop"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon25);
        stop->setIconSize(QSize(40, 40));
        stop->setFlat(true);

        horizontalLayout_2->addWidget(stop);

        nextFrame = new QPushButton(layoutWidget1);
        nextFrame->setObjectName(QString::fromUtf8("nextFrame"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/images/next_frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextFrame->setIcon(icon26);
        nextFrame->setIconSize(QSize(40, 40));
        nextFrame->setFlat(true);

        horizontalLayout_2->addWidget(nextFrame);

        endFrame = new QPushButton(layoutWidget1);
        endFrame->setObjectName(QString::fromUtf8("endFrame"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/images/end.png"), QSize(), QIcon::Normal, QIcon::Off);
        endFrame->setIcon(icon27);
        endFrame->setIconSize(QSize(40, 40));
        endFrame->setFlat(true);

        horizontalLayout_2->addWidget(endFrame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(openAction);
        toolBar->addAction(addAction);
        toolBar->addAction(clearAction);
        toolBar->addAction(saveAction);
        toolBar->addAction(saveasAction);
        toolBar->addAction(saveBinaryAction);
        toolBar->addAction(pointcolorAction);
        toolBar->addAction(bgcolorAction);
        toolBar->addAction(addCricleshow);
        toolBar->addAction(addCoordinate);
        toolBar->addAction(mainviewAction);
        toolBar->addAction(leftviewAction);
        toolBar->addAction(topviewAction);
        toolBar->addAction(cubeAction);
        toolBar->addAction(meshsurfaceAction);
        toolBar->addAction(cylinderAction);
        toolBar->addAction(sphereAction);
        toolBar->addAction(wireframeAction);
        toolBar->addAction(windowsThemeAction);
        toolBar->addAction(darculaThemeAction);
        toolBar->addAction(helpAction);
        toolBar->addAction(aboutAction);
        toolBar->addAction(exitAction);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OF_Lidar", nullptr));
        openAction->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(statustip)
        openAction->setStatusTip(QCoreApplication::translate("MainWindow", "open a exsting file", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        openAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAction->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(statustip)
        saveAction->setStatusTip(QCoreApplication::translate("MainWindow", "save the file", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        saveAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveasAction->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        cubeAction->setText(QCoreApplication::translate("MainWindow", "Generate cube", nullptr));
#if QT_CONFIG(statustip)
        cubeAction->setStatusTip(QCoreApplication::translate("MainWindow", "generate a cube point cloud", nullptr));
#endif // QT_CONFIG(statustip)
        helpAction->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(statustip)
        helpAction->setStatusTip(QCoreApplication::translate("MainWindow", "show help information", nullptr));
#endif // QT_CONFIG(statustip)
        aboutAction->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(statustip)
        aboutAction->setStatusTip(QCoreApplication::translate("MainWindow", "show some information of the software", nullptr));
#endif // QT_CONFIG(statustip)
        exitAction->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        exitAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        pointcolorAction->setText(QCoreApplication::translate("MainWindow", "Point cloud color", nullptr));
        bgcolorAction->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        mainviewAction->setText(QCoreApplication::translate("MainWindow", "Main view", nullptr));
        leftviewAction->setText(QCoreApplication::translate("MainWindow", "Left view", nullptr));
        topviewAction->setText(QCoreApplication::translate("MainWindow", "Top view", nullptr));
        clearAction->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        addAction->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        sphereAction->setText(QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        cylinderAction->setText(QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        meshsurfaceAction->setText(QCoreApplication::translate("MainWindow", "Surface", nullptr));
        wireframeAction->setText(QCoreApplication::translate("MainWindow", "Wireframe", nullptr));
        windowsThemeAction->setText(QCoreApplication::translate("MainWindow", "Windows", nullptr));
        darculaThemeAction->setText(QCoreApplication::translate("MainWindow", "Darcula", nullptr));
        saveBinaryAction->setText(QCoreApplication::translate("MainWindow", "Save as binary", nullptr));
#if QT_CONFIG(statustip)
        saveBinaryAction->setStatusTip(QCoreApplication::translate("MainWindow", "Save point cloud as binary file", nullptr));
#endif // QT_CONFIG(statustip)
        addCricleshow->setText(QCoreApplication::translate("MainWindow", "Cricle", nullptr));
#if QT_CONFIG(tooltip)
        addCricleshow->setToolTip(QCoreApplication::translate("MainWindow", "addCricle", nullptr));
#endif // QT_CONFIG(tooltip)
        addCoordinate->setText(QCoreApplication::translate("MainWindow", "Coordinate", nullptr));
#if QT_CONFIG(tooltip)
        addCoordinate->setToolTip(QCoreApplication::translate("MainWindow", "addCoordinate", nullptr));
#endif // QT_CONFIG(tooltip)
        consoleDock->setWindowTitle(QCoreApplication::translate("MainWindow", "Console", nullptr));
        QTableWidgetItem *___qtablewidgetitem = consoleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = consoleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Operation", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = consoleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Operation Object", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = consoleTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = consoleTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        dataDock->setWindowTitle(QCoreApplication::translate("MainWindow", "PointCloud", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = dataTree_2->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Point Cloud File", nullptr));
        propertyDock_2->setWindowTitle(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = propertyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = propertyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PointSize", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "FPS:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        fristFrame->setText(QString());
        lastFrame->setText(QString());
        play->setText(QString());
        stop->setText(QString());
        nextFrame->setText(QString());
        endFrame->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
