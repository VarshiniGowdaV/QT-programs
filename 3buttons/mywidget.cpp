#include "mywidget.h"
#include <QPushButton>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *b1 = new QPushButton("B1");
    QPushButton *b2 = new QPushButton("B2");
    QPushButton *b3 = new QPushButton("B3");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(b1);
    layout->addWidget(b2);
    layout->addWidget(b3);

    this->setLayout(layout);
}
