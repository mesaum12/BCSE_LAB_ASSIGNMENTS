#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <string>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <unistd.h>
#include <vector>
#include <chrono>
#include<dos.h>
#include<time.h>
#include<stdio.h>


using namespace std;
using namespace std::chrono;

using namespace std;
QImage img=QImage(700,700,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//this function is responsible for coloring the pixels
void MainWindow::point(int x,int y,int r,int g,int b)
{
    int k = ui->gridsize->value();//GridSize
    if(k>1)
    {
        int startX=x/k*k;
        int startY=y/k*k;

        //Drawing the pixels
        for(int i=startX+1;i<(startX+k) and i<img.width();i++)
            for(int j=startY+1;j<(startY+k) and j<img.height();j++)
                img.setPixel(i,j,qRgb(r,g,b));
    }
    else
        img.setPixel(x,y,qRgb(r,g,b));
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
void delay (int value=100) {
    int SLEEP_ms = value;
    QTime dieTime= QTime::currentTime().addMSecs(SLEEP_ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, value);
}
void MainWindow::showMousePosition(QPoint &pos)
{
       int size = ui->gridsize->value();
       int x = pos.x();
       int y = pos.y();
       if(x >= (img.width()/(2*size))*size  && x <= ((img.width()/(2*size))*size  + size)){
            x = 0;
       }
       else if(x >= img.width()/2)
        x = (x - (img.width()/(2*size))*size - size)/size + 1 ;
       else{
            x = -(((img.width()/(2*size))*size  - x)/size + 1) ;
       }
       if(y >= (img.height()/(2*size))*size && y <= ((img.height()/(2*size))*size + size)  )
           y = 0;
       else if(y >= img.height()/2)
        y = -((y - (img.height()/(2*size))*size - size)/size + 1);
       else{
           y = ((img.height()/(2*size))*size - y)/size + 1;
       }
       ui->mouse_movement->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    //ui->mouse_movement->setText(" X : "+QString::number(changeX(pos.x()))+", Y : "+QString::number(changeY(pos.y())));
}

void MainWindow::Mouse_Pressed()
{
    int size = ui->gridsize->value();
    int x = ui->frame->x;
    int y = ui->frame->y;
    if(x >= (img.width()/(2*size))*size  && x <= ((img.width()/(2*size))*size  + size)){
         x = 0;
    }
    else if(x >= img.width()/2)
     x = (x - (img.width()/(2*size))*size - size)/size + 1 ;
    else{
         x = -(((img.width()/(2*size))*size  - x)/size + 1) ;
    }
    if(y >= (img.height()/(2*size))*size && y <= ((img.height()/(2*size))*size + size)  )
        y = 0;
    else if(y >= img.height()/2)
     y = -((y - (img.height()/(2*size))*size - size)/size + 1);
    else{
        y = ((img.height()/(2*size))*size - y)/size + 1;
    }
    ui->mouse_pressed->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    //ui->mouse_pressed->setText(" X : "+QString::number(changeX(ui->frame->x))+", Y : "+QString::number(changeY(ui->frame->y)));
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
    point(ui->frame->x,ui->frame->y,0,255,255);

}
void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        //Draw Y-axis
        for(int i=0;i<=img.height();i++)
            point(i,img.width()/2,255,0,0);

        //Draw X-axis
        for(int i=0;i<=img.width();i++)
            point(img.height()/2,i,255,0,0);

    }
    else{
        //Draw Y-axis
        for(int i=0;i<=img.height();i++)
            point(i,img.width()/2,0,0,0);
        //Draw X-axis
        for(int i=0;i<=img.width();i++)
            point(img.height()/2,i,0,0,0);
    }
}
void MainWindow::on_set_point1_clicked()
{
    if(ui->draw_line->isChecked() || ui->fourConn->isChecked() || ui->eight_conn->isChecked()
            || ui->POLYGON->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

    }
}

void MainWindow::on_set_point2_clicked()
{
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);

    }
}

void MainWindow::on_Draw_clicked()
{

    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);

    if(ui->draw_line->isChecked()){
        painter.setPen(Qt::yellow);
        painter.drawLine(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}
int Color_flag=0;
void MainWindow::on_resetButton_clicked()
{
    Color_flag=0;
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    on_showgrid_clicked();
    on_show_axes_clicked();
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_showgrid_clicked()
{
    int k = ui->gridsize->value();

    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }

    for(int i=0;i<img.height();i+=k)
        for(int j=0;j<img.width();j++)
            img.setPixel(i,j,qRgb(56,224,56));

    ui->frame->setPixmap(QPixmap::fromImage(img));
    for(int i=0;i<img.width();i+=k)
        for(int j=0;j<img.height();j++)
             img.setPixel(j,i,qRgb(56,224,56));

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

//This function draws a line between the two selected points using DDA algorithm
void MainWindow::on_dda_clicked(int choice)
{

    int k = ui->gridsize->value();
    QElapsedTimer timer,timer1;
    timer.start();
    //Now p1 and p2 contains the points
    int x1=(p1.x()/k);
    int y1=(p1.y()/k);

    int x2=(p2.x()/k);
    int y2=(p2.y()/k);


    // here we implement the algorithm
    int dx=x2-x1;
    int dy=y2-y1;
    int steps=0; //number of steps to  put pixel

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    double Xinc=(double)dx/(double)steps;
    double Yinc=(double)dy/(double)steps;

    double x=x1*k+k/2;
    double y=y1*k+k/2;

    int time2=0;

    if (choice==0)
    {
        for(int v=0; v <steps; v++)
        {
            x = x + Xinc*k;
            y = y + Yinc*k;
            timer1.start();
            point((int)(x+0.5),(int)(y+0.5));
            time2+=(timer1.nsecsElapsed()/1000);
            delay();

        }
    }
    else
    {
        for(int v=0; v <steps; v++)
        {
            x = x + Xinc*k;
            y = y + Yinc*k;
            timer1.start();
            point((int)(x+0.5),(int)(y+0.5),255, 245, 51);
            time2+=(timer1.nsecsElapsed()/1000);
            delay(30);

        }
    }
    int time;
    if (choice==0)
    time=timer.nsecsElapsed()-(steps*1e8);
    else
    {
        time=timer.nsecsElapsed()-(steps*3*1e7);
    }
    ui->label_24->setText(QString::number(time/1000)+"us");
    ui->label_18->setText(QString::number(time/1000-time2)+"us");
}

//This function draws a line between the two selected points using Bressenham algorithm
void MainWindow::on_bressenham_clicked()
{
    int k = ui->gridsize->value();
    QElapsedTimer timer,timer1;
    timer.start();
    int counter=0;
        //Store the two points
        int x1=p1.x();
        int y1=p1.y();

        int x2=p2.x();
        int y2=p2.y();

        int dx=x2-x1;
        int dy=y2-y1;

        x1=(x1/k)*k+k/2;
        y1=(y1/k)*k+k/2;

        x2=(x2/k)*k+k/2;
        y2=(y2/k)*k+k/2;

        int xinc=(dx>0)?k:-k;
        int yinc=(dy>0)?k:-k;

        dx=abs(dx);
        dy=abs(dy);
        int time2=0;
        //Case for gentle slope
        if(dx>dy)
        {
            int p=2*(dy)-dx;
            int y=y1;

            for(int x=x1; x!=x2; x+=xinc)
            {
                counter++;
                timer1.start();
                if(Color_flag)
                point(x,y,255, 245, 51);
                else
                point(x,y);
                time2+=(timer1.nsecsElapsed()/1000);
                delay();
                if(p>=0)
                {
                    y+=yinc;
                    p-=2*dx;
                }
                p+=2*dy;
            }
        }
        //Case for steep slope
        else
        {
            int p=2*(dx)-dy;
            int x=x1;

            for(int y=y1; y!=y2; y+=yinc)
            {
                counter++;
                timer1.start();
                if(Color_flag)
                point(x,y,255, 245, 51);
                else
                point(x,y);
                time2+=(timer1.nsecsElapsed()/1000);
                delay();
                if(p>=0)
                {
                    x+=xinc;
                    p-=2*(dy);
                }
                p+=2*(dx);
            }
        }
        int time=timer.nsecsElapsed()-(counter*1e8);
        ui->label_25->setText(QString::number(time/1000)+"us");
        ui->label_19->setText(QString::number(time/1000-time2)+"us");


}


//Circle drawing algorithm
void MainWindow::MidPoint_Draw(QPoint p1,int r)
{
    QElapsedTimer timer,timer1;
    timer.start();
    int gridsize=ui->gridsize->value();
    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;



    int x = r*gridsize;
    int y = 0;
    int p = (1 - r)*gridsize;
    int time2=0;
    while(x > y) {
        timer1.start();
        point(x0 - x, y0 - y,125,0,0);
        delay();
        point(x0 + x, y0 - y,123,5,0);
        delay();
        point(x0 - x, y0 + y,122,6,9);
        delay();
        point(x0 + x, y0 + y,123,6,98);
        delay();
        point(x0 - y, y0 - x,122,124,231);
        delay();
        point(x0 + y, y0 - x,124,45,97);
        delay();
        point(x0 - y, y0 + x,221,223,210);
        delay();
        point(x0 + y, y0 + x,210,230,122);
        delay();
        time2+=(timer1.nsecsElapsed()/1000);
        y += gridsize;
        if(p <= 0) {
            p += 2*y + 1;
        } else {
            p += 2*y + 1 - 2*x;
            x -= gridsize;
        }
    }

   int time=timer.nsecsElapsed()/1000;
   ui->label_17->setText(QString::number(time-time2)+"us");

}
void MainWindow::on_midpt_clicked()
{
     if(ui->draw_circle->isChecked()){

        int r = ui->circle_radius->value();
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        MidPoint_Draw(p1,r);

    }
}
void MainWindow::on_bress_circle_clicked()
{
    QElapsedTimer timer,timer1;

    if(ui->draw_circle->isChecked()){

            timer.start();
            int r = ui->circle_radius->value();
            p1.setX(ui->frame->x);
            p1.setY(ui->frame->y);

            int gridsize=ui->gridsize->value();
            int x0 = p1.x()/gridsize;
            int y0 = p1.y()/gridsize;
            x0 = x0*gridsize + gridsize/2;
            y0 = y0*gridsize + gridsize/2;

            //start=high_resolution_clock::now();
            int x = 0;
            int y = r*gridsize;
            int p = (3 - 2*r)*gridsize;

            int time2=0;
            while(y > x) {

                timer1.start();
                point(x0 - x, y0 - y,125,0,0);
                delay();
                point(x0 + x, y0 - y,123,5,0);
                delay();
                point(x0 - x, y0 + y,122,6,9);
                delay();
                point(x0 + x, y0 + y,123,6,98);
                delay();
                point(x0 - y, y0 - x,122,124,231);
                delay();
                point(x0 + y, y0 - x,124,45,97);
                delay();
                point(x0 - y, y0 + x,221,223,210);
                delay();
                point(x0 + y, y0 + x,210,230,122);
                delay();
                time2+=(timer1.nsecsElapsed()/1000);
                x += gridsize;
                if(p <= 0) {
                    p += 4*x + 6;
                } else {
                    p += 4*(x-y) + 10;
                    y -= gridsize;
                }
            }

            int time=timer.nsecsElapsed()/1000;
            ui->label_23->setText(QString::number(time-time2)+"us");
        }

}

//Ellipse Drawing algorithm
void MainWindow::on_ellipse_clicked()
{
    //Get the radius
    int rx=ui->ellipse_rx->value();
    int ry=ui->ellipse_ry->value();

    //Set the centre
    if(ui->draw_ellipse->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        drawEllipse(p1,rx,ry);
    }
}
//Midpoint Ellipse drawing Algorithm
void MainWindow::drawEllipse(QPoint p, int rx, int ry)
{
    //Function to draw the ellipse
    //Get the centre
    QElapsedTimer timer,timer1;
    timer.start();
    int x_centre=p.x();
    int y_centre=p.y();
    int k = ui->gridsize->value();//GridSize

    x_centre=(x_centre/k)*k+k/2;
    y_centre=(y_centre/k)*k+k/2;

    int x=0;
    int y=ry;

    int rx2=rx*rx;
    int ry2=ry*ry;
    int twotimesrx2=2*rx2;
    int twotimesry2=2*ry2;
    int px=0.0;
    int py=twotimesrx2*y;


    //For first region
    int p1=ry2-rx2*ry+(0.25)*rx2; //Initial value of decision parameter

    int time2=0;
    while(px<py)
    {

        timer1.start();
        point(x_centre+x*k,y_centre+y*k,122,123,234);
        delay();
        point(x_centre-x*k,y_centre+y*k,112,115,223);
        delay();
        point(x_centre-x*k,y_centre-y*k,156,243,235);
        delay();
        point(x_centre+x*k,y_centre-y*k,123,231,125);
        delay();
        time2+=timer1.nsecsElapsed()/1000;
        x++;
        px+=twotimesry2;

        if(p1>=0)
        {
            y--;
            py-=twotimesrx2;
            p1=p1+ry2+px-py;

        }
        else
        {
            p1=p1+ry2+px;
        }
    }

    //For second region
    p1=ry2*((double)x+0.5)*((double)x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2; //Initial value of decision paramemter


    while(y>=0)
    {
        timer1.start();
        point(x_centre+x*k,y_centre+y*k,123,234,456);
        delay();
        point(x_centre-x*k,y_centre+y*k,124,129,245);
        delay();
        point(x_centre-x*k,y_centre-y*k,125,123,234);
        delay();
        point(x_centre+x*k,y_centre-y*k,223,245,255);
        delay();
        time2+=timer1.nsecsElapsed()/1000;

        y--;
        py-=twotimesrx2;
        if(p1<=0)
        {
            x++;
            px+=twotimesry2;
            p1=p1+rx2-py+px;

        }
        else
        {
            p1=p1+rx2-py;
        }

    }
    int time=timer.nsecsElapsed()/1000;
    ui->label_13->setText(QString::number(time-time2)+"us");

}
void MainWindow::drawPolarEllipse(QPoint p1,int major,int minor)
{
    QElapsedTimer timer,timer1;
    timer.start();
    int gridsize=ui->gridsize->value();
    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    int x, y,time2=0;
    //taking the increment as 1/radius and incrementing from 0 to pi/4 radians
    for(float i=0; i<=3.14/2; i= i+ (1/(float)(major+minor)/2)) {
        x = round(major*cos(i))*gridsize;
        y = round(minor*sin(i))*gridsize;
        timer1.start();
        point(x0 + x, y0 + y,125,0,0);
        delay();
        point(x0 - x, y0 + y,123,5,0);
        delay();
        point(x0 + x, y0 - y,122,6,9);
        delay();
        point(x0 - x, y0 - y,123,6,98);
        delay();
        time2+=timer1.nsecsElapsed()/1000;

    }
    int time = timer.nsecsElapsed()/1000;
    ui->label_28->setText(QString::number(time-time2)+"us");
}

void MainWindow::on_PolarEllipse_clicked()
{
        //Get the radius
        int rx=ui->ellipse_rx->value();
        int ry=ui->ellipse_ry->value();

        //Set the centre
        if(ui->draw_ellipse->isChecked()){
            p1.setX(ui->frame->x);
            p1.setY(ui->frame->y);

            drawPolarEllipse(p1,rx,ry);
        }
}
//Cartesian Circle
void MainWindow::drawCartesian(QPoint p1,int radius)
{
    QElapsedTimer timer,timer1;
    timer.start();
    int gridsize=ui->gridsize->value();
    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;
    radius=radius*gridsize;

       int x=0, y=radius*gridsize,time2=0;
    //taking the increment as 1/radius and incrementing from 0 to pi/4 radians
       while(x<=y)
       {
           y=round(sqrt(radius*radius-x*x));
           timer1.start();
           point(x0 - x, y0 - y,125,0,0);
           delay();
           point(x0 + x, y0 - y,123,5,0);
           delay();
           point(x0 - x, y0 + y,122,6,9);
           delay();
           point(x0 + x, y0 + y,123,6,98);
           delay();
           point(x0 - y, y0 - x,122,124,231);
           delay();
           point(x0 + y, y0 - x,124,45,97);
           delay();
           point(x0 - y, y0 + x,221,223,210);
           delay();
           point(x0 + y, y0 + x,210,230,122);
           delay();
           time2+=timer1.nsecsElapsed()/1000;
           x+=gridsize;
       }


    int time = timer.nsecsElapsed()/1000;
    ui->label_26->setText(QString::number(time-time2)+"us");
}

void MainWindow::on_Cartesian_clicked()
{
    if(ui->draw_circle->isChecked()){
       int r = ui->circle_radius->value();
       p1.setX(ui->frame->x);
       p1.setY(ui->frame->y);
       drawCartesian(p1,r);
   }
}

//Polar Circle
void MainWindow::drawPolar(QPoint p1,int radius)
{
    QElapsedTimer timer,timer1;
    timer.start();
    int gridsize=ui->gridsize->value();
    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    int x, y,time2=0;
    //taking the increment as 1/radius and incrementing from 0 to pi/4 radians
    for(float i=0; i<=3.14/4; i= i+ (1/(float)radius)) {
        x = ceil(radius*cos(i))*gridsize;
        y = ceil(radius*sin(i))*gridsize;
        timer1.start();
        point(x0 - x, y0 - y,125,0,0);
        delay();
        point(x0 + x, y0 - y,123,5,0);
        delay();
        point(x0 - x, y0 + y,122,6,9);
        delay();
        point(x0 + x, y0 + y,123,6,98);
        delay();
        point(x0 - y, y0 - x,122,124,231);
        delay();
        point(x0 + y, y0 - x,124,45,97);
        delay();
        point(x0 - y, y0 + x,221,223,210);
        delay();
        point(x0 + y, y0 + x,210,230,122);
        delay();
        time2+=(timer1.nsecsElapsed()/1000);
    }
    int time = timer.nsecsElapsed()/1000;
    ui->label_20->setText(QString::number(time-time2)+"us");
}

void MainWindow::on_Polar_clicked()
{
    if(ui->draw_circle->isChecked()){
       int r = ui->circle_radius->value();
       p1.setX(ui->frame->x);
       p1.setY(ui->frame->y);
       drawPolar(p1,r);
   }
}
void MainWindow::floodfillFunc(int x, int y, int r, int g, int b) {

    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    if(img.pixel(x,y) == qRgb(r,g,b)) return;
    if(img.pixel(x,y)!= qRgb(0,0,0))return;
    point(x,y,r,g,b);
    delay();

    int gridsize=ui->gridsize->value();
    if(!ui->eight_conn->isChecked())
    {
        floodfillFunc(x - gridsize, y, r,g,b);
        floodfillFunc(x + gridsize, y, r,g,b);
        floodfillFunc(x, y - gridsize, r,g,b);
        floodfillFunc(x, y + gridsize, r,g,b);
    }
    else
    {
        floodfillFunc(x - gridsize, y, r,g,b);
        floodfillFunc(x - gridsize, y+gridsize, r,g,b);
        floodfillFunc(x, y + gridsize, r,g,b);
        floodfillFunc(x+gridsize, y + gridsize, r,g,b);
        floodfillFunc(x + gridsize, y, r,g,b);
        floodfillFunc(x + gridsize, y-gridsize, r,g,b);
        floodfillFunc(x, y - gridsize, r,g,b);
        floodfillFunc(x-gridsize, y -gridsize, r,g,b);
    }

}

void MainWindow::on_FloodFill_clicked()
{
    int gridsize=ui->gridsize->value();
    int x = p1.x()/gridsize;
    int y = p1.y()/gridsize;
    x = x*gridsize + gridsize/2;
    y = y*gridsize + gridsize/2;
    point(x,y,0,0,0);
    floodfillFunc(x,y,255,255,255);
}

void MainWindow::boundaryFillFunc(int x, int y, QRgb edgecolour, int r, int g, int b) {
    if(x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    if(img.pixel(x,y) == edgecolour || img.pixel(x,y) == qRgb(r,g,b)) return;
    point(x,y,r,g,b);
    delay();
    int gridsize=ui->gridsize->value();
    //used the four way recursion
    if(!ui->eight_conn->isChecked())
    {
        boundaryFillFunc(x - gridsize, y, edgecolour,r,g,b);
        boundaryFillFunc(x + gridsize, y, edgecolour,r,g,b);
        boundaryFillFunc(x, y - gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x, y + gridsize, edgecolour,r,g,b);
    }
    else
    {
        boundaryFillFunc(x - gridsize, y, edgecolour,r,g,b);
        boundaryFillFunc(x - gridsize, y+gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x, y+gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x + gridsize, y+gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x + gridsize, y, edgecolour,r,g,b);
        boundaryFillFunc(x + gridsize, y-gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x, y - gridsize, edgecolour,r,g,b);
        boundaryFillFunc(x-gridsize, y - gridsize, edgecolour,r,g,b);
    }

}

void MainWindow::on_BoundaryFill_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
    int gridsize=ui->gridsize->value();
    int x = p1.x()/gridsize;
    int y = p1.y()/gridsize;
    x = x*gridsize + gridsize/2;
    y = y*gridsize + gridsize/2;
    point(x,y,0,0,0);
    //calling the filling function (recursively it fills the whole frame)
    boundaryFillFunc(x,y,qRgb(0,255,255),255,147,51);

}
vector<QPoint> points;
//int current_count=0;
void MainWindow::on_AddVertex_clicked()
{
    on_set_point1_clicked();
    //points[current_count++]=p1;
    points.push_back(p1);
}
void MainWindow::bressn(QPoint pa, QPoint pb)
{

        int k = ui->gridsize->value();

        //Store the two points
        int x1=pa.x();
        int y1=pa.y();

        int x2=pb.x();
        int y2=pb.y();

        int dx=x2-x1;
        int dy=y2-y1;

        x1=(x1/k)*k+k/2;
        y1=(y1/k)*k+k/2;

        x2=(x2/k)*k+k/2;
        y2=(y2/k)*k+k/2;

        int xinc=(dx>0)?k:-k;
        int yinc=(dy>0)?k:-k;

        dx=abs(dx);
        dy=abs(dy);

        //Case for gentle slope
        if(dx>dy)
        {
            int p=2*(dy)-dx;
            int y=y1;

            for(int x=x1; x!=x2; x+=xinc)
            {
                point(x,y);
                if(p>=0)
                {
                    y+=yinc;
                    p-=2*dx;
                }
                p+=2*dy;
            }
        }
        //Case for steep slope
        else
        {
            int p=2*(dx)-dy;
            int x=x1;

            for(int y=y1; y!=y2; y+=yinc)
            {

                point(x,y);
                if(p>=0)
                {
                    x+=xinc;
                    p-=2*(dy);
                }
                p+=2*(dx);
            }
        }
}
void MainWindow::on_DrawPolygon_clicked()
{

   for(int i=0;i<points.size();i++)
   {
        QPoint pa=points[i];
        QPoint pb=points[(i+1)%points.size()];
        bressn(pa,pb);
   }

}


void MainWindow::on_CENTRE_ELLIPSE_clicked()
{
   on_set_point1_clicked();
}


void MainWindow::on_CENTRE_CIRCLE_clicked()
{
    on_set_point1_clicked();
}


void MainWindow::on_SEED_clicked()
{
    on_set_point1_clicked();
}

//Scanline Filling Algorithm

std::vector<std::pair<int,int> > vertex_list;
void MainWindow::on_setvertex_clicked()
{
    int gridsize=ui->gridsize->value();
    vertex_list.push_back(std::make_pair((ui->frame->x/gridsize)*gridsize+gridsize/2,(ui->frame->y/gridsize)*gridsize+gridsize/2));
    int i=vertex_list.size();
    if(i>=2)
    {
        storeEdgeInTable(vertex_list[i-2].first, vertex_list[i-2].second, vertex_list[i-1].first, vertex_list[i-1].second);//storage of edges in edge table.
        p1.setX(vertex_list[i-1].first);p1.setY(vertex_list[i-1].second);
        p2.setX(vertex_list[i-2].first);p2.setY(vertex_list[i-2].second);
        on_dda_clicked();
    }
}
void MainWindow::on_clearvertex_clicked()
{
    vertex_list.clear();
    points.clear();
    initEdgeTable();
}

// Scanline Filling
//defining an data type for edge
typedef struct Edge
{
    int max_y_coordinate;
    float x_value_of_y_min;
    float slopeinverse;
}Edge;

typedef struct Edge_Collection
{
    // the array will give the scanline number
    // The edge table (ET) with edges entries sorted
    // in increasing y and x of the lower end

    int countEdge;    //no. of Edges
    Edge buckets[maxVer];
}EdgeTableTuple;

EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple;
void MainWindow::initEdgeTable()
{
    int i;
    for (i=0; i<maxHt; i++)
    {
        EdgeTable[i].countEdge = 0;
    }

    ActiveEdgeTuple.countEdge = 0;
}
//sorting the edges as per the x-coordinate
void insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    Edge temp;

    for (i = 1; i < ett->countEdge; i++)
    {
        temp.max_y_coordinate = ett->buckets[i].max_y_coordinate;
        temp.x_value_of_y_min = ett->buckets[i].x_value_of_y_min;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

    while ((temp.x_value_of_y_min < ett->buckets[j].x_value_of_y_min) && (j >= 0))
    {
        ett->buckets[j + 1].max_y_coordinate = ett->buckets[j].max_y_coordinate;
        ett->buckets[j + 1].x_value_of_y_min = ett->buckets[j].x_value_of_y_min;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
        ett->buckets[j + 1].max_y_coordinate = temp.max_y_coordinate;
        ett->buckets[j + 1].x_value_of_y_min = temp.x_value_of_y_min;
        ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}

void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    (receiver->buckets[(receiver)->countEdge]).max_y_coordinate = ym;
    (receiver->buckets[(receiver)->countEdge]).x_value_of_y_min = (float)xm;
    (receiver->buckets[(receiver)->countEdge]).slopeinverse = slopInv;

    insertionSort(receiver);
    (receiver->countEdge)++;
}

void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int max_y_coordinateTS,xwithyminTS, scanline;

    if (x2==x1)
    {
        minv=0.000000;
    }
    else
    {
    m = ((float)(y2-y1))/((float)(x2-x1));

    if (y2==y1)
        return;

    minv = (float)1.0/m;
    }

    if (y1>y2)
    {
        scanline=y2;
        max_y_coordinateTS=y1;
        xwithyminTS=x2;
    }
    else
    {
        scanline=y1;
        max_y_coordinateTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],max_y_coordinateTS,xwithyminTS,minv);
}

void removeEdgeBymax_y_coordinate(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->countEdge; i++)
    {
        if (Tup->buckets[i].max_y_coordinate == yy)
        {
            for ( j = i ; j < Tup->countEdge -1 ; j++ )
                {
                Tup->buckets[j].max_y_coordinate =Tup->buckets[j+1].max_y_coordinate;
                Tup->buckets[j].x_value_of_y_min =Tup->buckets[j+1].x_value_of_y_min;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->countEdge--;
            i--;
        }
    }
}

void updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;

    for (i=0; i<Tup->countEdge; i++)
    {
        (Tup->buckets[i]).x_value_of_y_min =(Tup->buckets[i]).x_value_of_y_min + (Tup->buckets[i]).slopeinverse;
    }
}

void MainWindow::on_scanlinefill_clicked()
{
    int i, j, x1, max_y_coordinate1, x2, max_y_coordinate2, FillFlag = 0, coordCount;

    for (i=0; i<maxHt; i++)
    {
        for (j=0; j<EdgeTable[i].countEdge; j++)
        {
            storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].
                     max_y_coordinate,EdgeTable[i].buckets[j].x_value_of_y_min,
                    EdgeTable[i].buckets[j].slopeinverse);
        }

        removeEdgeBymax_y_coordinate(&ActiveEdgeTuple, i);

        insertionSort(&ActiveEdgeTuple);

        j = 0;
        FillFlag = 0;
        coordCount = 0;
        x1 = 0;
        x2 = 0;
        max_y_coordinate1 = 0;
        max_y_coordinate2 = 0;
        while (j<ActiveEdgeTuple.countEdge)
        {
            if (coordCount%2==0)
            {
                x1 = (int)(ActiveEdgeTuple.buckets[j].x_value_of_y_min);
                max_y_coordinate1 = ActiveEdgeTuple.buckets[j].max_y_coordinate;
                if (x1==x2)
                {
                    if (((x1==max_y_coordinate1)&&(x2!=max_y_coordinate2))||((x1!=max_y_coordinate1)&&(x2==max_y_coordinate2)))
                    {
                        x2 = x1;
                        max_y_coordinate2 = max_y_coordinate1;
                    }

                    else
                    {
                        coordCount++;
                    }
                }

                else
                {
                        coordCount++;
                }
            }
            else
            {
                x2 = (int)ActiveEdgeTuple.buckets[j].x_value_of_y_min;
                max_y_coordinate2 = ActiveEdgeTuple.buckets[j].max_y_coordinate;

                FillFlag = 0;
                if (x1==x2)
                {
                    if (((x1==max_y_coordinate1)&&(x2!=max_y_coordinate2))||((x1!=max_y_coordinate1)&&(x2==max_y_coordinate2)))
                    {
                        x1 = x2;
                        max_y_coordinate1 = max_y_coordinate2;
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }
                }
                else
                {
                    coordCount++;
                    FillFlag = 1;
                }

            if(FillFlag)
            {
                    p1.setX(x1);p1.setY(i);
                    p2.setX(x2);p2.setY(i);
                    on_dda_clicked(1);
            }

        }

        j++;
    }
    updatexbyslopeinv(&ActiveEdgeTuple);
}

    vertex_list.clear();
    initEdgeTable();
}

//Transformations
void MainWindow::poly_draw(std::vector<std::pair<int,int> > vlist, int r, int g, int b) {
    for(int i=0;i<vlist.size()-1;i++)
    {
        p1.setX(vlist[i].first); p1.setY(vlist[i].second);
        p2.setX(vlist[i+1].first); p2.setY(vlist[i+1].second);
        on_dda_clicked(1);
    }
}
void matrix_multiply(double a[3][3], int b[3], double res[3]){
    int i,j;
    for(i=0;i<3;i++){
        res[i]=0;
        for(j=0;j<3;j++)
            res[i]+=(a[i][j]*b[j]);
    }
}
void MainWindow::on_translation_clicked(int flag,int x,int y)
{
    int tx = ui->xtranslate->value();
    int ty = ui->ytranslate->value();
    if(flag==0)
    {
        tx=x,ty=y;
    }
    int k = ui->gridsize->value();

    std::vector<std::pair<int,int> > old_vertex = vertex_list;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    tx*=k;
    ty*=k;
    ty=-ty;
    int i,len=vertex_list.size();

    // matrix for translation
    double mat[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};

    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first;
        coord[1]=vertex_list[i].second;
        coord[2]=1;
        matrix_multiply(mat,coord,res);
        vertex_list[i].first= res[0]/res[2];
        vertex_list[i].second= res[1]/res[2];
    }
    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,255,255,0);
}
void MainWindow::on_scaling_clicked()
{
    int sx = ui->xscale->value();
    int sy = ui->yscale->value();
    int gridsize = ui->gridsize->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

//    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    piv_x=((ui->frame->width()/2)/gridsize)*gridsize+gridsize/2;
    //piv_x=ui->frame->width()/2;

    cout<<piv_x<<"\n";

    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;
    piv_y=((ui->frame->height()/2)/gridsize)*gridsize+gridsize/2;
    //piv_y=ui->frame->height()/2;

    cout<<piv_y<<"\n";
    int i,len=vertex_list.size();

    // matrix for scaling
    double mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;

        matrix_multiply(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];


    }

    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,255,255,0);
}
void MainWindow::on_rotation_clicked()
{
    int angle = ui->angle->value();
    int gridsize = ui->gridsize->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    double dang=(double)angle*M_PI/180.0;
    double sinang=sin(dang);
    double cosang=cos(dang);

    //Point about which to be rotated
//    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
//    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    piv_x=((ui->frame->width()/2)/gridsize)*gridsize+gridsize/2;
    //piv_x=ui->frame->width()/2;

    cout<<piv_x<<"\n";

    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;
    piv_y=((ui->frame->height()/2)/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for rotation
    double mat[3][3]={{cosang,-sinang,0},{sinang,cosang,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        matrix_multiply(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];
    }

    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,255,255,0);
}
void MainWindow::on_shearing_clicked()
{
    int shx = ui->xshear->value();
    int shy = ui->yshear->value();
    int gridsize = ui->gridsize->value();

    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for shearing
    double mat[3][3]={{1,shx,0},{shy,1,0},{0,0,1}};
    int coord[3];
    double res[3];
    for(i=0;i<len;i++)
    {
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        matrix_multiply(mat,coord,res);
        vertex_list[i].first=res[0]/res[2]+piv_x;
        vertex_list[i].second=piv_y-res[1]/res[2];
    }
    poly_draw(old_vertex,0,0,0);
    poly_draw(vertex_list,255,255,0);
}
void MainWindow::on_reflection_clicked()
{
    if(ui->aboutEdge->isChecked())
        on_reflection1_clicked();
    else
        on_reflection2_clicked();
}
void MainWindow::on_reflection1_clicked()
{
    int i,len=vertex_list.size();
    int value=ui->EdgeNum->value();

    double dx=vertex_list[value].first-vertex_list[value-1].first;
    double dy=vertex_list[value].second-vertex_list[value-1].second;


//    double dx=p1.x()-p2.x();
//    double dy=p1.y()-p2.y();

    double a=-dy;
    double b=dx;
//    double c=p1.x()*dy-p1.y()*dx;
    double c=vertex_list[value].first*dy-vertex_list[value].second*dx;


    for(i=0;i<len;i++)
    {
        int x1=vertex_list[i].first;
        int y1=vertex_list[i].second;

        vertex_list[i].first=(int)((double)x1-(double)(2*a*(a*x1+b*y1+c))/(double)((a*a+b*b)));
        vertex_list[i].second=(int)((double)y1-(double)(2*b*(a*x1+b*y1+c))/(double)((a*a+b*b)));
    }
    poly_draw(vertex_list,255,255,255);
}
void MainWindow::on_about_a_point_clicked()
{
    int size = ui->gridsize->value();
    int x =p1.x();
    int y =p1.y();
    if(x >= (img.width()/(2*size))*size  && x <= ((img.width()/(2*size))*size  + size)){
         x = 0;
    }
    else if(x >= img.width()/2)
     x = (x - (img.width()/(2*size))*size - size)/size + 1 ;
    else{
         x = -(((img.width()/(2*size))*size  - x)/size + 1) ;
    }
    if(y >= (img.height()/(2*size))*size && y <= ((img.height()/(2*size))*size + size)  )
        y = 0;
    else if(y >= img.height()/2)
     y = -((y - (img.height()/(2*size))*size - size)/size + 1);
    else{
        y = ((img.height()/(2*size))*size - y)/size + 1;
    }
    on_translation_clicked(0,-x,-y);
    on_rotation_clicked();
    on_translation_clicked(0,x,y);

}

 void MainWindow::on_reflection2_clicked()
{
    if (ui->aboutEdge->isChecked() == false) {
        int rx, ry;
        if (ui->reflectxaxis->isChecked()) {
            rx = 1, ry = -1;
        } else if (ui->reflectyaxis->isChecked()) {
            rx = -1, ry = 1;
        } else if (ui->reflectorigin->isChecked()) {
            rx = -1, ry = -1;
        } else {
            return;
        }
        vector<pair<int,int>> old_vertex = vertex_list;
        int gridsize=ui->gridsize->value();
//        rx*=k;
//        ry*=k;
        int i,len=vertex_list.size();
        // matrix for reflection
        double mat[3][3]={{rx*1.0,0,0},{0,ry*1.0,0},{0,0,1}};

        //Point about which to be reflected
        int piv_x=((ui->frame->width()/2)/gridsize)*gridsize+gridsize/2;
        int piv_y=((ui->frame->height()/2)/gridsize)*gridsize+gridsize/2;

        int coord[3];
        double res[3];
        for(i=0;i<len;i++)
        {
            coord[0]=vertex_list[i].first-piv_x;
            coord[1]=piv_y-vertex_list[i].second;
            coord[2]=1;
            matrix_multiply(mat,coord,res);
            vertex_list[i].first=res[0]/res[2]+piv_x;
            vertex_list[i].second=piv_y-res[1]/res[2];
        }
        poly_draw(old_vertex,0,0,0);
        poly_draw(vertex_list,255,255,0);
        return;
    }
    int i,len=vertex_list.size();

    double dx=p1.x()-p2.x();
    double dy=p1.y()-p2.y();

    double a=-dy;
    double b=dx;
    double c=p1.x()*dy-p1.y()*dx;

    for(i=0;i<len;i++)
    {
        int x1=vertex_list[i].first;
        int y1=vertex_list[i].second;

        vertex_list[i].first=(int)((double)x1-(double)(2*a*(a*x1+b*y1+c))/(double)((a*a+b*b)));
        vertex_list[i].second=(int)((double)y1-(double)(2*b*(a*x1+b*y1+c))/(double)((a*a+b*b)));
    }
    poly_draw(vertex_list,255,255,255);
}


void MainWindow::on_set_point_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

}
//LINE CLIPPING
void MainWindow::on_BoundaryMake_clicked()
{
    int k=ui->gridsize->value();
    x_max=ui->x_max->value();
    x_min=ui->x_min->value();
    y_max=ui->y_max->value();
    y_min=ui->y_min->value();

    x_max*=k;
    x_max+=img.width()/2;

    x_min*=k;
    x_min+=img.width()/2;

    y_max*=k;
    y_max=img.height()/2-y_max;

    y_min*=k;
    y_min=img.height()/2-y_min;


    drawBound();
}

void MainWindow::drawBound()
{


    // Draw the boundary

    p1.setX(x_min);
    p2.setX(x_min);

    p1.setY(y_max);
    p2.setY(y_min);

    on_bressenham_clicked();

    //===========
    p1.setX(x_min);
    p2.setX(x_max);

    p1.setY(y_min);
    p2.setY(y_min);

    on_bressenham_clicked();

    //================
    p1.setX(x_max);
    p2.setX(x_max);

    p1.setY(y_min);
    p2.setY(y_max);

    on_bressenham_clicked();

    //=================
    p1.setX(x_max);
    p2.setX(x_min);

    p1.setY(y_max);
    p2.setY(y_max);

    on_bressenham_clicked();
}




// =================== LINE CLIPPING ===========================
// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000


// Function to compute region code for a point(x, y)
int MainWindow::computeCode(int x, int y)
{
    // initialized as being inside
    int code = INSIDE;
    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y > y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y < y_max)  // above the rectangle
        code |= TOP;

    return code;
}
// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void MainWindow::cohenSutherlandClip(int x1, int y1,int x2, int y2)
{
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);    //Region code for P1
    int code2 = computeCode(x2, y2);    //Region code for P2


    // Initialize line as outside the rectangular window
    bool accept = false;
    bool flag=false;

    while (true)
    {

        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            flag=true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (int)((double)(x2 - x1) *(double)(y_max - y1) /(double)(y2 - y1));
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (int)((double)(x2 - x1) * (double)(y_min - y1) / (double)(y2 - y1));
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_max - x1) / (double)(x2 - x1));
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_min - x1) / (double)(x2 - x1));
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        //If accepted
        //Just reset and draw the boundary and the line
        //Reset the screen and draw the grid
        on_showgrid_clicked();
        on_show_axes_clicked();
        Color_flag=0;
        drawBound();
        Color_flag=1;


        p1.setX(x1);
        p1.setY(y1);

        p2.setX(x2);
        p2.setY(y2);

        on_bressenham_clicked();
        //on_dda_clicked(1);
        if(flag)point(x2,y2,255, 245, 51);
    }
    else
    {

        //Reset the screen and draw the grid
        on_showgrid_clicked();
        on_show_axes_clicked();
        Color_flag=0;
        drawBound();
        Color_flag=1;


    }

}

void MainWindow::on_LineClip_clicked()
{
    Color_flag=1;
    cohenSutherlandClip(p1.x(),p1.y(),p2.x(),p2.y());
}

//Polygon Clipping
int MainWindow::x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (x3-x4) -(x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int retx=num/den;
    return retx;
}

// Returns y-value of point of intersection of
// two lines
int MainWindow::y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (y3-y4) -(y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int rety= (ui->frame->height()-num/den+1);
    return rety;
}

// This functions clips all the edges w.r.t one clip
// edge of clipping area
void MainWindow::clip(int x1, int y1, int x2, int y2)
{
    int poly_size=vertex_list.size()-1;
    int new_poly_size = 0;

    std::vector<std::pair<int,int> > new_points;

    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = vertex_list[i].first, iy = vertex_list[i].second;
        int kx = vertex_list[k].first, ky = vertex_list[k].second;

        // Calculating position of first and second point

        int i_pos,k_pos;
        if(x2==x1 && ix>x1) i_pos=1;
        else if(x2==x1 && ix<x1) i_pos=-1;
        else if(y2==y1 && iy<y1) i_pos=1;
        else i_pos=-1;

        if(x2==x1 && kx>x1) k_pos=1;
        else if(x2==x1 && kx<x1) k_pos=-1;
        else if(y2==y1 && ky<y1) k_pos=1;
        else k_pos=-1;

        if(y1>y2||x1>x2)
        {
            i_pos=(-1)*i_pos;
            k_pos=(-1)*k_pos;
        }

        // Case 1 : When both points are inside
        if (i_pos >= 0  && k_pos >= 0)
        {
            //Only second point is added
            //            new_points[new_poly_size][0] = kx;
            //            new_points[new_poly_size][1] = ky;
            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 2: When only first point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            // Point of intersection with edge
            // and the second point is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;

            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 3: When only second point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            //Only point of intersection with edge is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;
        }

        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }

    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    vertex_list.clear();
    for (int i = 0; i < new_points.size(); i++)
    {
        vertex_list.push_back(new_points[i]);
    }
    if(poly_size>0)
        vertex_list.push_back(new_points[0]);

}

// Implements Sutherland–Hodgman algorithm
void MainWindow::sutherlandHodgemanClip()
{
    //i and k are two consecutive indexes
    clip(x_min,y_max,x_min,y_min); //Left
    if(vertex_list.size()>0)
        clip(x_min,y_min,x_max,y_min); //Bottom
    if(vertex_list.size()>1)
        clip(x_max,y_min,x_max,y_max); //Right
    if(vertex_list.size()>1)
        clip(x_max,y_max,x_min,y_max); //Top

    on_showgrid_clicked();
    on_show_axes_clicked();
    drawBound();

    if(vertex_list.size()>1)
        poly_draw(vertex_list,255,255,0);

}

void MainWindow::on_ClipPolygon_clicked()
{
    sutherlandHodgemanClip();
}

//Liang-Berskey Line clipping

#define ROUND(a) ((int)(a+0.5))
int clipTest (float p,float q, float * t1, float * t2)
{
float r ;
int retVal = TRUE;

//line entry point
if (p < 0.0) {

    r = q /p ;

    // line portion is outside the clipping edge
    if ( r > *t2 )
    retVal = FALSE;

    else
    if (r > *t1 )
    *t1 = r;
}

else

//line leaving point
if (p>0.0) {
    r = q/p ;

    // line portion is outside
    if ( r<*t1 )
        retVal = FALSE;

    else if (r<*t2)
        *t2 = r;
}

// p = 0, so line is parallel to this clipping edge
else

// Line is outside clipping edge
if (q<0.0)
retVal = FALSE;

return ( retVal ) ;
}

typedef struct dcPt
{
  float x,y;
}dcPt;

dcPt winMin,winMax;
void MainWindow::on_vertex1_clicked()
{
    winMin.x=p1.x();
    winMin.y=p1.y();

}
void MainWindow::on_vertex2_clicked()
{

    winMax.x=p1.x();
    winMax.y=p1.y();
}
void MainWindow::on_clipLine_clicked()
{


int k=ui->gridsize->value();
float t1 = 0.0, t2 = 1.0, dx = p2.x()-p1.x(), dy;

// inside test wrt left edge
if(clipTest (-dx, p1.x() - winMin.x, &t1, &t2))

// inside test wrt right edge
if(clipTest (dx, winMax.x - p1.x(), &t1, &t2))

{
    dy = p2.y() - p1.y();

    // inside test wrt bottom edge
    if(clipTest (-dy, p1.y() - winMin.y, &t1, &t2))

        // inside test wrt top edge
        if(clipTest (dy, winMax.y - p1.y(), &t1, &t2)) {

        if(t2 < 1.0) {
            p2.setX(p1.x() + t2*dx);
            //p2.x() = p1.x() + t2*dx;
            //p2.y() = p1.y() + t2*dy;
            p2.setY(p1.y() + t2*dy);
        }

        if(t1 > 0.0) {
            p1.setX(p1.x() + t1*dx);
            //p1.x() += t1*dx;
            p1.setY(p1.y() + t1*dy);
            //p1.y() += t1*dy;
        }

        on_showgrid_clicked();
        on_show_axes_clicked();
        drawBound();

        p1.setX(ROUND(p1.x()));
        p1.setY(ROUND(p1.y()));

        p2.setX(ROUND(p2.x()));
        p2.setY(ROUND(p2.y()));

        //on_bressenham_clicked();
        on_dda_clicked();
        cout<<"hello saurabh\n";
        //lineDDA ( ROUND(p1.x), ROUND(p1.y), ROUND(p2.x), ROUND(p2.y) );

        }
    }

}

