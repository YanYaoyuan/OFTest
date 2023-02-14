/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QVTKOpenGLNativeWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *centralwidget;
    QDockWidget *consoleDock;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *consoleTable;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QDockWidget *dataDock;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout;
    QTreeWidget *dataTree_2;
    QDockWidget *propertyDock_2;
    QWidget *dockWidgetContents_9;
    QGridLayout *gridLayout_2;
    QTableWidget *propertyTable;
    QLabel *label;
    QPushButton *pushButton_2;
    QVTKOpenGLNativeWidget *qvtkWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1397, 804);
        MainWindow->setMinimumSize(QSize(1200, 800));
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon1);
        saveasAction = new QAction(MainWindow);
        saveasAction->setObjectName(QString::fromUtf8("saveasAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/images/saveBinary.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveasAction->setIcon(icon2);
        cubeAction = new QAction(MainWindow);
        cubeAction->setObjectName(QString::fromUtf8("cubeAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/images/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        cubeAction->setIcon(icon3);
        helpAction = new QAction(MainWindow);
        helpAction->setObjectName(QString::fromUtf8("helpAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpAction->setIcon(icon4);
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Resources/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutAction->setIcon(icon5);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Resources/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAction->setIcon(icon6);
        pointcolorAction = new QAction(MainWindow);
        pointcolorAction->setObjectName(QString::fromUtf8("pointcolorAction"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Resources/images/pointcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointcolorAction->setIcon(icon7);
        bgcolorAction = new QAction(MainWindow);
        bgcolorAction->setObjectName(QString::fromUtf8("bgcolorAction"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Resources/images/bgcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        bgcolorAction->setIcon(icon8);
        mainviewAction = new QAction(MainWindow);
        mainviewAction->setObjectName(QString::fromUtf8("mainviewAction"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Resources/images/zhengshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainviewAction->setIcon(icon9);
        leftviewAction = new QAction(MainWindow);
        leftviewAction->setObjectName(QString::fromUtf8("leftviewAction"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Resources/images/zuoshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftviewAction->setIcon(icon10);
        topviewAction = new QAction(MainWindow);
        topviewAction->setObjectName(QString::fromUtf8("topviewAction"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Resources/images/fushi.png"), QSize(), QIcon::Normal, QIcon::Off);
        topviewAction->setIcon(icon11);
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QString::fromUtf8("clearAction"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Resources/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearAction->setIcon(icon12);
        addAction = new QAction(MainWindow);
        addAction->setObjectName(QString::fromUtf8("addAction"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addAction->setIcon(icon13);
        sphereAction = new QAction(MainWindow);
        sphereAction->setObjectName(QString::fromUtf8("sphereAction"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Resources/images/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        sphereAction->setIcon(icon14);
        cylinderAction = new QAction(MainWindow);
        cylinderAction->setObjectName(QString::fromUtf8("cylinderAction"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Resources/images/cylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        cylinderAction->setIcon(icon15);
        meshsurfaceAction = new QAction(MainWindow);
        meshsurfaceAction->setObjectName(QString::fromUtf8("meshsurfaceAction"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Resources/images/mesh.png"), QSize(), QIcon::Normal, QIcon::Off);
        meshsurfaceAction->setIcon(icon16);
        wireframeAction = new QAction(MainWindow);
        wireframeAction->setObjectName(QString::fromUtf8("wireframeAction"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Resources/images/frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        wireframeAction->setIcon(icon17);
        windowsThemeAction = new QAction(MainWindow);
        windowsThemeAction->setObjectName(QString::fromUtf8("windowsThemeAction"));
        darculaThemeAction = new QAction(MainWindow);
        darculaThemeAction->setObjectName(QString::fromUtf8("darculaThemeAction"));
        saveBinaryAction = new QAction(MainWindow);
        saveBinaryAction->setObjectName(QString::fromUtf8("saveBinaryAction"));
        saveBinaryAction->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        consoleDock = new QDockWidget(centralwidget);
        consoleDock->setObjectName(QString::fromUtf8("consoleDock"));
        consoleDock->setGeometry(QRect(1, 541, 1100, 220));
        consoleDock->setMinimumSize(QSize(1100, 140));
        consoleDock->setMaximumSize(QSize(524287, 220));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
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
        consoleTable->setShowGrid(false);
        consoleTable->setGridStyle(Qt::SolidLine);
        consoleTable->setRowCount(0);
        consoleTable->setColumnCount(5);
        consoleTable->horizontalHeader()->setVisible(true);
        consoleTable->horizontalHeader()->setDefaultSectionSize(200);
        consoleTable->horizontalHeader()->setStretchLastSection(true);
        consoleTable->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(consoleTable);

        consoleDock->setWidget(dockWidgetContents_7);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 12, 276, 478));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        dataDock = new QDockWidget(layoutWidget);
        dataDock->setObjectName(QString::fromUtf8("dataDock"));
        dataDock->setEnabled(true);
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

        gridLayout_3->addWidget(dataDock, 0, 0, 1, 1);

        propertyDock_2 = new QDockWidget(layoutWidget);
        propertyDock_2->setObjectName(QString::fromUtf8("propertyDock_2"));
        propertyDock_2->setMinimumSize(QSize(250, 233));
        propertyDock_2->setFont(font);
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_9);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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

        gridLayout_2->addWidget(propertyTable, 0, 0, 1, 1);

        propertyDock_2->setWidget(dockWidgetContents_9);

        gridLayout_3->addWidget(propertyDock_2, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(470, 500, 200, 24));
        label->setMinimumSize(QSize(200, 0));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 500, 121, 23));
        qvtkWidget = new QVTKOpenGLNativeWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(290, 10, 821, 481));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1397, 23));
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
        toolBar->addAction(saveBinaryAction);
        toolBar->addAction(pointcolorAction);
        toolBar->addAction(mainviewAction);
        toolBar->addAction(leftviewAction);
        toolBar->addAction(topviewAction);

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
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
