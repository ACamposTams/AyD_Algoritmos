// falta rotacion y reflexion

#include "recttriprism.h"
#include "ui_recttriprism.h"

rectTriPrism::rectTriPrism(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rectTriPrism)
{
    ui->setupUi(this);
    rectTriPrism::showFullScreen();
}

rectTriPrism::~rectTriPrism()
{
    delete ui;
}

void rectTriPrism::paintEvent(QPaintEvent *e)
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

            int diagonal = (figures[i][2] - figures[i][0])/2;

            painter.drawLine(figures[i][0],figures[i][1],figures[i][2],figures[i][3]);
            painter.drawLine(figures[i][0],figures[i][1],figures[i][4],figures[i][5]);
            painter.drawLine(figures[i][2],figures[i][3],figures[i][4],figures[i][5]);

            painter.drawLine(figures[i][0]+diagonal,figures[i][1]-diagonal,figures[i][2]+diagonal,figures[i][3]-diagonal);
            painter.drawLine(figures[i][0]+diagonal,figures[i][1]-diagonal,figures[i][4]+diagonal,figures[i][5]-diagonal);
            painter.drawLine(figures[i][2]+diagonal,figures[i][3]-diagonal,figures[i][4]+diagonal,figures[i][5]-diagonal);

            painter.drawLine(figures[i][0],figures[i][1],figures[i][0]+diagonal,figures[i][1]-diagonal);
            painter.drawLine(figures[i][2],figures[i][3],figures[i][2]+diagonal,figures[i][3]-diagonal);
            painter.drawLine(figures[i][4],figures[i][5],figures[i][4]+diagonal,figures[i][5]-diagonal);
        }
    }
}

void rectTriPrism::on_pushButton_clicked()
{
            points.clear();
            double xCentro = 0;
            double yCentro = 0;

            int x1 = xCentro-50;
            points.push_back(x1);
            int y1 = yCentro+50;
            points.push_back(y1);
            int x2 = xCentro+50;
            points.push_back(x2);
            int y2 = yCentro+50;
            points.push_back(y2);
            int x3 = xCentro;
            points.push_back(x3);
            int y3 = yCentro-50;
            points.push_back(y3);

            figures.clear();
            figures.push_back(points);
            draw = true;
            update();
}

void rectTriPrism::on_pushButton_2_clicked()
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

std::vector<int> rectTriPrism::translation(std::vector<int> currentPoints)
{
    std::vector<int> traslatedPoints;
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();
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

void rectTriPrism::on_pushButton_3_clicked()
{
    QString degreeText = ui->lineEdit_2->text();

    if (!degreeText.isEmpty() && draw == true)
    {
        points = rotation(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> rectTriPrism::rotation(std::vector<int> currentPoints)
{
    std::vector<int> rotatedPoints;
    QString degreeText = ui->lineEdit_2->text();
    int degree = degreeText.toInt();
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

void rectTriPrism::on_pushButton_4_clicked()
{
    if (draw == true)
    {
        points = zoomIn(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> rectTriPrism::zoomIn(std::vector<int> currentPoints)
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

void rectTriPrism::on_pushButton_5_clicked()
{
    if (draw == true)
    {
        points = zoomOut(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> rectTriPrism::zoomOut(std::vector<int> currentPoints)
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

void rectTriPrism::on_pushButton_6_clicked()
{
    if (draw == true)
    {
        points = reflection(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> rectTriPrism::reflection(std::vector<int> currentPoints)
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
