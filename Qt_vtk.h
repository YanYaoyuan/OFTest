#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_vtk.h"
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
#include <QVTKOpenGLNativeWidget.h>
class Qt_vtk : public QMainWindow
{
    Q_OBJECT

public:
    Qt_vtk(QWidget *parent = nullptr);
    ~Qt_vtk();

	void test();

private:
    Ui::Qt_vtkClass ui;
};
