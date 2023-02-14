#ifndef POINTCLOUD_H
#define POINTCLOUD_H


#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

class pointcloud
{
public:
    pointcloud();
    void show();
    void elevationRendering(pcl::PointCloud<pcl::PointXYZRGB>& cloud);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;



private:


    void mainview_action();
    void leftview_action();
    void topview_action();
};

#endif // POINTCLOUD_H
