#ifndef POLYGONWINDOW_H
#define POLYGONWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <vector>

namespace Ui
{
class polygonWindow;
}

class polygonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit polygonWindow(QWidget *parent = 0);
    ~polygonWindow();
    std::vector<int> translation(std::vector<int>);
    std::vector<int> rotation(std::vector<int>);
    std::vector<int> reflection(std::vector<int>);
    std::vector<int> zoomOut(std::vector<int>);
    std::vector<int> zoomIn(std::vector<int>);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::polygonWindow *ui;

protected:
    void paintEvent(QPaintEvent *);
    bool draw = false;
    std::vector<int> points;
    std::vector<std::vector<int> > figures;
};

#endif // POLYGONWINDOW_H
