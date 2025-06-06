#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
private:
    int rectX;
    int rectY;
    int rectWidth;
    int rectheight;
public:
     MyWidget(int x,int y,int width,int height,QWidget *paret = nullptr);
    ~MyWidget();
 protected:
    void paintEvent(QPaintEvent *event)override;
};

#endif // MYWIDGET_H
