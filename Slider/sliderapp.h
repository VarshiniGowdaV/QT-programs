#ifndef SLIDERAPP_H
#define SLIDERAPP_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class SliderApp : public QWidget
{
    Q_OBJECT

public:
    explicit SliderApp(QWidget *parent = nullptr);

private slots:
    void updateValue(int value);

private:
    QSlider *slider;
    QLabel *valueLabel;
};

#endif // SLIDERAPP_H

