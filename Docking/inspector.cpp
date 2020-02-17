#include "inspector.h"
#include "ui_transform.h"
#include "ui_mesh.h"
#include <QVBoxLayout>

Inspector::Inspector(QWidget* parent):QWidget (parent),uiTransform(new Ui::Transform),uiMesh(new Ui::Mesh)
{
    QVBoxLayout* layout = new QVBoxLayout();

    QWidget* transformWidget = new QWidget;
    uiTransform->setupUi(transformWidget);
    QWidget* meshWidget = new QWidget;
    uiMesh->setupUi(meshWidget);

    layout->addWidget(transformWidget);
    layout->addWidget(meshWidget);
    setLayout(layout);
}

Inspector::~Inspector()
{
    delete uiTransform;
    delete uiMesh;
}
