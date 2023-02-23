#include "MyCloud.h"
#include "pcl/conversions.h"

MyCloud::MyCloud() {
    cloud.reset(new PointCloudT);
    mesh.reset(new pcl::PolygonMesh);
}

MyCloud::~MyCloud() {
}

void MyCloud::init(const QFileInfo& fileInfo, bool hasCloudParam, bool hasMeshParam) {
    hasCloud = hasCloudParam;
    hasMesh = hasMeshParam;

    filePath = fromQString(fileInfo.filePath());
    fileDir = fromQString(fileInfo.path());
    fileName = fromQString(fileInfo.fileName());
    fileSuffix = fromQString(fileInfo.suffix());

    if (!hasCloud && !hasMesh) {
        isValid = false;
        return;
    }

    isValid = true;
    if (hasMesh) {
        meshId = "mesh-" + fileName;
        cloudId = "cloud-" + fileName;
        pcl::fromPCLPointCloud2(mesh->cloud, *cloud);
        setPointAlpha(255);
        supportedModes = {"point", "mesh", "point+mesh"};
    }
    if (hasCloud) {
        cloudId = "cloud-" + fileName;
        setPointAlpha(255);
        supportedModes = {"point"};
    }

    // default show node
    curMode = "point";


}

void MyCloud::elevationRendering()
{


    // ----------------------------上中下红绿蓝颜色设置---------------------------
    uint8_t topColor[3] = { 255,0,0 };
    uint8_t midColor[3] = { 0,255,0 };
    uint8_t bottomColor[3] = { 0,0,255 };

    // ----------------------------获取当前点云高程极值---------------------------

    float minz = FLT_MAX;
    float maxz = -FLT_MAX;
    // min,max函数比pcl::getMinMax3D()效率高

    for(int i=0;i<(cloud->points.size());i++)
    {
        minz = fmin(minz, cloud->points[i].z); // z取值范围的最小值
        maxz = fmax(maxz, cloud->points[i].z); // z取值范围的最大值

    }

    float midz = (maxz + minz) / 2;
    // -----------------------------颜色渲染--------------------------------------
    for (size_t i = 0; i < (*cloud).points.size(); ++i)
    {
        if ((*cloud).points[i].z < midz)
        {
            float k1 = ((*cloud).points[i].z - minz) / (midz - minz);
            (*cloud).points[i].r = bottomColor[0] + (midColor[0] - bottomColor[0]) * k1;
            (*cloud).points[i].g = bottomColor[1] + (midColor[1] - bottomColor[1]) * k1;
            (*cloud).points[i].b = bottomColor[2] + (midColor[2] - bottomColor[2]) * k1;
        }
        else
        {
            float k2 = ((*cloud).points[i].z - minz) / (maxz - midz);
            (*cloud).points[i].r = midColor[0] + (topColor[0] - midColor[0]) * k2;
            (*cloud).points[i].g = midColor[1] + (topColor[1] - midColor[1]) * k2;
            (*cloud).points[i].b = midColor[2] + (topColor[2] - midColor[2]) * k2;
        }
    }
}








void MyCloud::setPointColor(int r, int g, int b) {
    //viewer改变颜色
    for (int i = 0; i != cloud->points.size(); ++i) {
        std::cout <<"single pointcloud color change" << std::endl;
        (*cloud).points[i].r = r;
        (*cloud).points[i].g = g;
        (*cloud).points[i].b = b;
    }



}

void MyCloud::setPointAlpha(int a) {
    for (int i = 0; i != cloud->points.size(); ++i) {
        cloud->points[i].a = a;
    }
}

void MyCloud::setShowMode(const string& mode) {
    curMode = mode;
    show();
}

void MyCloud::setPointSize(int a)
{
    viewer->setPointCloudRenderingProperties (
                pcl::visualization::PCL_VISUALIZER_POINT_SIZE, a/10, cloudId);
}

void MyCloud::showCloud() {
    viewer->setPointCloudRenderingProperties(
                pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 1.0, cloudId, 0);


}

void MyCloud::hideCloud() {
    viewer->setPointCloudRenderingProperties(
                pcl::visualization::RenderingProperties::PCL_VISUALIZER_OPACITY, 0.0, cloudId, 0);


}

void MyCloud::showMesh() {
    if (meshId == "") return; // no mesh
    viewer->addPolygonMesh(*mesh, meshId);
}

void MyCloud::hideMesh() {
    if (meshId == "") return;
    viewer->removePolygonMesh(meshId);
}

void MyCloud::show() {
    if (curMode == "point") {
        hideMesh();
        showCloud();
    }
    else if (curMode == "mesh") {
        hideCloud();
        showMesh();
    }
    else if (curMode == "point+mesh") {
        showCloud();
        showMesh();
    }
}

void MyCloud::hide() {
    hideCloud();
    hideMesh();
}

