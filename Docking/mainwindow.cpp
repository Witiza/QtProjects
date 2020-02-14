#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ui_inspector.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    uiMainWindow(new Ui::MainWindow), uiInspector(new Ui::Inspector)
{
    uiMainWindow->setupUi(this);

    //create empu widget
    QWidget* widget = new QWidget();
    //execute setupUI
    uiInspector->setupUi(widget);
    //set the widget into the dock
    uiMainWindow->dockInspector->setWidget(widget);

    connect(uiMainWindow->actionLoad_File, SIGNAL(triggered()),this,SLOT(onLoadFile()));
}

MainWindow::~MainWindow()
{
    delete uiMainWindow;
    delete uiInspector;
}

void MainWindow::onLoadFile()
{
    uiInspector->doubleSpinBox_2->setValue( uiInspector->doubleSpinBox_2->value()+1);
}
