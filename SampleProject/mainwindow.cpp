#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->morning_button,SIGNAL(clicked()),this,SLOT(onMorningPressed()));
    connect(ui->night_button,SIGNAL(clicked()),this,SLOT(onNightPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMorningPressed()
{
    ui->text->setText("GoodMorning");
}

void MainWindow::onNightPressed()
{
    ui->text->setText("GoodNight");
}
