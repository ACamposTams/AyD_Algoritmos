#include "conewindow.h"
#include "ui_conewindow.h"

coneWindow::coneWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::coneWindow)
{
    ui->setupUi(this);
    coneWindow::showFullScreen();
}

coneWindow::~coneWindow()
{
    delete ui;
}

void coneWindow::paintEvent(QPaintEvent *e)
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
            if (figDegrees[i] != 0)
            {
                painter.rotate(figDegrees[i]);
            }
            painter.drawEllipse(rects[i]);
            painter.drawLine(figures[i][4],figures[i][5]-figures[i][3],figures[i][0],figures[i][1]+(figures[i][3]/2));
            painter.drawLine(figures[i][4],figures[i][5]-figures[i][3],figures[i][0]+figures[i][2],figures[i][1]+(figures[i][3]/2));
        }
    }
}

void coneWindow::on_pushButton_clicked()
{
    points.clear();
    double xCentro = 0;
    double yCentro = 0;

    QRect rectangle(xCentro,yCentro,100,50);

    points.push_back(xCentro);
    points.push_back(yCentro);
    points.push_back(100);
    points.push_back(50);

    points.push_back(xCentro+50);
    points.push_back(yCentro-50);

    figures.clear();
    rects.clear();
    figures.push_back(points);
    rects.push_back(rectangle);
    figDegrees.push_back(0);
    draw = true;
    update();
}

void coneWindow::on_pushButton_2_clicked()
{
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();

    if (!xText.isEmpty() && !yText.isEmpty())
    {
        points = translation(points);
        figures.push_back(points);
        figDegrees.push_back(0);
        update();
     }
}

std::vector<int> coneWindow::translation(std::vector<int> currentPoints)
{
    QString xText = ui->lineEdit->text();
    QString yText = ui->lineEdit_3->text();

    int tx = xText.toInt();
    int ty = yText.toInt();

    std::vector<int> traslatedPoints;
    traslatedPoints = currentPoints;
    traslatedPoints[0] = traslatedPoints[0]+tx;
    traslatedPoints[1] = traslatedPoints[1]+ty;
    traslatedPoints[4] = traslatedPoints[4]+tx;
    traslatedPoints[5] = traslatedPoints[5]+ty;

    QRect rectangle(traslatedPoints[0],traslatedPoints[1],traslatedPoints[2],traslatedPoints[3]);
    rects.push_back(rectangle);

    return traslatedPoints;
}

void coneWindow::on_pushButton_3_clicked()
{
    QString degreeText = ui->lineEdit_2->text();

    if (!degreeText.isEmpty())
    {
        points = rotation(points);
        figures.push_back(points);
        update();
    }
}

std::vector<int> coneWindow::rotation(std::vector<int> currentPoints)
{
    QString degreeText = ui->lineEdit_2->text();
    int degrees = degreeText.toInt();
    std::vector<int> rotatedPoints = currentPoints;
    QRect rectangle(rotatedPoints[0],rotatedPoints[1],rotatedPoints[2],rotatedPoints[3]);
    rects.push_back(rectangle);
    figDegrees.push_back(degrees);
    return rotatedPoints;
}

void coneWindow::on_pushButton_4_clicked()
{
    points = zoomIn(points);
    figures.push_back(points);
    figDegrees.push_back(0);
    update();
}

std::vector<int> coneWindow::zoomIn(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    int zoomValue = 2;
    zoomedPoints = currentPoints;
    zoomedPoints[2] = zoomedPoints[2] * zoomValue;
    zoomedPoints[3] = zoomedPoints[3] * zoomValue;
    zoomedPoints[4] = zoomedPoints[0] + (zoomedPoints[2]/2);

    QRect rectangle(zoomedPoints[0],zoomedPoints[1],zoomedPoints[2],zoomedPoints[3]);
    rects.push_back(rectangle);

    return zoomedPoints;
}

void coneWindow::on_pushButton_5_clicked()
{
    points = zoomOut(points);
    figures.push_back(points);
    figDegrees.push_back(0);
    update();
}

std::vector<int> coneWindow::zoomOut(std::vector<int> currentPoints)
{
    std::vector<int> zoomedPoints;
    float zoomValue = 0.5;
    zoomedPoints = currentPoints;
    zoomedPoints[2] = zoomedPoints[2] * zoomValue;
    zoomedPoints[3] = zoomedPoints[3] * zoomValue;
    zoomedPoints[4] = zoomedPoints[0] + (zoomedPoints[2]/2);

    QRect rectangle(zoomedPoints[0],zoomedPoints[1],zoomedPoints[2],zoomedPoints[3]);
    rects.push_back(rectangle);

    return zoomedPoints;
}
