#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include "hierarchy.h"
#include "inspector.h"
#include "sceneview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),uiMainWindow(new Ui::MainWindow)
{
    uiMainWindow->setupUi(this);

//    connect(uiMainWindow->actionLoad_File, SIGNAL(triggered()),this,SLOT(onLoadFile()));
//    connect(uiMainWindow->actionSave_File, SIGNAL(triggered()),this,SLOT(onSaveFile()));


    hierarchy = new Hierarchy();
   uiMainWindow->dockHierarchy->setWidget(hierarchy);
   inspector = new Inspector();
   uiMainWindow->dockInspector->setWidget(inspector);

   sceneView = new SceneView();

   QVBoxLayout* layout = new QVBoxLayout();
   layout->addWidget(sceneView);
   uiMainWindow->centralWidget->setLayout(layout);
   //uiMainWindow->

   connect(hierarchy,SIGNAL(entitySelected(int)),inspector, SLOT(onEntitySelected(int)));
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;

}

void MainWindow::onLoadFile()
{
    //uiTransform->doubleSpinBox_2->setValue( uiTransform->doubleSpinBox_2->value()+1);

}

void MainWindow::onSaveFile()
{
//    QMessageBox::StandardButton button = QMessageBox::question(this,"Exit App","Do you want to exit?");
//    if(button == QMessageBox::Yes)
//    {
//        qApp->exit();
//    }
    QString path = QFileDialog::getOpenFileName(this,"Load File");
    if(!path.isEmpty())
    {
        QMessageBox::information(this,"Info",path);
    }
}
