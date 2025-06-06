#include "mywidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
MyWidget::MyWidget(int x,int y,int width,int height,QWidget *parent)
    : QWidget(parent),rectX(x),rectY(y),rectWidth(width),rectheight(height)
{
    qDebug()<<"Mywidget constructor called";
}
MyWidget::~MyWidget()
{
    qDebug()<<"Mywidget destructor called";
}
void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::black);
    painter.drawRect(rectX,rectY,rectWidth,rectheight);
}
