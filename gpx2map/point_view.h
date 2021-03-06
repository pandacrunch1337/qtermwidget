#ifndef POINT_VIEW_H
#define POINT_VIEW_H

#include "route_item.h"

#include <QWidget>
#include <QPen>
#include <QPushButton>
#include <QTreeWidget>
#include <QFrame>
#include <QSlider>
#include <QSplitter>
#include <QSpinBox>


//class PointView: public QWidget
class PointView: public QFrame
{
  Q_OBJECT

  public:
    PointView(QWidget * parent = 0, Qt::WindowFlags f = 0 );
    void set_point(const vector<Point> &p){points_=p;}
    QSize sizeHint() const;
    void set_scale(qreal s){scale_=s;}
    void set_min_point(qreal x, qreal y){min_x_=x; min_y_=y;}

  protected:
    void paintEvent(QPaintEvent *event);

  private:
    vector<Point> points_;
    QPen pen_;
    qreal scale_;
    qreal min_x_, min_y_;

    
};

class PointDisplay : public QFrame
{
  Q_OBJECT

  public:
    PointDisplay(QWidget * parent = 0, Qt::WindowFlags f = 0 );
    void set_point(const vector<Point> &p);
  public slots:
    void change_scale_slot(int value);
  protected:
    void closeEvent ( QCloseEvent * event );

  private:
    PointView *pv_;
    QTreeWidget *point_tree_view_;
    QSpinBox *scale_spin_box_;
    QSlider *scale_slider_;
    QSplitter *splitter_;


};

#endif
