/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *Draw;
    QRadioButton *draw_line;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *resetButton;
    QSpinBox *gridsize;
    QLabel *label;
    QPushButton *showgrid;
    QLabel *label_2;
    QPushButton *dda;
    QPushButton *bressenham;
    QSpinBox *circle_radius;
    QLabel *label_4;
    QPushButton *midpt;
    QPushButton *bress_circle;
    QRadioButton *draw_circle;
    QRadioButton *draw_ellipse;
    QPushButton *ellipse;
    QLabel *label_6;
    QSpinBox *ellipse_rx;
    QLabel *label_7;
    QSpinBox *ellipse_ry;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_8;
    QFrame *line_5;
    QLabel *label_9;
    QPushButton *Polar;
    QLabel *label_10;
    QPushButton *FloodFill;
    QPushButton *BoundaryFill;
    QPushButton *PolarEllipse;
    QPushButton *Cartesian;
    QPushButton *AddVertex;
    QPushButton *DrawPolygon;
    QFrame *line_4;
    QLabel *label_12;
    QPushButton *scanlinefill;
    QRadioButton *fourConn;
    QRadioButton *eight_conn;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line;
    QFrame *line_10;
    QFrame *line_11;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_16;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_21;
    QFrame *line_16;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_25;
    QFrame *line_17;
    QFrame *line_6;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_21;
    QLabel *label_27;
    QFrame *line_22;
    QLabel *label_13;
    QLabel *label_28;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_23;
    QLabel *label_26;
    QFrame *line_15;
    QRadioButton *POLYGON;
    QPushButton *CENTRE_ELLIPSE;
    QPushButton *CENTRE_CIRCLE;
    QPushButton *SEED;
    QPushButton *setvertex;
    QPushButton *clearvertex;
    QFrame *line_20;
    QLabel *label_11;
    QLabel *label_29;
    QFrame *line_23;
    QLabel *label_30;
    QSpinBox *xtranslate;
    QSpinBox *ytranslate;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *translation;
    QFrame *line_24;
    QSpinBox *xscale;
    QSpinBox *yscale;
    QPushButton *scaling;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QSpinBox *angle;
    QPushButton *rotation;
    QSpinBox *xshear;
    QSpinBox *yshear;
    QLabel *label_36;
    QLabel *label_37;
    QPushButton *shearing;
    QPushButton *reflection;
    QSpinBox *EdgeNum;
    QLabel *label_38;
    QPushButton *about_a_point;
    QPushButton *set_point;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1384, 682);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QString::fromUtf8("mouse_movement"));
        mouse_movement->setGeometry(QRect(710, 70, 91, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 50, 101, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QString::fromUtf8("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(810, 70, 81, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(810, 50, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(0, 0, 700, 1));
        x_axis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QString::fromUtf8("show_axes"));
        show_axes->setGeometry(QRect(710, 20, 91, 21));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QString::fromUtf8("Draw"));
        Draw->setGeometry(QRect(930, 90, 101, 31));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QString::fromUtf8("draw_line"));
        draw_line->setGeometry(QRect(940, 140, 77, 17));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QString::fromUtf8("set_point1"));
        set_point1->setGeometry(QRect(900, 50, 81, 31));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QString::fromUtf8("set_point2"));
        set_point2->setGeometry(QRect(990, 50, 71, 31));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(950, 580, 91, 31));
        resetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 255);\n"
"color: rgb(0, 0, 0);"));
        gridsize = new QSpinBox(centralWidget);
        gridsize->setObjectName(QString::fromUtf8("gridsize"));
        gridsize->setGeometry(QRect(870, 20, 61, 21));
        gridsize->setMinimum(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 20, 51, 16));
        showgrid = new QPushButton(centralWidget);
        showgrid->setObjectName(QString::fromUtf8("showgrid"));
        showgrid->setGeometry(QRect(960, 20, 81, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 130, 81, 31));
        dda = new QPushButton(centralWidget);
        dda->setObjectName(QString::fromUtf8("dda"));
        dda->setGeometry(QRect(710, 180, 91, 31));
        dda->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        bressenham = new QPushButton(centralWidget);
        bressenham->setObjectName(QString::fromUtf8("bressenham"));
        bressenham->setGeometry(QRect(710, 220, 91, 31));
        bressenham->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QString::fromUtf8("circle_radius"));
        circle_radius->setGeometry(QRect(710, 310, 42, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(800, 260, 161, 31));
        midpt = new QPushButton(centralWidget);
        midpt->setObjectName(QString::fromUtf8("midpt"));
        midpt->setGeometry(QRect(790, 290, 61, 31));
        midpt->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 0, 255);\n"
""));
        bress_circle = new QPushButton(centralWidget);
        bress_circle->setObjectName(QString::fromUtf8("bress_circle"));
        bress_circle->setGeometry(QRect(940, 290, 91, 31));
        bress_circle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);\n"
"color: rgb(0, 0, 0);"));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QString::fromUtf8("draw_circle"));
        draw_circle->setGeometry(QRect(950, 270, 101, 16));
        draw_ellipse = new QRadioButton(centralWidget);
        draw_ellipse->setObjectName(QString::fromUtf8("draw_ellipse"));
        draw_ellipse->setGeometry(QRect(970, 370, 84, 19));
        ellipse = new QPushButton(centralWidget);
        ellipse->setObjectName(QString::fromUtf8("ellipse"));
        ellipse->setGeometry(QRect(850, 400, 71, 21));
        ellipse->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 0);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(780, 440, 21, 16));
        ellipse_rx = new QSpinBox(centralWidget);
        ellipse_rx->setObjectName(QString::fromUtf8("ellipse_rx"));
        ellipse_rx->setGeometry(QRect(730, 440, 42, 22));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(710, 440, 21, 20));
        ellipse_ry = new QSpinBox(centralWidget);
        ellipse_ry->setObjectName(QString::fromUtf8("ellipse_ry"));
        ellipse_ry->setGeometry(QRect(800, 440, 42, 22));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(700, 250, 421, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(700, 360, 411, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(710, 290, 41, 21));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(710, 490, 331, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(830, 0, 91, 21));
        Polar = new QPushButton(centralWidget);
        Polar->setObjectName(QString::fromUtf8("Polar"));
        Polar->setGeometry(QRect(860, 290, 71, 31));
        Polar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(850, 470, 71, 31));
        FloodFill = new QPushButton(centralWidget);
        FloodFill->setObjectName(QString::fromUtf8("FloodFill"));
        FloodFill->setGeometry(QRect(950, 520, 81, 31));
        FloodFill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 85, 255);"));
        BoundaryFill = new QPushButton(centralWidget);
        BoundaryFill->setObjectName(QString::fromUtf8("BoundaryFill"));
        BoundaryFill->setGeometry(QRect(860, 520, 81, 31));
        BoundaryFill->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(85, 85, 255);"));
        PolarEllipse = new QPushButton(centralWidget);
        PolarEllipse->setObjectName(QString::fromUtf8("PolarEllipse"));
        PolarEllipse->setGeometry(QRect(940, 400, 71, 21));
        PolarEllipse->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 0);"));
        Cartesian = new QPushButton(centralWidget);
        Cartesian->setObjectName(QString::fromUtf8("Cartesian"));
        Cartesian->setGeometry(QRect(1050, 290, 71, 31));
        Cartesian->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 255);\n"
"color: rgb(0, 0, 0);"));
        AddVertex = new QPushButton(centralWidget);
        AddVertex->setObjectName(QString::fromUtf8("AddVertex"));
        AddVertex->setGeometry(QRect(710, 560, 61, 22));
        AddVertex->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);\n"
"color: rgb(0, 0, 127);"));
        DrawPolygon = new QPushButton(centralWidget);
        DrawPolygon->setObjectName(QString::fromUtf8("DrawPolygon"));
        DrawPolygon->setGeometry(QRect(710, 530, 61, 21));
        DrawPolygon->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 127);\n"
"color: rgb(0, 0, 127);"));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(850, 500, 20, 131));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(950, 500, 141, 20));
        scanlinefill = new QPushButton(centralWidget);
        scanlinefill->setObjectName(QString::fromUtf8("scanlinefill"));
        scanlinefill->setGeometry(QRect(1040, 520, 81, 31));
        scanlinefill->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        fourConn = new QRadioButton(centralWidget);
        fourConn->setObjectName(QString::fromUtf8("fourConn"));
        fourConn->setGeometry(QRect(930, 470, 61, 21));
        eight_conn = new QRadioButton(centralWidget);
        eight_conn->setObjectName(QString::fromUtf8("eight_conn"));
        eight_conn->setGeometry(QRect(1020, 470, 85, 20));
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(710, 460, 331, 21));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(710, 620, 151, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(700, 10, 341, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(700, 150, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(700, 120, 411, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(centralWidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(800, 160, 20, 81));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(830, 160, 31, 20));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(820, 220, 81, 21));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(830, 180, 47, 14));
        line_12 = new QFrame(centralWidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(810, 170, 261, 16));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralWidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(910, 180, 20, 71));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(centralWidget);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(810, 210, 261, 16));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(926, 180, 81, 20));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(926, 220, 81, 20));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(930, 160, 71, 16));
        line_16 = new QFrame(centralWidget);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(1010, 180, 16, 61));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(1020, 160, 81, 16));
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(1040, 180, 81, 20));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(1040, 220, 81, 20));
        line_17 = new QFrame(centralWidget);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(700, 280, 341, 16));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(850, 300, 21, 61));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_18 = new QFrame(centralWidget);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(920, 290, 20, 71));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);
        line_19 = new QFrame(centralWidget);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setGeometry(QRect(1030, 290, 20, 71));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);
        line_21 = new QFrame(centralWidget);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setGeometry(QRect(700, 390, 411, 16));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(830, 370, 101, 16));
        line_22 = new QFrame(centralWidget);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setGeometry(QRect(915, 400, 31, 71));
        line_22->setFrameShape(QFrame::VLine);
        line_22->setFrameShadow(QFrame::Sunken);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(860, 430, 47, 14));
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(950, 430, 47, 14));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(800, 330, 71, 21));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(870, 330, 71, 21));
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(940, 330, 71, 21));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(1050, 330, 81, 21));
        line_15 = new QFrame(centralWidget);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(780, 290, 20, 71));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        POLYGON = new QRadioButton(centralWidget);
        POLYGON->setObjectName(QString::fromUtf8("POLYGON"));
        POLYGON->setGeometry(QRect(710, 470, 85, 20));
        CENTRE_ELLIPSE = new QPushButton(centralWidget);
        CENTRE_ELLIPSE->setObjectName(QString::fromUtf8("CENTRE_ELLIPSE"));
        CENTRE_ELLIPSE->setGeometry(QRect(730, 410, 101, 21));
        CENTRE_CIRCLE = new QPushButton(centralWidget);
        CENTRE_CIRCLE->setObjectName(QString::fromUtf8("CENTRE_CIRCLE"));
        CENTRE_CIRCLE->setGeometry(QRect(700, 340, 81, 21));
        SEED = new QPushButton(centralWidget);
        SEED->setObjectName(QString::fromUtf8("SEED"));
        SEED->setGeometry(QRect(740, 590, 71, 21));
        SEED->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);\n"
"background-color: rgb(0, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        setvertex = new QPushButton(centralWidget);
        setvertex->setObjectName(QString::fromUtf8("setvertex"));
        setvertex->setGeometry(QRect(780, 530, 71, 21));
        setvertex->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        clearvertex = new QPushButton(centralWidget);
        clearvertex->setObjectName(QString::fromUtf8("clearvertex"));
        clearvertex->setGeometry(QRect(780, 560, 71, 21));
        clearvertex->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
        line_20 = new QFrame(centralWidget);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setGeometry(QRect(710, 520, 141, 16));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(710, 500, 61, 21));
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(780, 500, 61, 16));
        line_23 = new QFrame(centralWidget);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setGeometry(QRect(1120, 0, 20, 561));
        line_23->setFrameShape(QFrame::VLine);
        line_23->setFrameShadow(QFrame::Sunken);
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(1140, 0, 141, 21));
        xtranslate = new QSpinBox(centralWidget);
        xtranslate->setObjectName(QString::fromUtf8("xtranslate"));
        xtranslate->setGeometry(QRect(1150, 50, 42, 22));
        ytranslate = new QSpinBox(centralWidget);
        ytranslate->setObjectName(QString::fromUtf8("ytranslate"));
        ytranslate->setGeometry(QRect(1200, 50, 42, 22));
        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(1150, 30, 51, 16));
        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(1200, 30, 51, 16));
        translation = new QPushButton(centralWidget);
        translation->setObjectName(QString::fromUtf8("translation"));
        translation->setGeometry(QRect(1150, 80, 71, 22));
        line_24 = new QFrame(centralWidget);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setGeometry(QRect(1130, 20, 251, 16));
        line_24->setFrameShape(QFrame::HLine);
        line_24->setFrameShadow(QFrame::Sunken);
        xscale = new QSpinBox(centralWidget);
        xscale->setObjectName(QString::fromUtf8("xscale"));
        xscale->setGeometry(QRect(1150, 130, 42, 22));
        yscale = new QSpinBox(centralWidget);
        yscale->setObjectName(QString::fromUtf8("yscale"));
        yscale->setGeometry(QRect(1200, 130, 42, 22));
        scaling = new QPushButton(centralWidget);
        scaling->setObjectName(QString::fromUtf8("scaling"));
        scaling->setGeometry(QRect(1150, 160, 80, 22));
        label_33 = new QLabel(centralWidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(1150, 110, 47, 14));
        label_34 = new QLabel(centralWidget);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(1200, 110, 47, 14));
        label_35 = new QLabel(centralWidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(1150, 190, 91, 16));
        angle = new QSpinBox(centralWidget);
        angle->setObjectName(QString::fromUtf8("angle"));
        angle->setGeometry(QRect(1150, 210, 41, 22));
        rotation = new QPushButton(centralWidget);
        rotation->setObjectName(QString::fromUtf8("rotation"));
        rotation->setGeometry(QRect(1200, 210, 80, 22));
        xshear = new QSpinBox(centralWidget);
        xshear->setObjectName(QString::fromUtf8("xshear"));
        xshear->setGeometry(QRect(1150, 290, 42, 22));
        yshear = new QSpinBox(centralWidget);
        yshear->setObjectName(QString::fromUtf8("yshear"));
        yshear->setGeometry(QRect(1210, 290, 42, 22));
        label_36 = new QLabel(centralWidget);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(1150, 270, 47, 14));
        label_37 = new QLabel(centralWidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(1210, 270, 47, 14));
        shearing = new QPushButton(centralWidget);
        shearing->setObjectName(QString::fromUtf8("shearing"));
        shearing->setGeometry(QRect(1150, 320, 80, 22));
        reflection = new QPushButton(centralWidget);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        reflection->setGeometry(QRect(1150, 350, 80, 22));
        EdgeNum = new QSpinBox(centralWidget);
        EdgeNum->setObjectName(QString::fromUtf8("EdgeNum"));
        EdgeNum->setGeometry(QRect(1150, 380, 42, 22));
        label_38 = new QLabel(centralWidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(1200, 380, 61, 16));
        about_a_point = new QPushButton(centralWidget);
        about_a_point->setObjectName(QString::fromUtf8("about_a_point"));
        about_a_point->setGeometry(QRect(1200, 240, 71, 21));
        set_point = new QPushButton(centralWidget);
        set_point->setObjectName(QString::fromUtf8("set_point"));
        set_point->setGeometry(QRect(1130, 240, 61, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1384, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "    Mouse Movement", nullptr));
        mouse_pressed->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mouse Pressed", nullptr));
        show_axes->setText(QCoreApplication::translate("MainWindow", "Show Axes", nullptr));
        Draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        draw_line->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        set_point1->setText(QCoreApplication::translate("MainWindow", "Set point 1", nullptr));
        set_point2->setText(QCoreApplication::translate("MainWindow", "Set point 2", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Grid Size", nullptr));
        showgrid->setText(QCoreApplication::translate("MainWindow", "Show Grid", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "LINE DRAWING", nullptr));
        dda->setText(QCoreApplication::translate("MainWindow", "DDA", nullptr));
        bressenham->setText(QCoreApplication::translate("MainWindow", "BRESSENHAM", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Circle Drawing Algorithm", nullptr));
        midpt->setText(QCoreApplication::translate("MainWindow", "MIDPOINT", nullptr));
        bress_circle->setText(QCoreApplication::translate("MainWindow", "BRESSENHAM", nullptr));
        draw_circle->setText(QCoreApplication::translate("MainWindow", "DrawCircle", nullptr));
        draw_ellipse->setText(QCoreApplication::translate("MainWindow", "Draw Ellipse", nullptr));
        ellipse->setText(QCoreApplication::translate("MainWindow", "MIDPOINT", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "R1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "R2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Radius", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "BASIC UTILITIES", nullptr));
        Polar->setText(QCoreApplication::translate("MainWindow", "POLAR", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "FILLING", nullptr));
        FloodFill->setText(QCoreApplication::translate("MainWindow", "FloodFill", nullptr));
        BoundaryFill->setText(QCoreApplication::translate("MainWindow", "BoundaryFill", nullptr));
        PolarEllipse->setText(QCoreApplication::translate("MainWindow", "POLAR ", nullptr));
        Cartesian->setText(QCoreApplication::translate("MainWindow", "Cartesian", nullptr));
        AddVertex->setText(QCoreApplication::translate("MainWindow", "Add_Ver", nullptr));
        DrawPolygon->setText(QCoreApplication::translate("MainWindow", "DrawPoly", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ALGORITHMS", nullptr));
        scanlinefill->setText(QCoreApplication::translate("MainWindow", "SCANLINE FILL", nullptr));
        fourConn->setText(QCoreApplication::translate("MainWindow", "4 conn", nullptr));
        eight_conn->setText(QCoreApplication::translate("MainWindow", "8 conn", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ALGO", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "BRESSENHAM", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "DDA", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "0 ms", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "0 ms", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "POINT_EX", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "POINT_INC", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "0 ms", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "0 ms", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "ELLIPSE DRAWING", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "0 us", nullptr));
        POLYGON->setText(QCoreApplication::translate("MainWindow", "POLYGON", nullptr));
        CENTRE_ELLIPSE->setText(QCoreApplication::translate("MainWindow", "SET CENTRE", nullptr));
        CENTRE_CIRCLE->setText(QCoreApplication::translate("MainWindow", "SET_CENTRE", nullptr));
        SEED->setText(QCoreApplication::translate("MainWindow", "SET_SEED", nullptr));
        setvertex->setText(QCoreApplication::translate("MainWindow", "Set Vertex", nullptr));
        clearvertex->setText(QCoreApplication::translate("MainWindow", "Clear Vertex", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ver_Wise", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Edge_Wise", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Transformations", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "X-Trans", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Y-Trans", nullptr));
        translation->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        scaling->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "X-Scale", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Y-Scale", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Angle(in Degrees)", nullptr));
        rotation->setText(QCoreApplication::translate("MainWindow", "About Origin", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "X-Shear", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Y-Shear", nullptr));
        shearing->setText(QCoreApplication::translate("MainWindow", "Shear", nullptr));
        reflection->setText(QCoreApplication::translate("MainWindow", "Reflect", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "About Edge", nullptr));
        about_a_point->setText(QCoreApplication::translate("MainWindow", "AboutPoint", nullptr));
        set_point->setText(QCoreApplication::translate("MainWindow", "setPoint", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H