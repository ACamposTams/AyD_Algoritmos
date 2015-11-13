#include "arcwindow.h"
#include "ui_arcwindow.h"
#include <iostream>

arcWindow::arcWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arcWindow)
{
    ui->setupUi(this);
    arcWindow::showFullScreen();
}

arcWindow::~arcWindow()
{
    delete ui;
}

void arcWindow::paintEvent(QPaintEvent *e)
{
    if (draw == true)
    {
        QPainter painter(this);
        int w = width()/2;
        int h = height()/2;
        painter.translate(w,h);
        QPen pointPen(Qt::black);
        pointPen.setWidth(2);
        for (int i = 0; i < figures.size();i++)
        {
            if (i == figures.size()-1)
            {
               QPen newPen(Qt::red);
               painter.setPen(newPen);
            }
            else
            {
                painter.setPen(pointPen);
            }
            QRectF rectangle(figures[i][0],figures[i][1],figures[i][2],figures[i][3]);
            painter.drawArc(rectangle,figures[i][4],figures[i][5]);
        }
    }
}

void arcWindow::on_pushButton_clicked()
{
    points.clear();
    double xCentro = 0;
    double yCentro = 0;
    int startAngle = 0*16;
    int spanAngle = 90*16;
    points.push_back(xCentro);
    points.push_back(yCentro);
    points.push_back(100);
    points.push_back(100);
    points.push_back(startAngle);
    points.push_back(spanAngle);

    figures.clear();
    figures.push_back(points);
    draw = true;
    update();
}

void arcWindow::on_pushButton_2_clicked()
{
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();

    if (!xText.isEmpty() && !yText.isEmpty() && draw == true)
    {
        points = translation(points);
        figures.push_back(points);
        update();
     }
}

std::vector<int> arcWindow::translation(std::vector<int> currentPoints)
{
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();
    int tx = xText.toInt();
    int ty = yText.toInt();
    std::vector<int> traslatedPoints;
    traslatedPoints = currentPoints;
    traslatedPoints[0] = traslatedPoints[0]+tx;
    traslatedPoints[1] = traslatedPoints[1]+ty;
    return traslatedPoints;
}

void arcWindow::on_pushButton_3_clicked()
{
    QString degreeText = ui->lineEdit_2->text();

    if (!degreeText.isEmpty() && draw == true)
    {
        points = rotation(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> arcWindow::rotation(std::vector<int> currentPoints)
{
    QString degreeText = ui->lineEdit_2->text();
    int degree = degreeText.toInt();
    std::vector<int> rotatedPoints;
    rotatedPoints = currentPoints;
    rotatedPoints[4] = rotatedPoints[4] + (degree*16);
    return rotatedPoints;
}

void arcWindow::on_pushButton_4_clicked()
{
    if (draw == true)
    {
        points = zoomIn(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> arcWindow::zoomIn(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    int zoomValue = 2;
    zoomedPoints = currentPoints;
    zoomedPoints[2] = zoomedPoints[2] * zoomValue;
    zoomedPoints[3] = zoomedPoints[3] * zoomValue;
    return zoomedPoints;
}

void arcWindow::on_pushButton_5_clicked()
{
    if (draw == true)
    {
        points = zoomOut(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> arcWindow::zoomOut(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    float zoomValue = 0.5;
    zoomedPoints = currentPoints;
    zoomedPoints[2] = zoomedPoints[2] * zoomValue;
    zoomedPoints[3] = zoomedPoints[3] * zoomValue;
    return zoomedPoints;
}

void arcWindow::on_pushButton_6_clicked()
{
    if (draw == true)
    {
        points = reflection(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> arcWindow::reflection(std::vector<int> currentPoints)
{
    std::vector<int> rotatedPoints;
    rotatedPoints = currentPoints;
    rotatedPoints[4] = rotatedPoints[4] + (180*16);
    return rotatedPoints;
}
