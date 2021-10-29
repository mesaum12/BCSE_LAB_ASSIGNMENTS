/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[140];
    char stringdata0[978];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "Mouse_Pressed"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 17), // "showMousePosition"
QT_MOC_LITERAL(44, 7), // "QPoint&"
QT_MOC_LITERAL(52, 3), // "pos"
QT_MOC_LITERAL(56, 20), // "on_show_axes_clicked"
QT_MOC_LITERAL(77, 15), // "on_Draw_clicked"
QT_MOC_LITERAL(93, 21), // "on_set_point1_clicked"
QT_MOC_LITERAL(115, 21), // "on_set_point2_clicked"
QT_MOC_LITERAL(137, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(160, 19), // "on_showgrid_clicked"
QT_MOC_LITERAL(180, 14), // "on_dda_clicked"
QT_MOC_LITERAL(195, 6), // "choice"
QT_MOC_LITERAL(202, 21), // "on_bressenham_clicked"
QT_MOC_LITERAL(224, 16), // "on_midpt_clicked"
QT_MOC_LITERAL(241, 23), // "on_bress_circle_clicked"
QT_MOC_LITERAL(265, 18), // "on_ellipse_clicked"
QT_MOC_LITERAL(284, 11), // "drawEllipse"
QT_MOC_LITERAL(296, 2), // "p1"
QT_MOC_LITERAL(299, 2), // "rx"
QT_MOC_LITERAL(302, 2), // "ry"
QT_MOC_LITERAL(305, 13), // "MidPoint_Draw"
QT_MOC_LITERAL(319, 1), // "r"
QT_MOC_LITERAL(321, 9), // "drawPolar"
QT_MOC_LITERAL(331, 16), // "on_Polar_clicked"
QT_MOC_LITERAL(348, 13), // "floodfillFunc"
QT_MOC_LITERAL(362, 1), // "x"
QT_MOC_LITERAL(364, 1), // "y"
QT_MOC_LITERAL(366, 1), // "g"
QT_MOC_LITERAL(368, 1), // "b"
QT_MOC_LITERAL(370, 20), // "on_FloodFill_clicked"
QT_MOC_LITERAL(391, 23), // "on_PolarEllipse_clicked"
QT_MOC_LITERAL(415, 16), // "drawPolarEllipse"
QT_MOC_LITERAL(432, 5), // "major"
QT_MOC_LITERAL(438, 5), // "minor"
QT_MOC_LITERAL(444, 16), // "boundaryFillFunc"
QT_MOC_LITERAL(461, 4), // "QRgb"
QT_MOC_LITERAL(466, 10), // "edgecolour"
QT_MOC_LITERAL(477, 20), // "on_Cartesian_clicked"
QT_MOC_LITERAL(498, 13), // "drawCartesian"
QT_MOC_LITERAL(512, 6), // "radius"
QT_MOC_LITERAL(519, 23), // "on_BoundaryFill_clicked"
QT_MOC_LITERAL(543, 20), // "on_AddVertex_clicked"
QT_MOC_LITERAL(564, 22), // "on_DrawPolygon_clicked"
QT_MOC_LITERAL(587, 6), // "bressn"
QT_MOC_LITERAL(594, 2), // "p2"
QT_MOC_LITERAL(597, 25), // "on_CENTRE_ELLIPSE_clicked"
QT_MOC_LITERAL(623, 24), // "on_CENTRE_CIRCLE_clicked"
QT_MOC_LITERAL(648, 15), // "on_SEED_clicked"
QT_MOC_LITERAL(664, 20), // "on_setvertex_clicked"
QT_MOC_LITERAL(685, 22), // "on_clearvertex_clicked"
QT_MOC_LITERAL(708, 13), // "initEdgeTable"
QT_MOC_LITERAL(722, 16), // "storeEdgeInTable"
QT_MOC_LITERAL(739, 2), // "x1"
QT_MOC_LITERAL(742, 2), // "y1"
QT_MOC_LITERAL(745, 2), // "x2"
QT_MOC_LITERAL(748, 2), // "y2"
QT_MOC_LITERAL(751, 23), // "on_scanlinefill_clicked"
QT_MOC_LITERAL(775, 22), // "on_translation_clicked"
QT_MOC_LITERAL(798, 4), // "flag"
QT_MOC_LITERAL(803, 9), // "poly_draw"
QT_MOC_LITERAL(813, 31), // "std::vector<std::pair<int,int>>"
QT_MOC_LITERAL(845, 5), // "vlist"
QT_MOC_LITERAL(851, 18), // "on_scaling_clicked"
QT_MOC_LITERAL(870, 19), // "on_rotation_clicked"
QT_MOC_LITERAL(890, 19), // "on_shearing_clicked"
QT_MOC_LITERAL(910, 21), // "on_reflection_clicked"
QT_MOC_LITERAL(932, 24), // "on_about_a_point_clicked"
QT_MOC_LITERAL(957, 20) // "on_set_point_clicked"

    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0on_show_axes_clicked\0"
    "on_Draw_clicked\0on_set_point1_clicked\0"
    "on_set_point2_clicked\0on_resetButton_clicked\0"
    "on_showgrid_clicked\0on_dda_clicked\0"
    "choice\0on_bressenham_clicked\0"
    "on_midpt_clicked\0on_bress_circle_clicked\0"
    "on_ellipse_clicked\0drawEllipse\0p1\0rx\0"
    "ry\0MidPoint_Draw\0r\0drawPolar\0"
    "on_Polar_clicked\0floodfillFunc\0x\0y\0g\0"
    "b\0on_FloodFill_clicked\0on_PolarEllipse_clicked\0"
    "drawPolarEllipse\0major\0minor\0"
    "boundaryFillFunc\0QRgb\0edgecolour\0"
    "on_Cartesian_clicked\0drawCartesian\0"
    "radius\0on_BoundaryFill_clicked\0"
    "on_AddVertex_clicked\0on_DrawPolygon_clicked\0"
    "bressn\0p2\0on_CENTRE_ELLIPSE_clicked\0"
    "on_CENTRE_CIRCLE_clicked\0on_SEED_clicked\0"
    "on_setvertex_clicked\0on_clearvertex_clicked\0"
    "initEdgeTable\0storeEdgeInTable\0x1\0y1\0"
    "x2\0y2\0on_scanlinefill_clicked\0"
    "on_translation_clicked\0flag\0poly_draw\0"
    "std::vector<std::pair<int,int>>\0vlist\0"
    "on_scaling_clicked\0on_rotation_clicked\0"
    "on_shearing_clicked\0on_reflection_clicked\0"
    "on_about_a_point_clicked\0on_set_point_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  302,    2, 0x0a,    0 /* Public */,
       3,    1,  303,    2, 0x0a,    1 /* Public */,
       6,    0,  306,    2, 0x08,    3 /* Private */,
       7,    0,  307,    2, 0x08,    4 /* Private */,
       8,    0,  308,    2, 0x08,    5 /* Private */,
       9,    0,  309,    2, 0x08,    6 /* Private */,
      10,    0,  310,    2, 0x08,    7 /* Private */,
      11,    0,  311,    2, 0x08,    8 /* Private */,
      12,    1,  312,    2, 0x08,    9 /* Private */,
      12,    0,  315,    2, 0x28,   11 /* Private | MethodCloned */,
      14,    0,  316,    2, 0x08,   12 /* Private */,
      15,    0,  317,    2, 0x08,   13 /* Private */,
      16,    0,  318,    2, 0x08,   14 /* Private */,
      17,    0,  319,    2, 0x08,   15 /* Private */,
      18,    3,  320,    2, 0x08,   16 /* Private */,
      22,    2,  327,    2, 0x08,   20 /* Private */,
      24,    2,  332,    2, 0x08,   23 /* Private */,
      25,    0,  337,    2, 0x08,   26 /* Private */,
      26,    5,  338,    2, 0x08,   27 /* Private */,
      31,    0,  349,    2, 0x08,   33 /* Private */,
      32,    0,  350,    2, 0x08,   34 /* Private */,
      33,    3,  351,    2, 0x08,   35 /* Private */,
      36,    6,  358,    2, 0x08,   39 /* Private */,
      39,    0,  371,    2, 0x08,   46 /* Private */,
      40,    2,  372,    2, 0x08,   47 /* Private */,
      42,    0,  377,    2, 0x08,   50 /* Private */,
      43,    0,  378,    2, 0x08,   51 /* Private */,
      44,    0,  379,    2, 0x08,   52 /* Private */,
      45,    2,  380,    2, 0x08,   53 /* Private */,
      47,    0,  385,    2, 0x08,   56 /* Private */,
      48,    0,  386,    2, 0x08,   57 /* Private */,
      49,    0,  387,    2, 0x08,   58 /* Private */,
      50,    0,  388,    2, 0x08,   59 /* Private */,
      51,    0,  389,    2, 0x08,   60 /* Private */,
      52,    0,  390,    2, 0x08,   61 /* Private */,
      53,    4,  391,    2, 0x08,   62 /* Private */,
      58,    0,  400,    2, 0x08,   67 /* Private */,
      59,    3,  401,    2, 0x08,   68 /* Private */,
      59,    2,  408,    2, 0x28,   72 /* Private | MethodCloned */,
      59,    1,  413,    2, 0x28,   75 /* Private | MethodCloned */,
      59,    0,  416,    2, 0x28,   77 /* Private | MethodCloned */,
      61,    4,  417,    2, 0x08,   78 /* Private */,
      64,    0,  426,    2, 0x08,   83 /* Private */,
      65,    0,  427,    2, 0x08,   84 /* Private */,
      66,    0,  428,    2, 0x08,   85 /* Private */,
      67,    0,  429,    2, 0x08,   86 /* Private */,
      68,    0,  430,    2, 0x08,   87 /* Private */,
      69,    0,  431,    2, 0x08,   88 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int, QMetaType::Int,   19,   20,   21,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,   19,   23,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,   19,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   28,   23,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int, QMetaType::Int,   19,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 37, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   28,   38,   23,   29,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,   19,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,   19,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   54,   55,   56,   57,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   60,   27,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   60,   27,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 62, QMetaType::Int, QMetaType::Int, QMetaType::Int,   63,   23,   29,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_show_axes_clicked(); break;
        case 3: _t->on_Draw_clicked(); break;
        case 4: _t->on_set_point1_clicked(); break;
        case 5: _t->on_set_point2_clicked(); break;
        case 6: _t->on_resetButton_clicked(); break;
        case 7: _t->on_showgrid_clicked(); break;
        case 8: _t->on_dda_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_dda_clicked(); break;
        case 10: _t->on_bressenham_clicked(); break;
        case 11: _t->on_midpt_clicked(); break;
        case 12: _t->on_bress_circle_clicked(); break;
        case 13: _t->on_ellipse_clicked(); break;
        case 14: _t->drawEllipse((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->MidPoint_Draw((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->drawPolar((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_Polar_clicked(); break;
        case 18: _t->floodfillFunc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 19: _t->on_FloodFill_clicked(); break;
        case 20: _t->on_PolarEllipse_clicked(); break;
        case 21: _t->drawPolarEllipse((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 22: _t->boundaryFillFunc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QRgb(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 23: _t->on_Cartesian_clicked(); break;
        case 24: _t->drawCartesian((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->on_BoundaryFill_clicked(); break;
        case 26: _t->on_AddVertex_clicked(); break;
        case 27: _t->on_DrawPolygon_clicked(); break;
        case 28: _t->bressn((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 29: _t->on_CENTRE_ELLIPSE_clicked(); break;
        case 30: _t->on_CENTRE_CIRCLE_clicked(); break;
        case 31: _t->on_SEED_clicked(); break;
        case 32: _t->on_setvertex_clicked(); break;
        case 33: _t->on_clearvertex_clicked(); break;
        case 34: _t->initEdgeTable(); break;
        case 35: _t->storeEdgeInTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 36: _t->on_scanlinefill_clicked(); break;
        case 37: _t->on_translation_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 38: _t->on_translation_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->on_translation_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_translation_clicked(); break;
        case 41: _t->poly_draw((*reinterpret_cast< std::vector<std::pair<int,int>>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 42: _t->on_scaling_clicked(); break;
        case 43: _t->on_rotation_clicked(); break;
        case 44: _t->on_shearing_clicked(); break;
        case 45: _t->on_reflection_clicked(); break;
        case 46: _t->on_about_a_point_clicked(); break;
        case 47: _t->on_set_point_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QRgb, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::pair<int,int> >, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 48;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
