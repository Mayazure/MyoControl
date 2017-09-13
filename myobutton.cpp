#include "myobutton.h"
#include <QPainter>

MyoButton::MyoButton(int type)
{
    setMaximumSize(100,100);
    setMinimumSize(100,100);
    resize(100,100);
    this->type = type;
}

void MyoButton::paintEvent(QPaintEvent *pEvent)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen(QColor(r,g,b),1,Qt::SolidLine,Qt::FlatCap,Qt::RoundJoin);
    painter.setPen(pen);

    QBrush brush(QColor(r,g,b,a), Qt::SolidPattern);
    painter.setBrush(brush);

//    painter.rotate(angle);

    //    painter.setBrush(brush);

    //    painter.drawRect(l1,l2,100,20);

//    static const QPointF points[4] = {
//        {QPointF(20,0),
//        QPointF(100,80),
//        QPointF(80,100),
//        QPointF(0,20)}
//    };
    painter.drawPolygon(points[type],4);
    //    painter.drawText(rect(),Qt::AlignCenter,"Myo");
    painter.end();
}

void MyoButton::setColor(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void MyoButton::setLevel(int a)
{
    this->a = a;
    update();
}

//void MyoButton::setAngle(int angle)
//{
//    this->angle = angle;
//}

//void MyoButton::setL(int l1, int l2)
//{
//    this->l1 = l1;
//    this->l2 = l2;
//}
