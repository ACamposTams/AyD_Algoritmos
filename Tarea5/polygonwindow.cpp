#include "polygonwindow.h"
#include "ui_polygonwindow.h"
#include <math.h>

polygonWindow::polygonWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::polygonWindow)
{
    ui->setupUi(this);
    polygonWindow::showFullScreen();
}

polygonWindow::~polygonWindow()
{
    delete ui;
}

void polygonWindow::paintEvent(QPaintEvent *e)
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
            for (int j = 0; j < points.size();j+=4)
            {
                painter.drawLine(figures[i][j],figures[i][j+1], figures[i][j+2], figures[i][j+3]);
            }
        }
    }
}

void polygonWindow::on_pushButton_clicked()
{
      QString n = ui->boxXfin->toPlainText();

        if (!n.isEmpty())
        {
            points.clear();
            int sides = n.toInt();
            double radius = 100;
            double angle = (double)360.0/(double)sides;
            double xCentro = 0;//xStr.toInt();
            double yCentro = 0;//yStr.toInt();

            int xi,yi,xf,yf;
            double val = M_PI / 180;
            angle *= val;
            int a = 0;

            for(a=1; a<=sides; a++)
            {
                xi = xCentro + (radius * cos(angle*a));
                yi = yCentro + (radius * sin(angle*a));
                xf = xCentro + (radius * cos(angle*(a+1)));
                yf = yCentro + (radius * sin(angle*(a+1)));
                points.push_back(xi);
                points.push_back(yi);
                points.push_back(xf);
                points.push_back(yf);
            }
            figures.clear();
            figures.push_back(points);
            draw = true;
            update();
        }
}

void polygonWindow::on_pushButton_2_clicked()
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

std::vector<int> polygonWindow::translation(std::vector<int> currentPoints)
{
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();

    if (!xText.isEmpty() && !yText.isEmpty())
    {
        std::vector<int> traslatedPoints;
        int tx = xText.toInt();
        int ty = yText.toInt();
        bool x = true;

        for (int i=0;i<currentPoints.size();i++)
        {
            if (x)
            {
                traslatedPoints.push_back(currentPoints[i]+tx);
                x = false;
            }
            else
            {
                traslatedPoints.push_back(currentPoints[i]+ty);
                x = true;
            }
        }
        return traslatedPoints;
    }
}

void polygonWindow::on_pushButton_3_clicked()
{
    QString degreeText = ui->lineEdit_2->text();

    if (!degreeText.isEmpty() && draw == true)
    {
        points = rotation(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> polygonWindow::rotation(std::vector<int> currentPoints)
{
    QString degreeText = ui->lineEdit_2->text();
    int degree = degreeText.toInt();
    std::vector<int> rotatedPoints;
    bool x = true;
    int xr = currentPoints[0];
    int yr = currentPoints[1];

        for (int i = 0; i < currentPoints.size();i++)
        {
            if (x)
            {
                rotatedPoints.push_back(xr + ((currentPoints[i]-xr) * cos(degree)) - ((currentPoints[i+1]-yr) * sin(degree)));
                x = false;
            }
            else
            {
                rotatedPoints.push_back(yr + ((currentPoints[i-1]-xr) * sin(degree)) + ((currentPoints[i]-yr) * cos(degree)));
                x = true;
            }
        }
    return rotatedPoints;
}

void polygonWindow::on_pushButton_4_clicked()
{
    if (draw == true)
    {
        points = zoomIn(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> polygonWindow::zoomIn(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    int zoomValue = 2;
    bool x = true;
    int xf = currentPoints[0];
    int yf = currentPoints[1];
    for (int i = 0; i < currentPoints.size();i++)
            {
                if (x)
                {
                    zoomedPoints.push_back(xf + (currentPoints[i] - xf)*zoomValue);
                    x = false;
                }
                else
                {
                    zoomedPoints.push_back(yf + (currentPoints[i] - yf)*zoomValue);
                    x = true;
                }
            }
    return zoomedPoints;
}

void polygonWindow::on_pushButton_5_clicked()
{
    if (draw == true)
    {
        points = zoomOut(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> polygonWindow::zoomOut(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    bool x = true;
    int xf = currentPoints[0];
    int yf = currentPoints[1];
    for (int i = 0; i < currentPoints.size();i++)
            {
                if (x)
                {
                    zoomedPoints.push_back(xf + (currentPoints[i] - xf)*(0.5));
                    x = false;
                }
                else
                {
                    zoomedPoints.push_back(yf + (currentPoints[i] - yf)*(0.5));
                    x = true;
                }
            }
    return zoomedPoints;
}

void polygonWindow::on_pushButton_6_clicked()
{
    if (draw == true)
    {
        points = reflection(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> polygonWindow::reflection(std::vector<int> currentPoints)
{
    std::vector<int> rotatedPoints;
    bool x = true;
        int xr = currentPoints[0];
        int yr = currentPoints[1];

        for (int i = 0; i < currentPoints.size();i++)
        {
            if (x)
            {
                rotatedPoints.push_back(xr + ((currentPoints[i]-xr) * cos(135)) - ((currentPoints[i+1]-yr) * sin(135)));
                x = false;
            }
            else
            {
                rotatedPoints.push_back(yr + ((currentPoints[i-1]-xr) * sin(135)) + ((currentPoints[i]-yr) * cos(135)));
                x = true;
            }
        }
    return rotatedPoints;
}
