#include "vtk_show.h"

vtk_show::vtk_show(int win_size, QWidget *parent)
    : QVTKOpenGLNativeWidget(parent)
{
    // The default color
    red         = 128;
    green       = 128;
    blue        = 128;
    Window_Size = 0;
    Vtk_Win_Point_Cloud = new VTK_POINT_CLOUD_S[1920*1080*4*10];
    qDebug()<<"aaaa1";
#if VTK_MAJOR_VERSION > 8
    qDebug()<<"aaaa11";
  auto renderer2 = vtkSmartPointer<vtkRenderer>::New();
  auto renderWindow2 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    qDebug()<<"aaaa113";
  renderWindow2->AddRenderer(renderer2);
    qDebug()<<"aaaa114";
  viewer.reset(new pcl::visualization::PCLVisualizer(renderer2, renderWindow2, "viewer", false));
  //viewer.reset(new pcl::visualization::PCLVisualizer ("viewer", false));
    qDebug()<<"aaaa112";
  this->setRenderWindow(viewer->getRenderWindow());
    qDebug()<<"aaaa2";
  viewer->setupInteractor(this->interactor(), this->renderWindow());
    qDebug()<<"aaaa3";
#else
    qDebug()<<"aaaa12";
  viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
  this->SetRenderWindow(viewer->getRenderWindow());
  viewer->setupInteractor(this->GetInteractor(), this->GetRenderWindow());
#endif


    std::string fileName = "3.ply";
    pcl::PolygonMesh meshData;//读取原始数据
    pcl::io::loadPolygonFile(fileName,meshData);

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(meshData.cloud, *cloud);//将obj数据转换为点云数据

    // 显示结果图
    viewer->setBackgroundColor (0, 0, 0); //设置背景
    // viewer->addCoordinateSystem (15.0); //设置坐标系
    qDebug()<<"aaaaa";
    pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> fildColor(cloud, "z");
    viewer->addPointCloud<pcl::PointXYZ>(cloud, fildColor, "sample cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
    viewer->resetCamera ();
    update ();

    // cloud.reset (new PointCloudT);
    // qDebug()<<"aaaa31";
    // viewer->addPointCloud (cloud, "cloud");
    // qDebug()<<"aaaa32";
    // viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, "cloud");
    // qDebug()<<"aaaa33";
    // VTKWindow_Resize(win_size);
    // viewer->resetCamera ();
    // update ();
    // //widget定义为QVTKOpenGLNativeWidget类型窗口
    // auto renderer = vtkSmartPointer<vtkRenderer>::New();
    // auto renderWindow2 = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    // qDebug()<<"aaaa13";
    // renderWindow2->AddRenderer(renderer);

    // // Set up the QVTK window
    // qDebug()<<"aaaa12";
    // viewer.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow2, "viewer", false));
    // //viewer.reset(new pcl::visualization::PCLVisualizer ("viewer", false));




    // qDebug()<<"aaaa1";
    // vtkNew<vtkGenericOpenGLRenderWindow> window;
    // window->AddRenderer(viewer->getRendererCollection()->GetFirstRenderer());
    // setRenderWindow(window.Get());
    // //setRenderWindow (viewer->getRenderWindow ());

    // qDebug()<<"aaaa2";//GetInteractor GetRenderWindow
    // viewer->setupInteractor (this->interactor(),  this->renderWindow());
    // qDebug()<<"aaaa3";


    // viewer->addText("", 100, 100, 20, 1.0,255.0,255.0,"No_text");//红
    // viewer->addText("", 500, 500, 20, 255.0,255.0,1.0,"INFO_text");//蓝
    // viewer->addText("", 700, 700, 20, 255.0,1.0,255.0,"Yes_text");//绿

    // qDebug()<<"aaaa4";
    // // Setup the cloud pointer
    // cloud.reset (new PointCloudT);
// //    cloude_color.reset(new pcl::PointCloud<pcl::PointXYZ>);
// //    pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> fildColor(cloude_color, "z"); // 按照z字段进行渲染


// //    viewer->addPointCloud<pcl::PointXYZ>(cloude_color, fildColor, "cloud");

    // viewer->addPointCloud (cloud, "cloud");
    // viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, "cloud");
    // qDebug()<<"aaaa3";
    // VTKWindow_Resize(win_size);

    // viewer->resetCamera ();
    // update ();
}


void vtk_show::test(){
    vtkSmartPointer<vtkNamedColors> namedColors =
      vtkSmartPointer<vtkNamedColors>::New();

    // Sphere
    vtkSmartPointer<vtkSphereSource> sphereSource =
      vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetRadius(400);
    sphereSource->Update();

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkSmartPointer<vtkActor> sphereActor =
      vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);
    sphereActor->GetProperty()->SetDiffuseColor(
      namedColors->GetColor3d("Tomato").GetData());

    // Camera
    vtkSmartPointer<vtkCamera> camera =
      vtkSmartPointer<vtkCamera>::New();

    vtkSmartPointer<vtkCameraActor> cameraActor =
      vtkSmartPointer<vtkCameraActor>::New();
    cameraActor->SetCamera(camera);
    cameraActor->GetProperty()->SetColor(0, 0, 0);

    // (Xmin,Xmax,Ymin,Ymax,Zmin,Zmax).
    double* bounds = new double[6];
    bounds = cameraActor->GetBounds();
    std::cout << "bounds: " << bounds[0] << " " << bounds[1] << " " << bounds[2] << " " <<
        bounds[3] << " " << bounds[4] << " " << bounds[5] << std::endl;

    // Visualize
    vtkSmartPointer<vtkRenderer> renderer =
      vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow =
      vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    renderer->AddActor(sphereActor);
    // Compute the active camera parameters
    renderer->ResetCamera();

    // Set the camera parameters for the camera actor
    camera->DeepCopy(renderer->GetActiveCamera());
    renderer->AddActor(cameraActor);

    // Position the camera so that we can see the camera actor
    renderer->GetActiveCamera()->SetPosition(1, 0, 0);
    renderer->GetActiveCamera()->SetFocalPoint(0, 0, 0);
    renderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    renderer->GetActiveCamera()->Azimuth(30);
    renderer->GetActiveCamera()->Elevation(30);

    renderer->ResetCamera();
    renderer->SetBackground(namedColors->GetColor3d("SlateGray").GetData());

    renderWindow->Render();
    renderWindowInteractor->Start();
}
