#include "hierarchy.h"
#include "ui_hierarchy.h"

Hierarchy::Hierarchy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hierarchy)
{
    ui->setupUi(this);

    connect(ui->add_entity, SIGNAL(clicked()),this,SLOT(onAddEntity()));
    connect(ui->remove_entity, SIGNAL(clicked()),this,SLOT(onRemoveEntity()));
    connect(ui->listWidget, SIGNAL(currentRowChanged(int)),this,SLOT(onEntitySelected(int)));

}

Hierarchy::~Hierarchy()
{
    delete ui;
}

void Hierarchy::onAddEntity()
{
    ui->listWidget->addItem("Entity");
}

void Hierarchy::onRemoveEntity()
{
    ui->listWidget->takeItem( ui->listWidget->currentRow());
}

void Hierarchy::onEntitySelected(int row)
{

    emit entitySelected(row);
}
