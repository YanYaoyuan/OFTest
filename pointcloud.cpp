#include "pointcloud.h"
#include <QDir>
#include <QDebug>
pointcloud::pointcloud()
{
    //pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
}

void pointcloud::elevationRendering(pcl::PointCloud<pcl::PointXYZRGB>& cloud)
{
    // ----------------------------上中下红绿蓝颜色设置---------------------------
    uint8_t topColor[3] = { 255,0,0 };
    uint8_t midColor[3] = { 0,255,0 };
    uint8_t bottomColor[3] = { 0,0,255 };

    // ----------------------------获取当前点云高程极值---------------------------

    float minz = FLT_MAX;
    float maxz = -FLT_MAX;
    // min,max函数比pcl::getMinMax3D()效率高
    for (auto& point_i : cloud)
    {
        minz = fmin(minz, point_i.z); // z取值范围的最小值
        maxz = fmax(maxz, point_i.z); // z取值范围的最大值

    }

    float midz = (maxz + minz) / 2;
    // -----------------------------颜色渲染--------------------------------------
    for (size_t i = 0; i < cloud.points.size(); ++i)
    {
        if (cloud.points[i].z < midz)
        {
            float k1 = (cloud.points[i].z - minz) / (midz - minz);
            cloud.points[i].r = bottomColor[0] + (midColor[0] - bottomColor[0]) * k1;
            cloud.points[i].g = bottomColor[1] + (midColor[1] - bottomColor[1]) * k1;
            cloud.points[i].b = bottomColor[2] + (midColor[2] - bottomColor[2]) * k1;
        }
        else
        {
            float k2 = (cloud.points[i].z - minz) / (maxz - midz);
            cloud.points[i].r = midColor[0] + (topColor[0] - midColor[0]) * k2;
            cloud.points[i].g = midColor[1] + (topColor[1] - midColor[1]) * k2;
            cloud.points[i].b = midColor[2] + (topColor[2] - midColor[2]) * k2;
        }
    }
}


void pointcloud::show()
{

    //while(true){
        // -------------------------------加载点云数据----------------------------------
        cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
        viewer.reset(new pcl::visualization::PCLVisualizer("3D Point", true));
        std::cout<<"currentPath    "<< QDir::currentPath().toStdString()<<std::endl;
        if (pcl::io::loadPCDFile("../data/1.pcd", *cloud) < 0)
        {
            PCL_ERROR("Could not read file\n");
            //return (-1);
        }

        // -------------------------------按高程设置颜色-----------------------------------
        elevationRendering(*cloud);
        pcl::io::savePCDFileBinary("Binary.pcd", *cloud); // 高程渲染后的点云


        viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "sample");

        while (!viewer->wasStopped())
        {
            viewer->spinOnce();
        }

    //}

}


// 三视图
void pointcloud::mainview_action() {
    viewer->setCameraPosition(0, -1, 0, 0.5, 0.5, 0.5, 0, 0, 1);
    while (!viewer->wasStopped())
    {
        viewer->spinOnce();
    }
    //ui.screen->update();
}

void pointcloud::leftview_action() {
    viewer->setCameraPosition(-1, 0, 0, 0, 0, 0, 0, 0, 1);
    while (!viewer->wasStopped())
    {
        viewer->spinOnce();
    }
    //ui.screen->update();
}

void pointcloud::topview_action() {
    viewer->setCameraPosition(0, 0, 1, 0, 0, 0, 0, 1, 0);
    while (!viewer->wasStopped())
    {
        viewer->spinOnce();
    }
    //ui.screen->update();
}
