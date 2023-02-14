#include "Qt_vtk.h"

Qt_vtk::Qt_vtk(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

		Qt_vtk::test();

}

Qt_vtk::~Qt_vtk()
{}


void Qt_vtk::test() {
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
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	//vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	
	//renderWindow->AddRenderer(renderer);

	/*vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);
*/
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
	//renderer->SetBackground(0.3, 0.4, 0.3);

	//ui.qvtkWidget->setRenderWindow(renderWindow);
	//renderWindow->Render();
	//renderWindowInteractor->Start();


	

	QVTKOpenGLNativeWidget* qvtkWidget = new QVTKOpenGLNativeWidget();
	//��ʼ��VTK����Ⱦ����ƽʱ�õıȽ϶���vtkRenderWindow��������QT��Ҫ����vtkGenericOpenGLRenderWindow��ʵ������vtkRenderWindow����һ��
	//vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	//����Ⱦ�����뵽VTK�����С�������д��һ�У������ٽ�׼���õ�vtkRenderer���뵽renderWindow��Ҳ�ǿ���ͬ�����ݵ�
	//qvtkWidget->setRenderWindow(renderWindow);
	ui.qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	ui.qvtkWidget->GetRenderWindow()->SetSize(640, 480);
	
	
	
}