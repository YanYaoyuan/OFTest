#ifndef __MY_CLOUD_H__
#define __MY_CLOUD_H__

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/PolygonMesh.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <QtCore/QDir>
#include <string>
#include <QtCore/QFileInfo>
#include "Tools.h"



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
//#include <QVTKOpenGLNativeWidget.h>
#include <vtkRegularPolygonSource.h>
#include "vtkAutoInit.h"


using namespace std;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;



class MyCloud
{
public:
    MyCloud();
    ~MyCloud();

    bool isValid = false;

    PointCloudT::Ptr cloud;      // point cloud pointer
    pcl::PolygonMesh::Ptr mesh;  // polygon mesh pointer

    string filePath;     // dir + file name   e.g. /home/user/hello.min.ply
    string fileDir;      // only dir          e.g. /home/user
    string fileName;     // only file name    e.g. hello.min.ply
    string fileSuffix;   // file name suffx   e.g. ply

    string cloudId;      // cloud id in `viewer`: "cloud-" + fileName
    string meshId;       // mesh id in `viewer`: "mesh-" + fileName

    bool hasCloud = false;
    bool hasMesh = false;

    // string filename;             // point cloud file full name
    // string subname;              // point cloud file short name
    // string dirname = "E:\\Date\\PointCloud\\";

    bool visible = true;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    string curMode = "point";    // default show mode
    vector<string> supportedModes;




    void setPointColor(int r, int g, int b);
    void setPointAlpha(int a);
    void setShowMode(const string& mode);
    void setPointSize(int a);
    void showCloud();
    void hideCloud();
    void showMesh();
    void hideMesh();
    void show();
    void hide();

    void init(const QFileInfo& fileInfo, bool hasCloud, bool hasMesh);

    static MyCloud getInvalidMyCloud() {
        MyCloud myCloud;
        myCloud.isValid = false;
        return myCloud;
    }



    void elevationRendering();


};
#endif

