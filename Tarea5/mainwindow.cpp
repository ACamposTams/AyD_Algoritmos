#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "polygonwindow.h"
#include "arcwindow.h"
#include "cubewindow.h"
#include "rectprismwindow.h"
#include "recttriprism.h"
#include "conewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    polygonWindow polygon;
    polygon.setModal(true);
    polygon.exec();
}

void MainWindow::on_toolButton_2_clicked()
{
    arcWindow arc;
    arc.setModal(true);
    arc.exec();
}

void MainWindow::on_toolButton_3_clicked()
{
    cubeWindow cube;
    cube.setModal(true);
    cube.exec();
}

void MainWindow::on_toolButton_4_clicked()
{
    rectPrismWindow prism;
    prism.setModal(true);
    prism.exec();
}

void MainWindow::on_toolButton_5_clicked()
{
    rectTriPrism prism;
    prism.setModal(true);
    prism.exec();
}

void MainWindow::on_toolButton_6_clicked()
{
    coneWindow cone;
    cone.setModal(true);
    cone.exec();
}
