#ifndef VTK_SHOW_H
#define VTK_SHOW_H
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
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
#include <QVTKRenderWidget.h>
#include <QVTKOpenGLNativeWidget.h>

typedef pcl::PointXYZRGBA       PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

//点云数据
typedef struct vtkpointcloud{
    float x;
    float y;
    float z;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
}VTK_POINT_CLOUD_S;

class vtk_show : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:
    explicit vtk_show(int win_size,QWidget *parent = nullptr);
    ~vtk_show();
    void test();
    void VTKWindow_Resize(int win_size);
    void Update_Window_PointCloude();
    void Set_Error_Text(QString str);
    void Set_OK_Text(QString str);
    void Set_Info_Text(QString str);
    VTK_POINT_CLOUD_S *Vtk_Win_Point_Cloud;

private:
    pcl::visualization::PCLVisualizer::Ptr viewer;
    PointCloudT::Ptr                       cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr              cloude_color;
    std::string                            Text;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    int Window_Size;


};

#endif // VTK_SHOW_H
