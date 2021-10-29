#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <vector>
#include <algorithm>
#define maxVer 50
#define maxHt 1000
#define maxWd 800

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    int x_max,x_min,y_max,y_min;

    void point(int x,int y,int r=0,int g=255,int b=255);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_resetButton_clicked();

    //int changeX(int x);

    //int changeY(int y);

    void on_showgrid_clicked();

    void on_dda_clicked(int choice=0);

    void on_bressenham_clicked();

    void on_midpt_clicked();

    void on_bress_circle_clicked();

    void on_ellipse_clicked();

    void drawEllipse(QPoint p1,int rx,int ry);

    void MidPoint_Draw(QPoint p1,int r);
    //void drawCartesian(QPoint p1, int r);

    void drawPolar(QPoint p1,int r);

    void on_Polar_clicked();
//    void floodfillFunc(int x1, int y1,int k, QRgb q1, int r,int g,int b);
    void floodfillFunc(int x, int y, int r, int g, int b) ;
    void on_FloodFill_clicked();
    void on_PolarEllipse_clicked();
    void drawPolarEllipse(QPoint p1,int major,int minor);

    void boundaryFillFunc(int x, int y, QRgb edgecolour, int r, int g, int b);
    void on_Cartesian_clicked();
    void drawCartesian(QPoint p1,int radius);
    void on_BoundaryFill_clicked();
    //void on_polygonDraw_clicked(int x1,int y1,int x2,int y2);
    void on_AddVertex_clicked();
    void on_DrawPolygon_clicked();
    void bressn(QPoint p1, QPoint p2);

    void on_CENTRE_ELLIPSE_clicked();
    void on_CENTRE_CIRCLE_clicked();
    void on_SEED_clicked();
    void on_setvertex_clicked();
    void on_clearvertex_clicked();
    void initEdgeTable();
    void storeEdgeInTable (int x1,int y1, int x2, int y2);
    void on_scanlinefill_clicked();
    void on_translation_clicked(int flag=1,int x=0,int y=0);
    void poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b);
    void on_scaling_clicked();
    void on_rotation_clicked();
    void on_shearing_clicked();
    void on_reflection_clicked();
    void on_about_a_point_clicked();
    void on_set_point_clicked();
//    void on_about_x_clicked();
//    void on_reflect_clicked();
};

#endif // MAINWINDOW_H
